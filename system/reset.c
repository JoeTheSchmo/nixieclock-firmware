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

#include <audio.h>
#include <clock.h>
#include <console.h>
#include <display.h>
#include <keyboard.h>
#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <string.h>
#include <system.h>
#include <timer.h>

extern uint8_t bss_start;
extern uint8_t bss_end;
extern uint8_t data_start;
extern uint8_t data_end;
extern uint8_t data_load;

extern void twi_init(void);

void reset_handler() {
    // Disable Exceptions and Interrupts
    asm volatile ("cpsid f");
    asm volatile ("cpsid i");

    // Initialize the RTT and Event Timer
    timer_init();

    // Reset and Disable the Watchdog Timer
    WDT_CR = WDT_CR_WDRSTT | WDT_CR_KEY;
    WDT_MR = WDT_MR_WDDIS;

    // Enable Peripheral Clocks for the PIOs
    PMC_PCER = (1 << PMC_ID_PIOA);
    PMC_PCER = (1 << PMC_ID_PIOB);
    PMC_PCER = (1 << PMC_ID_PIOC);

    // Clear the PIO Interrupt Status Registers
    PIO_ISR(PIOA);
    PIO_ISR(PIOB);
    PIO_ISR(PIOC);

    // Configure the High-Voltage Pin and Disable the PSU (HV Off)
    PIO_PER(PIN_HV5530_HVEN_PIO)  = (1 << PIN_HV5530_HVEN_IDX); // Enable PIO on Pin
    PIO_OER(PIN_HV5530_HVEN_PIO)  = (1 << PIN_HV5530_HVEN_IDX); // Enable Output
    PIO_PUDR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX); // Disable Pull-Up
    PIO_CODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX); // Clear Output Data Register

    // Configure the initial state of the 5v PSU (5v On)
    PIO_PER(PIN_5VPSU_EN_PIO)  = (1 << PIN_5VPSU_EN_IDX);    // Enable PIO on Pin
    PIO_OER(PIN_5VPSU_EN_PIO)  = (1 << PIN_5VPSU_EN_IDX);    // Enable Output
    PIO_PUER(PIN_5VPSU_EN_PIO) = (1 << PIN_5VPSU_EN_IDX);    // Enable Pull-Up
    PIO_CODR(PIN_5VPSU_EN_PIO) = (1 << PIN_5VPSU_EN_IDX);    // Clear Output Data Register

    // Configure the ZigBee Shutdown Pin (ZigBee Off)
    PIO_PER(PIN_ZIGBEE_SHDN_PIO)  = (1 << PIN_ZIGBEE_SHDN_IDX); // Enable PIO on Pin
    PIO_OER(PIN_ZIGBEE_SHDN_PIO)  = (1 << PIN_ZIGBEE_SHDN_IDX); // Enable Output
    PIO_PUER(PIN_ZIGBEE_SHDN_PIO) = (1 << PIN_ZIGBEE_SHDN_IDX); // Enable Pull-Up
    PIO_CODR(PIN_ZIGBEE_SHDN_PIO) = (1 << PIN_ZIGBEE_SHDN_IDX); // Clear Output Data Register

    // Enable User Resets by Asserting the NRST Pin
    // Assert NRST for 2^(11+1) Slow Clock Cycles (32 kHz * 4096 = 128ms)
    RSTC_MR = RSTC_MR_URSTEN | (11 << RSTC_MR_ERSTL_Off) | RSTC_MR_KEY;

    // Set the Flash Read/Write Cycles to 4 (for stable operation at 96MHz)
    EEFC_FMR(EEFC0) = ((EEFC_FMR(EEFC0) & ~EEFC_FMR_FWS_Msk) | (4 << (EEFC_FMR_FWS_Off)));
    EEFC_FMR(EEFC1) = ((EEFC_FMR(EEFC1) & ~EEFC_FMR_FWS_Msk) | (4 << (EEFC_FMR_FWS_Off)));

    // Configure Clock Generator Main Clock (External 12MHz Xtal)
    // Startup time 15625uS for Xtal (65 for 65*8 cycles at slow clock, ~32000Hz)
    CKGR_MOR = CKGR_MOR_KEY | (CKGR_MOR & ~(CKGR_MOR_MOSCXTBY)) |
        CKGR_MOR_MOSCXTEN | (65 << CKGR_MOR_MOSCXTST_Off);
    // Wait the main Xtal to stabilize
    while ((PMC_SR & PMC_SR_MOSCXTS) == 0);
    // Select Xtal as the Main Clock Source
    CKGR_MOR |= CKGR_MOR_KEY | CKGR_MOR_MOSCSEL;
    // Wait for the selection to complete
    while (!(PMC_SR & PMC_SR_MOSCSELS));

    // Configure Clock Generator PLLA Clock (12MHz Xtal * (15+1) = 192MHz)
    // Disable the PLL
    CKGR_PLLAR = CKGR_PLLAR_ONE;
    // Enable with the correct settings
    CKGR_PLLAR = CKGR_PLLAR_ONE | (1 << CKGR_PLLAR_DIVA_Off) |
        (15 << CKGR_PLLAR_MULA_Off) | (0x3F << CKGR_PLLAR_PLLACOUNT_Off);
    // Wait for a lock
    while (!(PMC_SR & PMC_SR_LOCKA));

    // Configure Clock Generator USB UTMI PLL (12MHz Xtal * 40 = 480MHz)
    // Enable the UTMI PLLA
    CKGR_UCKR = CKGR_UCKR_UPLLEN | (0xF << CKGR_UCKR_UPLLCOUNT_Off);
    // Wait for a lock
    while (!(PMC_SR & PMC_SR_LOCKU));

    // Configure Master Clock Controller (MCK = PLLA / 2 = 96MHz)
    // Program clock divider as 2
    PMC_MCKR = (PMC_MCKR & ~(PMC_MCKR_PRES_Msk)) | PMC_MCKR_PRES_CLK_2;
    // Program clock source as PLLA
    PMC_MCKR = (PMC_MCKR & ~(PMC_MCKR_CSS_Msk)) | PMC_MCKR_CSS_PLLA_CLK;
    // Wait for the master clock to be ready
    while (!(PMC_SR & PMC_SR_MCKRDY));

    // Zero the uninitialized data segment
    if (&bss_end - &bss_start > 0) {
        memset(&bss_start, 0, &bss_end - &bss_start);
    }

    // Load the initialized data segment
    if (&data_start != &data_load) {
        memcpy(&data_start, &data_load, &data_end - &data_start);
    }

    // Divide the interrupts into 4 groups of 4; 0-3, 4-7, 8-11, 12-15.
    // Interrupts within the same group will not preempt each other but an
    // interrupt from a group with a lower priority will. When two interrupts
    // within the same group are received at the same time, the one with the
    // lower priority number will be serviced first.
    AIRCR = AIRCR_VECTKEY | (0x5 << AIRCR_PRIGROUP_Off);

    // Set SVC Interrupt Priority to 4
    SHPR2 = ((SHPR2 & ~SHPR2_PRI_11_Msk) | (0x40 << SHPR2_PRI_11_Off));

    // Trap Divide-by-0 as Hard Fault
    CCR |= CCR_DIV_0_TRP;

    // Enable Exceptions
    asm volatile ("cpsie f");

    // Enable the Serial Console
    console_init();

    // Initialize the TWI Driver
    twi_init();

    // Enable Interrupts
    asm volatile ("cpsie i");

    // Print terminal headline
    kputs("\r\n\r\n");
    kputs("nixieclock-firmware: Nixie Clock Main Firmware Program\r\n");
    kputs("Copyright (C) 2013 - 2015 Joe Ciccone and Ed Koloski\r\n");
    kputs("This program comes with ABSOLUTELY NO WARRANTY; for details type 'license show'.\r\n");
    kputs("This is free software, and you are welcome to redistribute it\r\n");
    kputs("under certain conditions; type 'license show' for details.\r\n");
    kputs("\r\n");

    // Print the reset cause
    kputs("Reset Reason: ");
    switch (RSTC_SR & RSTC_SR_RSTTYP_Msk) {
    case RSTC_SR_RSTTYP_GENERAL:    kputs("General");   break;
    case RSTC_SR_RSTTYP_BACKUP:     kputs("Backup");    break;
    case RSTC_SR_RSTTYP_WATCHDOG:   kputs("Watchdog");  break;
    case RSTC_SR_RSTTYP_SOFTWARE:   kputs("Software");  break;
    case RSTC_SR_RSTTYP_USER:       kputs("User");      break;
    default:
        kprintf("Unknown (%lu)", ((RSTC_SR & RSTC_SR_RSTTYP_Msk) >> RSTC_SR_RSTTYP_Off));
    }
    kputs("\r\n");

    // Initialize Services
    clock_init();
    audio_init();
    display_init();
    keyboard_init();

    // Enable the Interactive Console
    console_start();

    // Initialization Complete
    while (1) {}
}
