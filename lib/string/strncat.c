//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2015 Joe Ciccone
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

#include <types.h>

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
