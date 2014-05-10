/**
 * \file
 *
 * \brief User Board Definition.
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _USER_BOARD_H_
#define _USER_BOARD_H_

#include "compiler.h"
#include "system_sam3u.h"
#include "exceptions.h"

/*----------------------------------------------------------------------------*/
/**
 *  \page user_board_opfreq USER_BOARD - Operating frequencies
 *  This page lists several definition related to the board operating frequency
 *
 *  \section Definitions
 *  - \ref BOARD_FREQ_*
 *  - \ref BOARD_MCK
 */

/** Board oscillator settings */
#define BOARD_FREQ_SLCK_XTAL        (32768U)
#define BOARD_FREQ_SLCK_BYPASS      (32768U)
#define BOARD_FREQ_MAINCK_XTAL      (12000000U)
#define BOARD_FREQ_MAINCK_BYPASS    (12000000U)

/** Master clock frequency */
#define BOARD_MCK                   CHIP_FREQ_CPU_MAX

/** board main clock xtal statup time */
#define BOARD_OSC_STARTUP_US   15625

/*----------------------------------------------------------------------------*/
/**
 * \page user_board_info USER_BOARD - Board informations
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 * - \ref sam3u_user
 * - \ref sam3u
 * - \ref cortexm3
 */

/** Name of the board */
#define BOARD_NAME "NixieClockRevA"
/** Board definition */
#define sam3u_user
/** Family definition (already defined) */
#define sam3u
/** Core definition */
#define cortexm3

/*----------------------------------------------------------------------------*/

//! Console Board Definitions
#define CONSOLE_UART                    UART
#define CONSOLE_UART_ID                 ID_UART

//! HSMCI Board Definitions

//! Number of slot connected on HSMCI interface
#define SD_MMC_HSMCI_MEM_CNT            1
#define SD_MMC_HSMCI_SLOT_0_SIZE        8

//! MCI MCCDA Pin Definition
#define PIN_HSMCI_MCCDA_GPIO            (PIO_PA4_IDX)
#define PIN_HSMCI_MCCDA_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCCK Pin Definition
#define PIN_HSMCI_MCCK_GPIO             (PIO_PA3_IDX)
#define PIN_HSMCI_MCCK_FLAGS            (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCDA0 Pin Definition
#define PIN_HSMCI_MCDA0_GPIO            (PIO_PA5_IDX)
#define PIN_HSMCI_MCDA0_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCDA1 Pin Definition
#define PIN_HSMCI_MCDA1_GPIO            (PIO_PA6_IDX)
#define PIN_HSMCI_MCDA1_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCDA2 Pin Definition
#define PIN_HSMCI_MCDA2_GPIO            (PIO_PA7_IDX)
#define PIN_HSMCI_MCDA2_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCDA3 Pin Definition
#define PIN_HSMCI_MCDA3_GPIO            (PIO_PA8_IDX)
#define PIN_HSMCI_MCDA3_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
//! MCI MCDA4 Pin Definition
#define PIN_HSMCI_MCDA4_GPIO            (PIO_PC28_IDX)
#define PIN_HSMCI_MCDA4_FLAGS           (PIO_PERIPH_B | PIO_DEFAULT)
//! MCI MCDA5 Pin Definition
#define PIN_HSMCI_MCDA5_GPIO            (PIO_PC29_IDX)
#define PIN_HSMCI_MCDA5_FLAGS           (PIO_PERIPH_B | PIO_DEFAULT)
//! MCI MCDA6 Pin Definition
#define PIN_HSMCI_MCDA6_GPIO            (PIO_PC30_IDX)
#define PIN_HSMCI_MCDA6_FLAGS           (PIO_PERIPH_B | PIO_DEFAULT)
//! MCI MCDA7 Pin Definition
#define PIN_HSMCI_MCDA7_GPIO            (PIO_PC31_IDX)
#define PIN_HSMCI_MCDA7_FLAGS           (PIO_PERIPH_B | PIO_DEFAULT)

//! SD/MMC card detect pin definition.
#define SD_MMC_0_CD_GPIO                (PIO_PA25_IDX)
#define SD_MMC_0_CD_PIO_ID              ID_PIOA
#define SD_MMC_0_CD_FLAGS               (PIO_INPUT | PIO_PULLUP)
#define SD_MMC_0_CD_DETECT_VALUE        0

//! HV5530 Board Definitions

//! HV5530 High Voltage Enable Pin Definition
#define PIN_HV5530_HVEN_GPIO            (PIO_PB0_IDX)
#define PIN_HV5530_HVEN_FLAGS           (PIO_TYPE_PIO_OUTPUT_0 | PIO_PULLUP)
//! HV5530 Blank Pin Definition
#define PIN_HV5530_BLANK_GPIO           (PIO_PC0_IDX)
#define PIN_HV5530_BLANK_FLAGS          (PIO_TYPE_PIO_OUTPUT_1 | PIO_PULLUP)
//! HV5530 Latch Pin Definition
#define PIN_HV5530_LATCH_GPIO           (PIO_PC1_IDX)
#define PIN_HV5530_LATCH_FLAGS          (PIO_TYPE_PIO_OUTPUT_1 | PIO_PULLUP)

//! NAND Board Definitions

//! NAND Pins Definition: OE
#define PIN_EBI_NANDOE_GPIO             (PIO_PB17_IDX)
#define PIN_EBI_NANDOE_FLAGS            (PIO_PERIPH_A | PIO_PULLUP)
//! NAND Pins Definition: WE
#define PIN_EBI_NANDWE_GPIO             (PIO_PB18_IDX)
#define PIN_EBI_NANDWE_FLAGS            (PIO_PERIPH_A | PIO_PULLUP)
//! NAND Pins Definition: CLE
#define PIN_EBI_NANDCLE_GPIO            (PIO_PB22_IDX)
#define PIN_EBI_NANDCLE_FLAGS           (PIO_PERIPH_A | PIO_PULLUP)
//! NAND Pins Definition: ALE
#define PIN_EBI_NANDALE_GPIO            (PIO_PB21_IDX)
#define PIN_EBI_NANDALE_FLAGS           (PIO_PERIPH_A | PIO_PULLUP)
//! NAND Pins Definition: D[0:15]
#define PIN_EBI_NANDIO_0_GPIO           (PIO_PB9_IDX)
#define PIN_EBI_NANDIO_0_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_1_GPIO           (PIO_PB10_IDX)
#define PIN_EBI_NANDIO_1_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_2_GPIO           (PIO_PB11_IDX)
#define PIN_EBI_NANDIO_2_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_3_GPIO           (PIO_PB12_IDX)
#define PIN_EBI_NANDIO_3_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_4_GPIO           (PIO_PB13_IDX)
#define PIN_EBI_NANDIO_4_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_5_GPIO           (PIO_PB14_IDX)
#define PIN_EBI_NANDIO_5_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_6_GPIO           (PIO_PB15_IDX)
#define PIN_EBI_NANDIO_6_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_7_GPIO           (PIO_PB16_IDX)
#define PIN_EBI_NANDIO_7_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_8_GPIO           (PIO_PB25_IDX)
#define PIN_EBI_NANDIO_8_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_9_GPIO           (PIO_PB26_IDX)
#define PIN_EBI_NANDIO_9_FLAGS          (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_10_GPIO          (PIO_PB27_IDX)
#define PIN_EBI_NANDIO_10_FLAGS         (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_11_GPIO          (PIO_PB28_IDX)
#define PIN_EBI_NANDIO_11_FLAGS         (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_12_GPIO          (PIO_PB29_IDX)
#define PIN_EBI_NANDIO_12_FLAGS         (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_13_GPIO          (PIO_PB30_IDX)
#define PIN_EBI_NANDIO_13_FLAGS         (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_14_GPIO          (PIO_PB31_IDX)
#define PIN_EBI_NANDIO_14_FLAGS         (PIO_PERIPH_A | PIO_PULLUP)
#define PIN_EBI_NANDIO_15_GPIO          (PIO_PB6_IDX)
#define PIN_EBI_NANDIO_15_FLAGS         (PIO_PERIPH_B | PIO_PULLUP)
//! NAND Chip Enable Pin Definition
#define PIN_NF_CE_GPIO                  (PIO_PC12_IDX)
#define PIN_NF_CE_FLAGS                 (PIO_PERIPH_A | PIO_PULLUP)
//! NAND Ready/Busy Pin Definition
#define PIN_NF_RB_GPIO                  (PIO_PB24_IDX)
#define PIN_NF_RB_FLAGS                 (PIO_PERIPH_A | PIO_PULLUP)
//! Chip select number for NAND
#define BOARD_NAND_CS                   1
//! Address for transferring command bytes to the NAND
#define BOARD_NF_COMMAND_ADDR           0x60000000
//! Address for transferring address bytes to the NAND
#define BOARD_NF_ADDRESS_ADDR           0x61200000
//! Address for transferring data bytes to the NAND
#define BOARD_NF_DATA_ADDR              0x61000000
//! Bus width for NAND
#define CONF_NF_BUSWIDTH                16
//! SMC NFC using five address cycle
#define CONF_NF_NEED_FIVE_ADDRESS_CYCLES 1
//! Access timing for NAND
#define CONF_NF_SETUP_TIMING (SMC_SETUP_NWE_SETUP(1) \
		| SMC_SETUP_NCS_WR_SETUP(2) \
		| SMC_SETUP_NRD_SETUP(1) \
		| SMC_SETUP_NCS_RD_SETUP(2))
#define CONF_NF_PULSE_TIMING (SMC_PULSE_NWE_PULSE(3) \
		| SMC_PULSE_NCS_WR_PULSE(4) \
		| SMC_PULSE_NRD_PULSE(4) \
		| SMC_PULSE_NCS_RD_PULSE(4))
#define CONF_NF_CYCLE_TIMING (SMC_CYCLE_NWE_CYCLE(6) \
		| SMC_CYCLE_NRD_CYCLE(9))
#define CONF_NF_TIMING (SMC_TIMINGS_TCLR(3) \
		| SMC_TIMINGS_TADL(4) \
		| SMC_TIMINGS_TAR(2) \
		| SMC_TIMINGS_TRR(2) \
		| SMC_TIMINGS_TWB(4) \
		| SMC_TIMINGS_RBNSEL(7) \
		| (SMC_TIMINGS_NFSEL))
//! Support DMA
#define CONF_NF_USE_DMA
#ifdef CONF_NF_USE_DMA
//! DMA channel used for NAND
#define CONF_NF_DMA_CHANNEL             0
#endif

//! PCK0 Board Definitions

//! PCK0 Pin Definition
#define PIN_PCK0_GPIO                   (PIO_PA21_IDX)
#define PIN_PCK0_FLAGS                  (PIO_PERIPH_B | PIO_DEFAULT)

//! SPI Board Definitions

//! SPI MISO Pin Definition
#define PIN_SPI_MISO_GPIO               (PIO_PA13_IDX)
#define PIN_SPI_MISO_FLAGS              (PIO_PERIPH_A | PIO_PULLUP)
//! SPI MOSI Pin Definition
#define PIN_SPI_MOSI_GPIO               (PIO_PA14_IDX)
#define PIN_SPI_MOSI_FLAGS              (PIO_PERIPH_A | PIO_PULLUP)
//! SPI SPCK Pin Definition
#define PIN_SPI_SPCK_GPIO               (PIO_PA15_IDX)
#define PIN_SPI_SPCK_FLAGS              (PIO_PERIPH_A | PIO_PULLUP)

//! SSC Board Definitions

//! SSC pin Transmitter Data (TD)
#define PIN_SSC_TD_GPIO                 (PIO_PA26_IDX)
#define PIN_SSC_TD_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)
//! SSC pin Transmitter Clock (TK)
#define PIN_SSC_TK_GPIO                 (PIO_PA28_IDX)
#define PIN_SSC_TK_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)
//! SSC pin Transmitter FrameSync (TF)
#define PIN_SSC_TF_GPIO                 (PIO_PA30_IDX)
#define PIN_SSC_TF_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)
//! SSC pin Receiver Data (RD)
#define PIN_SSC_RD_GPIO                 (PIO_PA27_IDX)
#define PIN_SSC_RD_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)
//! SSC pin Receiver Clock (RK)
#define PIN_SSC_RK_GPIO                 (PIO_PA29_IDX)
#define PIN_SSC_RK_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)
//! SSC pin Receiver FrameSync (RF)
#define PIN_SSC_RF_GPIO                 (PIO_PA31_IDX)
#define PIN_SSC_RF_FLAGS                (PIO_PERIPH_A | PIO_DEFAULT)

//! SSD1306 Board Definitions

//! SSD1306 TWI Interface
#define TWI_SSD1306                     TWI0
//! SSD1306 Slave address
#define SSD1306_SLAVE_ADDRESS           0x3c

//! TWI0 Board Definitions

//! TWI0 SDA Pin Definition
#define PIN_TWI0_SDA_GPIO               (PIO_PA9_IDX)
#define PIN_TWI0_SDA_FLAGS              (PIO_PERIPH_A | PIO_DEFAULT)
//! TWI0 SCL Pin Definition
#define PIN_TWI0_SCL_GPIO               (PIO_PA10_IDX)
#define PIN_TWI0_SCL_FLAGS              (PIO_PERIPH_A | PIO_DEFAULT)

//! UART Board Definitions

//! UART URXD Pin Definition
#define PIN_UART_URXD_GPIO              (PIO_PA11_IDX)
#define PIN_UART_URXD_FLAGS             (PIO_PERIPH_A | PIO_DEFAULT)
//! UART UTXD Pin Definition
#define PIN_UART_UTXD_GPIO              (PIO_PA12_IDX)
#define PIN_UART_UTXD_FLAGS             (PIO_PERIPH_A | PIO_DEFAULT)

//! USART0 Board Definitions

//! USART0 RXD Pin Definition
#define PIN_USART0_RXD_GPIO             (PIO_PA19_IDX)
#define PIN_USART0_RXD_FLAGS            (PIO_PERIPH_A | PIO_DEFAULT)
//! USART0 TXD Pin Definition
#define PIN_USART0_TXD_GPIO             (PIO_PA18_IDX)
#define PIN_USART0_TXD_FLAGS            (PIO_PERIPH_A | PIO_DEFAULT)
//! USART0 CTS Pin Definition
#define PIN_USART0_CTS_GPIO             (PIO_PB8_IDX)
#define PIN_USART0_CTS_FLAGS            (PIO_PERIPH_A | PIO_DEFAULT)
//! USART0 RTS Pin Definition
#define PIN_USART0_RTS_GPIO             (PIO_PB9_IDX)
#define PIN_USART0_RTS_FLAGS            (PIO_PERIPH_A | PIO_DEFAULT)

//! WM8731 Board Definitions

//! WM8731 TWI Interface
#define TWI_WM8731                      TWI0
//! SSD1306 Slave address
#define WM8731_SLAVE_ADDRESS            0x1b

//! XBee Board Definitions

//! XBee Shutdown Pin Definition
#define PIN_XBEE_SHDN_GPIO              (PIO_PB4_IDX)
#define PIN_XBEE_SHDN_FLAGS             (PIO_TYPE_PIO_OUTPUT_0 | PIO_PULLUP)
//! XBee DTR Pin Definition
#define PIN_XBEE_DTR_GPIO               (PIO_PB5_IDX)
#define PIN_XBEE_DTR_FLAGS              (PIO_TYPE_PIO_OUTPUT_0 | PIO_PULLUP)

#endif  // _USER_BOARD_H_
