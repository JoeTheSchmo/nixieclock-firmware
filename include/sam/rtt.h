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

#ifndef __SAM__RTT_H_
#define __SAM__RTT_H_

#include <types.h>

#define RTT_MR              (*(reg_rw_t*)(RTT+0x0000))
#define RTT_AR              (*(reg_rw_t*)(RTT+0x0004))
#define RTT_VR              (*(reg_ro_t*)(RTT+0x0008))
#define RTT_SR              (*(reg_ro_t*)(RTT+0x000C))

#define RTT_MR_RTPRES_Msk   0x0000FFFF
#define RTT_MR_RTPRES_Off   0x00
#define RTT_MR_ALMIEN       0x00010000
#define RTT_MR_RTTINCIEN    0x00020000
#define RTT_MR_RTTRST       0x00040000

#define RTT_SR_ALMS         0x00000001
#define RTT_SR_RTTINC       0x00000002

#endif // __SAM__RTT_H_
