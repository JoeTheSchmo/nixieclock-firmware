// vim: set tabstop=4 shiftwidth=4 expandtab :
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

#define MAX6656_RTLS        0x00
#define MAX6656_RRTE        0x01
#define MAX6656_RSL         0x02
#define MAX6656_RCL         0x03
#define MAX6656_RCRA        0x04
#define MAX6656_RLHN        0x05
#define MAX6656_RLLI        0x06
#define MAX6656_RRHI        0x07
#define MAX6656_RRLS        0x08
#define MAX6656_WCA         0x09
#define MAX6656_WCRW        0x0A
#define MAX6656_WLHO        0x0B
#define MAX6656_WLLM        0x0C
#define MAX6656_WRHA        0x0D
#define MAX6656_WRLN        0x0E
#define MAX6656_RRET1       0x10
#define MAX6656_RRET2       0x11
#define MAX6656_RLET        0x12
#define MAX6656_RRT2        0x13
#define MAX6656_RRHL2       0x14
#define MAX6656_RRLL2       0x15
#define MAX6656_RLOL        0x16
#define MAX6656_RLOL1       0x17
#define MAX6656_RLOL2       0x18
#define MAX6656_WLOL        0x19
#define MAX6656_WLOL1       0x1A
#define MAX6656_WLOL2       0x1B
#define MAX6656_WRH2        0x1C
#define MAX6656_WRL2        0x1D
#define MAX6656_WV0HL       0x1E
#define MAX6656_WV0LL       0x1F
#define MAX6656_WV1HL       0x20
#define MAX6656_WV1LL       0x21
#define MAX6656_WV2HL       0x22
#define MAX6656_WV2LL       0x23
#define MAX6656_WV3HL       0x24
#define MAX6656_WV3LL       0x25
#define MAX6656_RV0HL       0x26
#define MAX6656_RV0LL       0x27
#define MAX6656_RV1HL       0x28
#define MAX6656_RV1LL       0x29
#define MAX6656_RV2HL       0x2A
#define MAX6656_RV2LL       0x2B
#define MAX6656_RV3HL       0x2C
#define MAX6656_RV3LL       0x2D
#define MAX6656_RV0         0x2E
#define MAX6656_RV1         0x2F
#define MAX6656_RV2         0x30
#define MAX6656_RV3         0x31
#define MAX6656_RSL2        0x32
#define MAX6656_RCL2        0x33
#define MAX6656_WCA2        0x34
#define MAX6656_RDRD        0xFE
#define MAX6656_RDRV        0xFF

#define MAX6656_

#endif // __MAX6656_H_
