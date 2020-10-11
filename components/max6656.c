//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2016 Joe Ciccone
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
#include <system.h>
#include <types.h>
#include <max6656.h>

int32_t max6656_get_3_3v_value() {
    uint8_t value;
    if (twi_read(MAX6656_TWI_ADDR, MAX6656_RV0, &value, 1) < 0) {
        return -1;
    }

    return (value + 12) * 157 / 10;
}

int32_t max6656_get_12v_value() {
    uint8_t value;
    if (twi_read(MAX6656_TWI_ADDR, MAX6656_RV1, &value, 1) < 0) {
        return -1;
    }

    return (value + 12) * 571 / 10;
}

int32_t max6656_get_5v_value() {
    uint8_t value;
    if (twi_read(MAX6656_TWI_ADDR, MAX6656_RV2, &value, 1) < 0) {
        return -1;
    }

    return (value + 12) * 238 / 10;
}

int32_t max6656_get_1_8v_value() {
    uint8_t value;
    if (twi_read(MAX6656_TWI_ADDR, MAX6656_RV3, &value, 1) < 0) {
        return -1;
    }

    return (value + 12) * 119 / 10;
}
