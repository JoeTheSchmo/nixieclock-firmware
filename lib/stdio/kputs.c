/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stdio.h>

/* Put String on Console
 *
 * This function writes a null terminated string to the UART.
 */
int kputs(const char *s) {
	while (*s != '\0') {
		if (kputc(*s++) < 0) {
			return -1;
		}
	}
	return 0;
}
