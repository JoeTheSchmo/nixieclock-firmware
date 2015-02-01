/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "compiler.h"
#include "board.h"
#include "ioport.h"
#include "rstc.h"
#include "twi.h"
#include "wdt.h"

static inline void board_init_5vpsu(void) {
	// Configure PIN_5VPSU_EN
	ioport_enable_pin(PIN_5VPSU_EN);
	ioport_set_pin_dir(PIN_5VPSU_EN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_LOW);

	// Configure PIN_5VPSU_PG
	ioport_enable_pin(PIN_5VPSU_PG);
	ioport_set_pin_dir(PIN_5VPSU_PG, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(PIN_5VPSU_PG, IOPORT_MODE_PULLUP);
}

static inline void board_init_ds3231(void) {
	// Configure PIN_DS3231_INT
	ioport_enable_pin(PIN_DS3231_INT);
	ioport_set_pin_dir(PIN_DS3231_INT, IOPORT_DIR_INPUT);
}

static inline void board_init_hv5530(void) {
	// Configure PIN_HV5530_HVEN
	ioport_set_pin_dir(PIN_HV5530_HVEN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_LOW);

	// Configure PIN_HV5530_BLANK
	ioport_set_pin_dir(PIN_HV5530_HVEN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_HIGH);

	// Configure PIN_HV5530_LATCH
	ioport_set_pin_dir(PIN_HV5530_LATCH, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_HV5530_LATCH, IOPORT_PIN_LEVEL_HIGH);
}


static inline void board_init_leds(void) {
	// Configure PIN_LED_0
	ioport_set_pin_dir(PIN_LED_0, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_LED_0, IOPORT_PIN_LEVEL_LOW);

	// Configure PIN_LED_1
	ioport_set_pin_dir(PIN_LED_1, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_LED_1, IOPORT_PIN_LEVEL_LOW);

	// Configure PIN_LED_2
	ioport_set_pin_dir(PIN_LED_2, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_LED_2, IOPORT_PIN_LEVEL_LOW);

	// Configure PIN_LED_3
	ioport_set_pin_dir(PIN_LED_3, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_LED_3, IOPORT_PIN_LEVEL_LOW);
}

static inline void board_init_pck0(void) {
	// Configure PIN_PCK0
	ioport_disable_pin(PIN_PCK0);
	ioport_set_pin_mode(PIN_PCK0, IOPORT_MODE_MUX_B);
}

static inline void board_init_spi(void) {
	// Configure PIN_SPI_MISO (PA13 / Peripheral A / Pull-Up)
	ioport_disable_pin(PIN_SPI_MISO);
	ioport_set_pin_mode(PIN_SPI_MISO, IOPORT_MODE_MUX_A | IOPORT_MODE_PULLUP);

	// Configure PIN_SPI_MOSI (PA14 / Peripheral A / Pull-Up)
	ioport_disable_pin(PIN_SPI_MOSI);
	ioport_set_pin_mode(PIN_SPI_MOSI, IOPORT_MODE_MUX_A | IOPORT_MODE_PULLUP);

	// Configure PIN_SPI_SPCK (PA15 / Peripheral A / Pull-Up)
	ioport_disable_pin(PIN_SPI_SPCK);
	ioport_set_pin_mode(PIN_SPI_SPCK, IOPORT_MODE_MUX_A | IOPORT_MODE_PULLUP);
}

static inline void board_init_ssc(void) {
	// Configure PIN_SSC_TD (PA26 / Peripheral A)
	ioport_disable_pin(PIN_SSC_TD);
	ioport_set_pin_mode(PIN_SSC_TD, IOPORT_MODE_MUX_A);

	// Configure PIN_SSC_RD (PA27 / Peripheral A)
	ioport_disable_pin(PIN_SSC_RD);
	ioport_set_pin_mode(PIN_SSC_RD, IOPORT_MODE_MUX_A);

	// Configure PIN_SSC_TK (PA28 / Peripheral A)
	ioport_disable_pin(PIN_SSC_TK);
	ioport_set_pin_mode(PIN_SSC_TK, IOPORT_MODE_MUX_A);

	// Configure PIN_SSC_RK (PA29 / Peripheral A)
	ioport_disable_pin(PIN_SSC_RK);
	ioport_set_pin_mode(PIN_SSC_RK, IOPORT_MODE_MUX_A);

	// Configure PIN_SSC_TF (PA30 / Peripheral A)
	ioport_disable_pin(PIN_SSC_TF);
	ioport_set_pin_mode(PIN_SSC_TF, IOPORT_MODE_MUX_A);

	// Configure PIN_SSC_RF (PA31 / Peripheral A)
	ioport_disable_pin(PIN_SSC_RF);
	ioport_set_pin_mode(PIN_SSC_RF, IOPORT_MODE_MUX_A);
}

static inline void board_init_twi0(void) {
	// Configure PIN_TWI0_SDA (PA9 / Peripheral A)
	ioport_disable_pin(PIN_TWI0_SDA);
	ioport_set_pin_mode(PIN_TWI0_SDA, IOPORT_MODE_MUX_A);

	// Configure PIN_TWI0_SCL (PA10 / Peripheral A)
	ioport_disable_pin(PIN_TWI0_SCL);
	ioport_set_pin_mode(PIN_TWI0_SCL, IOPORT_MODE_MUX_A);

	// Prepare TWI0 Options
	twi_options_t opt;
	opt.master_clk = sysclk_get_peripheral_hz();
	opt.speed = 400000;
	opt.smbus = 0;

	// Initialize TWI0
	sysclk_enable_peripheral_clock(ID_TWI0);
	twi_master_init(TWI0, &opt);
}

static inline void board_init_uart(void) {
	// Configure PIN_UART_RXD (PA11 / Peripheral A)
	ioport_disable_pin(PIN_UART_RXD);
	ioport_set_pin_mode(PIN_UART_RXD, IOPORT_MODE_MUX_A);

	// Configure PIN_UART_TXD (PA12 / Peripheral A)
	ioport_disable_pin(PIN_UART_TXD);
	ioport_set_pin_mode(PIN_UART_TXD, IOPORT_MODE_MUX_A);
}

static inline void board_init_xbee(void) {
	// Configure PIN_XBEE_SHDN
	ioport_enable_pin(PIN_XBEE_SHDN);
	ioport_set_pin_dir(PIN_XBEE_SHDN, PIN_XBEE_SHDN);
	ioport_set_pin_level(PIN_XBEE_SHDN, IOPORT_PIN_LEVEL_LOW);
}

void board_init(void) {
	// Disable the Watch Dog Timer
	wdt_disable(WDT);

	// Assert NRST for 2^(11+1) Slow Clock Cycles (32 kHz * 4096 = 128ms)
	rstc_set_external_reset(RSTC, 11);
	// Enable User Resets by Asserting the NRST Pin
	rstc_enable_user_reset(RSTC);

	// Initialize the ioport service
	ioport_init();

	// Setup Various I/O
	board_init_5vpsu();
	board_init_ds3231();
	board_init_hv5530();
	board_init_leds();
	board_init_pck0();
	board_init_spi();
	board_init_ssc();
	board_init_twi0();
	board_init_uart();
	board_init_xbee();
}
