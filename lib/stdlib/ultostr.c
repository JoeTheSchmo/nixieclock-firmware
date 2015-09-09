// vim: set tabstop=4 shiftwidth=4 expandtab
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

#include <types.h>

char *ultostr(uint32_t value, char *str, int8_t base) {
    // Working Pointer
    char *p = str;

    // Sanity Check
    if (base > 16) {
        *str = '\0';
        return str;
    }

    // Find number of digits and prepare pointer
    uint32_t temp = value;
    int8_t length = 0;
    do {
        *p++ = '0';
        length++;
        temp /= base;
    } while (temp > 0);

    // Terminate the String
    *p = '\0';

    // Fill in the string backwards
    do {
        *--p = "0123456789abcdef"[(value % base)];
        value /= base;
    } while (value > 0);

    return str;
}
