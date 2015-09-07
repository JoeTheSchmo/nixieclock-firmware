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

#ifndef __SAM__EEFC_H_
#define __SAM__EEFC_H_

#include <types.h>

#define EEFC_FMR(EEFC)  (*(reg_rw_t*)(EEFC+0x0000))
#define EEFC_FCR(EEFC)  (*(reg_wo_t*)(EEFC+0x0004))
#define EEFC_FSR(EEFC)  (*(reg_ro_t*)(EEFC+0x0008))
#define EEFC_FRR(EEFC)  (*(reg_ro_t*)(EEFC+0x000C))

#define EEFC_FMR_FWS_Msk    0x00000F00
#define EEFC_FMR_FWS_Off    0x08

#endif // __SAM__EEFC_H_
