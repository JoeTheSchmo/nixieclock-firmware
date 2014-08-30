/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

int32_t strcmp(const char *s1, const char *s2) {
	for (; *s1 == *s2; s1++, s2++) {
		if (*s1 == '\0') {
			return 0;
		}
	}

	return (*s1 > *s2 ? -1 : 1);
}