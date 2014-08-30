/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "components/ssd1306/ssd1306.h"
#include "services/clock/clock.h"
#include "stdlib.h"

/** Display Date and Time on Display
 *
 * This function uses the cached date and time from the clock service to
 * print the date and time on the graphical display.
 */
void display_rtc_update() {
	// Convert the Date to a String
	char date[11];
	ultostr(clock.cent, date, 10);
	if (clock.year < 10) {
		date[2] = '0';
		ultostr(clock.year, date+3, 10);
	} else {
		ultostr(clock.year, date+2, 10);
	}
	date[4] = '/';
	if (clock.month < 10) {
		date[5] = '0';
		ultostr(clock.month, date+6, 10);
	} else {
		ultostr(clock.month, date+5, 10);
	}
	date[7] = '/';
	if (clock.date < 10) {
		date[8] = '0';
		ultostr(clock.date, date+9, 10);
	} else {
		ultostr(clock.date, date+8, 10);
	}
	date[10] = '\0';

	// Convert the Time to a String
	char time[9];
	if (clock.hour < 10) {
		time[0] = '0';
		ultostr(clock.hour, time+1, 10);
	} else {
		ultostr(clock.hour, time, 10);
	}
	time[2] = ':';
	if (clock.minute < 10) {
		time[3] = '0';
		ultostr(clock.minute, time+4, 10);
	} else {
		ultostr(clock.minute, time+3, 10);
	}
	time[5] = ':';
	if (clock.second < 10) {
		time[6] = '0';
		ultostr(clock.second, time+7, 10);
	} else {
		ultostr(clock.second, time+6, 10);
	}
	time[8] = '\0';

	// Draw the Date in Page 0
	ssd1306_set_page_start_addr(0);
	ssd1306_set_column_start_addr(24);
	ssd1306_puts(date);
	// Draw the Time in Page 1
	ssd1306_set_page_start_addr(1);
	ssd1306_set_column_start_addr(32);
	ssd1306_puts(time);
}

/** Display Service Initialization
 *
 * Initialize the ssd1306 component and prepare the graphical display interface
 * for usage.
 */
void display_init(void) {
	// Setup the Controller from Reset
	ssd1306_init();

	// Set Horizontal Addressing Mode, Window = { Col 0 - 127, Page 0 - 3 }
	ssd1306_set_mem_addr_mode(0x0);
	ssd1306_set_column_addr(0x0, 0x7F);
	ssd1306_set_page_addr(0x0, 0x3);
}
