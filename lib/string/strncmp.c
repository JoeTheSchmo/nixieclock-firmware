/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n) {
	for (; *s1 == *s2; s1++, s2++) {
		if (--n == 0) {
			return 0;
		}
		if (*s1 == '\0') {
			return 0;
		}
	}

	return (*s1 > *s2 ? -1 : 1);
}
