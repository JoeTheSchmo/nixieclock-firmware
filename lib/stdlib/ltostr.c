/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Convert a long int to a string
 *
 * This function converts an long int to a string with the base between 0
 * to 16. If the number is negative, the sign will be set as the first
 * character.
 */
char *ltostr(int32_t value, char *str, int8_t base) {
	// Working Pointer
	char *p = str;

	// Sanity Check
	if (base > 16) {
		*str = '\0';
		return str;
	}

	// Make sure this is a positive number
	if (value < 0) {
		// Print a sign if base 10
		if (base == 10) {
			*p++ = '-';
		}
		value = -value;
	}

	// Find number of digits and prepare pointer
	int32_t temp = value;
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