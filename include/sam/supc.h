// vim: set tabstop=4 shiftwidth=4 expandtab :
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

#ifndef __SAM__SUPC_H_
#define __SAM__SUPC_H_

#include <types.h>

#define SUPC_CR         (*(reg_wo_t*)(SUPC+0x0000))
#define SUPC_SMMR       (*(reg_rw_t*)(SUPC+0x0004))
#define SUPC_MR         (*(reg_rw_t*)(SUPC+0x0008))
#define SUPC_WUMR       (*(reg_rw_t*)(SUPC+0x000C))
#define SUPC_WUIR       (*(reg_rw_t*)(SUPC+0x0010))
#define SUPC_SR         (*(reg_ro_t*)(SUPC+0x0014))

#define SUPC_CR_XTALSEL         0x00000008
#define SUPC_CR_KEY             0xA5000000

#define SUPC_MR_OSCBYPASS       0x00100000
#define SUPC_MR_KEY             0xA5000000

#endif
