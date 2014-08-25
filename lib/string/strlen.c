/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Append one string to another
 *
 * This function returns the length of the string.
 */
size_t strlen(const char *s) {
	size_t l = 0;
	while (*s++ != '\0') {
		l++;
	}

	return l;
}