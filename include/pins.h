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

#ifndef __PINS_H_
#define __PINS_H_

// 5V PSU Pin Definitions
#define PIN_5VPSU_EN_PIO PIOC
#define PIN_5VPSU_EN_IDX 13
#define PIN_5VPSU_PG_PIO PIOA
#define PIN_5VPSU_PG_IDX 18

// DS3231 Pin Definitions
#define PIN_DS3231_INT_PIO PIOC
#define PIN_DS3231_INT_IDX 2

// LED Pin Definitions
#define PIN_LED0_PIO PIOC
#define PIN_LED0_IDX 17
#define PIN_LED1_PIO PIOC
#define PIN_LED1_IDX 18

// HV5530 High Voltage Pin Defintions
#define PIN_HV5530_HVEN_PIO PIOB
#define PIN_HV5530_HVEN_IDX 0
#define PIN_HV5530_BLANK_PIO PIOC
#define PIN_HV5530_BLANK_IDX 29
#define PIN_HV5530_LATCH_PIO PIOC
#define PIN_HV5530_LATCH_IDX 30
#define PIN_HV5530_SPI_MOSI_PIO PIOA
#define PIN_HV5530_SPI_MOSI_IDX 14
#define PIN_HV5530_SPI_SPCK_PIO PIOA
#define PIN_HV5530_SPI_SPCK_IDX 15

// PCA9534A GPIO Expander Pin Definitions
#define PIN_PCA9534A_INT_PIO PIOC
#define PIN_PCA9534A_INT_IDX 28

// TWI0 Pin Defintions
#define PIN_TWI0_SDA_PIO PIOA
#define PIN_TWI0_SDA_IDX 9
#define PIN_TWI0_SCL_PIO PIOA
#define PIN_TWI0_SCL_IDX 10

// UART Pin Defintions
#define PIN_UART_RXD_PIO PIOA
#define PIN_UART_RXD_IDX 11
#define PIN_UART_TXD_PIO PIOA
#define PIN_UART_TXD_IDX 12

// WM8731 Pin Definitions
#define PIN_WM8731_AMP_SD_PIO PIOA
#define PIN_WM8731_AMP_SD_IDX 17
#define PIN_WM8731_HP_DET_PIO PIOA
#define PIN_WM8731_HP_DET_IDX 24
#define PIN_WM8731_PCK0_PIO PIOA
#define PIN_WM8731_PCK0_IDX 27
#define PIN_WM8731_SSC_RK_PIO PIOA
#define PIN_WM8731_SSC_RK_IDX 29
#define PIN_WM8731_SSC_TD_PIO PIOA
#define PIN_WM8731_SSC_TD_IDX 26
#define PIN_WM8731_SSC_TF_PIO PIOA
#define PIN_WM8731_SSC_TF_IDX 30
#define PIN_WM8731_SSC_TK_PIO PIOA
#define PIN_WM8731_SSC_TK_IDX 28

// ZIGBEE Pin Definition
#define PIN_ZIGBEE_SHDN_PIO PIOB
#define PIN_ZIGBEE_SHDN_IDX 4

#endif // __PINS_H_
