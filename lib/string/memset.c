/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stddef.h>

/** Fill memory with constant
 *
 * This function sets the first n bytes of memory located at the pointer s with
 * the constant byte c.
 */
void *memset(void *s, int c, size_t n) {
	while (n--) {
		*(char *)s++ = c;
	}

	return s;
}
