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

#include <sam3u4e.h>
#include <types.h>

int32_t _internal_twi_write(uint8_t caddr, uint32_t raddr, uint8_t *dptr, uint16_t dlen) {
    uint32_t sr;
    uint8_t rlen = (raddr & 0xFF000000) >> 0x18;

    // We must have at least one data byte
    if (dlen == 0) {
        return -2;
    }

    // Wait for TXCOMP Flag
    // This ensures empty holding and shift registers, and that
    // a STOP condition has been sent to the last device
    while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

    // Configure the Master Mode Register
    TWI_MMR(TWI0) = ((caddr << TWI_MMR_DADR_Off) & TWI_MMR_DADR_Msk) |
        ((rlen << TWI_MMR_IADRSZ_Off) & TWI_MMR_IADRSZ_Msk);

    // Set the Internal Address Register
    TWI_IADR(TWI0) = raddr & 0x00FFFFFF;

    // Prepare the PDC for TX on TWI0
    PDC_TPR(TWI0) = (uint32_t)dptr;
    PDC_TCR(TWI0) = dlen;

    // Start the Transfer
    PDC_PTCR(TWI0) = PDC_PTCR_TXTEN;

    // Check for finished or errors
    do {
        // Copy Status Register
        sr = TWI_SR(TWI0);

        // Check for a NACK
        if (sr & TWI_SR_NACK) {
            // Exit the loop and shutdown the transfer
            break;
        }
    } while (!(sr & TWI_SR_ENDTX));

    // Stop the PDC
    PDC_PTCR(TWI0) = PDC_PTCR_TXTDIS;

    // Wait for THR to empty
    while (!(TWI_SR(TWI0) & TWI_SR_TXRDY));

    // Send a STOP
    TWI_CR(TWI0) = TWI_CR_STOP;

    // Wait for TX to Complete
    while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

    // Return error if unsuccessful
    if (sr & TWI_SR_NACK) {
        return -1;
    }

    // Otherwise return success
    return 0;
}

int32_t _internal_twi_read(uint8_t caddr, uint32_t raddr, uint8_t *dptr, uint16_t dlen) {
    uint32_t sr;
    uint8_t stop = 0;
    uint8_t rlen = (raddr & 0xFF000000) >> 0x18;

    // We must have at least one data byte
    if (dlen == 0) {
        return -2;
    }

    // Wait for TXCOMP Flag
    // Yes, I know this is the RX Routine, the flag is still TXCOMP
    // This ensures empty holding and shift registers, and that
    // a STOP condition has been sent to the last device
    while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

    // Configure the Master Mode Register
    TWI_MMR(TWI0) = ((caddr << TWI_MMR_DADR_Off) & TWI_MMR_DADR_Msk) |
        ((rlen << TWI_MMR_IADRSZ_Off) & TWI_MMR_IADRSZ_Msk) |
        TWI_MMR_MREAD;

    // Set the Internal Address Register
    TWI_IADR(TWI0) = raddr & 0x00FFFFFF;

    if (dlen == 1) {
        // Send START now and STOP after RX this byte
        TWI_CR(TWI0) = TWI_CR_START | TWI_CR_STOP;
        stop = 1;
    } else {
        TWI_CR(TWI0) = TWI_CR_START;
    }

    // Wait for byte in RHR
    do {
        // Copy the Status Register
        sr = TWI_SR(TWI0);

        // Check for NACK
        if (sr & TWI_SR_NACK) {
            break;
        }

        // Read data byte
        if (sr & TWI_SR_RXRDY) {
            // Save the byte to memory
            *dptr++ = TWI_RHR(TWI0);
            dlen--;
        } else {
            continue;
        }

        // Next iteration will be last read
        if ((dlen == 1)&&(stop == 0)) {
            TWI_CR(TWI0) = TWI_CR_STOP;
            stop = 1;
        }
    } while (dlen > 0);

    // Wait for the transfer to complete
    while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

    // Return error if unsuccessful
    if (sr & TWI_SR_NACK) {
        return -1;
    }

    // Otherwise return success
    return 0;
}
