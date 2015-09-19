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

extern void stack_bottom();
extern void reset_handler();

void dummy_handler() {
    while (1) {}
}

extern void stack_bottom();
extern void reset_handler();
void nmi_handler() __attribute__ ((weak, alias("dummy_handler")));
void hardfault_handler() __attribute__ ((weak, alias("dummy_handler")));
void memmanage_handler() __attribute__ ((weak, alias("dummy_handler")));
void busfault_handler() __attribute__ ((weak, alias("dummy_handler")));
void usagefault_handler() __attribute__ ((weak, alias("dummy_handler")));
void svcall_handler() __attribute__ ((weak, alias("dummy_handler")));
void debugmon_handler() __attribute__ ((weak, alias("dummy_handler")));
void pendsv_handler() __attribute__ ((weak, alias("dummy_handler")));
void systick_handler() __attribute__ ((weak, alias("dummy_handler")));
void supc_handler() __attribute__ ((weak, alias("dummy_handler")));
void rstc_handler() __attribute__ ((weak, alias("dummy_handler")));
void rtc_handler() __attribute__ ((weak, alias("dummy_handler")));
void rtt_handler() __attribute__ ((weak, alias("dummy_handler")));
void wdt_handler() __attribute__ ((weak, alias("dummy_handler")));
void pmc_handler() __attribute__ ((weak, alias("dummy_handler")));
void eefc0_handler() __attribute__ ((weak, alias("dummy_handler")));
void eefc1_handler() __attribute__ ((weak, alias("dummy_handler")));
void uart_handler() __attribute__ ((weak, alias("dummy_handler")));
void smc_handler() __attribute__ ((weak, alias("dummy_handler")));
void pioa_handler() __attribute__ ((weak, alias("dummy_handler")));
void piob_handler() __attribute__ ((weak, alias("dummy_handler")));
void pioc_handler() __attribute__ ((weak, alias("dummy_handler")));
void usart0_handler() __attribute__ ((weak, alias("dummy_handler")));
void usart1_handler() __attribute__ ((weak, alias("dummy_handler")));
void usart2_handler() __attribute__ ((weak, alias("dummy_handler")));
void usart3_handler() __attribute__ ((weak, alias("dummy_handler")));
void hsmci_handler() __attribute__ ((weak, alias("dummy_handler")));
void twi0_handler() __attribute__ ((weak, alias("dummy_handler")));
void twi1_handler() __attribute__ ((weak, alias("dummy_handler")));
void spi_handler() __attribute__ ((weak, alias("dummy_handler")));
void ssc_handler() __attribute__ ((weak, alias("dummy_handler")));
void tc0_handler() __attribute__ ((weak, alias("dummy_handler")));
void tc1_handler() __attribute__ ((weak, alias("dummy_handler")));
void tc2_handler() __attribute__ ((weak, alias("dummy_handler")));
void pwm_handler() __attribute__ ((weak, alias("dummy_handler")));
void adc12b_handler() __attribute__ ((weak, alias("dummy_handler")));
void adc_handler() __attribute__ ((weak, alias("dummy_handler")));
void dmac_handler() __attribute__ ((weak, alias("dummy_handler")));
void udphs_handler() __attribute__ ((weak, alias("dummy_handler")));

typedef void (*vector_t)(void);
__attribute__ ((section(".vectors")))
vector_t vector_table[] = {
    stack_bottom,
    reset_handler,
    nmi_handler,
    hardfault_handler,
    memmanage_handler,
    busfault_handler,
    usagefault_handler,
    0, 0, 0, 0,
    svcall_handler,
    debugmon_handler,
    0,
    pendsv_handler,
    systick_handler,

    supc_handler,
    rstc_handler,
    rtc_handler,
    rtt_handler,
    wdt_handler,
    pmc_handler,
    eefc0_handler,
    eefc1_handler,
    uart_handler,
    smc_handler,
    pioa_handler,
    piob_handler,
    pioc_handler,
    usart0_handler,
    usart1_handler,
    usart2_handler,
    usart3_handler,
    hsmci_handler,
    twi0_handler,
    twi1_handler,
    spi_handler,
    ssc_handler,
    tc0_handler,
    tc1_handler,
    tc2_handler,
    pwm_handler,
    adc12b_handler,
    adc_handler,
    dmac_handler,
    udphs_handler
};
