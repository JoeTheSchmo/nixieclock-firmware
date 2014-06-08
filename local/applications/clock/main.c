/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
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

void NMI_Handler(void) {
	while(1) {};
}
void HardFault_Handler(void) {
	SCB_Type *scb = (void*)(0xE000ED00);
	if (scb->HFSR & SCB_HFSR_VECTTBL_Msk) {
		pio_set_pin_high(PIN_LED_0_GPIO);
	} else if (scb->HFSR & SCB_HFSR_FORCED_Msk) {
		pio_set_pin_high(PIN_LED_1_GPIO);
	} else if (scb->HFSR & SCB_HFSR_VECTTBL_Msk) {
		pio_set_pin_high(PIN_LED_2_GPIO);
	}
	while(1) {};
}
void MemManage_Handler(void) {
	pio_set_pin_high(PIN_LED_1_GPIO);
	while(1) {};
}
void BusFault_Handler(void) {
	pio_set_pin_high(PIN_LED_2_GPIO);
	while(1) {};
}
void UsageFault_Handler(void) {
	pio_set_pin_high(PIN_LED_3_GPIO);
	while(1) {};
}
void SVC_Handler(void) {
	while(1) {};
}
void DebugMon_Handler(void) {
	while(1) {};
}
void PendSV_Handler(void) {
	while(1) {};
}
void SysTick_Handler(void) {
	while(1) {};
}


/**
 *  Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.charlength = US_MR_CHRL_8_BIT,
		.paritytype = CONF_UART_PARITY,
		.stopbits = US_MR_NBSTOP_1_BIT
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

	/* Initialize the Display Service */
	display_init();

	/* Initialize the Clock Service */
	clock_init();

	/* Initialize SD MMC stack */
	sd_mmc_init();

	/* Initialize the Audio Service */
	audio_init();

	/* Initialization Complete */

	/* Do Nothing */
	while(1) {
		delay_ms(1000);
	};

	return 0;
}
