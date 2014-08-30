/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Fill memory with constant
 *
 * This function sets the first n bytes of memory located at the pointer s with
 * the constant byte c.
 */
void *memset(void *s, uint8_t c, size_t n) {
	while (n--) {
		*(uint8_t *)s++ = c;
	}

	return s;
}