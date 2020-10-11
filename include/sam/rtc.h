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

#ifndef __SAM__RTC_H_
#define __SAM__RTC_H_

#include <types.h>

#define RTC_CR              (*(reg_rw_t*)(RTC+0x0000))
#define RTC_MR              (*(reg_rw_t*)(RTC+0x0004))
#define RTC_TIMR            (*(reg_rw_t*)(RTC+0x0008))
#define RTC_CALR            (*(reg_rw_t*)(RTC+0x000C))
#define RTC_TIMALR          (*(reg_rw_t*)(RTC+0x0010))
#define RTC_CALALR          (*(reg_rw_t*)(RTC+0x0014))
#define RTC_SR              (*(reg_ro_t*)(RTC+0x0018))
#define RTC_SCCR            (*(reg_wo_t*)(RTC+0x001C))
#define RTC_IER             (*(reg_wo_t*)(RTC+0x0020))
#define RTC_IDR             (*(reg_wo_t*)(RTC+0x0024))
#define RTC_IMR             (*(reg_ro_t*)(RTC+0x0028))
#define RTC_VER             (*(reg_ro_t*)(RTC+0x002C))
#define RTC_WPMR            (*(reg_rw_t*)(RTC+0x00E4))

#define RTC_CR_UPDTIM       0x00000001
#define RTC_CR_UPDCAL       0x00000002

#define RTC_MR_HRMOD        0x00000001

#define RTC_TIMR_SEC_Msk    0x000007F
#define RTC_TIMR_SEC_Off    0x00
#define RTC_TIMR_MIN_Msk    0x00007F00
#define RTC_TIMR_MIN_Off    0x08
#define RTC_TIMR_HOUR_Msk   0x003F0000
#define RTC_TIMR_HOUR_Off   0x10
#define RTC_TIMR_AMPM       0x00400000

#define RTC_CALR_CENT_Msk   0x0000007F
#define RTC_CALR_CENT_Off   0x00
#define RTC_CALR_YEAR_Msk   0x0000FF00
#define RTC_CALR_YEAR_Off   0x08
#define RTC_CALR_MONTH_Msk  0x001F0000
#define RTC_CALR_MONTH_Off  0x10
#define RTC_CALR_DAY_Msk    0x00E00000
#define RTC_CALR_DAY_Off    0x15
#define RTC_CALR_DATE_Msk   0x3F000000
#define RTC_CALR_DATE_Off   0x18

#define RTC_SR_ACKUPD       0x00000001
#define RTC_SR_SEC          0x00000004

#define RTC_SCCR_ACKCLR       0x00000001
#define RTC_SCCR_SECCLR     0x00000004

#define RTC_IER_SECEN       0x00000004

#define RTC_VER_NVTIM       0x00000001
#define RTC_VER_NVCAL       0x00000002

#endif // __SAM__RTC_H_
