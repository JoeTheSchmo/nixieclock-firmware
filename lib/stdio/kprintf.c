/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/** Formatted Output Conversion
 *
 * This function prints a string to the console that matches the format
 * specified.
 */
void kprintf(const char *format, ...) {
	// Start the argument list
	__builtin_va_list args;
	__builtin_va_start(args, format);

	// Temporary buffer for numeric conversions
	char ibuf[33];
	ssize_t ibufl;

	// Finished Processing Modifier Flag
	int8_t done = 0;

	// Flags
	uint32_t flag_zero_pad = 0;

	// Length Modifiers
	int8_t mod_len_h = 0;
	int8_t mod_len_l = 0;

	// Process the output
	while (*format) {
		switch (*format) {
		case '%':
			// Reset the Flags
			done = 0;
			flag_zero_pad = 0;
			mod_len_h = 0;
			mod_len_l = 0;

			// Iterate until the end of the modifier processing flags
			while ((*format)&&(!done)) {
				switch(*++format) {
				// Flags
				case '0':
					flag_zero_pad = strtoul(++format, &format, 10);
					format--;
					break;

				// Length Modifiers for d, i, o, u, x, or X
				case 'h': mod_len_h += mod_len_h > 1 ? 0 : 1; break;
				case 'l': mod_len_l += mod_len_l > 1 ? 0 : 1; break;

				// Apply the Requested Conversion
				case 'd': // Integer
				case 'i': // Integer
					// Convert the Number to a String
					ltostr(__builtin_va_arg(args, int32_t), ibuf, 10);

					// Apply the Padding if Requested
					if (flag_zero_pad > 0) {
						ibufl = flag_zero_pad - strlen(ibuf);
						if (ibuf[0] == '-') {
							kputc('-');
							ibuf[0] = '0';
							ibufl--;
						}
						while (ibufl-- > 0) {
							kputc('0');
						}
					}

					// Print the String and Finish
					kputs(ibuf);
					done = 1;
					break;
				case 'o': // Octal
					// Convert the Number to a String
					ultostr(__builtin_va_arg(args, uint32_t), ibuf, 8);

					// Apply the Padding if Requested
					if (flag_zero_pad > 0) {
						ibufl = flag_zero_pad - strlen(ibuf);
						while (ibufl-- > 0) {
							kputc('0');
						}
					}

					// Print the String and Finish
					kputs(ibuf);
					done = 1;
					break;
				case 'u': // Unsigned Integer
					// Convert the Number to a String
					ultostr(__builtin_va_arg(args, uint32_t), ibuf, 10);

					// Apply the Padding if Requested
					if (flag_zero_pad > 0) {
						ibufl = flag_zero_pad - strlen(ibuf);
						while (ibufl-- > 0) {
							kputc('0');
						}
					}

					// Print the String and Finish
					kputs(ibuf);
					done = 1;
					break;
				case 'x': // Lower Case Hex
					// Convert the Number to a String
					ultostr(__builtin_va_arg(args, uint32_t), ibuf, 16);

					// Apply the Padding if Requested
					if (flag_zero_pad > 0) {
						ibufl = flag_zero_pad - strlen(ibuf);
						while (ibufl-- > 0) {
							kputc('0');
						}
					}

					// Print the String and Finish
					kputs(ibuf);
					done = 1;
					break;
				case 'X': // Upper Case Hex
					// Convert the Number to a String
					ultostr(__builtin_va_arg(args, uint32_t), ibuf, 16);

					// Apply the Padding if Requested
					if (flag_zero_pad > 0) {
						ibufl = flag_zero_pad - strlen(ibuf);
						while (ibufl-- > 0) {
							kputc('0');
						}
					}

					// Convert the String to Upper Case
					char *p = ibuf;
					while (*p) {
						*p = toupper(*p);
						p++;
					}

					// Print the String and Finish
					kputs(ibuf);
					done = 1;
					break;
				case 's': // String
					kputs(__builtin_va_arg(args, char*));
					done = 1;
					break;
				}
			}
			break;
		default:
			// Output the Character
			kputc(*format);
		}

		// Increment Pointer for the Next Iteration
		format++;
	}

	// Finish the argument list
	__builtin_va_end(args);
}