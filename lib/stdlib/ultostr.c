/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Convert an unsigned long int to a string
 *
 * This function converts an unsigned long int to a string with the base
 * between 0 to 16.
 */
char *ultostr(uint32_t value, char *str, int8_t base) {
	// Working Pointer
	char *p = str;

	// Sanity Check
	if (base > 16) {
		*str = '\0';
		return str;
	}

	// Find number of digits and prepare pointer
	uint32_t temp = value;
	int8_t length = 0;
	do {
		*p++ = '0';
		length++;
		temp /= base;
	} while (temp > 0);

	// Terminate the String
	*p = '\0';

	// Fill in the string backwards
	do {
		*--p = "0123456789abcdef"[(value % base)];
		value /= base;
	} while (value > 0);

	return str;
}