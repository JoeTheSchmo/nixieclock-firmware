/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

/** Converts the letter 'c' to lower case, if possible. */
char tolower(const char c) {
	if ((c >= 'A')&&(c <= 'Z')) {
		return c + 0x20;
	}
	return c;
}
