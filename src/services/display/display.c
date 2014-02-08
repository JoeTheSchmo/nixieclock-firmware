/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

void display_show_rtc(void) {
	// Draw the date in page 0
	{
		char date[11];
		{
			uint32_t ul_year, ul_month, ul_day;
			rtc_get_date(RTC, &ul_year, &ul_month, &ul_day, NULL);
			snprintf(date, 11, "%04lu/%02lu/%02lu", ul_year, ul_month, ul_day);
		};
		ssd1306_set_page_start_addr(0);
		ssd1306_set_column_start_addr(0);
		ssd1306_puts(date);
	};

	// Draw the time in page 1
	{
		char time[9];

		{
			uint32_t ul_hour, ul_minute, ul_second;
			rtc_get_time(RTC, &ul_hour, &ul_minute, &ul_second);
			snprintf(time, 9, "%02lu:%02lu:%02lu", ul_hour, ul_minute, ul_second);
		};

		ssd1306_set_page_start_addr(1);
		ssd1306_set_column_start_addr(8);
		ssd1306_puts(time);
	};
}

/**
 * Init TWI interface for SSD1306 .
 */
static void display_init_ssd1306_twi(void)
{	/* Configure the options of TWI driver */
	twi_options_t opt = {
		.master_clk = sysclk_get_peripheral_hz(),
		.speed = SSD1306_TWI_CLK,
		.chip = SSD1306_SLAVE_ADDRESS
	};

	twi_master_setup(TWI_SSD1306, &opt);
}

/**
 * Configure the SSD1306 Display Controller .
 */
static void display_init_ssd1306(void) {
	display_init_ssd1306_twi();
	ssd1306_init();

	// Set Horizontal Addressing Mode, Window = { Col 0 - 127, Page 0 - 3 }
	ssd1306_set_mem_addr_mode(0x0);
	ssd1306_set_column_addr(0x0, 0x7F);
	ssd1306_set_page_addr(0x0, 0x3);
}

/**
 * Init the Display Service
 */
void display_init(void) {
	display_init_ssd1306();
}
