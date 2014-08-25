/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Converts the letter 'c' to lower case, if possible. */
char tolower(const char c) {
	if ((c >= 'A')&&(c <= 'Z')) {
		return c + 0x20;
	}
	return c;
}