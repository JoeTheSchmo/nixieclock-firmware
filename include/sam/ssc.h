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

#ifndef __SAM__SSC_H_
#define __SAM__SSC_H_

#include <types.h>

#define SSC_CR          (*(reg_wo_t*)(SSC+0x0000))
#define SSC_CMR         (*(reg_rw_t*)(SSC+0x0004))
#define SSC_RCMR        (*(reg_rw_t*)(SSC+0x0010))
#define SSC_RFMR        (*(reg_rw_t*)(SSC+0x0014))
#define SSC_TCMR        (*(reg_rw_t*)(SSC+0x0018))
#define SSC_TFMR        (*(reg_rw_t*)(SSC+0x001C))
#define SSC_RHR         (*(reg_ro_t*)(SSC+0x0020))
#define SSC_THR         (*(reg_wo_t*)(SSC+0x0024))
#define SSC_RSHR        (*(reg_ro_t*)(SSC+0x0030))
#define SSC_TSHR        (*(reg_rw_t*)(SSC+0x0034))
#define SSC_RC0R        (*(reg_rw_t*)(SSC+0x0038))
#define SSC_RC1R        (*(reg_rw_t*)(SSC+0x003C))
#define SSC_SR          (*(reg_ro_t*)(SSC+0x0040))
#define SSC_IER         (*(reg_wo_t*)(SSC+0x0044))
#define SSC_IDR         (*(reg_wo_t*)(SSC+0x0048))
#define SSC_IMR         (*(reg_ro_t*)(SSC+0x004C))
#define SSC_WPMR        (*(reg_rw_t*)(SSC+0x00E4))
#define SSC_WPSR        (*(reg_ro_t*)(SSC+0x00E8))

#define SSC_CR_RXEN                 0x00000001
#define SSC_CR_RXDIS                0x00000002
#define SSC_CR_TXEN                 0x00000100
#define SSC_CR_TXDIS                0x00000200
#define SSC_CR_SWRST                0x00008000

#define SSC_CMR_DIV_Msk             0x00000FFF
#define SSC_CMR_DIV_Off             0x00

#define SSC_TCMR_CKS_CKO_TRANSFER   0x00000008
#define SSC_TCMR_START_RF_EDGE      0x00000700
#define SSC_TCMR_STTDLY_Msk         0x00FF0000
#define SSC_TCMR_STTDLY_Off         0x10
#define SSC_TCMR_PERIOD_Msk         0xFF000000
#define SSC_TCMR_PERIOD_Off         0x18

#define SSC_TFMR_DATLEN_Msk         0x0000001F
#define SSC_TFMR_DATLEN_Off         0x00
#define SSC_TFMR_MSBF               0x00000080
#define SSC_TFMR_FSOS_TOGGLING      0x00500000

#define SSC_SR_TXRDY                0x00000001
#define SSC_SR_TXEMPTY              0x00000002

#define SSC_IER_TXRDY               0x00000001
#define SSC_IER_TXEMPTY             0x00000002

#endif // __SAM__SSC_H_
