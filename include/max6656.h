//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2016 Joe Ciccone / Ed Koloski
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

#ifndef __MAX6656_H_
#define __MAX6656_H_

#include <types.h>

#define MAX6656_TWI_ADDR    0x18

#define MAX6656_RV0         0x0100002E
#define MAX6656_RV1         0x0100002F
#define MAX6656_RV2         0x01000030
#define MAX6656_RV3         0x01000031

extern int32_t max6656_get_3_3v_value();
extern int32_t max6656_get_12v_value();
extern int32_t max6656_get_5v_value();
extern int32_t max6656_get_1_8v_value();

#endif // __MAX6656_H_
