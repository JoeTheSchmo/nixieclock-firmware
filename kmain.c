/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "board/init.h"
#include "board/pins.h"
#include "components/ssd1306/ssd1306.h"
#include "cpu/peripherals/pio.h"
#include "cpu/peripherals/rstc.h"
#include "services/audio/audio.h"
#include "services/clock/clock.h"
#include "services/console/console.h"
#include "services/display/display.h"
#include "stdio.h"

/** Print Reset Reason
 *
 *
 * This function read the reset controller status register and informs the
 * user how the cpu was reset.
 */
void print_reset_type(void) {
	uint32_t rst_typ = ((RSTC_SR & RSTC_SR_RSTTYP_Msk) >> RSTC_SR_RSTTYP_Pos);
	kputs("cpu: reset type; ");
	switch (rst_typ) {
	case RSTC_SR_RSTTYP_GENERAL: kputs("general\r\n"); break;
	case RSTC_SR_RSTTYP_BACKUP: kputs("backup\r\n"); break;
	case RSTC_SR_RSTTYP_WATCHDOG: kputs("watchdog\r\n"); break;
	case RSTC_SR_RSTTYP_SOFTWARE: kputs("software\r\n"); break;
	case RSTC_SR_RSTTYP_USER: kputs("user\r\n"); break;
	default: kprintf("unknown (%lu)\r\n", rst_typ);
	}
}

/** Firmware Entry Point
 *
 * After \ref reset_handler finishes the core initialization, this function
 * is the main firmware entry point. Clock configuration and main loops.
 */
void kmain(void) {
	sysclock_init();
	board_init();

	// Enable interrupts and fault handlers
	asm volatile("cpsie i");
	asm volatile("dmb");

	// Enable the Console
	console_init();

	// Console Header
	kputs("\r\n\r\n----------\r\n");
	kputs("Nixie Clock\r\n");

	// Inform the User how the CPU Reset
	print_reset_type();

	// Initialize the Clock Face
	clock_init();

	// Initialize the Display
	display_init();

	// Initialize the Audio Service
	audio_init();

	// Turn On LED 0
	PIO_SODR(PIN_LED_0_PIO) = (1 << PIN_LED_0_IDX);

	// Idle until the next instruction comes along.
	while (1) {
		asm volatile ("wfi");
	}
}
