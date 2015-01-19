/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _BOARD_PINS_H_
#define _BOARD_PINS_H_

//! 5V PSU Board Definitions

//! 5V PSU Enable Pin
#define PIN_5VPSU_EN_PIO PIOC
#define PIN_5VPSU_EN_IDX 13
//! 5V PSU Power Good Pin
#define PIN_5VPSU_PG_PIO PIOA
#define PIN_5VPSU_PG_IDX 20

//! DS3231 Board Definitions

//! DS3231 Interrupt Pin
#define PIN_DS3231_INT_PIO PIOC
#define PIN_DS3231_INT_IDX 2

//! HV5530 Board Definitions

//! HV5530 High Voltage Enable Pin Definition
#define PIN_HV5530_HVEN_PIO PIOB
#define PIN_HV5530_HVEN_IDX 0
//! HV5530 Blank Pin Definition
#define PIN_HV5530_BLANK_PIO PIOC
#define PIN_HV5530_BLANK_IDX 0
//! HV5530 Latch Pin Definition
#define PIN_HV5530_LATCH_PIO PIOC
#define PIN_HV5530_LATCH_IDX 1

//! LED Board Definitions

//! LED 0 Pin Definition
#define PIN_LED_0_PIO PIOC
#define PIN_LED_0_IDX 15
//! LED 1 Pin Definition
#define PIN_LED_1_PIO PIOC
#define PIN_LED_1_IDX 16
//! LED 2 Pin Definition
#define PIN_LED_2_PIO PIOC
#define PIN_LED_2_IDX 17
//! LED 3 Pin Definition
#define PIN_LED_3_PIO PIOC
#define PIN_LED_3_IDX 18

//! PCK0 Board Definitions

//! PCK0 Pin Definition
#define PIN_PCK0_PIO PIOA
#define PIN_PCK0_IDX 21

//! SPI Board Definitions

//! SPI MISO Pin Definition
#define PIN_SPI_MISO_PIO PIOA
#define PIN_SPI_MISO_IDX 13
//! SPI MOSI Pin Definition
#define PIN_SPI_MOSI_PIO PIOA
#define PIN_SPI_MOSI_IDX 14
//! SPI SPCK Pin Definition
#define PIN_SPI_SPCK_PIO PIOA
#define PIN_SPI_SPCK_IDX 15

//! SSC Board Definitions

//! SSC TD Pin Definition
#define PIN_SSC_TD_PIO PIOA
#define PIN_SSC_TD_IDX 26
//! SSC RD Pin Definition
#define PIN_SSC_RD_PIO PIOA
#define PIN_SSC_RD_IDX 27
//! SSC TK Pin Definition
#define PIN_SSC_TK_PIO PIOA
#define PIN_SSC_TK_IDX 28
//! SSC RK Pin Definition
#define PIN_SSC_RK_PIO PIOA
#define PIN_SSC_RK_IDX 29
//! SSC TF Pin Definition
#define PIN_SSC_TF_PIO PIOA
#define PIN_SSC_TF_IDX 30
//! SSC RF Pin Definition
#define PIN_SSC_RF_PIO PIOA
#define PIN_SSC_RF_IDX 31

//! TWI0 Board Definitions

//! TWI0 SDA
#define PIN_TWI0_SDA_PIO PIOA
#define PIN_TWI0_SDA_IDX 9
//! TWI0 SCL
#define PIN_TWI0_SCL_PIO PIOA
#define PIN_TWI0_SCL_IDX 10

//! UART Pin Definitions

//! UART RXD Pin Definition
#define PIN_UART_RXD_PIO PIOA
#define PIN_UART_RXD_IDX 11
//! UART TXD Pin Definition
#define PIN_UART_TXD_PIO PIOA
#define PIN_UART_TXD_IDX 12

#endif //_BOARD_PINS_H_
