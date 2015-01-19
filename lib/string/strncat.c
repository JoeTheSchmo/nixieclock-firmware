/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"

/** Append one string to another
 *
 * This function appends the src string to the dest string. At most n bytes
 * will be copied from the source to the destination.
 */
char *strncat(char *d, const char *s, size_t n) {
	// Working Pointer
	char *p = d;

	// Iterate to the end of the Destination String
	while (*p++ != '\0');

	// Append the Source String to the Destination String
	// Copying at most n Characters
	while ((n-- > 0)&&(*s != '\0')) {
		*p++ = *s++;
	}

	// Null Terminate the Destination
	*p = '\0';

	return d;
}