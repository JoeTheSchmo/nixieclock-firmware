/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

/**
 * \brief Interrupt handler for the RTC. Refresh the display.
 */
void RTC_Handler(void) {
	uint32_t ul_status = rtc_get_status(RTC);

	// Second increment interrupt
	if ((ul_status & RTC_SR_SEC) == RTC_SR_SEC) {
		// Disable RTC interrupt
		rtc_disable_interrupt(RTC, RTC_IDR_SECDIS);

		// Display the Time on the Clock Display
		hv5530_set_from_rtc();

		// Trigger an Event to the Display Service
		display_show_rtc();

		// Clear Second Event from RTC Status Register
		rtc_clear_status(RTC, RTC_SCCR_SECCLR);

		// Enable RTC interrupt
		rtc_enable_interrupt(RTC, RTC_IER_SECEN);
	}
}

void clock_init(void) {
	// Initialize the Clock Display Shift Registers
	hv5530_init();

	// Default RTC Configuration, 24-Hour mode
	rtc_set_hour_mode(RTC, 0);

	// Configure RTC Interrupts
	NVIC_DisableIRQ(RTC_IRQn);
	NVIC_ClearPendingIRQ(RTC_IRQn);
	NVIC_SetPriority(RTC_IRQn, 0xF);
	NVIC_EnableIRQ(RTC_IRQn);
	rtc_enable_interrupt(RTC, RTC_IER_SECEN);
}
