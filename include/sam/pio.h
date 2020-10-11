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

#ifndef __SAM__PIO_H_
#define __SAM__PIO_H_

#include <types.h>

#define PIO_PER(PIO)     (*(reg_wo_t*)(PIO+0x0000))
#define PIO_PDR(PIO)     (*(reg_wo_t*)(PIO+0x0004))
#define PIO_PSR(PIO)     (*(reg_ro_t*)(PIO+0x0008))
#define PIO_OER(PIO)     (*(reg_wo_t*)(PIO+0x0010))
#define PIO_ODR(PIO)     (*(reg_wo_t*)(PIO+0x0014))
#define PIO_OSR(PIO)     (*(reg_ro_t*)(PIO+0x0018))
#define PIO_IFER(PIO)    (*(reg_wo_t*)(PIO+0x0020))
#define PIO_IFDR(PIO)    (*(reg_wo_t*)(PIO+0x0024))
#define PIO_IFSR(PIO)    (*(reg_ro_t*)(PIO+0x0028))
#define PIO_SODR(PIO)    (*(reg_wo_t*)(PIO+0x0030))
#define PIO_CODR(PIO)    (*(reg_wo_t*)(PIO+0x0034))
#define PIO_ODSR(PIO)    (*(reg_rw_t*)(PIO+0x0038))
#define PIO_PDSR(PIO)    (*(reg_ro_t*)(PIO+0x003C))
#define PIO_IER(PIO)     (*(reg_wo_t*)(PIO+0x0040))
#define PIO_IDR(PIO)     (*(reg_wo_t*)(PIO+0x0044))
#define PIO_IMR(PIO)     (*(reg_ro_t*)(PIO+0x0048))
#define PIO_ISR(PIO)     (*(reg_ro_t*)(PIO+0x004C))
#define PIO_MDER(PIO)    (*(reg_wo_t*)(PIO+0x0050))
#define PIO_MDDR(PIO)    (*(reg_wo_t*)(PIO+0x0054))
#define PIO_MDSR(PIO)    (*(reg_ro_t*)(PIO+0x0058))
#define PIO_PUDR(PIO)    (*(reg_wo_t*)(PIO+0x0060))
#define PIO_PUER(PIO)    (*(reg_wo_t*)(PIO+0x0064))
#define PIO_PUSR(PIO)    (*(reg_ro_t*)(PIO+0x0068))
#define PIO_ABSR(PIO)    (*(reg_rw_t*)(PIO+0x0070))
#define PIO_SCIFSR(PIO)  (*(reg_wo_t*)(PIO+0x0080))
#define PIO_DIFSR(PIO)   (*(reg_wo_t*)(PIO+0x0084))
#define PIO_IFDGSR(PIO)  (*(reg_ro_t*)(PIO+0x0088))
#define PIO_SCDR(PIO)    (*(reg_rw_t*)(PIO+0x008C))
#define PIO_OWER(PIO)    (*(reg_wo_t*)(PIO+0x00A0))
#define PIO_OWDR(PIO)    (*(reg_wo_t*)(PIO+0x00A4))
#define PIO_OWSR(PIO)    (*(reg_ro_t*)(PIO+0x00A8))
#define PIO_AIMER(PIO)   (*(reg_wo_t*)(PIO+0x00B0))
#define PIO_AIMDR(PIO)   (*(reg_wo_t*)(PIO+0x00B4))
#define PIO_AIMMR(PIO)   (*(reg_ro_t*)(PIO+0x00B8))
#define PIO_ESR(PIO)     (*(reg_wo_t*)(PIO+0x00C0))
#define PIO_LSR(PIO)     (*(reg_wo_t*)(PIO+0x00C4))
#define PIO_ELSR(PIO)    (*(reg_ro_t*)(PIO+0x00C8))
#define PIO_FELLSR(PIO)  (*(reg_wo_t*)(PIO+0x00D0))
#define PIO_REHLSR(PIO)  (*(reg_wo_t*)(PIO+0x00D4))
#define PIO_FRLHSR(PIO)  (*(reg_ro_t*)(PIO+0x00D8))
#define PIO_LOCKSR(PIO)  (*(reg_ro_t*)(PIO+0x00E0))
#define PIO_WPMR(PIO)    (*(reg_rw_t*)(PIO+0x00E4))
#define PIO_WPSR(PIO)    (*(reg_ro_t*)(PIO+0x00E8))

#endif // __SAM__PIO_H_
