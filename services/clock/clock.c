/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "components/hv5530/hv5530.h"
#include "cpu/cortex-m3/nvic.h"
#include "cpu/peripherals/rtc.h"
#include "services/display/display.h"
#include "stdio.h"

//! Global Cache for the Calendar Date
volatile uint8_t clock_cal_cent = 0;
//! Global Cache for the Calendar Date
volatile uint8_t clock_cal_year = 0;
//! Global Cache for the Calendar Date
volatile uint8_t clock_cal_month = 0;
//! Global Cache for the Calendar Date
volatile uint8_t clock_cal_day = 0;
//! Global Cache for the Calendar Date
volatile uint8_t clock_cal_date = 0;

//! Global Cache for the Time of Day
volatile uint8_t clock_time_hour = 0;
//! Global Cache for the Time of Day
volatile uint8_t clock_time_minute = 0;
//! Global Cache for the Time of Day
volatile uint8_t clock_time_second = 0;

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
	clock_cal_cent = (10 * ((cent & 0xF0) >> 4)) + (cent & 0xF);
	clock_cal_year = (10 * ((year & 0xF0) >> 4)) + (year & 0xF);
	clock_cal_month = (10 * ((month & 0xF0) >> 4)) + (month & 0xF);
	clock_cal_day = day;
	clock_cal_date = (10 * ((date & 0xF0) >> 4)) + (date & 0xF);
	clock_time_hour = (10 * ((hour & 0xF0) >> 4)) + (hour & 0xF);
	clock_time_minute = (10 * ((minute & 0xF0) >> 4)) + (minute & 0xF);
	clock_time_second = (10 * ((second & 0xF0) >> 4)) + (second & 0xF);
}

/** \brief RTC Interrupt Handler
 *
 * Every second update the global variables, set the clock face, and send
 * the time of day to the display service.
 */
void rtc_handler() {
	// Update the Clock Face every Second
	if (RTC_SR & RTC_SR_SEC) {
		// Clear the flag in the status register
		RTC_SCCR = RTC_SCCR_SECCLR;

		// Update the Global Date and Time Variables from the RTC
		clock_refresh_globals();

		// Update the Clock Face
		hv5530_set_digits(clock_time_hour, clock_time_minute, clock_time_second);

		// Notify the Display Service of this Event
		display_rtc_update();
	}
}

/** \brief Set the Time in the RTC
 *
 * This function sets the Time of Day in the RTC.
 */
int32_t clock_set_time(uint8_t hour, uint8_t minute, uint8_t second) {
	// Store the Status of the Enabled Interrupts
	uint32_t imr = RTC_IMR;
	// Disable all Enabled Interrupts
	RTC_IDR = imr;

	// Wait for a Second Event in the Status Register
	while (!(RTC_SR & RTC_SR_SEC));
	// Clear the Second Event Flag
	RTC_SCCR = RTC_SCCR_SECCLR;

	// Stop the RTC and Request a Time Update
	RTC_CR |= RTC_CR_UPDTIM;
	// Wait for the RTC to Acknowledge our Request
	while (!(RTC_SR & RTC_SR_ACKUPD));
	// Clear the Acknowledge Flag
	RTC_SCCR = RTC_SCCR_ACKCLR;

	// Stage the new Register Value
	uint32_t timr = 0;
	// Truncate if 12 Hour Mode Active
	if ((hour > 12)&&(RTC_MR & RTC_MR_HRMOD)) {
		timr |= RTC_TIMR_AMPM;
		hour -= 12;
	}
	// Stage Time of Day
	timr |= RTC_TIMR_HOUR(((hour / 10) << 4) + (hour % 10));
	timr |= RTC_TIMR_MIN(((minute / 10) << 4) + (minute % 10));
	timr |= RTC_TIMR_SEC(((second / 10) << 4) + (second % 10));
	// Write the Value to the Register
	RTC_TIMR = timr;

	// Clear the Request for a Time Update in the Control Register
	RTC_CR &= ~(RTC_CR_UPDTIM);

	// Re-Enable the Interrupts Disabled Earlier
	RTC_IER = imr;

	// Return an Error if the Time Register has Invalid Data
	if (RTC_VER & RTC_VER_NVTIM) {
		return -1;
	}

	return 0;
}

/** \brief Set the Date in the RTC
 *
 * This function sets the Date and Year in the RTC.
 */
int32_t clock_set_date(uint8_t cent, uint8_t year, uint8_t month, uint8_t day, uint8_t date) {
	// Store the Status of the Enabled Interrupts
	uint32_t imr = RTC_IMR;
	// Disable all Enabled Interrupts
	RTC_IDR = imr;

	// Wait for a Second Event in the Status Register
	while (!(RTC_SR & RTC_SR_SEC));
	// Clear the Second Event Flag
	RTC_SCCR = RTC_SCCR_SECCLR;

	// Stop the RTC and Request a Calendar Update
	RTC_CR |= RTC_CR_UPDCAL;
	// Wait for the RTC to Acknowledge our Request
	while (!(RTC_SR & RTC_SR_ACKUPD));
	// Clear the Acknowledge Flag
	RTC_SCCR = RTC_SCCR_ACKCLR;

	// Stage the new Register Value
	uint32_t calr = 0;
	calr |= RTC_CALR_CENT(((cent / 10) << 4) + (cent % 10));
	calr |= RTC_CALR_YEAR(((year / 10) << 4) + (year % 10));
	calr |= RTC_CALR_MONTH(((month / 10) << 4) + (month % 10));
	calr |= RTC_CALR_DAY(((day / 10) << 4) + (day % 10));
	calr |= RTC_CALR_DATE(((date / 10) << 4) + (date % 10));
	// Write the Value to the Register
	RTC_CALR = calr;

	// Clear the Request for a Calendar Update in the Control Register
	RTC_CR &= ~(RTC_CR_UPDCAL);

	// Re-Enable the Interrupts Disabled Earlier
	RTC_IER = imr;

	// Return an Error if the Calendar Register has Invalid Data
	if (RTC_VER & RTC_VER_NVCAL) {
		return -1;
	}

	return 0;
}

/** Clock Service Initialization
 *
 * Initialize the hv5530 component and enable the second event interrupt
 * in the RTC.
 */
void clock_init(void) {
	// Prepare the Clock Face
	hv5530_init();

	// Enable the RTC Interrupt in the NVIC
	ICER0 = (1 << PMC_ID_RTC); // Disable Interrupt
	ICPR0 = (1 << PMC_ID_RTC); // Clear Pending
	IPR0  = (IPR0 & 0xFF00FFFF) | (0xF0 << 16); // Set the Priority to 15
	ISER0 = (1 << PMC_ID_RTC); // Enable Interrupt
	// Enable Interrupts for RTC
	RTC_IER = RTC_IER_SECEN;
}
