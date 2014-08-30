/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "ctype.h"
#include "types.h"

/** Convert a string to an unsigned long int
 *
 * This function converts the initial part of the string nptr to an unsigned
 * long int value according to the given base, which must be within 0 to 16.
 *
 * The string may begin with an arbitrarily amount of white space followed
 * by a single optional + or - sign. If base is 0 or 16, and the string
 * starts with 0x, the base is assumed to be 16.
 *
 * If endptr is not NULL, this function stores the address of the first
 * invalid character in *endptr (and returns 0). 
 */
uint32_t strtoul(const char *nptr, const char **endptr, int8_t base) {
	// Ignore leading White Space
	while (isspace(*nptr)) {
		nptr++;
	}

	// Ignore a leading sign
	if ((*nptr == '-')||(*nptr == '+')) {
		nptr++;
	}

	// Ignore a leading "0x" when the base is 0 or 16
	if ((base == 0)||(base == 16)) {
		if (*nptr == '0') {
			if (*++nptr == 'x') {
				nptr++;
				base = 16;
			} else {
				nptr--;
			}
		}
	}

	// Assume the number is base 10 if not set to 16 above
	if (base == 0) {
		base = 10;
	}

	// Extract the Number
	uint32_t value = 0;
	while (*nptr) {
		// Make sure we are working in lower case for hex
		char c = tolower(*nptr);

		// Verify this is still a number, otherwise break
		if (base < 11) {
			if (!((c >= '0')&&(c <= '0' + base - 1))) {
				break;
			}
		} else {
			if (!(((c >= '0')&&(c <= '9'))||((c >= 'a')&&(c <= 'a' + base - 11)))) {
				break;
			}
		}

		// Continue Processing the Value
		if ((c >= '0')&&(c <= '9')) {
			value = (value * base) + (c - '0');
		} else {
			value = (value * base) + (c - 'a') + 10;
		}

		nptr++;
	}

	// Return the end pointer to the caller
	if (endptr) {
		*endptr = nptr;
	}

	// Return the value
	return value;
}