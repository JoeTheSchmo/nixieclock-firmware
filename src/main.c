/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * \mainpage Nixie Clock Firmware
 *
 * \section Purpose
 *
 * This is a pre-release firmware for the Nixie Clock designed by Ed Koloski and
 * Joe Ciccone. The firmware, hardware, documentation, and any other associated
 * items should be considered unstable and subject to change without notice.
 *
 * This has been a test of the emergency broadcast system.
 *
 * \section Usage
 *
 * -# Build the program and download it inside the evaluation board.
 * -# On the computer, open and configure a terminal application
 *    (e.g. HyperTerminal on Microsoft Windows) with these settings:
 *   - 115200 bauds
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# Start the application.
 *
 */

#include "asf.h"
#include "stdio_serial.h"

#include "conf_board.h"
#include "conf_clock.h"

/**
 * \brief Interrupt handler for the RTC. Refresh the display.
 */
void RTC_Handler(void) {
	uint32_t ul_status = rtc_get_status(RTC);

	/* Second increment interrupt */
	if ((ul_status & RTC_SR_SEC) == RTC_SR_SEC) {
		/* Disable RTC interrupt */
		rtc_disable_interrupt(RTC, RTC_IDR_SECDIS);

		hv5530_set_from_rtc();
		display_hx8347a_show_rtc();

		rtc_clear_status(RTC, RTC_SCCR_SECCLR);

		rtc_enable_interrupt(RTC, RTC_IER_SECEN);
	}
}

/**
 *  Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/**
 *  \brief Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	/* Prepare interrupts */
	irq_initialize_vectors();
	cpu_irq_enable();

	/* Initialize the SAM system */
	sysclk_init();
	board_init();

	/* Initialize the console uart */
	configure_console();

	/* Enable peripheral clock */
	pmc_enable_periph_clk(ID_SMC);

	/* Output version information */
	printf("\r\n" \
		"-- Nixie Clock Firmware v"VERSION" --\r\n" \
		"-- "BOARD_NAME" --\r\n" \
		"-- Compiled: "__DATE__" "__TIME__" --\r\n");

	/* Initialize the clock display shift registers */
	hv5530_init();

	/* Initialize the graphical display */
	display_init();

	/* Initialize SD MMC stack */
	sd_mmc_init();

	/* Initialze the Audio Service */
	audio_init();

	/* Default RTC configuration, 24-hour mode */
	rtc_set_hour_mode(RTC, 0);

	/* Configure RTC interrupts */
	NVIC_DisableIRQ(RTC_IRQn);
	NVIC_ClearPendingIRQ(RTC_IRQn);
	NVIC_SetPriority(RTC_IRQn, 0);
	NVIC_EnableIRQ(RTC_IRQn);
	rtc_enable_interrupt(RTC, RTC_IER_SECEN);

	/* Initialization Complete: Start Work */

	/* Test setting for the RTC */
	rtc_set_time(RTC, 11, 15, 32);
	rtc_set_date(RTC, 2012, 12, 6, 1);

	/* Test output to the hx8347a display */
	display_hx8347a_test();

	/* Main Loop */
	while(1) {
		/* Do Something */
		delay_ms(1000);
	};

	return 0;
}
