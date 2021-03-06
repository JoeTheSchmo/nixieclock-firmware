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

#ifndef __STDLIB_H_
#define __STDLIB_H_

#include <types.h>

extern char *ltostr(int32_t value, char *str, int8_t base);
extern uint32_t strtoul(const char *nptr, const char **endptr, int8_t base);
extern char *ultostr(uint32_t value, char *str, int8_t base);

#endif // __STDLIB_H_
