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

#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <wm8731.h>

// Audio State
volatile enum {
    audio_state_init = 1,
} audio_state = 0;

void audio_init(void) {
    // Configure MAX9717 Amplifier Shutdown (Amp Off by Default, Pin High)
    PIO_PER(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX); // Enable PIO on Pin
    PIO_OER(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX); // Enable Output
    PIO_SODR(PIN_WM8731_AMP_SD_PIO) = (1 << PIN_WM8731_AMP_SD_IDX); // Set Output Data Register

    // Configure Programmable Clock Controller (PCK0 = MCK / 8 = 12MHz)
    PMC_PCK0 = PMC_PCKx_CSS_MCK | PMC_PCKx_PRES_CLK_8;
    // Enable PCK0
    PMC_SCER = PMC_SCER_PCK0;
    // Wait for PCK0 to become ready
    while (!(PMC_SR & PMC_SR_PCKRDY0));

    // Configure the PCK0 Pin, Connected to WM8731 MCLK
    PIO_PDR(PIN_WM8731_PCK0_PIO)   = (1 << PIN_WM8731_PCK0_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_PCK0_PIO) |= (1 << PIN_WM8731_PCK0_IDX); // Select Peripheral B

    // Configure the SSC Pins for the WM8731 ADC/DAC
    PIO_PDR(PIN_WM8731_SSC_RD_PIO)   =  (1 << PIN_WM8731_SSC_TD_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_RD_PIO) &= ~(1 << PIN_WM8731_SSC_TD_IDX); // Select Peripheral A
    PIO_PDR(PIN_WM8731_SSC_RF_PIO)   =  (1 << PIN_WM8731_SSC_TF_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_RF_PIO) &= ~(1 << PIN_WM8731_SSC_TF_IDX); // Select Peripheral A
    PIO_PDR(PIN_WM8731_SSC_RK_PIO)   =  (1 << PIN_WM8731_SSC_TK_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_RK_PIO) &= ~(1 << PIN_WM8731_SSC_TK_IDX); // Select Peripheral A
    PIO_PDR(PIN_WM8731_SSC_TD_PIO)   =  (1 << PIN_WM8731_SSC_TD_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_TD_PIO) &= ~(1 << PIN_WM8731_SSC_TD_IDX); // Select Peripheral A
    PIO_PDR(PIN_WM8731_SSC_TF_PIO)   =  (1 << PIN_WM8731_SSC_TF_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_TF_PIO) &= ~(1 << PIN_WM8731_SSC_TF_IDX); // Select Peripheral A
    PIO_PDR(PIN_WM8731_SSC_TK_PIO)   =  (1 << PIN_WM8731_SSC_TK_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_TK_PIO) &= ~(1 << PIN_WM8731_SSC_TK_IDX); // Select Peripheral A

    // Reset the Audio Codec
    if (wm8731_reset() < 0) {
        kputs("Failed to Reset the WM8731 Audio Codec.\r\n");
        return;
    } else {
        // Configure the Audio Codec
    }

    // Audio has finished initializing
    audio_state |= audio_state_init;
}
