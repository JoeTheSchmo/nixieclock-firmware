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

#ifndef __SAM__UART_H_
#define __SAM__UART_H_

#include <types.h>

#define UART_CR         (*(reg_wo_t*)(UART+0x0000))
#define UART_MR         (*(reg_rw_t*)(UART+0x0004))
#define UART_IER        (*(reg_wo_t*)(UART+0x0008))
#define UART_IDR        (*(reg_wo_t*)(UART+0x000C))
#define UART_IMR        (*(reg_ro_t*)(UART+0x0010))
#define UART_SR         (*(reg_ro_t*)(UART+0x0014))
#define UART_RHR        (*(reg_ro_t*)(UART+0x0018))
#define UART_THR        (*(reg_wo_t*)(UART+0x001C))
#define UART_BRGR       (*(reg_rw_t*)(UART+0x0020))

#define UART_CR_RSTRX   0x00000004
#define UART_CR_RSTTX   0x00000008
#define UART_CR_RXEN    0x00000010
#define UART_CR_RXDIS   0x00000020
#define UART_CR_TXEN    0x00000040
#define UART_CR_TXDIS   0x00000080
#define UART_CR_RSTSTA  0x00000100

#define UART_MR_PAR_NO              0x00000800
#define UART_MR_CHMODE_NORMAL       0x00000000

#define UART_IER_RXRDY  0x00000001

#define UART_SR_RXRDY   0x00000001
#define UART_SR_TXRDY   0x00000002

#endif // __SAM__UART_H_
