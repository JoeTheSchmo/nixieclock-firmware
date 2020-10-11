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

#ifndef __SAM__PDC_H_
#define __SAM__PDC_H_

#include <types.h>

#define PDC_RPR(PDC)    (*(reg_rw_t*)(PDC+0x0100))
#define PDC_RCR(PDC)    (*(reg_rw_t*)(PDC+0x0104))
#define PDC_TPR(PDC)    (*(reg_rw_t*)(PDC+0x0108))
#define PDC_TCR(PDC)    (*(reg_rw_t*)(PDC+0x010C))
#define PDC_RNPR(PDC)   (*(reg_rw_t*)(PDC+0x0110))
#define PDC_RNCR(PDC)   (*(reg_rw_t*)(PDC+0x0114))
#define PDC_TNPR(PDC)   (*(reg_rw_t*)(PDC+0x0118))
#define PDC_TNCR(PDC)   (*(reg_rw_t*)(PDC+0x011C))
#define PDC_PTCR(PDC)   (*(reg_wo_t*)(PDC+0x0120))
#define PDC_PTSR(PDC)   (*(reg_ro_t*)(PDC+0x0124))

#define PDC_PTCR_RXTEN  0x00000001
#define PDC_PTCR_RXTDIS 0x00000002
#define PDC_PTCR_TXTEN  0x00000100
#define PDC_PTCR_TXTDIS 0x00000200

#define PDC_PTSR_RXTEN  0x00000001
#define PDC_PTSR_TXTEN  0x00000100

#endif // __SAM__PDC_H_
