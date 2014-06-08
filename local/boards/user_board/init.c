/**
 * \file
 *
 * \brief USER_BOARD board init.
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
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

#include "compiler.h"
#include "board.h"
#include "conf_board.h"
#include "pio.h"
#include "ioport.h"
#include "twi_master.h"

static inline void board_init_hsmci(void) {
#ifdef CONF_BOARD_SD_MMC_HSMCI
	// Configure HSMCI pins
	pio_configure_pin(PIN_HSMCI_MCCDA_GPIO, PIN_HSMCI_MCCDA_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCCK_GPIO, PIN_HSMCI_MCCK_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA0_GPIO, PIN_HSMCI_MCDA0_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA1_GPIO, PIN_HSMCI_MCDA1_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA2_GPIO, PIN_HSMCI_MCDA2_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA3_GPIO, PIN_HSMCI_MCDA3_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA4_GPIO, PIN_HSMCI_MCDA4_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA5_GPIO, PIN_HSMCI_MCDA5_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA6_GPIO, PIN_HSMCI_MCDA6_FLAGS);
	pio_configure_pin(PIN_HSMCI_MCDA7_GPIO, PIN_HSMCI_MCDA7_FLAGS);

	// Configure SD/MMC card detect pin
	pio_configure_pin(SD_MMC_0_CD_GPIO, SD_MMC_0_CD_FLAGS);
#endif
}

static inline void board_init_hv5530(void) {
#ifdef CONF_BOARD_HV5530
	// Configure the HV Power Supply
	pio_configure_pin(PIN_HV5530_HVEN_GPIO, PIN_HV5530_HVEN_FLAGS);

	// Configure Misc GPIO for the HV5530
	pio_configure_pin(PIN_HV5530_BLANK_GPIO, PIN_HV5530_BLANK_FLAGS);
	pio_configure_pin(PIN_HV5530_LATCH_GPIO, PIN_HV5530_LATCH_FLAGS);
#endif
}

static inline void board_init_leds(void) {
#ifdef CONF_BOARD_LEDS
	pio_configure_pin(PIN_LED_0_GPIO, PIN_LED_0_FLAGS);
	pio_configure_pin(PIN_LED_1_GPIO, PIN_LED_1_FLAGS);
	pio_configure_pin(PIN_LED_2_GPIO, PIN_LED_2_FLAGS);
	pio_configure_pin(PIN_LED_3_GPIO, PIN_LED_3_FLAGS);
#endif
}

static inline void board_init_nand(void) {
#ifdef CONF_BOARD_NAND
	// Configure NAND Pins
	pio_configure_pin(PIN_EBI_NANDOE_GPIO, PIN_EBI_NANDOE_FLAGS);
	pio_configure_pin(PIN_EBI_NANDWE_GPIO, PIN_EBI_NANDWE_FLAGS);
	pio_configure_pin(PIN_EBI_NANDCLE_GPIO, PIN_EBI_NANDCLE_FLAGS);
	pio_configure_pin(PIN_EBI_NANDALE_GPIO, PIN_EBI_NANDALE_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_0_GPIO, PIN_EBI_NANDIO_0_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_1_GPIO, PIN_EBI_NANDIO_1_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_2_GPIO, PIN_EBI_NANDIO_2_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_3_GPIO, PIN_EBI_NANDIO_3_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_4_GPIO, PIN_EBI_NANDIO_4_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_5_GPIO, PIN_EBI_NANDIO_5_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_6_GPIO, PIN_EBI_NANDIO_6_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_7_GPIO, PIN_EBI_NANDIO_7_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_8_GPIO, PIN_EBI_NANDIO_8_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_9_GPIO, PIN_EBI_NANDIO_9_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_10_GPIO, PIN_EBI_NANDIO_10_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_11_GPIO, PIN_EBI_NANDIO_11_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_12_GPIO, PIN_EBI_NANDIO_12_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_13_GPIO, PIN_EBI_NANDIO_13_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_14_GPIO, PIN_EBI_NANDIO_14_FLAGS);
	pio_configure_pin(PIN_EBI_NANDIO_15_GPIO, PIN_EBI_NANDIO_15_FLAGS);
	pio_configure_pin(PIN_NF_CE_GPIO, PIN_NF_CE_FLAGS);
	pio_configure_pin(PIN_NF_RB_GPIO, PIN_NF_RB_FLAGS);
#endif
}

static inline void board_init_pck0(void) {
#ifdef CONF_BOARD_PCK0
	// Configure PCK0 Pin
	pio_configure_pin(PIN_PCK0_GPIO, PIN_PCK0_FLAGS);
#endif
}

static inline void board_init_spi(void) {
#ifdef CONF_BOARD_SPI
	// Configure SPI Pins
	pio_configure_pin(PIN_SPI_MISO_GPIO, PIN_SPI_MISO_FLAGS);
	pio_configure_pin(PIN_SPI_MOSI_GPIO, PIN_SPI_MOSI_FLAGS);
	pio_configure_pin(PIN_SPI_SPCK_GPIO, PIN_SPI_SPCK_FLAGS);
#endif
}

static inline void board_init_ssc(void) {
#ifdef CONF_BOARD_SSC
	// Configure SSC Pins
	pio_configure_pin(PIN_SSC_TD_GPIO, PIN_SSC_TD_FLAGS);
	pio_configure_pin(PIN_SSC_TK_GPIO, PIN_SSC_TK_FLAGS);
	pio_configure_pin(PIN_SSC_TF_GPIO, PIN_SSC_TF_FLAGS);
	pio_configure_pin(PIN_SSC_RD_GPIO, PIN_SSC_RD_FLAGS);
	pio_configure_pin(PIN_SSC_RK_GPIO, PIN_SSC_RK_FLAGS);
	pio_configure_pin(PIN_SSC_RF_GPIO, PIN_SSC_RF_FLAGS);
#endif
}

static inline void board_init_twi0(void) {
#ifdef CONF_BOARD_TWI0
	// Configure TWI0 Pins
	pio_configure_pin(PIN_TWI0_SDA_GPIO, PIN_TWI0_SDA_FLAGS);
	pio_configure_pin(PIN_TWI0_SCL_GPIO, PIN_TWI0_SCL_FLAGS);
#endif

#ifdef CONF_BOARD_TWI0_MASTER_CLK
	// Initialize TWI0
	twi_options_t twi0_opt = {
		.master_clk = sysclk_get_peripheral_hz(),
		.speed = CONF_BOARD_TWI0_MASTER_CLK
	};
	twi_master_setup(TWI0, &twi0_opt);
#endif
}

static inline void board_init_uart(void) {
#ifdef CONF_BOARD_UART_CONSOLE
	// Configure UART Pins
	pio_configure_pin(PIN_UART_URXD_GPIO, PIN_UART_URXD_FLAGS);
	pio_configure_pin(PIN_UART_UTXD_GPIO, PIN_UART_UTXD_FLAGS);
#endif
}

static inline void board_init_usart0(void) {
#ifdef CONF_BOARD_USART0
	// Configure UART Pins
	pio_configure_pin(PIN_USART0_RXD_GPIO, PIN_USART0_RXD_FLAGS);
	pio_configure_pin(PIN_USART0_TXD_GPIO, PIN_USART0_TXD_FLAGS);
	pio_configure_pin(PIN_USART0_CTS_GPIO, PIN_USART0_CTS_FLAGS);
	pio_configure_pin(PIN_USART0_RTS_GPIO, PIN_USART0_RTS_FLAGS);
#endif
}

static inline void board_init_xbee(void) {
#ifndef CONF_BOARD_XBEE
	// Configure XBee Pins
	pio_configure_pin(PIN_XBEE_SHDN_GPIO, PIN_XBEE_SHDN_FLAGS);
	pio_configure_pin(PIN_XBEE_DTR_GPIO, PIN_XBEE_DTR_FLAGS);
#endif
}

void board_init(void) {
#ifndef CONF_BOARD_KEEP_WATCHDOG_AT_INIT
	/* Disable the watchdog */
	WDT->WDT_MR = WDT_MR_WDDIS;
#endif

	/* GPIO has been deprecated, the old code just keeps it for compatibility.
	 * In new designs IOPORT is used instead.
	 * Here IOPORT must be initialized for others to use before setting up IO.
	 */
	ioport_init();

	// Initialize I/O and Peripherals
	board_init_hsmci();
	board_init_hv5530();
	board_init_leds();
	board_init_nand();
	board_init_pck0();
	board_init_spi();
	board_init_ssc();
	board_init_twi0();
	board_init_uart();
	board_init_usart0();
	board_init_xbee();
}
