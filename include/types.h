// vim: set tabstop=4 shiftwidth=4 expandtab :
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

#ifndef __TYPES_H_
#define __TYPES_H_

// Signed Numeric Types
typedef __INT8_TYPE__   int8_t;
typedef __INT16_TYPE__  int16_t;
typedef __INT32_TYPE__  int32_t;

// Unsigned Numeric Types
typedef __UINT8_TYPE__  uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;

// Size Types
typedef __UINT32_TYPE__ size_t;
typedef __INT32_TYPE__  ssize_t;

// Register Types
typedef volatile const __UINT32_TYPE__ reg_ro_t;
typedef volatile       __UINT32_TYPE__ reg_wo_t;
typedef volatile       __UINT32_TYPE__ reg_rw_t;

#endif // __TYPES_H_
