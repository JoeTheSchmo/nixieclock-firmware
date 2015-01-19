/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

char *strchrnul(const char *s, char c) {
	while (*s != '\0') {
		if (*s == c) {
			return (char *)s;
		}
		s++;
	}

	return (char *)s;
}