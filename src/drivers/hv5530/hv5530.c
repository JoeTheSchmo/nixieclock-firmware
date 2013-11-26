/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

struct spi_device SPI_DEVICE_DISPLAY = {
	.id = 0
};

void hv5530_init(void) {
	/* Initialize the SPI controller */
	spi_master_init(SPI);
	spi_master_setup_device(SPI, &SPI_DEVICE_DISPLAY, SPI_MODE_1, 1000000, 0);
	spi_enable(SPI);
	gpio_configure_pin(PIO_PC0_IDX, PIO_TYPE_PIO_OUTPUT_0 | PIO_DEFAULT); // Blank
	gpio_configure_pin(PIO_PC1_IDX, PIO_TYPE_PIO_OUTPUT_0 | PIO_DEFAULT); // Latch
}

void hv5530_set_registers(uint8_t *data) {
	/* Transmit to the shift register */
	spi_select_device(SPI, &SPI_DEVICE_DISPLAY);
	spi_write_packet(SPI, data, 8);
	spi_deselect_device(SPI, &SPI_DEVICE_DISPLAY);
	/* Latch the display values */
	gpio_set_pin_high(PIO_PC1_IDX);
	delay_us(1);
	gpio_set_pin_low(PIO_PC1_IDX);
}

void hv5530_set_from_rtc(void) {
	uint32_t ul_hour, ul_minute, ul_second;
	rtc_get_time(RTC, &ul_hour, &ul_minute, &ul_second);

	uint8_t display_data[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	/**
	64: SEC_ONE_0
	63: SEC_ONE_1
	62: SEC_ONE_2
	61: SEC_ONE_3
	60: SEC_ONE_4
	59: SEC_ONE_5
	58: SEC_ONE_6
	57: SEC_ONE_7
	56: SEC_ONE_8
	55: SEC_ONE_9
	*/
	switch (ul_second % 10) {
	case 0: display_data[0] |= 1 << 7; break;
	case 1: display_data[0] |= 1 << 6; break;
	case 2: display_data[0] |= 1 << 5; break;
	case 3: display_data[0] |= 1 << 4; break;
	case 4: display_data[0] |= 1 << 3; break;
	case 5: display_data[0] |= 1 << 2; break;
	case 6: display_data[0] |= 1 << 1; break;
	case 7: display_data[0] |= 1 << 0; break;
	case 8: display_data[1] |= 1 << 7; break;
	case 9: display_data[1] |= 1 << 6; break;
	}

	/**
	54: SEC_TEN_0
	53: SEC_TEN_9
	52: SEC_TEN_8
	51: SEC_TEN_7
	50: SEC_TEN_6
	49: SEC_TEN_5
	48: SEC_TEN_4
	47: SEC_TEN_3
	46: SEC_TEN_2
	45: SEC_TEN_1
	*/
	switch (ul_second / 10) {
	case 0: display_data[1] |= 1 << 5; break;
	case 9: display_data[1] |= 1 << 4; break;
	case 8: display_data[1] |= 1 << 3; break;
	case 7: display_data[1] |= 1 << 2; break;
	case 6: display_data[1] |= 1 << 1; break;
	case 5: display_data[1] |= 1 << 0; break;
	case 4: display_data[2] |= 1 << 7; break;
	case 3: display_data[2] |= 1 << 6; break;
	case 2: display_data[2] |= 1 << 5; break;
	case 1: display_data[2] |= 1 << 4; break;
	}

	/**
	44: RCOL_TOP
	43: RCOL_BOT
	*/
	display_data[2] |= 1 << 3;
	display_data[2] |= 1 << 2;

	/**
	42: MIN_ONE_0
	41: MIN_ONE_9
	40: MIN_ONE_8
	39: MIN_ONE_7
	38: MIN_ONE_6
	37: MIN_ONE_5
	36: MIN_ONE_4
	35: MIN_ONE_3
	34: MIN_ONE_2
	33: MIN_ONE_1
	*/
	switch (ul_minute % 10) {
	case 0: display_data[2] |= 1 << 1; break;
	case 9: display_data[2] |= 1 << 0; break;
	case 8: display_data[3] |= 1 << 7; break;
	case 7: display_data[3] |= 1 << 6; break;
	case 6: display_data[3] |= 1 << 5; break;
	case 5: display_data[3] |= 1 << 4; break;
	case 4: display_data[3] |= 1 << 3; break;
	case 3: display_data[3] |= 1 << 2; break;
	case 2: display_data[3] |= 1 << 1; break;
	case 1: display_data[3] |= 1 << 0; break;
	}

	/**
	32: MIN_TEN_0
	31: MIN_TEN_1
	30: MIN_TEN_2
	29: MIN_TEN_3
	28: MIN_TEN_4
	27: MIN_TEN_5
	26: MIN_TEN_6
	25: MIN_TEN_7
	24: MIN_TEN_8
	23: MIN_TEN_9
	*/
	switch (ul_minute / 10) {
	case 0: display_data[4] |= 1 << 7; break;
	case 1: display_data[4] |= 1 << 6; break;
	case 2: display_data[4] |= 1 << 5; break;
	case 3: display_data[4] |= 1 << 4; break;
	case 4: display_data[4] |= 1 << 3; break;
	case 5: display_data[4] |= 1 << 2; break;
	case 6: display_data[4] |= 1 << 1; break;
	case 7: display_data[4] |= 1 << 0; break;
	case 8: display_data[5] |= 1 << 7; break;
	case 9: display_data[5] |= 1 << 6; break;
	}

	/**
	22: HR_ONE_0
	21: HR_ONE_9
	20: HR_ONE_8
	19: HR_ONE_7
	18: HR_ONE_6
	17: HR_ONE_5
	16: HR_ONE_4
	15: HR_ONE_3
	14: HR_ONE_2
	13: HR_ONE_1
	*/
	switch (ul_hour % 10) {
	case 0: display_data[5] |= 1 << 5; break;
	case 9: display_data[5] |= 1 << 4; break;
	case 8: display_data[5] |= 1 << 3; break;
	case 7: display_data[5] |= 1 << 2; break;
	case 6: display_data[5] |= 1 << 1; break;
	case 5: display_data[5] |= 1 << 0; break;
	case 4: display_data[6] |= 1 << 7; break;
	case 3: display_data[6] |= 1 << 6; break;
	case 2: display_data[6] |= 1 << 5; break;
	case 1: display_data[6] |= 1 << 4; break;
	}

	/**
	12: LCOL_TOP
	11: LCOL_BOT
	*/
	display_data[6] |= 1 << 3;
	display_data[6] |= 1 << 2;

	/**
	10: HR_TEN_0
	09: HR_TEN_9
	08: HR_TEN_8
	07: HR_TEN_7
	06: HR_TEN_6
	05: HR_TEN_5
	04: HR_TEN_4
	03: HR_TEN_3
	02: HR_TEN_2
	01: HR_TEN_1
	*/
	switch (ul_hour / 10) {
	case 0: display_data[6] |= 1 << 1; break;
	case 9: display_data[6] |= 1 << 0; break;
	case 8: display_data[7] |= 1 << 7; break;
	case 7: display_data[7] |= 1 << 6; break;
	case 6: display_data[7] |= 1 << 5; break;
	case 5: display_data[7] |= 1 << 4; break;
	case 4: display_data[7] |= 1 << 3; break;
	case 3: display_data[7] |= 1 << 2; break;
	case 2: display_data[7] |= 1 << 1; break;
	case 1: display_data[7] |= 1 << 0; break;
	}

	hv5530_set_registers(display_data);
}
