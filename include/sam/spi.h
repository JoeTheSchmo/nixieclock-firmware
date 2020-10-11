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

#ifndef __SPI_H_
#define __SPI_H_

#include <types.h>

#define SPI_CR   (*(reg_wo_t*)(SPI+0x0000))
#define SPI_MR   (*(reg_rw_t*)(SPI+0x0004))
#define SPI_RDR  (*(reg_ro_t*)(SPI+0x0008))
#define SPI_TDR  (*(reg_wo_t*)(SPI+0x000C))
#define SPI_SR   (*(reg_ro_t*)(SPI+0x0010))
#define SPI_IER  (*(reg_wo_t*)(SPI+0x0014))
#define SPI_IDR  (*(reg_wo_t*)(SPI+0x0018))
#define SPI_IMR  (*(reg_ro_t*)(SPI+0x001C))
#define SPI_CSR0 (*(reg_rw_t*)(SPI+0x0030))
#define SPI_CSR1 (*(reg_rw_t*)(SPI+0x0034))
#define SPI_CSR2 (*(reg_rw_t*)(SPI+0x0038))
#define SPI_CSR3 (*(reg_rw_t*)(SPI+0x003C))
#define SPI_WPMR (*(reg_wo_t*)(SPI+0x00E4))
#define SPI_WPSR (*(reg_ro_t*)(SPI+0x00E8))

#define SPI_CR_SPIEN        0x00000001
#define SPI_CR_SWRST        0x00000080

#define SPI_MR_MSTR         0x00000001
#define SPI_MR_MODFDIS      0x00000010

#define SPI_CSR_CPOL        0x00000001
#define SPI_CSR_SCBR_Msk    0x0000FF00
#define SPI_CSR_SCBR_Off    0x08

#define SPI_SR_TDRE         0x00000002
#define SPI_SR_TXEMPTY      0x00000200

#define SPI_IER_TDRE        0x00000002
#define SPI_IER_TXEMPTY     0x00000200

#define SPI_IDR_TDRE        0x00000002
#define SPI_IDR_TXEMPTY     0x00000200

#endif // __SPI_H_
