/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

#define DISPLAY_DATA_SIZE 8
uint8_t display_data[DISPLAY_DATA_SIZE];

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

void hv5530_test(void) {

	/* Set a pattern to read by the logic analyzer */
	display_data[0] = 0b01010101;
	display_data[1] = 0x00;
	display_data[2] = 0xFF;
	display_data[3] = 0x00;
	display_data[4] = 0xFF;
	display_data[5] = 0x00;
	display_data[6] = 0xFF;
	display_data[7] = 0x00;

	/* Transmit to the shift register */
	spi_select_device(SPI, &SPI_DEVICE_DISPLAY);
	spi_write_packet(SPI, display_data, 8);
	spi_deselect_device(SPI, &SPI_DEVICE_DISPLAY);
	/* Latch the display values */
	gpio_set_pin_high(PIO_PC1_IDX);
	delay_us(1);
	gpio_set_pin_low(PIO_PC1_IDX);

}