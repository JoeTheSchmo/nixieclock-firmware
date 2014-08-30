/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "board/pins.h"
#include "cpu/peripherals/eefc.h"
#include "cpu/peripherals/pio.h"
#include "cpu/peripherals/pmc.h"
#include "cpu/peripherals/rstc.h"
#include "cpu/peripherals/twi.h"
#include "cpu/peripherals/wdt.h"
#include "types.h"

static inline void board_init_ds3231(void) {
	// Configure PIN_DS3231_INT
	PIO_PER(PIN_DS3231_INT_PIO)  = (1 << PIN_DS3231_INT_IDX);    // Enable PIO on Pin
	PIO_ODR(PIN_DS3231_INT_PIO)  = (1 << PIN_DS3231_INT_IDX);    // Disable Output
	PIO_PUDR(PIN_DS3231_INT_PIO) = (1 << PIN_DS3231_INT_IDX);    // Disable Pull-Up
}

static inline void board_init_hv5530(void) {
	// Configure PIN_HV5530_HVEN
	PIO_PER(PIN_HV5530_HVEN_PIO)  = (1 << PIN_HV5530_HVEN_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_HV5530_HVEN_PIO)  = (1 << PIN_HV5530_HVEN_IDX);    // Enable Output
	PIO_PUDR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);    // Disable Pull-Up
	PIO_CODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);    // Clear Output Data Register

	// Configure PIN_HV5530_BLANK
	PIO_PER(PIN_HV5530_BLANK_PIO)  = (1 << PIN_HV5530_BLANK_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_HV5530_BLANK_PIO)  = (1 << PIN_HV5530_BLANK_IDX);    // Enable Output
	PIO_PUER(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX);    // Enable Pull-Up
	PIO_SODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX);    // Set Output Data Register

	// Configure PIN_HV5530_LATCH
	PIO_PER(PIN_HV5530_LATCH_PIO)  = (1 << PIN_HV5530_LATCH_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_HV5530_LATCH_PIO)  = (1 << PIN_HV5530_LATCH_IDX);    // Enable Output
	PIO_PUER(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX);    // Enable Pull-Up
	PIO_SODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX);    // Set Output Data Register
}

static inline void board_init_leds(void) {
	// Configure PIN_LED_0
	PIO_PER(PIN_LED_0_PIO)  = (1 << PIN_LED_0_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_LED_0_PIO)  = (1 << PIN_LED_0_IDX);    // Enable Output
	PIO_CODR(PIN_LED_0_PIO) = (1 << PIN_LED_0_IDX);    // Clear Output Data Register

	// Configure PIN_LED_1
	PIO_PER(PIN_LED_1_PIO)  = (1 << PIN_LED_1_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_LED_1_PIO)  = (1 << PIN_LED_1_IDX);    // Enable Output
	PIO_CODR(PIN_LED_1_PIO) = (1 << PIN_LED_1_IDX);    // Clear Output Data Register

	// Configure PIN_LED_2
	PIO_PER(PIN_LED_2_PIO)  = (1 << PIN_LED_2_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_LED_2_PIO)  = (1 << PIN_LED_2_IDX);    // Enable Output
	PIO_CODR(PIN_LED_2_PIO) = (1 << PIN_LED_2_IDX);    // Clear Output Data Register

	// Configure PIN_LED_3
	PIO_PER(PIN_LED_3_PIO)  = (1 << PIN_LED_3_IDX);    // Enable PIO on Pin
	PIO_OER(PIN_LED_3_PIO)  = (1 << PIN_LED_3_IDX);    // Enable Output
	PIO_CODR(PIN_LED_3_PIO) = (1 << PIN_LED_3_IDX);    // Clear Output Data Register
}

static inline void board_init_pck0(void) {
	// Configure PIN_PCK0
	PIO_PDR(PIN_PCK0_PIO)   = (1 << PIN_PCK0_IDX); // Disable PIO on Pin
	PIO_ABSR(PIN_PCK0_PIO) |= (1 << PIN_PCK0_IDX); // Select Peripheral B
}

static inline void board_init_spi(void) {
	// Configure PIN_SPI_MISO (PA13 / Peripheral A / Pull-Up)
	PIO_PDR(PIN_SPI_MISO_PIO)   =  (1 << PIN_SPI_MISO_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_SPI_MISO_PIO) &= ~(1 << PIN_SPI_MISO_IDX); // Select Peripheral A
	PIO_PUDR(PIN_SPI_MISO_PIO)  =  (1 << PIN_SPI_MISO_IDX); // Enable Pull-Up

	// Configure PIN_SPI_MOSI (PA14 / Peripheral A / Pull-Up)
	PIO_PDR(PIN_SPI_MOSI_PIO)   =  (1 << PIN_SPI_MOSI_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_SPI_MOSI_PIO) &= ~(1 << PIN_SPI_MOSI_IDX); // Select Peripheral A
	PIO_PUDR(PIN_SPI_MOSI_PIO)  =  (1 << PIN_SPI_MOSI_IDX); // Enable Pull-Up

	// Configure PIN_SPI_SPCK (PA15 / Peripheral A / Pull-Up)
	PIO_PDR(PIN_SPI_SPCK_PIO)   =  (1 << PIN_SPI_SPCK_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_SPI_SPCK_PIO) &= ~(1 << PIN_SPI_SPCK_IDX); // Select Peripheral A
	PIO_PUDR(PIN_SPI_SPCK_PIO)  =  (1 << PIN_SPI_SPCK_IDX); // Enable Pull-Up
}

static inline void board_init_twi0(void) {
	// Configure PIN_TWI0_SDA (PA9 / Peripheral A)
	PIO_PDR(PIN_TWI0_SDA_PIO)   =  (1 << PIN_TWI0_SDA_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_TWI0_SDA_PIO) &= ~(1 << PIN_TWI0_SDA_IDX); // Select Peripheral A

	// Configure PIN_TWI0_SCL (PA10 / Peripheral A)
	PIO_PDR(PIN_TWI0_SCL_PIO)   =  (1 << PIN_TWI0_SCL_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_TWI0_SCL_PIO) &= ~(1 << PIN_TWI0_SCL_IDX); // Select Peripheral A

	// Reset TWI0
	TWI_CR(TWI0) = TWI_CR_SWRST;
	// Set the Clock Waveform Generator Register (400 kHz) (96 MHz / 240 == 400 kHz)
	TWI_CWGR(TWI0) = TWI_CWGR_CLDIV(240) | TWI_CWGR_CHDIV(240) | TWI_CWGR_CKDIV(0);
	// Disable Slave Mode and Enable Master Mode
	TWI_CR(TWI0) = TWI_CR_MSEN | TWI_CR_SVDIS;
}

static inline void board_init_uart(void) {
	// Configure PIN_UART_RXD (PA11 / Peripheral A)
	PIO_PDR(PIN_UART_RXD_PIO)   =  (1 << PIN_UART_RXD_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_UART_RXD_PIO) &= ~(1 << PIN_UART_RXD_IDX); // Select Peripheral A

	// Configure PIN_UART_TXD (PA12 / Peripheral A)
	PIO_PDR(PIN_UART_TXD_PIO)   =  (1 << PIN_UART_TXD_IDX); // Disable PIO to Enable Peripheral on Pin
	PIO_ABSR(PIN_UART_TXD_PIO) &= ~(1 << PIN_UART_TXD_IDX); // Select Peripheral A
}

void board_init(void) {
	// Reset the Watch Dog Timer
	WDT_CR = WDT_CR_WDRSTT | WDT_CR_KEY;
	// Disable the Watch Dog Timer
	WDT_MR = WDT_MR_WDDIS;

	// Enable User Resets by Asserting the NRST Pin
	RSTC_MR |= RSTC_MR_URSTEN | RSTC_MR_KEY;
	// Assert NRST for 2^(11+1) Slow Clock Cycles (32 kHz * 4096 = 128ms)
	RSTC_MR |= RSTC_MR_ERSTL(11) | RSTC_MR_KEY;

	// Setup the Peripherals
	board_init_ds3231();
	board_init_hv5530();
	board_init_leds();
	board_init_pck0();
	board_init_spi();
	board_init_twi0();
	board_init_uart();
}

void sysclock_init(void) {
	// Set Flash Read/Write Cycles to 4
	// This allows stable operation at for 96MHz
	EEFC_FMR(EEFC0) |= EEFC_FMR_FWS(4);
	EEFC_FMR(EEFC1) |= EEFC_FMR_FWS(4);

	// Configure Clock Generator Main Clock (External 12MHz Xtal)
	// Startup time 15625uS for Xtal (65 for 65*8 cycles at slow clock, ~32000Hz)
	CKGR_MOR = CKGR_MOR_KEY | (CKGR_MOR & ~(CKGR_MOR_MOSCXTBY)) | CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCXTST(65);
	// Wait the main Xtal to stabilize
	while ((PMC_SR & PMC_SR_MOSCXTS) == 0);
	// Select Xtal as the Main Clock Source
	CKGR_MOR |= CKGR_MOR_KEY | CKGR_MOR_MOSCSEL;
	// Wait for the selection to complete
	while (!(PMC_SR & PMC_SR_MOSCSELS));

	// Configure Clock Generator PLLA Clock (12MHz Xtal * 16 = 192MHz)
	// Disable the PLL
	CKGR_PLLAR = CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(0);
	// Enable with the correct settings
	CKGR_PLLAR = CKGR_PLLAR_ONE | CKGR_PLLAR_DIVA(1) | CKGR_PLLAR_MULA(15) | CKGR_PLLAR_PLLACOUNT(0x3F);
	// Wait for a lock
	while (!(PMC_SR & PMC_SR_LOCKA));

	// Configure Clock Generator USB UTMI PLL (12MHz Xtal * 40 = 480MHz)
	// Enable the UTMI PLLA
	CKGR_UCKR = CKGR_UCKR_UPLLEN | CKGR_UCKR_UPLLCOUNT(0xF);
	// Wait for a lock
	while (!(PMC_SR & PMC_SR_LOCKU));

	// Configure Master Clock Controller (MCK = PLLA / 2 = 96MHz)
	// Program Divider
	PMC_MCKR = (PMC_MCKR & ~(PMC_MCKR_PRES_Msk)) | PMC_MCKR_PRES(PMC_MCKR_PRES_CLK_2);
	// Wait for master clock to be ready
	while (!(PMC_SR & PMC_SR_MCKRDY));
	// Program clock source
	PMC_MCKR = (PMC_MCKR & ~(PMC_MCKR_CSS_Msk)) | PMC_MCKR_CSS(PMC_MCKR_CSS_PLLA_CLK);
	// Wait for the master clock to be ready
	while (!(PMC_SR & PMC_SR_MCKRDY));

	// Configure Programmable Clock Controller (PCK0)
	// Enable PCK0
	PMC_SCER = PMC_SCER_PCK0;
	// Configure PCK0
	PMC_PCK0 = PMC_PCK_CSS(PMC_PCK_CSS_MCK) | PMC_PCK_PRES(PMC_PCK_PRES_CLK_64);
	// Wait for PCK0 to become ready
	while (!(PMC_SR & PMC_SR_PCKRDY0));

	// Enable Clocks for the Peripherals Below
	PMC_PCER = (1 << PMC_ID_UART);
	PMC_PCER = (1 << PMC_ID_PIOA);
	PMC_PCER = (1 << PMC_ID_PIOB);
	PMC_PCER = (1 << PMC_ID_PIOC);
	PMC_PCER = (1 << PMC_ID_SPI);
	PMC_PCER = (1 << PMC_ID_TC0);
	PMC_PCER = (1 << PMC_ID_TWI0);
}
