/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _USER_BOARD_H_
#define _USER_BOARD_H_

#include "compiler.h"
#include "system_sam3u.h"
#include "exceptions.h"

/*----------------------------------------------------------------------------*/
/**
 *  \page user_board_opfreq USER BOARD - Operating frequencies
 *  This page lists several definition related to the board operating frequency
 *
 *  \section Definitions
 *  - \ref BOARD_FREQ_SLCK_XTAL
 *  - \ref BOARD_FREQ_SLCK_BYPASS
 *  - \ref BOARD_FREQ_MAINCK_XTAL
 *  - \ref BOARD_FREQ_MAINCK_BYPASS
 *  - \ref BOARD_MCK
 */

//! Board oscillator settings - Slow Clock XTAL
#define BOARD_FREQ_SLCK_XTAL        (32768U)
//! Board oscillator settings - Slow Clock Bypass
#define BOARD_FREQ_SLCK_BYPASS      (32768U)
//! Board oscillator settings - Main Clock XTAL
#define BOARD_FREQ_MAINCK_XTAL      (12000000U)
//! Board oscillator settings - Main Clock Bypass
#define BOARD_FREQ_MAINCK_BYPASS    (12000000U)

//! Master clock frequency
#define BOARD_MCK                   CHIP_FREQ_CPU_MAX

//! Board main clock xtal startup time
#define BOARD_OSC_STARTUP_US   15625

/*----------------------------------------------------------------------------*/

//! 5V PSU Board Definitions

//! 5V PSU Enable Pin
#define PIN_5VPSU_EN IOPORT_CREATE_PIN(PIOC, 13)
//! 5V PSU Power Good Pin
#define PIN_5VPSU_PG IOPORT_CREATE_PIN(PIOA, 20)

//! DS3231 Board Definitions

//! DS3231 Interrupt Pin
#define PIN_DS3231_INT IOPORT_CREATE_PIN(PIOC, 2)

//! HV5530 Board Definitions

//! HV5530 High Voltage Enable Pin Definition
#define PIN_HV5530_HVEN IOPORT_CREATE_PIN(PIOB, 0)
//! HV5530 Blank Pin Definition
#define PIN_HV5530_BLANK IOPORT_CREATE_PIN(PIOC, 0)
//! HV5530 Latch Pin Definition
#define PIN_HV5530_LATCH IOPORT_CREATE_PIN(PIOC, 1)

//! LED Board Definitions

//! LED 0 Pin Definition
#define PIN_LED_0 IOPORT_CREATE_PIN(PIOC, 15)
//! LED 1 Pin Definition
#define PIN_LED_1 IOPORT_CREATE_PIN(PIOC, 16)
//! LED 2 Pin Definition
#define PIN_LED_2 IOPORT_CREATE_PIN(PIOC, 17)
//! LED 3 Pin Definition
#define PIN_LED_3 IOPORT_CREATE_PIN(PIOC, 18)

//! PCK0 Board Definitions

//! PCK0 Pin Definition
#define PIN_PCK0 IOPORT_CREATE_PIN(PIOA, 21)

//! SPI Board Definitions

//! SPI MISO Pin Definition
#define PIN_SPI_MISO IOPORT_CREATE_PIN(PIOA, 13)
//! SPI MOSI Pin Definition
#define PIN_SPI_MOSI IOPORT_CREATE_PIN(PIOA, 14)
//! SPI SPCK Pin Definition
#define PIN_SPI_SPCK IOPORT_CREATE_PIN(PIOA, 15)

//! SSC Board Definitions

//! SSC TD Pin Definition
#define PIN_SSC_TD IOPORT_CREATE_PIN(PIOA, 26)
//! SSC RD Pin Definition
#define PIN_SSC_RD IOPORT_CREATE_PIN(PIOA, 27)
//! SSC TK Pin Definition
#define PIN_SSC_TK IOPORT_CREATE_PIN(PIOA, 28)
//! SSC RK Pin Definition
#define PIN_SSC_RK IOPORT_CREATE_PIN(PIOA, 29)
//! SSC TF Pin Definition
#define PIN_SSC_TF IOPORT_CREATE_PIN(PIOA, 30)
//! SSC RF Pin Definition
#define PIN_SSC_RF IOPORT_CREATE_PIN(PIOA, 31)

//! TWI0 Board Definitions

//! TWI0 SDA
#define PIN_TWI0_SDA IOPORT_CREATE_PIN(PIOA, 9)
//! TWI0 SCL
#define PIN_TWI0_SCL IOPORT_CREATE_PIN(PIOA, 10)

//! UART Pin Definitions

//! UART RXD Pin Definition
#define PIN_UART_RXD IOPORT_CREATE_PIN(PIOA, 11)
//! UART TXD Pin Definition
#define PIN_UART_TXD IOPORT_CREATE_PIN(PIOA, 12)

//! XBEE Pin Definitions

//! XBEE SHDN Pin Definition
#define PIN_XBEE_SHDN IOPORT_CREATE_PIN(PIOB, 4)

#endif  // _USER_BOARD_H_
