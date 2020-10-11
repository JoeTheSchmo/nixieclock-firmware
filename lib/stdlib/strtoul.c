//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2015 Joe Ciccone
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <ctype.h>
#include <types.h>

uint32_t strtoul(const char *nptr, const char **endptr, int8_t base) {
    // Ignore leading White Space
    while (isspace(*nptr)) {
        nptr++;
    }

    // Ignore a leading sign
    if ((*nptr == '-')||(*nptr == '+')) {
        nptr++;
    }

    // Ignore a leading "0x" when the base is 0 or 16
    if ((base == 0)||(base == 16)) {
        if (*nptr == '0') {
            if (*++nptr == 'x') {
                nptr++;
                base = 16;
            } else {
                nptr--;
            }
        }
    }

    // Assume the number is base 10 if not set to 16 above
    if (base == 0) {
        base = 10;
    }

    // Extract the Number
    uint32_t value = 0;
    while (*nptr) {
        // Make sure we are working in lower case for hex
        char c = tolower(*nptr);

        // Verify this is still a number, otherwise break
        if (base < 11) {
            if (!((c >= '0')&&(c <= '0' + base - 1))) {
                break;
            }
        } else {
            if (!(((c >= '0')&&(c <= '9'))||((c >= 'a')&&(c <= 'a' + base - 11)))) {
                break;
            }
        }

        // Continue Processing the Value
        if ((c >= '0')&&(c <= '9')) {
            value = (value * base) + (c - '0');
        } else {
            value = (value * base) + (c - 'a') + 10;
        }

        nptr++;
    }

    // Return the end pointer to the caller
    if (endptr) {
        *endptr = nptr;
    }

    // Return the value
    return value;
}
