/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Checks for white-space characters
 *
 * This function returns 1 if the character is white-space. These characters
 * are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'), 
 * horizontal tab ('\t'), and vertical tab ('\v').
 */
int32_t isspace(const char c) {
	switch (c) {
	case ' ':
	case '\f':
	case '\n':
	case '\r':
	case '\t':
	case '\v':
		return 1;
	}

	return 0;
}