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

#include <display.h>
#include <menu.h>
#include <pca9534a.h>
#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <system.h>

// Last known state of the IO Expander on the Button Board
uint8_t pca9534a_last = 0x00;

void pioa_handler(void) {
    // Do Nothing
}

void piob_handler(void) {
    // Do Nothing
}

void pioc_handler(void) {
    // Read the Status Register
    uint32_t pioc_sr = PIO_ISR(PIOC) & PIO_IMR(PIOC);

    // Check for a Button Board IO Expander Interrupt
    if (pioc_sr & (1 << PIN_PCA9534A_INT_IDX)) {
        uint8_t pca9534a_now, pca9534a_press;
        if (twi_read(PCA9534A_TWI_ADDR, PCA9534A_IR, &pca9534a_now, 1) < 0) {
            kputs("Failed to read PCA9534A, Disabling Interrupt\r\n");
            PIO_IDR(PIN_PCA9534A_INT_PIO) = (1 << PIN_PCA9534A_INT_IDX); // Disable Interrupt
        } else {
            // Check for Key-Press (0 -> 1)
            pca9534a_press = ~pca9534a_last & pca9534a_now;
            if (pca9534a_press) {
                // Enter Key
                if (pca9534a_press & PCA9534A_CENTER) {
                    menu_key_press(menu_key_enter);
                }

                // Back Key
                if (pca9534a_press & PCA9534A_BACK) {
                    menu_key_press(menu_key_back);
                }

                // North Key
                if (pca9534a_press & PCA9534A_NORTH) {
                    menu_key_press(menu_key_north);
                }

                // South Key
                if (pca9534a_press & PCA9534A_SOUTH) {
                    menu_key_press(menu_key_south);
                }

                // East Key
                if (pca9534a_press & PCA9534A_EAST) {
                    menu_key_press(menu_key_east);
                }

                // West Key
                if (pca9534a_press & PCA9534A_WEST) {
                    menu_key_press(menu_key_west);
                }
            }

            // Store the last known state for the next run through
            pca9534a_last = pca9534a_now;
        }
    }
}

void keyboard_init(void) {
    int32_t ret = 0;

    // Enable the PIOA Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_PIOA); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_PIOA); // Clear Pending
    IPR(PMC_ID_PIOA) = (IPR(PMC_ID_PIOA) & ~(IPR_IP_Msk(PMC_ID_PIOA))) | IPR_IP(PMC_ID_PIOA, 0xC); // Set the Priority to 12
    ISER0 = (1 << PMC_ID_PIOA); // Enable Interrupt

    // Enable the PIOB Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_PIOB); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_PIOB); // Clear Pending
    IPR(PMC_ID_PIOB) = (IPR(PMC_ID_PIOB) & ~(IPR_IP_Msk(PMC_ID_PIOB))) | IPR_IP(PMC_ID_PIOB, 0xC); // Set the Priority to 12
    ISER0 = (1 << PMC_ID_PIOB); // Enable Interrupt

    // Enable the PIOC Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_PIOC); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_PIOC); // Clear Pending
    IPR(PMC_ID_PIOC) = (IPR(PMC_ID_PIOC) & ~(IPR_IP_Msk(PMC_ID_PIOC))) | IPR_IP(PMC_ID_PIOC, 0xC); // Set the Priority to 12
    ISER0 = (1 << PMC_ID_PIOC); // Enable Interrupt

    // Initialize the Button Board IO Expander
    uint8_t pca9534a = 0xFF;
    if (ret >= 0) { // Set Output Port to 0xFF
        ret = twi_write(PCA9534A_TWI_ADDR, PCA9534A_OR, &pca9534a, 1);
    }
    if (ret >= 0) { // Set Polarity Inversion to 0xFF
        ret = twi_write(PCA9534A_TWI_ADDR, PCA9534A_PR, &pca9534a, 1);
    }
    if (ret >= 0) { // Set All IO Lines to Input, 0xFF
        ret = twi_write(PCA9534A_TWI_ADDR, PCA9534A_CR, &pca9534a, 1);
    }
    if (ret < 0) {
        kputs("Failed to Configure PCA9534A on Button Board\r\n");
        PIO_IDR(PIN_PCA9534A_INT_PIO)    = (1 << PIN_PCA9534A_INT_IDX); // Disable Interrupt
    } else {
        // Enable Interrupt on PCA9534A INT Signal
        PIO_PER(PIN_PCA9534A_INT_PIO)    = (1 << PIN_PCA9534A_INT_IDX); // Enable PIO on Pin
        PIO_CODR(PIN_PCA9534A_INT_PIO)   = (1 << PIN_PCA9534A_INT_IDX); // Clear Output Data Register
        PIO_ESR(PIN_PCA9534A_INT_PIO)    = (1 << PIN_PCA9534A_INT_IDX); // Interrupt is Edge Event
        PIO_FELLSR(PIN_PCA9534A_INT_PIO) = (1 << PIN_PCA9534A_INT_IDX); // Select Falling Edge
        PIO_AIMER(PIN_PCA9534A_INT_PIO)  = (1 << PIN_PCA9534A_INT_IDX); // Enable Additional Interrupt Mode
        PIO_IER(PIN_PCA9534A_INT_PIO)    = (1 << PIN_PCA9534A_INT_IDX); // Enable Interrupt
    }
}
