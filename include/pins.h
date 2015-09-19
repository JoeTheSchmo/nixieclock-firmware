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

#ifndef __PINS_H_
#define __PINS_H_

// HV5530 High Voltage Pin Defintions
#define PIN_HV5530_HVEN_PIO PIOB
#define PIN_HV5530_HVEN_IDX 0

// UART Pin Defintions
#define PIN_UART_RXD_PIO PIOA
#define PIN_UART_RXD_IDX 11
#define PIN_UART_TXD_PIO PIOA
#define PIN_UART_TXD_IDX 12

#endif // __PINS_H_
