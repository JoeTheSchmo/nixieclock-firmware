/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

// Undefined Vector Handler
extern void undefined_handler(void);

// Exception Interrupt Vectors
extern void reset_handler(void);
extern void hardfault_handler(void)     __attribute__((weak,alias("undefined_handler")));
extern void memfault_handler(void)      __attribute__((weak,alias("undefined_handler")));
extern void busfault_handler(void)      __attribute__((weak,alias("undefined_handler")));
extern void usagefault_handler(void)    __attribute__((weak,alias("undefined_handler")));
extern void svcall_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void pendsv_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void systick_handler(void)       __attribute__((weak,alias("undefined_handler")));

// Peripheral Interrupt Vectors
extern void supc_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void rstc_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void rtc_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void rtt_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void wdt_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void pmc_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void eefc0_handler(void)         __attribute__((weak,alias("undefined_handler")));
extern void eefc1_handler(void)         __attribute__((weak,alias("undefined_handler")));
extern void uart_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void smc_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void pioa_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void piob_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void pioc_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void usart0_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void usart1_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void usart2_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void usart3_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void hsmci_handler(void)         __attribute__((weak,alias("undefined_handler")));
extern void twi0_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void twi1_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void spi_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void ssc_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void tc0_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void tc1_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void tc2_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void pwm_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void adc12b_handler(void)        __attribute__((weak,alias("undefined_handler")));
extern void adc_handler(void)           __attribute__((weak,alias("undefined_handler")));
extern void dmac_handler(void)          __attribute__((weak,alias("undefined_handler")));
extern void udphs_handler(void)         __attribute__((weak,alias("undefined_handler")));

/* Vector Table
 *
 * The vector table contains the reset value of the stack pointer, and the
 * start address. As well as the called vectors for all of the exception
 * and interrupt handlers.
 */
vector_t vector_table[]  __attribute__ ((section(".vectors"))) = {
	(void*)0x20084000,  // IRQ -16 - Initial Stack Pointer, End of RAM
	reset_handler,      // IRQ -15 - Reset Exception Handler
	0,                  // IRQ -14 - Reserved
	hardfault_handler,  // IRQ -13 - Hard Fault Exception Handler
	memfault_handler,   // IRQ -12 - Memory Fault Exception Handler
	busfault_handler,   // IRQ -11 - Bus Fault Exception Handler
	usagefault_handler, // IRQ -10 - Usage Fault Exception Handler
	0,                  // IRQ  -9 - Reserved
	0,                  // IRQ  -8 - Reserved
	0,                  // IRQ  -7 - Reserved
	0,                  // IRQ  -6 - Reserved
	svcall_handler,     // IRQ  -5 - SVCall Exception Handler
	0,                  // IRQ  -4 - Reserved
	0,                  // IRQ  -3 - Reserved
	pendsv_handler,     // IRQ  -2 - PendSV Exception Handler
	systick_handler,    // IRQ  -1 - SysTick Exception Handler
	supc_handler,       // IRQ   0 - Supply Controller
	rstc_handler,       // IRQ   1 - Reset Controller
	rtc_handler,        // IRQ   2 - Real Time Clock
	rtt_handler,        // IRQ   3 - Real Time Timer
	wdt_handler,        // IRQ   4 - Watchdog Timer
	pmc_handler,        // IRQ   5 - Power Management Controller
	eefc0_handler,      // IRQ   6 - Enhanced Embedded Flash Controller 0
	eefc1_handler,      // IRQ   7 - Enhanced Embedded Flash Controller 1
	uart_handler,       // IRQ   8 - Universal Async Receiver Transmitter
	smc_handler,        // IRQ   9 - Static Memory Controller
	pioa_handler,       // IRQ  10 - Parallel Input/Output Controller A
	piob_handler,       // IRQ  11 - Parallel Input/Output Controller B
	pioc_handler,       // IRQ  12 - Parallel Input/Output Controller C
	usart0_handler,     // IRQ  13 - Universal Sync/Async Receiver Transmitter 0
	usart1_handler,     // IRQ  14 - Universal Sync/Async Receiver Transmitter 1
	usart2_handler,     // IRQ  15 - Universal Sync/Async Receiver Transmitter 2
	usart3_handler,     // IRQ  16 - Universal Sync/Async Receiver Transmitter 3
	hsmci_handler,      // IRQ  17 - High-Speed Media Card Interface
	twi0_handler,       // IRQ  18 - Two-wire Interface 0
	twi1_handler,       // IRQ  19 - Two-wire Interface 1
	spi_handler,        // IRQ  20 - Serial Peripheral Interface
	ssc_handler,        // IRQ  21 - Synchronous Serial Controller
	tc0_handler,        // IRQ  22 - Timer Counter 0
	tc1_handler,        // IRQ  23 - Timer Counter 1
	tc2_handler,        // IRQ  24 - Timer Counter 2
	pwm_handler,        // IRQ  25 - Pulse Width Modulation
	adc12b_handler,     // IRQ  26 - 12-bit ADC
	adc_handler,        // IRQ  27 - 10-bit ADC
	dmac_handler,       // IRQ  28 - DMA Controller
	udphs_handler       // IRQ  29 - USB High Speed Port
};

/** Undefined Exception Vector
 *
 * This function is set as the default handler for any undefined handler. A
 * weak link is provided for all other vectors to this symbol.
 */
void undefined_handler(void) {
	while(1);
};

extern void kmain(void);
extern uint32_t _flash_data;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;

/** Reset Handler
 *
 * This function is the reset vector for the CPU. The "Hello World" so to
 * speak. Memory is initialized and zeroed.
 */
void reset_handler(void) {
	// Load the Data section into RAM
	uint32_t *src = &_flash_data; // TODO Stack Leak
	uint32_t *dst = &_data_start; // TODO Stack Leak
	while (dst < &_data_end) {
		*dst++ = *src++;
	}

	// Zero the BSS Section
	dst = &_bss_start;
	while (dst < &_bss_end) {
		*dst++ = '\0';
	}

	// Start the program
	kmain();
}
