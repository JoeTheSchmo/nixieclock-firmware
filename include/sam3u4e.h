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

#ifndef __SAM3U4E_H_
#define __SAM3U4E_H_

#include "arm/nvic.h"
#include "arm/scb.h"

#include "sam/eefc.h"
#include "sam/pdc.h"
#include "sam/pio.h"
#include "sam/pmc.h"
#include "sam/rstc.h"
#include "sam/spi.h"
#include "sam/tc.h"
#include "sam/twi.h"
#include "sam/uart.h"
#include "sam/wdt.h"

// Peripheral Address Table
#define MCI    ((void*)(0x40000000U))
#define SSC    ((void*)(0x40004000U))
#define SPI    ((void*)(0x40008000U))
#define TC0    ((void*)(0x40080000U))
#define TC1    ((void*)(0x40000040U))
#define TC2    ((void*)(0x40000080U))
#define TWI0   ((void*)(0x40084000U))
#define TWI1   ((void*)(0x40088000U))
#define PWM    ((void*)(0x4008C000U))
#define USART0 ((void*)(0x40090000U))
#define USART1 ((void*)(0x40094000U))
#define USART2 ((void*)(0x40098000U))
#define USART3 ((void*)(0x4009C000U))
#define UDPHS  ((void*)(0x400A4000U))
#define ADC12B ((void*)(0x400A8000U))
#define ADC    ((void*)(0x400AC000U))
#define DMAC   ((void*)(0x400B0000U))

// System Controller Address Table
#define SMC    ((void*)(0x400E0000U))
#define MATRIX ((void*)(0x400E0200U))
#define PMC    ((void*)(0x400E0400U))
#define UART   ((void*)(0x400E0600U))
#define CHIPID ((void*)(0x400E0740U))
#define EEFC0  ((void*)(0x400E0800U))
#define EEFC1  ((void*)(0x400E0A00U))
#define PIOA   ((void*)(0x400E0C00U))
#define PIOB   ((void*)(0x400E0E00U))
#define PIOC   ((void*)(0x400E1000U))
#define RSTC   ((void*)(0x400E1200U))
#define SUPC   ((void*)(0x400E1210U))
#define RTT    ((void*)(0x400E1230U))
#define WDT    ((void*)(0x400E1250U))
#define RTC    ((void*)(0x400E1260U))
#define GPBR   ((void*)(0x400E1290U))

// Peripheral ID Numbers
#define PMC_ID_SUPC    0
#define PMC_ID_RSTC    1
#define PMC_ID_RTC     2
#define PMC_ID_RTT     3
#define PMC_ID_WDT     4
#define PMC_ID_PMC     5
#define PMC_ID_EEFC0   6
#define PMC_ID_EEFC1   7
#define PMC_ID_UART    8
#define PMC_ID_SMC     9
#define PMC_ID_PIOA   10
#define PMC_ID_PIOB   11
#define PMC_ID_PIOC   12
#define PMC_ID_USART0 13
#define PMC_ID_USART1 14
#define PMC_ID_USART2 15
#define PMC_ID_USART3 16
#define PMC_ID_HSMCI  17
#define PMC_ID_TWI0   18
#define PMC_ID_TWI1   19
#define PMC_ID_SPI    20
#define PMC_ID_SSC    21
#define PMC_ID_TC0    22
#define PMC_ID_TC1    23
#define PMC_ID_TC2    24
#define PMC_ID_PWM    25
#define PMC_ID_ADC12B 26
#define PMC_ID_ADC    27
#define PMC_ID_DMAC   28
#define PMC_ID_UDPHS  29

#endif // __SAM3U4E_H_
