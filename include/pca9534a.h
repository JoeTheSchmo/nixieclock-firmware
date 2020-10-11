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

#ifndef __PCA9534A_H_
#define __PCA9534A_H_

#include <types.h>

#define PCA9534A_TWI_ADDR   0x39

#define PCA9534A_IR         0x01000000
#define PCA9534A_OR         0x01000001
#define PCA9534A_PR         0x01000002
#define PCA9534A_CR         0x01000003

#define PCA9534A_NORTH      0x01
#define PCA9534A_SOUTH      0x02
#define PCA9534A_EAST       0x04
#define PCA9534A_WEST       0x08
#define PCA9534A_CENTER     0x10
#define PCA9534A_BACK       0x20
#define PCA9534A_DISMIS     0x40
#define PCA9534A_SNOOZE     0x80

#endif // __PCA_9534A_H_
