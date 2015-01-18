/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "components/ds3231/ds3231.h"
#include "components/hv5530/hv5530.h"
#include "cpu/cortex-m3/nvic.h"
#include "cpu/peripherals/rtc.h"
#include "services/clock/clock.h"
#include "services/display/display.h"
#include "stdio.h"
#include "string.h"

//! Global Cache for the Date and Time since the last second event
volatile timespec_t clock;

//! Clock State Flags
volatile enum {
	clock_state_init = 1,  //!< If flag is set, the driver has been initialized
	clock_state_sync = 2,  //!< If flag is set, the drivers time has been set from the ds3231 chip
} clock_state = 0;


/** \brief Update the Global Date and Time Cache from RTC
 *
 * This function sets the clock_cal_* and clock_time_* global variables with
 * the current time from the RTC.
 */
void clock_refresh_globals(void) {

	// Read the Date Register until we get 2 consecutive matching values
	uint32_t calr = RTC_CALR;
	while (calr != RTC_CALR) {
		calr = RTC_CALR;
	}

	// Read the Time Register until we get 2 consecutive matching values
	uint32_t timr = RTC_TIMR;
	while (timr != RTC_TIMR) {
		timr = RTC_TIMR;
	}

	// Extract the Date Fields
	uint32_t cent = (calr & RTC_CALR_CENT_Msk) >> RTC_CALR_CENT_Pos;
	uint32_t year = (calr & RTC_CALR_YEAR_Msk) >> RTC_CALR_YEAR_Pos;
	uint32_t month = (calr & RTC_CALR_MONTH_Msk) >> RTC_CALR_MONTH_Pos;
	uint32_t day = (calr & RTC_CALR_DAY_Msk) >> RTC_CALR_DAY_Pos;
	uint32_t date = (calr & RTC_CALR_DATE_Msk) >> RTC_CALR_DATE_Pos;

	// Extract the Time Fields
	uint32_t hour = (timr & RTC_TIMR_HOUR_Msk) >> RTC_TIMR_HOUR_Pos;
	uint32_t minute = (timr & RTC_TIMR_MIN_Msk) >> RTC_TIMR_MIN_Pos;
	uint32_t second = (timr & RTC_TIMR_SEC_Msk) >> RTC_TIMR_SEC_Pos;

	// Convert from BCD to Integer and Store
	clock.cent = (10 * ((cent & 0xF0) >> 4)) + (cent & 0xF);
	clock.year = (10 * ((year & 0xF0) >> 4)) + (year & 0xF);
	clock.month = (10 * ((month & 0xF0) >> 4)) + (month & 0xF);
	clock.day = day;
	clock.date = (10 * ((date & 0xF0) >> 4)) + (date & 0xF);
	clock.hour = (10 * ((hour & 0xF0) >> 4)) + (hour & 0xF);
	clock.minute = (10 * ((minute & 0xF0) >> 4)) + (minute & 0xF);
	clock.second = (10 * ((second & 0xF0) >> 4)) + (second & 0xF);
}

/** \brief Set DS3231 External RTC
 *
 * This function sets the time in the DS3231 External RTC and clears the
 * sync flag in the clock state so that it will be read into the internal
 * state at the next second event.
 */
int32_t clock_set(timespec_t *time) {
	// Working Register Set
	uint8_t ds3231_regs[7];
	memset(ds3231_regs, 0, 7);

	// Convert the Time to the BCD Encoded Register Mapping (24hr mode)
	ds3231_regs[0] = 0x7F & ((((time->second / 10) << 4) | (time->second % 10)));
	ds3231_regs[1] = 0x7F & (((time->minute / 10) << 4) | (time->minute % 10));
	ds3231_regs[2] = 0x3F & (((time->hour / 10) << 4) | (time->hour % 10));

	// Convert the Date to the BCD Encoded Register Mapping (24hr mode)
	ds3231_regs[3] = 0x07 & (time->day);
	ds3231_regs[4] = 0x3F & (((time->date / 10) << 4) | (time->date % 10));
	ds3231_regs[5] = 0x1F & (((time->month / 10) << 4) | (time->month % 10));
	if (time->cent == 20) {
		ds3231_regs[5] |= 0x80;
	}
	ds3231_regs[6] = 0xFF & (((time->year / 10) << 4) | (time->year % 10));

	// Write the Registers to the DS3231 RTC
	if (ds3231_write_register(0x00, 7, ds3231_regs) < 0) {
		kputs("ds3231: failed to write date and time registers\r\n");
		return -1;
	}

	// Force the Internal RTC to re-sync
	clock_state &= ~(clock_state_sync);

	// Successfully Updated the RTC
	return 0;
}

/** \brief Set Internal RTC from DS3231 External RTC
 *
 * This function reads the current date and time from the DS3231 External RTC
 * and applies that time to the Internal RTC.
 */
int32_t clock_set_rtc_from_ds3231(void) {
	int32_t ret = 0;

	// Stop the RTC and Request a Calendar and Time Update
	RTC_CR |= RTC_CR_UPDTIM | RTC_CR_UPDCAL;
	// Wait for the RTC to Acknowledge our Request
	while (!(RTC_SR & RTC_SR_ACKUPD));
	// Clear the Acknowledge Flag
	RTC_SCCR = RTC_SCCR_ACKCLR;

	// Read the time and date from the external ds3231
	uint8_t ds3231[7];
	if (ds3231_read_register(0x00, 7, ds3231) < 0) {
		kputs("ds3231: failed to read date and time registers\r\n");
		ret = -1;
	} else {
		// Stage a new time register
		uint32_t timr = 0;
		timr |= RTC_TIMR_SEC(ds3231[0] & 0x7F);
		timr |= RTC_TIMR_MIN(ds3231[1] & 0x7F);
		if (ds3231[2] & 0x40) {
			// 12 hour mode
			RTC_MR |= RTC_MR_HRMOD;
			timr |= RTC_TIMR_HOUR(ds3231[2] & 0x1F);
		} else {
			// 24 hour mode
			RTC_MR &= ~(RTC_MR_HRMOD);
			timr |= RTC_TIMR_HOUR(ds3231[2] & 0x3F);
		}

		// Stage a new calendar register
		uint32_t calr = 0;
		calr |= RTC_CALR_DAY(ds3231[3] & 0x07);
		calr |= RTC_CALR_DATE(ds3231[4] & 0x3F);
		calr |= RTC_CALR_MONTH(ds3231[5] & 0x1F);
		calr |= RTC_CALR_CENT(((ds3231[5] & 0x80) >> 7) + 19);
		calr |= RTC_CALR_YEAR(ds3231[6]);

		// Write the Values to the RTC
		RTC_TIMR = timr;
		RTC_CALR = calr;
	}

	// Clear the Request for a Time Update in the Control Register
	RTC_CR &= ~(RTC_CR_UPDTIM | RTC_CR_UPDCAL);

	// Return an Error if the Time Register has Invalid Data
	if (RTC_VER & (RTC_VER_NVTIM | RTC_VER_NVCAL)) {
		return -1;
	}

	return ret;
}

/** \brief RTC Interrupt Handler
 *
 * Every second update the global variables, set the clock face, and send
 * the time of day to the display service.
 *
 * The clock sync flag will also be checked, if it is not set, the Internal
 * RTC will be refreshed.
 */
void rtc_handler() {
	// Update the Clock Face every Second
	if (RTC_SR & RTC_SR_SEC) {
		// Check if we need to re-sync with the external time source
		if (!(clock_state & clock_state_sync)) {
			clock_set_rtc_from_ds3231();
			clock_state |= clock_state_sync;
		}

		// Update the Global Date and Time Variables from the RTC
		clock_refresh_globals();

		// Update the Clock Face
		hv5530_set_digits(clock.hour, clock.minute, clock.second);

		// Notify the Display Service of this Event
		display_rtc_update();

		// Clear the flag in the status register
		RTC_SCCR = RTC_SCCR_SECCLR;
	}
}

/** Clock Service Initialization
 *
 * Initialize the hv5530 component and enable the second event interrupt
 * in the RTC.
 */
void clock_init(void) {
	// Prepare the RTC and OSC
	ds3231_init();

	// Prepare the Clock Face
	hv5530_init();

	// Enable the RTC Interrupt in the NVIC
	ICER0 = (1 << PMC_ID_RTC); // Disable Interrupt
	ICPR0 = (1 << PMC_ID_RTC); // Clear Pending
	IPR0  = (IPR0 & 0xFF00FFFF) | (0xF0 << 16); // Set the Priority to 15
	ISER0 = (1 << PMC_ID_RTC); // Enable Interrupt
	// Enable Interrupts for RTC
	RTC_IER = RTC_IER_SECEN;

	// Set the initialized flag
	clock_state |= clock_state_init;
}
