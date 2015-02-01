/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

/** Checks for a printable character including space. */
int isprint(const char c) {
	if ((c >= ' ')&&(c <= '~')) {
		return 1;
	}
	return 0;
}
