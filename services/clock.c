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

#include <clock.h>
#include <display.h>
#include <ds3231.h>
#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <system.h>
#include <types.h>

// Global Time of Day Cache
volatile timespec_t clock;

// Global Time Format Flag
volatile uint8_t clock_display_24hr = 0;

// Month Names
char clock_month_name[13][4] = { "   ",
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

// Days in each Month
uint8_t clock_month_days[13] = { 0,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

// Day of Week Names
char clock_day_name[8][4] = { "   ",
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
};

// Clock State
volatile enum {
    clock_state_sync = 1,
} clock_state = 0;

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

        // Drop the Latch Line (Part 1)
        PIO_CODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX); // Low

        // Latch on Compare B
        TC_RB(TC0) = TC_CV(TC0) + 4;

        // Enable Interrupt on Compare B
        TC_IER(TC0) = TC_IER_CPBS;
    }
}

void hv5530_write_registers(void) {
    // reset the register buffer idx
    hv5530_tx_pos = 0;

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

    if (sr & TC_SR_CPBS) {
        // Latch the Shift Registers (Part 2)
        PIO_SODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX); // High

        // Disable RB Compare
        TC_IDR(TC0) = TC_IDR_CPBS;
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

void hv5530_set_digits(uint32_t hour, uint32_t minute, uint32_t second) {
    uint8_t i;

    // reset to a blank value and move the current value to the
    // old cross-fade register set
    for (i = 0; i < 8; i++) {
        hv5530_xfade_old[i] = hv5530_xfade_new[i];
        hv5530_xfade_new[i] = 0xFF;
    }

    switch(second % 10) {
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

    switch(second / 10) {
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

    switch(minute % 10) {
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

    switch(minute / 10) {
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

void clock_update_globaltime(void) {
    uint32_t calr;
    uint32_t timr;
    uint32_t temp;

    // Read the Date Register until 2 consecutive matching values
    while (calr != RTC_CALR) {
        calr = RTC_CALR;
    }

    // Read the Time Register until 2 consecutive matching values
    while (timr != RTC_TIMR) {
        timr = RTC_TIMR;
    }

    temp = (calr & RTC_CALR_CENT_Msk) >> RTC_CALR_CENT_Off;
    clock.year = (1000 * ((temp & 0xF0) >> 4)) + (100 * (temp & 0xF));

    temp = (calr & RTC_CALR_YEAR_Msk) >> RTC_CALR_YEAR_Off;
    clock.year += (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);

    temp = (calr & RTC_CALR_MONTH_Msk) >> RTC_CALR_MONTH_Off;
    clock.month = (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);

    temp = (calr & RTC_CALR_DAY_Msk) >> RTC_CALR_DAY_Off;
    clock.day = temp;

    temp = (calr & RTC_CALR_DATE_Msk) >> RTC_CALR_DATE_Off;
    clock.date = (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);

    temp = (timr & RTC_TIMR_HOUR_Msk) >> RTC_TIMR_HOUR_Off;
    clock.hour = (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);

    temp = (timr & RTC_TIMR_MIN_Msk) >> RTC_TIMR_MIN_Off;
    clock.minute = (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);

    temp = (timr & RTC_TIMR_SEC_Msk) >> RTC_TIMR_SEC_Off;
    clock.second = (10 * ((temp & 0xF0) >> 4)) + (temp & 0xF);
}

int clock_set(timespec_t *time) {
    // Working Register Set
    uint8_t ds3231[7] = { 0, };

    // Convert the Time to the BCD Encoded Register Mapping (24hr mode)
    ds3231[0] = 0x7F & ((((time->second / 10) << 4) | (time->second % 10)));
    ds3231[1] = 0x7F & (((time->minute / 10) << 4) | (time->minute % 10));
    ds3231[2] = 0x3F & (((time->hour / 10) << 4) | (time->hour % 10));

    // Convert the Date to the BCD Encoded Register Mapping
    ds3231[3] = 0x07 & (time->day);
    ds3231[4] = 0x3F & (((time->date / 10) << 4) | (time->date % 10));
    ds3231[5] = 0x1F & (((time->month / 10) << 4) | (time->month % 10));
    if ((time->year / 100) > 19) {
        ds3231[5] |= 0x80;
    }
    ds3231[6] = 0xFF & ((((time->year % 100) / 10) << 4) | (time->year % 10));

    // Write the Registers to the DS3231 RTC
    if (twi_write(DS3231_TWI_ADDR, 0x01000000, ds3231, 7) < 0) {
        kputs("Failed to Write Date/Time to External RTC\r\n");
        return -1;
    }

    // Force the Internal RTC to re-sync
    clock_state &= ~(clock_state_sync);

    // Successfully Updated the RTC
    return 0;
}

int clock_set_from_ds3231() {
    int ret = 0;

    // Stop the RTC and Request a Calendar and Time Update
    RTC_CR |= RTC_CR_UPDTIM | RTC_CR_UPDCAL;
    // Wait for Acknowledge
    while (!(RTC_SR & RTC_SR_ACKUPD));
    // Clear Acknowledge
    RTC_SCCR = RTC_SCCR_ACKCLR;

    // Read the Date/Time Registers from the External RTC
    uint8_t ds3231[7];
    if (twi_read(DS3231_TWI_ADDR, 0x01000000, ds3231, 7) < 0) {
        kputs("Failed to Read Date/Time from External RTC\r\n");
        ret = -1;
    }

    // Update the Internal RTC on valid data from the External RTC
    if (ret >= 0) {
        // State a new Time Register
        uint32_t timr = 0;
        timr |= ((ds3231[0] & 0x7F) << RTC_TIMR_SEC_Off) & RTC_TIMR_SEC_Msk;
        timr |= ((ds3231[1] & 0x7F) << RTC_TIMR_MIN_Off) & RTC_TIMR_MIN_Msk;
        if (ds3231[2] & 0x40) {
            // 12 hour mode
            RTC_MR |= RTC_MR_HRMOD;
            timr |= ((ds3231[2] & 0x1F) << RTC_TIMR_HOUR_Off) & RTC_TIMR_HOUR_Msk;
        } else {
            // 24 hour mode
            RTC_MR &= ~(RTC_MR_HRMOD);
            timr |= ((ds3231[2] & 0x3F) << RTC_TIMR_HOUR_Off) & RTC_TIMR_HOUR_Msk;
        }

        // Stage a new Date Register
        uint32_t calr = 0;
        calr |= ((ds3231[3] & 0x07) << RTC_CALR_DAY_Off) & RTC_CALR_DAY_Msk;
        calr |= ((ds3231[4] & 0x3F) << RTC_CALR_DATE_Off) & RTC_CALR_DATE_Msk;
        calr |= ((ds3231[5] & 0x1F) << RTC_CALR_MONTH_Off) & RTC_CALR_MONTH_Msk;
        if (ds3231[5] & 0x80) {
            calr |= (0x20 << RTC_CALR_CENT_Off) & RTC_CALR_CENT_Msk;
        } else {
            calr |= (0x19 << RTC_CALR_CENT_Off) & RTC_CALR_CENT_Msk;
        }
        calr |= ((ds3231[6]) << RTC_CALR_YEAR_Off) & RTC_CALR_YEAR_Msk;

        // Set the Date/Time Registers
        RTC_TIMR = timr;
        RTC_CALR = calr;
    }

    // Clear the Update Request in the Internal RTC
    RTC_CR &= ~(RTC_CR_UPDTIM | RTC_CR_UPDCAL);

    // Return an Error on Invalid Data
    if (RTC_VER & (RTC_VER_NVTIM | RTC_VER_NVCAL)) {
        ret = -1;
    }

    return ret;
}

void rtc_handler() {
    // Update the clock face
    if (RTC_SR * RTC_SR_SEC) {
        // Check if the Internal RTC is in Sync with the External RTC
        if (!(clock_state & clock_state_sync)) {
            // Update the Internal RTC
            if (clock_set_from_ds3231() >= 0) {
                clock_state |= clock_state_sync;
            }
        }

        // Update the Global Date/Time Structure
        clock_update_globaltime();

        // Update the clock face
        hv5530_set_digits(
            (clock_display_24hr ? clock.hour : clock.hour % 12),
            clock.minute,
            clock.second);

        // Send and event to the display service
        display_event_clock();

        // Clear the second flag in the status register
        RTC_SCCR = RTC_SCCR_SECCLR;
    }
}

// Initialize all components related to time keeping and the clock face
void clock_init(void) {
    // Initialize the DS3231 RTC and enable the 32kHz Output
    uint8_t ds3231_cr[2] = {0x00, 0x08};
    if (twi_write(DS3231_TWI_ADDR, DS3231_CR, ds3231_cr, 2) < 0) {
        kputs("Failed write to DS3231 Control Register\r\n");
    } else {
        kputs("Switching Slow-Clock to External 32kHz Reference...");
        // By-pass the Crystal Osc
        SUPC_MR |= SUPC_MR_KEY | SUPC_MR_OSCBYPASS;
        // Select the External Reference
        SUPC_CR = SUPC_CR_KEY | SUPC_CR_XTALSEL;
        // Wait for Selection to Complete
        while (!(PMC_SR & PMC_SR_OSCSELS));

        kputs("Done\r\n");
    }

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

    // Enable the RTC Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_RTC); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_RTC); // Clear Pending
    IPR(PMC_ID_RTC) = (IPR(PMC_ID_RTC) & ~(IPR_IP_Msk(PMC_ID_RTC))) | IPR_IP(PMC_ID_RTC, 0x8); // Set the Priority to 8
    ISER0 = (1 << PMC_ID_RTC); // Enable Interrupt
    // Enable Interrupts for RTC
    RTC_IER = RTC_IER_SECEN;

    // Enable the HV PSU
    PIO_SODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);

    // Initial write to the registers
    hv5530_write_registers();
}
