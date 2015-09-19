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
#include <string.h>

extern void *bss_start;
extern void *bss_end;
extern void *data_start;
extern void *data_end;
extern void *data_load;

void reset_handler() {
    // Disable Interrupts
    asm volatile("cpsid i");

    // Enable Exceptions
    asm volatile ("cpsie f");

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

    // Configure Clock Generator Main Clock (External 12MHz Xtal)
    // Startup time 15625uS for Xtal (65 for 65*8 cycles at slow clock, ~32000Hz)
    CKGR_MOR = CKGR_MOR_KEY | (CKGR_MOR & ~(CKGR_MOR_MOSCXTBY)) | CKGR_MOR_MOSCXTEN | (65 << CKGR_MOR_MOSCXTST_Off);
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
    CKGR_PLLAR = CKGR_PLLAR_ONE | (1 << CKGR_PLLAR_DIVA_Off) | (15 << CKGR_PLLAR_MULA_Off) | (0x3F << CKGR_PLLAR_PLLACOUNT_Off);
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

    // Configure Programmable Clock Controller (PCK0 = MCK / 8 = 12MHz)
    PMC_PCK0 = PMC_PCKx_CSS_MCK | PMC_PCKx_PRES_CLK_8;
    // Enable PCK0
    PMC_SCER = PMC_SCER_PCK0;
    // Wait for PCK0 to become ready
    while (!(PMC_SR & PMC_SR_PCKRDY0));

    // Divide the interrupts into 4 groups of 4; 0-3, 4-7, 8-11, 12-15.
    // Interrupts within the same group will not pre-empt each other but an
    // interrupt from a group with a lower priority will. When two interrupts
    // within the same group are received at the same time, the one with the
    // lower priority will be serviced first.
    AIRCR = AIRCR_VECTKEY | (0x5 << AIRCR_PRIGROUP_Off);

    // Enable Peripheral Clocks for the PIOs
    PMC_PCER = (1 << PMC_ID_PIOA);
    PMC_PCER = (1 << PMC_ID_PIOB);
    PMC_PCER = (1 << PMC_ID_PIOC);

    // Enable UART Pins
    PIO_PDR(PIN_UART_RXD_PIO)   =  (1 << PIN_UART_RXD_IDX); // Disable PIO to Enable Peripheral on Pin
    PIO_ABSR(PIN_UART_RXD_PIO) &= ~(1 << PIN_UART_RXD_IDX); // Select Peripheral A
    PIO_PDR(PIN_UART_TXD_PIO)   =  (1 << PIN_UART_TXD_IDX); // Disable PIO to Enable Peripheral on Pin
    PIO_ABSR(PIN_UART_TXD_PIO) &= ~(1 << PIN_UART_TXD_IDX); // Select Peripheral A

    // Enable the peripheral clock for the UART
    PMC_PCER = (1 << PMC_ID_UART);

    // Reset and disable the UART
    UART_CR = UART_CR_RSTRX | UART_CR_RSTTX | UART_CR_RXDIS | UART_CR_TXDIS;// | UART_CR_RSTSTA;
    // Set No Parity and Normal Mode
    UART_MR = UART_MR_PAR_NO | UART_MR_CHMODE_NORMAL;

    // Set the UART BAUD rate to 9600bps (96MHz / (16 * 625) = 9600)
    UART_BRGR = 625;

    // Enable the UART Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_UART); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_UART); // Clear Pending
    IPR(PMC_ID_UART) = (IPR(PMC_ID_UART) & ~(IPR_IP_Msk(PMC_ID_UART))) | IPR_IP(PMC_ID_UART, 0xC); // Set the Priority to 12
    ISER0 = (1 << PMC_ID_UART); // Enable Interrupt
    // Enable RX Interrupt for the UART
    UART_IER = UART_IER_RXRDY;

    // Enable the UART TX
    UART_CR = UART_CR_TXEN;

    // Now that the debug serial console is available, Enable Interrupts
    asm volatile("cpsie i");

    // TODO: Remaining Initialization

    // Enable the UART RX
    UART_CR = UART_CR_RXEN;

    // Initialization Complete
    while (1) {}
}
