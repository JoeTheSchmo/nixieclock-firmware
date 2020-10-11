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

// 440Hz 24Bit 48kHz Sine Wave
static uint32_t sine_wave[200] = {
    0x00000000, 0x00000000, 0x00080984, 0x00080984, 0x00100AEB, 0x00100AEB, 0x0017FC1C, 0x0017FC1C,
    0x001FD511, 0x001FD511, 0x00278DDE, 0x00278DDE, 0x002F1EB4, 0x002F1EB4, 0x00367FEF, 0x00367FEF,
    0x003DAA1A, 0x003DAA1A, 0x004495F8, 0x004495F8, 0x004B3C8B, 0x004B3C8B, 0x0051971B, 0x0051971B,
    0x00579F3C, 0x00579F3C, 0x005D4ED7, 0x005D4ED7, 0x0062A02C, 0x0062A02C, 0x00678DDD, 0x00678DDD,
    0x006C12EF, 0x006C12EF, 0x00702AD0, 0x00702AD0, 0x0073D15E, 0x0073D15E, 0x007702E9, 0x007702E9,
    0x0079BC37, 0x0079BC37, 0x007BFA87, 0x007BFA87, 0x007DBB95, 0x007DBB95, 0x007EFD9C, 0x007EFD9C,
    0x007FBF56, 0x007FBF56, 0x007FFFFF, 0x007FFFFF, 0x007FBF56, 0x007FBF56, 0x007EFD9C, 0x007EFD9C,
    0x007DBB95, 0x007DBB95, 0x007BFA87, 0x007BFA87, 0x0079BC37, 0x0079BC37, 0x007702E9, 0x007702E9,
    0x0073D15E, 0x0073D15E, 0x00702AD0, 0x00702AD0, 0x006C12EF, 0x006C12EF, 0x00678DDD, 0x00678DDD,
    0x0062A02C, 0x0062A02C, 0x005D4ED7, 0x005D4ED7, 0x00579F3C, 0x00579F3C, 0x0051971B, 0x0051971B,
    0x004B3C8B, 0x004B3C8B, 0x004495F8, 0x004495F8, 0x003DAA1A, 0x003DAA1A, 0x00367FEF, 0x00367FEF,
    0x002F1EB4, 0x002F1EB4, 0x00278DDE, 0x00278DDE, 0x001FD511, 0x001FD511, 0x0017FC1C, 0x0017FC1C,
    0x00100AEB, 0x00100AEB, 0x00080984, 0x00080984, 0x00000000, 0x00000000, 0xFFF7F67C, 0xFFF7F67C,
    0xFFEFF515, 0xFFEFF515, 0xFFE803E4, 0xFFE803E4, 0xFFE02AEF, 0xFFE02AEF, 0xFFD87222, 0xFFD87222,
    0xFFD0E14C, 0xFFD0E14C, 0xFFC98011, 0xFFC98011, 0xFFC255E6, 0xFFC255E6, 0xFFBB6A08, 0xFFBB6A08,
    0xFFB4C375, 0xFFB4C375, 0xFFAE68E5, 0xFFAE68E5, 0xFFA860C4, 0xFFA860C4, 0xFFA2B129, 0xFFA2B129,
    0xFF9D5FD4, 0xFF9D5FD4, 0xFF987223, 0xFF987223, 0xFF93ED11, 0xFF93ED11, 0xFF8FD530, 0xFF8FD530,
    0xFF8C2EA2, 0xFF8C2EA2, 0xFF88FD17, 0xFF88FD17, 0xFF8643C9, 0xFF8643C9, 0xFF840579, 0xFF840579,
    0xFF82446B, 0xFF82446B, 0xFF810264, 0xFF810264, 0xFF8040AA, 0xFF8040AA, 0xFF800001, 0xFF800001,
    0xFF8040AA, 0xFF8040AA, 0xFF810264, 0xFF810264, 0xFF82446B, 0xFF82446B, 0xFF840579, 0xFF840579,
    0xFF8643C9, 0xFF8643C9, 0xFF88FD17, 0xFF88FD17, 0xFF8C2EA2, 0xFF8C2EA2, 0xFF8FD530, 0xFF8FD530,
    0xFF93ED11, 0xFF93ED11, 0xFF987223, 0xFF987223, 0xFF9D5FD4, 0xFF9D5FD4, 0xFFA2B129, 0xFFA2B129,
    0xFFA860C4, 0xFFA860C4, 0xFFAE68E5, 0xFFAE68E5, 0xFFB4C375, 0xFFB4C375, 0xFFBB6A08, 0xFFBB6A08,
    0xFFC255E6, 0xFFC255E6, 0xFFC98011, 0xFFC98011, 0xFFD0E14C, 0xFFD0E14C, 0xFFD87222, 0xFFD87222,
    0xFFE02AEF, 0xFFE02AEF, 0xFFE803E4, 0xFFE803E4, 0xFFEFF515, 0xFFEFF515, 0xFFF7F67C, 0xFFF7F67C
};

static uint32_t *audio_stream;
static uint32_t audio_position;
static uint32_t audio_done_at;

void ssc_handler(void) {
    if (SSC_SR & SSC_SR_TXRDY) {
        SSC_THR = audio_stream[audio_position++];

        if (audio_position >= audio_done_at) {
            audio_position = 0;
        }
    }
}

void audio_play_sine(void) {
    audio_stream = sine_wave;
    audio_position = 0;
    audio_done_at = 200;

    // Enable the SSC for Transmit
    SSC_CR = SSC_CR_TXEN;
}

void audio_check_headphones(void) {

    // Check if the headphones are plugged in
    if (PIO_PDSR(PIN_WM8731_HP_DET_PIO) & (1 << PIN_WM8731_HP_DET_IDX)) {
        // Headphones are plugged in, Shutdown the Amplifier
        PIO_CODR(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX); // Clear Output Data Register
        kprintf("Headphones connected\n\r");
    } else {
        // Headphones are unplugged, Enable Amplifier
        PIO_SODR(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX); // Set Output Data Register
        kprintf("Headphones disconnected\n\r");
    }
}

void audio_init(void) {
    // Configure MAX9717 Amplifier Shutdown (Amp Off by Default, Pin Low)
    PIO_PER(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX);   // Enable PIO on Pin
    PIO_OER(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX);   // Enable Output

    PIO_PUDR(PIN_WM8731_AMP_SD_PIO) &= ~(1 << PIN_WM8731_AMP_SD_IDX);   // Enable Pull-Up
    PIO_SODR(PIN_WM8731_AMP_SD_PIO)  = (1 << PIN_WM8731_AMP_SD_IDX); // Set Output Data Register

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
    PIO_PDR(PIN_WM8731_SSC_RK_PIO)   =  (1 << PIN_WM8731_SSC_RK_IDX); // Disable PIO on Pin
    PIO_ABSR(PIN_WM8731_SSC_RK_PIO) &= ~(1 << PIN_WM8731_SSC_RK_IDX); // Select Peripheral A
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

        // Disable the bypass
        wm8731_set_bypass(0);

        // Select DAC as Audio Output
        wm8731_set_dac_select(1);

        // Set Sampling to USB (12MHz MCLK) (48kHz DAC)
        wm8731_set_sampling(1, 0, 0);

        // Set the frame format to i2s
        wm8731_set_digital_audio_format(2);

        // Set digital audio bit length to 24bits
        wm8731_set_digital_audio_data_bit_length(2);

        // Unmute the DAC
        wm8731_set_dac_soft_mute(0);

        // Set de-emphasis to 48kHz
        wm8731_set_deemphasis(3);

        // Set the component power states
        wm8731_set_powerdown_dac(0);
        wm8731_set_powerdown_out(0);
        wm8731_set_powerdown_osc(1);
        wm8731_set_powerdown_poweroff(0);

        // Activate the CODEC
        wm8731_set_active(1);
    }

    // Enable the SSC Peripheral Clock
    PMC_PCER = (1 << PMC_ID_SSC);
    // Reset the SSC
    SSC_CR = SSC_CR_SWRST;
    // Set the clock to MCK/(20*2) = 2.4MHz
    // 48,000 kHz * (24+1)bits/channel * 2channels/frame = 2.4MHz
    SSC_CMR = (20 << SSC_CMR_DIV_Off) & SSC_CMR_DIV_Msk;
    // Setup the Transmit Clock Mode Register
    SSC_TCMR = SSC_TCMR_CKS_CKO_TRANSFER |
        ((1 << SSC_TCMR_STTDLY_Off) & SSC_TCMR_STTDLY_Msk) |
        ((24 << SSC_TCMR_PERIOD_Off) & SSC_TCMR_PERIOD_Msk);
    // Setup the Transmit Frame Mode Register
    SSC_TFMR = ((24 << SSC_TFMR_DATLEN_Off) & SSC_TFMR_DATLEN_Msk) |
        SSC_TFMR_MSBF |
        SSC_TFMR_FSOS_TOGGLING;

    // Enable the SSC Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_SSC); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_SSC); // Clear Pending
    IPR(PMC_ID_SSC) = (IPR(PMC_ID_SSC) & ~(IPR_IP_Msk(PMC_ID_SSC))) | IPR_IP(PMC_ID_SSC, 0x0); // Set the Priority to 0
    ISER0 = (1 << PMC_ID_SSC); // Enable Interrupt

    // Enable the interrupts
    SSC_IER = SSC_IER_TXRDY;

    // Enable Interrupt on Headphones State Change
    PIO_PER(PIN_WM8731_HP_DET_PIO)   = (1 << PIN_WM8731_HP_DET_IDX); // Enable PIO on Pin
    PIO_CODR(PIN_WM8731_HP_DET_PIO)  = (1 << PIN_WM8731_HP_DET_IDX); // Clear Output Data Register
    PIO_ESR(PIN_WM8731_HP_DET_PIO)   = (1 << PIN_WM8731_HP_DET_IDX); // Interrupt is Edge Event
    PIO_IER(PIN_WM8731_HP_DET_PIO)   = (1 << PIN_WM8731_HP_DET_IDX); // Enable Interrupt

    // Audio has finished initializing
    audio_state |= audio_state_init;

    // Check if headphones are plugged in
    audio_check_headphones();
}
