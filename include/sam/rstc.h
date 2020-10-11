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

#ifndef __SAM__RSTC_H_
#define __SAM__RSTC_H_

#include <types.h>

#define RSTC_CR     (*(reg_wo_t*)(RSTC+0x0000))
#define RSTC_SR     (*(reg_ro_t*)(RSTC+0x0004))
#define RSTC_MR     (*(reg_rw_t*)(RSTC+0x0008))

#define RSTC_CR_PROCRST         0x00000001
#define RSTC_CR_PERRST          0x00000004
#define RSTC_CR_EXTRST          0x00000008
#define RSTC_CR_KEY             0xA5000000

#define RSTC_SR_RSTTYP_Msk      0x00000700
#define RSTC_SR_RSTTYP_Off      0x08
#define RSTC_SR_RSTTYP_GENERAL  0x00000000
#define RSTC_SR_RSTTYP_BACKUP   0x00000100
#define RSTC_SR_RSTTYP_WATCHDOG 0x00000200
#define RSTC_SR_RSTTYP_SOFTWARE 0x00000300
#define RSTC_SR_RSTTYP_USER     0x00000400

#define RSTC_MR_URSTEN          0x00000001
#define RSTC_MR_ERSTL_Msk       0x00000F00
#define RSTC_MR_ERSTL_Off       0x08
#define RSTC_MR_KEY             0xA5000000

#endif // __SAM__RSTC_H_
