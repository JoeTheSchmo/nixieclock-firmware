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

#ifndef __ARM__SCB_H_
#define __ARM__SCB_H_

#define ACTLR            (*(reg_rw_t*)(0xE000E008))
#define CPUID            (*(reg_ro_t*)(0xE000ED00))
#define ICSR             (*(reg_rw_t*)(0xE000ED04))
#define VTOR             (*(reg_rw_t*)(0xE000ED08))
#define AIRCR            (*(reg_rw_t*)(0xE000ED0C))
#define SCR              (*(reg_rw_t*)(0xE000ED10))
#define CCR              (*(reg_rw_t*)(0xE000ED14))
#define SHPR1            (*(reg_rw_t*)(0xE000ED18))
#define SHPR2            (*(reg_rw_t*)(0xE000ED1C))
#define SHPR3            (*(reg_rw_t*)(0xE000ED20))
#define SHCRS            (*(reg_rw_t*)(0xE000ED24))
#define CFSR             (*(reg_rw_t*)(0xE000ED28))
/*
#define MMSR             (*(reg_rw_t*)(0xE000ED28))
#define BFSR             (*(reg_rw_t*)(0xE000ED29))
#define UFSR             (*(reg_rw_t*)(0xE000ED2A))
*/
#define HFSR             (*(reg_rw_t*)(0xE000ED2C))
#define MMAR             (*(reg_rw_t*)(0xE000ED34))
#define BFAR             (*(reg_rw_t*)(0xE000ED38))
#define AFSR             (*(reg_rw_t*)(0xE000ED3C))

#define AIRCR_VECTKEY       0x05FA0000
#define AIRCR_PRIGROUP_Msk  0x00000700
#define AIRCR_PRIGROUP_Off  0x08

#define SCR_SLEEPONEXIT     0x00000002

#define CCR_DIV_0_TRP       0x00000010

#define SHPR2_PRI_11_Msk    0xFF000000
#define SHPR2_PRI_11_Off    0x18

#endif // __ARM__SCB_H_
