/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

/** Append one string to another
 *
 * This function appends the src string to the dest string.
 */
char *strcat(char *d, const char *s) {
	// Working Pointer
	char *p = d;

	// Iterate to the end of the Destination String
	while (*p++ != '\0');

	// Append the Source String to the Destination String
	while (*s != '\0') {
		*p++ = *s++;
	}

	// Null Terminate the Destination
	*p = '\0';

	return d;
}
