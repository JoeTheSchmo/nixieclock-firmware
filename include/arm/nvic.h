// vim: set tabstop=4 shiftwidth=4 expandtab
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

#ifndef __ARM__NVIC_H_
#define __ARM__NVIC_H_

#define ISER0            (*(reg_rw_t*)(0xE000E100))
#define ICER0            (*(reg_rw_t*)(0xE000E180))
#define ISPR0            (*(reg_rw_t*)(0xE000E200))
#define ICPR0            (*(reg_rw_t*)(0xE000E280))
#define IABR0            (*(reg_ro_t*)(0xE000E300))
#define IPR(n)           (*(reg_rw_t*)(0xE000E400+((n & 0x1C) >> 2) * 0x4))
#define IPR0             (*(reg_rw_t*)(0xE000E400))
#define IPR1             (*(reg_rw_t*)(0xE000E404))
#define IPR2             (*(reg_rw_t*)(0xE000E408))
#define IPR3             (*(reg_rw_t*)(0xE000E40C))
#define IPR4             (*(reg_rw_t*)(0xE000E410))
#define IPR5             (*(reg_rw_t*)(0xE000E414))
#define IPR6             (*(reg_rw_t*)(0xE000E418))
#define IPR7             (*(reg_rw_t*)(0xE000E41C))
#define STIR             (*(reg_wo_t*)(0xE000E41C))

#define IPR_IP(n, p)    (((p) & 0xF) << IPR_IP_Off(n))
#define IPR_IP_Off(n)   ((((n) & 0x3) * 8) + 4)
#define IPR_IP_Msk(n)   (0xF << IPR_IP_Off(n))

#endif // __ARM__NVIC_H_
