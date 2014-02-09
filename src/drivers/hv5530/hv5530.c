/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

struct spi_device SPI_DEVICE_CLOCK = {
	.id = 0
};

/** \brief Write and Latch the Shift Registers
 *
 * This function selects the SPI slave device, transmits 8 bytes provided,
 * and pulses the latch line to update the display.
 *
 * \param data Pointer to an 8 byte buffer containing new display data.
 */
void hv5530_set_registers(uint8_t *data) {
	// Transmit to the shift register
	spi_select_device(SPI, &SPI_DEVICE_CLOCK);
	spi_write_packet(SPI, data, 8);
	spi_deselect_device(SPI, &SPI_DEVICE_CLOCK);

	// Latch the display values
	gpio_set_pin_high(PIO_PC1_IDX);
	delay_us(1);
	gpio_set_pin_low(PIO_PC1_IDX);
}

/** \brief Update Clock with specified Time of Day
 *
 * This function converts a time of day to a register map and writes the values
 * into the shift registers.
 *
 * \param ul_hour Time of Day, Hours
 * \param ul_minute Time of Day, Minutes
 * \param ul_second Time of Day, Seconds
 */
void hv5530_set_digits(uint32_t ul_hour, uint32_t ul_minute, uint32_t ul_second) {
	uint8_t reg[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

	switch(ul_second % 10) {
	case 0: reg[0] &= 0b01111111; break; // 64: SEC_ONE_0
	case 9: reg[0] &= 0b10111111; break; // 63: SEC_ONE_9
	case 8: reg[0] &= 0b11011111; break; // 62: SEC_ONE_8
	case 7: reg[0] &= 0b11101111; break; // 61: SEC_ONE_7
	case 6: reg[0] &= 0b11110111; break; // 60: SEC_ONE_6
	case 5: reg[0] &= 0b11111011; break; // 59: SEC_ONE_5
	case 4: reg[0] &= 0b11111101; break; // 58: SEC_ONE_4
	case 3: reg[0] &= 0b11111110; break; // 57: SEC_ONE_3
	case 2: reg[1] &= 0b01111111; break; // 56: SEC_ONE_2
	case 1: reg[1] &= 0b10111111; break; // 55: SEC_ONE_1
	}

	switch(ul_second / 10) {
	case 0: reg[1] &= 0b11011111; break; // 54: SEC_TEN_0
	case 9: reg[1] &= 0b11101111; break; // 53: SEC_TEN_9
	case 8: reg[1] &= 0b11110111; break; // 52: SEC_TEN_8
	case 7: reg[1] &= 0b11111011; break; // 51: SEC_TEN_7
	case 6: reg[1] &= 0b11111101; break; // 50: SEC_TEN_6
	case 5: reg[1] &= 0b11111110; break; // 49: SEC_TEN_5
	case 4: reg[2] &= 0b01111111; break; // 48: SEC_TEN_4
	case 3: reg[2] &= 0b10111111; break; // 47: SEC_TEN_3
	case 2: reg[2] &= 0b11011111; break; // 46: SEC_TEN_2
	case 1: reg[2] &= 0b11101111; break; // 45: SEC_TEN_1
	}

	reg[2] &= 0b11110111; // 44: RCOL_TOP
	reg[2] &= 0b11111011; // 43: RCOL_BOT

	switch(ul_minute % 10) {
	case 0: reg[2] &= 0b11111101; break; // 42: MIN_ONE_0
	case 9: reg[2] &= 0b11111110; break; // 41: MIN_ONE_9
	case 8: reg[3] &= 0b01111111; break; // 40: MIN_ONE_8
	case 7: reg[3] &= 0b10111111; break; // 39: MIN_ONE_7
	case 6: reg[3] &= 0b11011111; break; // 38: MIN_ONE_6
	case 5: reg[3] &= 0b11101111; break; // 37: MIN_ONE_5
	case 4: reg[3] &= 0b11110111; break; // 36: MIN_ONE_4
	case 3: reg[3] &= 0b11111011; break; // 35: MIN_ONE_3
	case 2: reg[3] &= 0b11111101; break; // 34: MIN_ONE_2
	case 1: reg[3] &= 0b11111110; break; // 33: MIN_ONE_1
	}

	switch(ul_minute / 10) {
	case 0: reg[4] &= 0b01111111; break; // 32: MIN_TEN_0
	case 9: reg[4] &= 0b10111111; break; // 31: MIN_TEN_9
	case 8: reg[4] &= 0b11011111; break; // 30: MIN_TEN_8
	case 7: reg[4] &= 0b11101111; break; // 29: MIN_TEN_7
	case 6: reg[4] &= 0b11110111; break; // 28: MIN_TEN_6
	case 5: reg[4] &= 0b11111011; break; // 27: MIN_TEN_5
	case 4: reg[4] &= 0b11111101; break; // 26: MIN_TEN_4
	case 3: reg[4] &= 0b11111110; break; // 25: MIN_TEN_3
	case 2: reg[5] &= 0b01111111; break; // 24: MIN_TEN_2
	case 1: reg[5] &= 0b10111111; break; // 23: MIN_TEN_1
	}

	switch(ul_hour % 10) {
	case 0: reg[5] &= 0b11011111; break; // 22: HOUR_ONE_0
	case 9: reg[5] &= 0b11101111; break; // 21: HOUR_ONE_9
	case 8: reg[5] &= 0b11110111; break; // 20: HOUR_ONE_8
	case 7: reg[5] &= 0b11111011; break; // 19: HOUR_ONE_7
	case 6: reg[5] &= 0b11111101; break; // 18: HOUR_ONE_6
	case 5: reg[5] &= 0b11111110; break; // 17: HOUR_ONE_5
	case 4: reg[6] &= 0b01111111; break; // 16: HOUR_ONE_4
	case 3: reg[6] &= 0b10111111; break; // 15: HOUR_ONE_3
	case 2: reg[6] &= 0b11011111; break; // 14: HOUR_ONE_2
	case 1: reg[6] &= 0b11101111; break; // 13: HOUR_ONE_1
	}

	reg[6] &= 0b11110111; // 12: LCOL_TOP
	reg[6] &= 0b11111011; // 11: LCOL_BOT

	switch(ul_hour / 10) {
	case 0: reg[6] &= 0b11111101; break; // 10: HOUR_TEN_0
	case 9: reg[6] &= 0b11111110; break; // 09: HOUR_TEN_9
	case 8: reg[7] &= 0b01111111; break; // 08: HOUR_TEN_8
	case 7: reg[7] &= 0b10111111; break; // 07: HOUR_TEN_7
	case 6: reg[7] &= 0b11011111; break; // 06: HOUR_TEN_6
	case 5: reg[7] &= 0b11101111; break; // 05: HOUR_TEN_5
	case 4: reg[7] &= 0b11110111; break; // 04: HOUR_TEN_4
	case 3: reg[7] &= 0b11111011; break; // 03: HOUR_TEN_3
	case 2: reg[7] &= 0b11111101; break; // 02: HOUR_TEN_2
	case 1: reg[7] &= 0b11111110; break; // 01: HOUR_TEN_1
	}

	hv5530_set_registers(reg);
}

/** \brief Update Clock with Time of Day from RTC
 *
 * This function reads the time of day from the RTC and writes it to the
 * shift registers.
 */
void hv5530_set_from_rtc(void) {
	uint32_t ul_hour, ul_minute, ul_second;
	rtc_get_time(RTC, &ul_hour, &ul_minute, &ul_second);
	hv5530_set_digits(ul_hour, ul_minute, ul_second);
}

/** \brief Initialize the Nixie Clock Display
 *
 * This function sets up the SPI Controller, writes a blank display, and turns
 * on the High-Voltage Power Supply.
 */
void hv5530_init(void) {
	// Initialize the SPI controller
	spi_master_init(SPI);
	spi_master_setup_device(SPI, &SPI_DEVICE_CLOCK, SPI_MODE_0, 800000, 0);
	spi_enable(SPI);
	gpio_configure_pin(PIO_PC0_IDX, PIO_TYPE_PIO_OUTPUT_0 | PIO_DEFAULT); // Blank
	gpio_configure_pin(PIO_PC1_IDX, PIO_TYPE_PIO_OUTPUT_0 | PIO_DEFAULT); // Latch

	// Initialize the GPIO for the HV PSU as Disabled
	gpio_configure_pin(PIO_PB0_IDX, PIO_TYPE_PIO_OUTPUT_1 | PIO_DEFAULT); // HV Enable (Active Low)

	// Write a zero state
	uint8_t blank[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	hv5530_set_registers(blank);

	// Enable the HV PSU
	gpio_set_pin_low(PIO_PB0_IDX);
}
