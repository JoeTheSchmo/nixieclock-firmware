/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */
#include <stdio.h>

#include "audio.h"
#include "board.h"
#include "clock.h"
#include "compiler.h"
#include "console.h"
#include "display.h"
#include "ioport.h"
#include "rstc.h"
#include "sleep.h"
#include "svcall.h"
#include "sysclk.h"

/** NMI Handler
 *
 * This function is called when a NMI exception has occurred.
 */
void __attribute__((naked)) NMI_Handler(void) {
	//kputs("Exception: NMI\r\n");
	while(1);
}

/** Hard Fault Handler
 *
 * This function is called when a hard fault exception has occurred.
 */
void __attribute__((naked)) HardFault_Handler(void) {
	//kputs("Exception: Hard Fault\r\n");
	while(1);
}

/** Memory Fault Handler
 *
 * This function is called when a memory fault exception has occurred.
 */
void __attribute__((naked)) MemManage_Handler(void) {
	//kputs("Exception: Memory Fault\r\n");
	while (1);
}

/** Bus Fault Handler
 *
 * This function is called when a bus fault exception has occurred.
 */
void __attribute__((naked)) BusFault_Handler(void) {
	//kputs("Exception: Bus Fault\r\n");
	while (1);
}

/** Usage Fault Handler
 *
 * This function is called when a usage fault exception has occurred.
 */
void __attribute__((naked)) UsageFault_Handler(void) {
	//kputs("Exception: Usage Fault\r\n");
	while (1);
}

/** Dummy Call
 *
 * We are not using libc but the ASF startup routines are expecting this call.
 */
void __attribute__((naked)) __libc_init_array(void) {
	asm volatile ("bx lr");
}

/** Print Reset Reason
 *
 *
 * This function read the reset controller status register and informs the
 * user how the cpu was reset.
 */
void print_reset_type(void) {
	uint32_t type = rstc_get_reset_cause(RSTC);
	kputs("cpu: reset type; ");
	switch (type) {
	case RSTC_GENERAL_RESET:  kputs("general\r\n"); break;
	case RSTC_BACKUP_RESET:   kputs("backup\r\n"); break;
	case RSTC_WATCHDOG_RESET: kputs("watchdog\r\n"); break;
	case RSTC_SOFTWARE_RESET: kputs("software\r\n"); break;
	case RSTC_USER_RESET:     kputs("user\r\n"); break;
	default: kprintf("unknown (%lu)\r\n", type);
	}
}

/** Firmware Entry Point
 *
 * After \ref reset_handler finishes the core initialization, this function
 * is the main firmware entry point. Clock configuration and main loops.
 */
int main(void) {
	// Prepare system clock and gpio
	sysclk_init();
	board_init();

	// Divide the interrupts into 4 groups of 4; 0-3, 4-7, 8-11, 12-15.
	// Interrupts within the same group will not preempt each other but an
	// interrupt from a group with a lower priority will. When two interrupts
	// within the same group are received at the same time, the one with the
	// lower priority will be serviced first.
	NVIC_SetPriorityGrouping(5);

	// Enable CPU Interrupts and Exceptions
	cpu_irq_enable();

	// Configure the SVCall Interrupt
	svcall_init();

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
	ioport_set_pin_level(PIN_LED_0, IOPORT_PIN_LEVEL_HIGH);

	// Idle until the next instruction comes along.
	while (1) {
		//pmc_sleep(SAM_PM_SMODE_SLEEP_WFI);
	}
}
