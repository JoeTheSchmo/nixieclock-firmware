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
#include <system.h>
#include <types.h>

// Overall brightness of the display
volatile uint32_t hv5530_duty_cycle = 0xB000;

// Crossfade new digit mask
volatile uint8_t hv5530_xfade_new[8] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// Crossfade old digit mask
volatile uint8_t hv5530_xfade_old[8] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// Current data being loaded into the shift registers
volatile uint8_t *hv5530_tx_regs = hv5530_xfade_new;
volatile uint8_t hv5530_tx_pos = 8;

// Routine to load the shift registers
void spi_handler(void) {
    // Check for TX Ready Interrupt
    if (SPI_SR & SPI_SR_TDRE) {
        // Send remaining bytes or disable interrupt
        if (hv5530_tx_pos < 8) {
            SPI_TDR = hv5530_tx_regs[hv5530_tx_pos++];
        } else {
            SPI_IDR = SPI_IDR_TDRE;
        }
    }

    // Check for TX Empty Interrupt
    if (SPI_SR & SPI_SR_TXEMPTY) {
        // Disable the Transmit Empty Interrupt
        SPI_IDR = SPI_IDR_TXEMPTY;

        // Latch the Shift Registers (Part 2)
        PIO_SODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX); // High
    }
}

void hv5530_write_registers(void) {
    // reset the register buffer idx
    hv5530_tx_pos = 0;

    // Drop the Latch Line (Part 1)
    PIO_CODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX); // Low

    // Enable the TDRE and TXEMPTY Interrupts
    SPI_IER = SPI_IER_TDRE | SPI_IER_TXEMPTY;
}

// Routine to handle the display duty cycle and cross-fading
void tc0_handler(void) {
    static uint32_t sr = 0;
    static uint32_t ra = 0;
    static uint32_t rc = 0;

    // Copy the Status Register
    sr = TC_SR(TC0);

    if (sr & TC_SR_CPCS) {
        // RC Match, Blank the Display
        PIO_SODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX); // High

        // Read the RC Counter
        rc = TC_RC(TC0);
    }

    if (sr & TC_SR_CPAS) {
        // Read the RA Counter
        ra = TC_RA(TC0);

        // Check if we should cross-fade or disable compare of RA
        if (ra < hv5530_duty_cycle) {
            // Display the old state
            hv5530_tx_regs = hv5530_xfade_old;
            hv5530_write_registers();
        } else {
            // Disable RA Compare
            TC_IDR(TC0) = TC_IDR_CPAS;
            ra = 0;
        }
    }

    if (sr & TC_SR_COVFS) {
        // Counter Overflow, Turn on the Display
        PIO_CODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX); // Low

        // If cross-fading, update the counter for the next interval
        if (ra > 0) {
            // Display the new state
            hv5530_tx_regs = hv5530_xfade_new;
            hv5530_write_registers();

            // Switch digits back on RA Compare
            TC_RA(TC0) = ra + 0x250;
        }

        // Change the duty cycle where required
        if (rc < hv5530_duty_cycle) {
            if (hv5530_duty_cycle - rc > 0x40) {
                TC_RC(TC0) = rc + 0x40;
            } else {
                TC_RC(TC0) = hv5530_duty_cycle;
            }
        } else if (rc > hv5530_duty_cycle) {
            if (rc - hv5530_duty_cycle > 0x40) {
                TC_RC(TC0) = rc - 0x40;
            } else {
                TC_RC(TC0) = rc;
            }
        }
    }
}

void hv5530_set_digits(uint32_t hour, uint32_t min, uint32_t sec) {
    uint8_t i;

    // reset to a blank value and move the current value to the
    // old cross-fade register set
    for (i = 0; i < 8; i++) {
        hv5530_xfade_old[i] = hv5530_xfade_new[i];
        hv5530_xfade_new[i] = 0xFF;
    }

    switch(sec % 10) {
    case 0: hv5530_xfade_new[0] &= 0b01111111; break; // 64: SEC_ONE_0
    case 9: hv5530_xfade_new[0] &= 0b10111111; break; // 63: SEC_ONE_9
    case 8: hv5530_xfade_new[0] &= 0b11011111; break; // 62: SEC_ONE_8
    case 7: hv5530_xfade_new[0] &= 0b11101111; break; // 61: SEC_ONE_7
    case 6: hv5530_xfade_new[0] &= 0b11110111; break; // 60: SEC_ONE_6
    case 5: hv5530_xfade_new[0] &= 0b11111011; break; // 59: SEC_ONE_5
    case 4: hv5530_xfade_new[0] &= 0b11111101; break; // 58: SEC_ONE_4
    case 3: hv5530_xfade_new[0] &= 0b11111110; break; // 57: SEC_ONE_3
    case 2: hv5530_xfade_new[1] &= 0b01111111; break; // 56: SEC_ONE_2
    case 1: hv5530_xfade_new[1] &= 0b10111111; break; // 55: SEC_ONE_1
    }

    switch(sec / 10) {
    case 0: hv5530_xfade_new[1] &= 0b11011111; break; // 54: SEC_TEN_0
    case 9: hv5530_xfade_new[1] &= 0b11101111; break; // 53: SEC_TEN_9
    case 8: hv5530_xfade_new[1] &= 0b11110111; break; // 52: SEC_TEN_8
    case 7: hv5530_xfade_new[1] &= 0b11111011; break; // 51: SEC_TEN_7
    case 6: hv5530_xfade_new[1] &= 0b11111101; break; // 50: SEC_TEN_6
    case 5: hv5530_xfade_new[1] &= 0b11111110; break; // 49: SEC_TEN_5
    case 4: hv5530_xfade_new[2] &= 0b01111111; break; // 48: SEC_TEN_4
    case 3: hv5530_xfade_new[2] &= 0b10111111; break; // 47: SEC_TEN_3
    case 2: hv5530_xfade_new[2] &= 0b11011111; break; // 46: SEC_TEN_2
    case 1: hv5530_xfade_new[2] &= 0b11101111; break; // 45: SEC_TEN_1
    }

    // Do not light the colons
    //hv5530_xfade_new[2] &= 0b11110111; // 44: RCOL_TOP
    //hv5530_xfade_new[2] &= 0b11111011; // 43: RCOL_BOT

    switch(min % 10) {
    case 0: hv5530_xfade_new[2] &= 0b11111101; break; // 42: MIN_ONE_0
    case 9: hv5530_xfade_new[2] &= 0b11111110; break; // 41: MIN_ONE_9
    case 8: hv5530_xfade_new[3] &= 0b01111111; break; // 40: MIN_ONE_8
    case 7: hv5530_xfade_new[3] &= 0b10111111; break; // 39: MIN_ONE_7
    case 6: hv5530_xfade_new[3] &= 0b11011111; break; // 38: MIN_ONE_6
    case 5: hv5530_xfade_new[3] &= 0b11101111; break; // 37: MIN_ONE_5
    case 4: hv5530_xfade_new[3] &= 0b11110111; break; // 36: MIN_ONE_4
    case 3: hv5530_xfade_new[3] &= 0b11111011; break; // 35: MIN_ONE_3
    case 2: hv5530_xfade_new[3] &= 0b11111101; break; // 34: MIN_ONE_2
    case 1: hv5530_xfade_new[3] &= 0b11111110; break; // 33: MIN_ONE_1
    }

    switch(min / 10) {
    case 0: hv5530_xfade_new[4] &= 0b01111111; break; // 32: MIN_TEN_0
    case 9: hv5530_xfade_new[4] &= 0b10111111; break; // 31: MIN_TEN_9
    case 8: hv5530_xfade_new[4] &= 0b11011111; break; // 30: MIN_TEN_8
    case 7: hv5530_xfade_new[4] &= 0b11101111; break; // 29: MIN_TEN_7
    case 6: hv5530_xfade_new[4] &= 0b11110111; break; // 28: MIN_TEN_6
    case 5: hv5530_xfade_new[4] &= 0b11111011; break; // 27: MIN_TEN_5
    case 4: hv5530_xfade_new[4] &= 0b11111101; break; // 26: MIN_TEN_4
    case 3: hv5530_xfade_new[4] &= 0b11111110; break; // 25: MIN_TEN_3
    case 2: hv5530_xfade_new[5] &= 0b01111111; break; // 24: MIN_TEN_2
    case 1: hv5530_xfade_new[5] &= 0b10111111; break; // 23: MIN_TEN_1
    }

    switch(hour % 10) {
    case 0: hv5530_xfade_new[5] &= 0b11011111; break; // 22: HOUR_ONE_0
    case 9: hv5530_xfade_new[5] &= 0b11101111; break; // 21: HOUR_ONE_9
    case 8: hv5530_xfade_new[5] &= 0b11110111; break; // 20: HOUR_ONE_8
    case 7: hv5530_xfade_new[5] &= 0b11111011; break; // 19: HOUR_ONE_7
    case 6: hv5530_xfade_new[5] &= 0b11111101; break; // 18: HOUR_ONE_6
    case 5: hv5530_xfade_new[5] &= 0b11111110; break; // 17: HOUR_ONE_5
    case 4: hv5530_xfade_new[6] &= 0b01111111; break; // 16: HOUR_ONE_4
    case 3: hv5530_xfade_new[6] &= 0b10111111; break; // 15: HOUR_ONE_3
    case 2: hv5530_xfade_new[6] &= 0b11011111; break; // 14: HOUR_ONE_2
    case 1: hv5530_xfade_new[6] &= 0b11101111; break; // 13: HOUR_ONE_1
    }

    // Do not light the colons
    //hv5530_xfade_new[6] &= 0b11110111; // 12: LCOL_TOP
    //hv5530_xfade_new[6] &= 0b11111011; // 11: LCOL_BOT

    switch(hour / 10) {
    case 0: hv5530_xfade_new[6] &= 0b11111101; break; // 10: HOUR_TEN_0
    case 9: hv5530_xfade_new[6] &= 0b11111110; break; // 09: HOUR_TEN_9
    case 8: hv5530_xfade_new[7] &= 0b01111111; break; // 08: HOUR_TEN_8
    case 7: hv5530_xfade_new[7] &= 0b10111111; break; // 07: HOUR_TEN_7
    case 6: hv5530_xfade_new[7] &= 0b11011111; break; // 06: HOUR_TEN_6
    case 5: hv5530_xfade_new[7] &= 0b11101111; break; // 05: HOUR_TEN_5
    case 4: hv5530_xfade_new[7] &= 0b11110111; break; // 04: HOUR_TEN_4
    case 3: hv5530_xfade_new[7] &= 0b11111011; break; // 03: HOUR_TEN_3
    case 2: hv5530_xfade_new[7] &= 0b11111101; break; // 02: HOUR_TEN_2
    case 1: hv5530_xfade_new[7] &= 0b11111110; break; // 01: HOUR_TEN_1
    }

    // Set RA and enable RA Compare Interrupt
    TC_RA(TC0) = 0x250;
    TC_IER(TC0) = TC_IER_CPAS;
}

// Initialize all components related to time keeping and the clock face
void clock_init(void) {
    // Configure PIN_HV5530_BLANK
    PIO_PER(PIN_HV5530_BLANK_PIO)  = (1 << PIN_HV5530_BLANK_IDX); // Enable PIO on Pin
    PIO_OER(PIN_HV5530_BLANK_PIO)  = (1 << PIN_HV5530_BLANK_IDX); // Enable Output
    PIO_SODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX); // Set Output Data Register

    // Configure PIN_HV5530_LATCH
    PIO_PER(PIN_HV5530_LATCH_PIO)  = (1 << PIN_HV5530_LATCH_IDX); // Enable PIO on Pin
    PIO_OER(PIN_HV5530_LATCH_PIO)  = (1 << PIN_HV5530_LATCH_IDX); // Enable Output
    PIO_SODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX); // Set Output Data Register

    // Configure PIN_HV5530_SPI_MOSI
    PIO_PDR(PIN_HV5530_SPI_MOSI_PIO)   =  (1 << PIN_HV5530_SPI_MOSI_IDX); // Disable PIO to Enable Peripheral
    PIO_ABSR(PIN_HV5530_SPI_MOSI_PIO) &= ~(1 << PIN_HV5530_SPI_MOSI_IDX); // Select Peripheral A
    PIO_PUDR(PIN_HV5530_SPI_MOSI_PIO)  =  (1 << PIN_HV5530_SPI_MOSI_IDX); // Enable Pull-Up

    // Configure PIN_HV5530_SPI_SPCK
    PIO_PDR(PIN_HV5530_SPI_SPCK_PIO)   =  (1 << PIN_HV5530_SPI_SPCK_IDX); // Disable PIO to Enable Peripheral
    PIO_ABSR(PIN_HV5530_SPI_SPCK_PIO) &= ~(1 << PIN_HV5530_SPI_SPCK_IDX); // Select Peripheral A
    PIO_PUDR(PIN_HV5530_SPI_SPCK_PIO)  =  (1 << PIN_HV5530_SPI_SPCK_IDX); // Enable Pull-Up

    // Enable the SPI Peripheral Clock
    PMC_PCER = (1 << PMC_ID_SPI);

    // Reset the controller
    SPI_CR = SPI_CR_SWRST;
    // Set master mode and disable mode fault detection
    SPI_MR |= SPI_MR_MSTR | SPI_MR_MODFDIS;
    // Set SPI Mode 3 with clock divisor of 32 (96MHz/32 = 3MHz)
    SPI_CSR0 = SPI_CSR_CPOL | ((32 << SPI_CSR_SCBR_Off) & SPI_CSR_SCBR_Msk);
    // Enable the SPI controller
    SPI_CR = SPI_CR_SPIEN;
    // Enable the SPI Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_SPI); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_SPI); // Clear Pending
    IPR(PMC_ID_SPI) = (IPR(PMC_ID_SPI) & ~(IPR_IP_Msk(PMC_ID_SPI))) | IPR_IP(PMC_ID_SPI, 0x0); // Set the Priority to 0
    ISER0 = (1 << PMC_ID_SPI); // Enable Interrupt

    // Enable the TC0 Peripheral Clock
    PMC_PCER = (1 << PMC_ID_TC0);

    // Disable TC0 Clock
    TC_CCR(TC0) = TC_CCR_CLKDIS;
    // Configure TC0 for MCK/8 and Waveform Mode
    TC_CMR(TC0) = TC_CMR_WM_TCCLKS_TIMER_CLOCK2 | TC_CMR_WM_WAVE;
    // Start with a Duty Cycle of ~5%
    TC_RC(TC0) = 0x100;
    // Enable the TC0 Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_TC0); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_TC0); // Clear Pending
    IPR(PMC_ID_TC0) = (IPR(PMC_ID_TC0) & ~(IPR_IP_Msk(PMC_ID_TC0))) | IPR_IP(PMC_ID_TC0, 0x1); // Set the Priority to 1
    ISER0 = (1 << PMC_ID_TC0); // Enable Interrupt
    // Enable Interrupts for TC0
    TC_IER(TC0) = TC_IER_COVFS | TC_IER_CPCS;
    // Enable TC0 Clock and Start Counters
    TC_CCR(TC0) = TC_CCR_CLKEN | TC_CCR_SWTRG;

    // Enable the HV PSU
    PIO_SODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);

    // Initial write to the registers
    hv5530_write_registers();
}
