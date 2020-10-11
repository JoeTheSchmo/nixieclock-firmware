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

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include <types.h>

extern int32_t svcall(uint8_t code, uint32_t a0, uint32_t a1, uint32_t a2);

static inline int32_t __attribute__((always_inline))
  twi_write(uint8_t caddr, uint32_t raddr, uint8_t *dptr, uint16_t dlen) {
    return svcall(0x00,
        (uint32_t)((caddr & 0xFF) << 0x10 | (dlen & 0xFFFF)),
        (uint32_t)(raddr),
        (uint32_t)(dptr)
    );
}

static inline int32_t __attribute__((always_inline))
  twi_read(uint8_t caddr, uint32_t raddr, uint8_t *dptr, uint16_t dlen) {
    return svcall(0x01,
        (uint32_t)((caddr & 0xFF) << 0x10 | (dlen & 0xFFFF)),
        (uint32_t)(raddr),
        (uint32_t)(dptr)
    );
}

#endif // __SYSTEM_H_

