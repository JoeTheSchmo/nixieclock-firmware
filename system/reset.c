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

#include <sam3u4e.h>
#include <string.h>

extern void *bss_start;
extern void *bss_end;
extern void *data_start;
extern void *data_end;
extern void *data_load;

void reset_handler() {
    // Zero the uninitialized data segment
    if (bss_end - bss_start > 0) {
        memset(bss_start, 0, bss_end - bss_start);
    }

    // Load the initialized data segment
    if (data_start != data_load) {
        memcpy(data_start, data_load, data_end - data_start);
    }

    // Reset and Disable the Watchdog Timer
    WDT_CR = WDT_CR_WDRSTT | WDT_CR_KEY;
    WDT_MR = WDT_MR_WDDIS;

    // Enable User Resets by Asserting the NRST Pin
    // Assert NRST for 2^(11+1) Slow Clock Cycles (32 kHz * 4096 = 128ms)
    RSTC_MR = RSTC_MR_URSTEN | (11 << RSTC_MR_ERSTL_Off) | RSTC_MR_KEY;

    // Set the Flash Read/Write Cycles to 4 (for stable operation at 96MHz)
    EEFC_FMR(EEFC0) = ((EEFC_FMR(EEFC0) & ~EEFC_FMR_FWS_Msk) | (4 << (EEFC_FMR_FWS_Off)));
    EEFC_FMR(EEFC1) = ((EEFC_FMR(EEFC1) & ~EEFC_FMR_FWS_Msk) | (4 << (EEFC_FMR_FWS_Off)));

    while (1) {}
}
