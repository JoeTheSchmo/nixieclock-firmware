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

#ifndef __TC_H_
#define __TC_H_

#include <types.h>

#define TC_CCR(TC)       (*(reg_wo_t*)(TC +0x0000))
#define TC_CMR(TC)       (*(reg_rw_t*)(TC +0x0004))
#define TC_CV(TC)        (*(reg_ro_t*)(TC +0x0010))
#define TC_RA(TC)        (*(reg_rw_t*)(TC +0x0014))
#define TC_RB(TC)        (*(reg_rw_t*)(TC +0x0018))
#define TC_RC(TC)        (*(reg_rw_t*)(TC +0x001C))
#define TC_SR(TC)        (*(reg_ro_t*)(TC +0x0020))
#define TC_IER(TC)       (*(reg_wo_t*)(TC +0x0024))
#define TC_IDR(TC)       (*(reg_wo_t*)(TC +0x0028))
#define TC_IMR(TC)       (*(reg_ro_t*)(TC +0x002C))
#define TC_BCR           (*(reg_wo_t*)(TC0+0x00C0))
#define TC_BMR           (*(reg_rw_t*)(TC0+0x00C4))
#define TC_QIER          (*(reg_wo_t*)(TC0+0x00C8))
#define TC_QIDR          (*(reg_wo_t*)(TC0+0x00CC))
#define TC_QIMR          (*(reg_ro_t*)(TC0+0x00D0))
#define TC_QISR          (*(reg_ro_t*)(TC0+0x00D4))

#define TC_CCR_CLKEN                    0x00000001
#define TC_CCR_CLKDIS                   0x00000002
#define TC_CCR_SWTRG                    0x00000004

#define TC_CMR_WM_TCCLKS_Msk            0x00000007
#define TC_CMR_WM_TCCLKS_Off            0x00
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK2   0x00000001
#define TC_CMR_WM_WAVE                  0x00008000

#define TC_SR_COVFS                     0x00000001
#define TC_SR_CPAS                      0x00000004
#define TC_SR_CPCS                      0x00000010

#define TC_IER_COVFS                    0x00000001
#define TC_IER_CPAS                     0x00000004
#define TC_IER_CPCS                     0x00000010

#define TC_IDR_CPAS                     0x00000004

#endif // __TC_H_
