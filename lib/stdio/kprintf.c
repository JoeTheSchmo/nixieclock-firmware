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

#include <stdio.h>

ssize_t kprintf(const char *format, ...) {
    // Start the argument list
    __builtin_va_list args;
    __builtin_va_start(args, format);

    // Call the real printf
    ssize_t r = vxprintf(kputc, kputs, format, args);

    // Finish the argument list
    __builtin_va_end(args);

    // Return the Number of Printed Characters
    return r;
}
