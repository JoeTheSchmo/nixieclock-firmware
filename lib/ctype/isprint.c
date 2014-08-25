/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Checks for a printable character including space. */
int32_t isprint(const char c) {
	if ((c >= ' ')&&(c <= '~')) {
		return 1;
	}
	return 0;
}