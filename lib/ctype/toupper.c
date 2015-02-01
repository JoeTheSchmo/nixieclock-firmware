/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

/** Converts the letter 'c' to upper case, if possible. */
char toupper(const char c) {
	if ((c >= 'a')&&(c <= 'z')) {
		return c - 0x20;
	}
	return c;
}
