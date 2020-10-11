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

#ifndef __SAM__TWI_H_
#define __SAM__TWI_H_

#include <types.h>

#define TWI_CR(TWI)         (*(reg_wo_t*)(TWI+0x0000))
#define TWI_MMR(TWI)        (*(reg_rw_t*)(TWI+0x0004))
#define TWI_SMR(TWI)        (*(reg_rw_t*)(TWI+0x0008))
#define TWI_IADR(TWI)       (*(reg_rw_t*)(TWI+0x000C))
#define TWI_CWGR(TWI)       (*(reg_rw_t*)(TWI+0x0010))
#define TWI_SR(TWI)         (*(reg_ro_t*)(TWI+0x0020))
#define TWI_IER(TWI)        (*(reg_wo_t*)(TWI+0x0024))
#define TWI_IDR(TWI)        (*(reg_wo_t*)(TWI+0x0028))
#define TWI_IMR(TWI)        (*(reg_ro_t*)(TWI+0x002C))
#define TWI_RHR(TWI)        (*(reg_ro_t*)(TWI+0x0030))
#define TWI_THR(TWI)        (*(reg_wo_t*)(TWI+0x0034))

#define TWI_CR_START        0x00000001
#define TWI_CR_STOP         0x00000002
#define TWI_CR_MSEN         0x00000004
#define TWI_CR_MSDIS        0x00000008
#define TWI_CR_SVDIS        0x00000020
#define TWI_CR_QUICK        0x00000040
#define TWI_CR_SWRST        0x00000080

#define TWI_MMR_IADRSZ_Msk  0x00000300
#define TWI_MMR_IADRSZ_Off  0x08
#define TWI_MMR_MREAD       0x00001000
#define TWI_MMR_DADR_Msk    0x007F0000
#define TWI_MMR_DADR_Off    0x10

#define TWI_CWGR_CLDIV_Msk  0x000000FF
#define TWI_CWGR_CLDIV_Off  0x00
#define TWI_CWGR_CHDIV_Msk  0x0000FF00
#define TWI_CWGR_CHDIV_Off  0x08
#define TWI_CWGR_CKDIV_Msk  0x00070000
#define TWI_CWGR_CKDIV_Off  0x10

#define TWI_SR_TXCOMP       0x00000001
#define TWI_SR_RXRDY        0x00000002
#define TWI_SR_TXRDY        0x00000004
#define TWI_SR_NACK         0x00000100
#define TWI_SR_ENDRX        0x00001000
#define TWI_SR_ENDTX        0x00002000

#endif
