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

#ifndef __SAM__PMC_H_
#define __SAM__PMC_H_

#include <types.h>

#define PMC_SCER         (*(reg_wo_t*)(PMC+0x0000))
#define PMC_SCDR         (*(reg_wo_t*)(PMC+0x0004))
#define PMC_SCSR         (*(reg_ro_t*)(PMC+0x0008))
#define PMC_PCER         (*(reg_wo_t*)(PMC+0x0010))
#define PMC_PCDR         (*(reg_wo_t*)(PMC+0x0014))
#define PMC_PCSR         (*(reg_ro_t*)(PMC+0x0018))
#define CKGR_UCKR        (*(reg_rw_t*)(PMC+0x001C))
#define CKGR_MOR         (*(reg_rw_t*)(PMC+0x0020))
#define CKGR_MCFR        (*(reg_ro_t*)(PMC+0x0024))
#define CKGR_PLLAR       (*(reg_rw_t*)(PMC+0x0028))
#define PMC_MCKR         (*(reg_rw_t*)(PMC+0x0030))
#define PMC_PCK0         (*(reg_rw_t*)(PMC+0x0040))
#define PMC_PCK1         (*(reg_rw_t*)(PMC+0x0044))
#define PMC_PCK2         (*(reg_rw_t*)(PMC+0x0048))
#define PMC_IER          (*(reg_wo_t*)(PMC+0x0060))
#define PMC_IDR          (*(reg_wo_t*)(PMC+0x0064))
#define PMC_SR           (*(reg_ro_t*)(PMC+0x0068))
#define PMC_IMR          (*(reg_ro_t*)(PMC+0x006C))
#define PMC_FSMR         (*(reg_rw_t*)(PMC+0x0070))
#define PMC_FSPR         (*(reg_rw_t*)(PMC+0x0074))
#define PMC_FOCR         (*(reg_wo_t*)(PMC+0x0078))
#define PMC_WPMR         (*(reg_rw_t*)(PMC+0x00E4))
#define PMC_WPSR         (*(reg_ro_t*)(PMC+0x00E8))

#define PMC_SCER_PCK0           0x00000100

#define PMC_SCDR_PCK0           0x00000100

#define CKGR_UCKR_UPLLEN        0x00010000
#define CKGR_UCKR_UPLLCOUNT_Msk 0x00F00000
#define CKGR_UCKR_UPLLCOUNT_Off 0x14

#define CKGR_MOR_MOSCXTEN       0x00000001
#define CKGR_MOR_MOSCXTBY       0x00000002
#define CKGR_MOR_MOSCXTST_Msk   0x0000FF00
#define CKGR_MOR_MOSCXTST_Off   0x08
#define CKGR_MOR_MOSCSEL        0x01000000
#define CKGR_MOR_KEY            0x00370000

#define CKGR_PLLAR_DIVA_Msk     0x000000FF
#define CKGR_PLLAR_DIVA_Off     0x00
#define CKGR_PLLAR_PLLACOUNT_Msk 0x00003F00
#define CKGR_PLLAR_PLLACOUNT_Off 0x08
#define CKGR_PLLAR_MULA_Msk     0x07FF0000
#define CKGR_PLLAR_MULA_Off     0x10
#define CKGR_PLLAR_ONE          0x20000000

#define PMC_MCKR_CSS_Msk        0x00000003
#define PMC_MCKR_CSS_PLLA_CLK   0x00000002
#define PMC_MCKR_PRES_Msk       0x00000070
#define PMC_MCKR_PRES_CLK_2     0x00000010

#define PMC_PCKx_CSS_MCK        0x00000004
#define PMC_PCKx_PRES_CLK_8     0x00000030

#define PMC_SR_MOSCXTS          0x00000001
#define PMC_SR_LOCKA            0x00000002
#define PMC_SR_MCKRDY           0x00000008
#define PMC_SR_PCKRDY0          0x00000100
#define PMC_SR_LOCKU            0x00000040
#define PMC_SR_MOSCSELS         0x00010000

#endif // __SAM__PMC_H_
