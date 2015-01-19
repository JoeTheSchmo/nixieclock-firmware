/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

char *strrchr(const char *s, char c) {
	const char *p = 0;
	while (*s != '\0') {
		if (*s == c) {
			p = s;
		}
		s++;
	}

	return (char *)p;
}