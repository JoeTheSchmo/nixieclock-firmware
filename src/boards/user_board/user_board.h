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
#define BOARD_NAME "USER_BOARD"
/** Board definition */
#define sam3u_user
/** Family definition (already defined) */
#define sam3u
/** Core definition */
#define cortexm3

/*----------------------------------------------------------------------------*/

//! UART pins (UTXD0 and URXD0) definitions, PA9,10.
#define PINS_UART       (PIO_PA11A_URXD | PIO_PA12A_UTXD)
#define PINS_UART_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)

#define PINS_UART_MASK PIO_PA11A_URXD|PIO_PA12A_UTXD
#define PINS_UART_PIO PIOA
#define PINS_UART_ID ID_PIOA
#define PINS_UART_TYPE PIO_PERIPH_A
#define PINS_UART_ATTR PIO_DEFAULT

/** EBI Data Bus pins */
#define PIN_EBI_DATA_BUS_D0        PIO_PB9_IDX
#define PIN_EBI_DATA_BUS_D1        PIO_PB10_IDX
#define PIN_EBI_DATA_BUS_D2        PIO_PB11_IDX
#define PIN_EBI_DATA_BUS_D3        PIO_PB12_IDX
#define PIN_EBI_DATA_BUS_D4        PIO_PB13_IDX
#define PIN_EBI_DATA_BUS_D5        PIO_PB14_IDX
#define PIN_EBI_DATA_BUS_D6        PIO_PB15_IDX
#define PIN_EBI_DATA_BUS_D7        PIO_PB16_IDX
#define PIN_EBI_DATA_BUS_D8        PIO_PB25_IDX
#define PIN_EBI_DATA_BUS_D9        PIO_PB26_IDX
#define PIN_EBI_DATA_BUS_D10      PIO_PB27_IDX
#define PIN_EBI_DATA_BUS_D11      PIO_PB28_IDX
#define PIN_EBI_DATA_BUS_D12      PIO_PB29_IDX
#define PIN_EBI_DATA_BUS_D13      PIO_PB30_IDX
#define PIN_EBI_DATA_BUS_D14      PIO_PB31_IDX
#define PIN_EBI_DATA_BUS_FLAG1   PIO_PERIPH_A | PIO_PULLUP
#define PIN_EBI_DATA_BUS_D15      PIO_PB6_IDX
#define PIN_EBI_DATA_BUS_FLAG2  PIO_PERIPH_B | PIO_PULLUP
/** EBI NRD pin */
#define PIN_EBI_NRD                 PIO_PB19_IDX
#define PIN_EBI_NRD_FLAGS       PIO_PERIPH_A | PIO_PULLUP
#define PIN_EBI_NRD_MASK  1 << 19
#define PIN_EBI_NRD_PIO  PIOB
#define PIN_EBI_NRD_ID  ID_PIOB
#define PIN_EBI_NRD_TYPE PIO_PERIPH_A
#define PIN_EBI_NRD_ATTR PIO_PULLUP
/** EBI NWE pin */
#define PIN_EBI_NWE                  PIO_PB23_IDX
#define PIN_EBI_NWE_FLAGS       PIO_PERIPH_A | PIO_PULLUP
#define PIN_EBI_NWE_MASK  1 << 23
#define PIN_EBI_NWE_PIO  PIOB
#define PIN_EBI_NWE_ID  ID_PIOB
#define PIN_EBI_NWE_TYPE PIO_PERIPH_A
#define PIN_EBI_NWE_ATTR PIO_PULLUP
/** EBI NCS0 pin */
#define PIN_EBI_NCS0                PIO_PB20_IDX
#define PIN_EBI_NCS0_FLAGS     PIO_PERIPH_A | PIO_PULLUP
#define PIN_EBI_NCS0_MASK  1 << 20
#define PIN_EBI_NCS0_PIO  PIOB
#define PIN_EBI_NCS0_ID  ID_PIOB
#define PIN_EBI_NCS0_TYPE PIO_PERIPH_A
#define PIN_EBI_NCS0_ATTR PIO_PULLUP
/** EBI address bus pins  */
#define PIN_EBI_ADDR_BUS_A0 PIO_PB7_IDX
#define PIN_EBI_ADDR_BUS_NBS0 PIO_PB7_IDX
#define PIN_EBI_ADDR_BUS_A1     PIO_PB8_IDX
#define PIN_EBI_ADDR_BUS_FLAG1  PIO_PERIPH_B | PIO_PULLUP
#define PIN_EBI_ADDR_BUS_NBS1 PIO_PC15_IDX
#define PIN_EBI_ADDR_BUS_A2     PIO_PC0_IDX
#define PIN_EBI_ADDR_BUS_A3     PIO_PC1_IDX
#define PIN_EBI_ADDR_BUS_A4     PIO_PC2_IDX
#define PIN_EBI_ADDR_BUS_A5     PIO_PC3_IDX
#define PIN_EBI_ADDR_BUS_A6     PIO_PC4_IDX
#define PIN_EBI_ADDR_BUS_A7     PIO_PC5_IDX
#define PIN_EBI_ADDR_BUS_A8     PIO_PC6_IDX
#define PIN_EBI_ADDR_BUS_A9     PIO_PC7_IDX
#define PIN_EBI_ADDR_BUS_A10   PIO_PC8_IDX
#define PIN_EBI_ADDR_BUS_A11   PIO_PC9_IDX
#define PIN_EBI_ADDR_BUS_A12   PIO_PC10_IDX
#define PIN_EBI_ADDR_BUS_A13   PIO_PC11_IDX
#define PIN_EBI_ADDR_BUS_A14   PIO_PC20_IDX
#define PIN_EBI_ADDR_BUS_A15   PIO_PC21_IDX
#define PIN_EBI_ADDR_BUS_A16   PIO_PC22_IDX
#define PIN_EBI_ADDR_BUS_A17   PIO_PC23_IDX
#define PIN_EBI_ADDR_BUS_A18   PIO_PC24_IDX
#define PIN_EBI_ADDR_BUS_A19   PIO_PC25_IDX
#define PIN_EBI_ADDR_BUS_A20   PIO_PC26_IDX
#define PIN_EBI_ADDR_BUS_FLAG2  PIO_PERIPH_A | PIO_PULLUP
/** EBI pin for LCD CS */
#define PIN_EBI_NCS2                 PIO_PC16_IDX
#define PIN_EBI_NCS2_FLAGS      PIO_PERIPH_A | PIO_PULLUP
#define PIN_EBI_NCS2_MASK  1 << 16
#define PIN_EBI_NCS2_PIO  PIOC
#define PIN_EBI_NCS2_ID  ID_PIOC
#define PIN_EBI_NCS2_TYPE PIO_PERIPH_A
#define PIN_EBI_NCS2_ATTR PIO_PULLUP
/** EBI pin for LCD RS */
#define PIN_EBI_LCD_RS                PIO_PB8_IDX
#define PIN_EBI_LCD_RS_FLAGS     PIO_PERIPH_B | PIO_PULLUP
#define PIN_EBI_LCD_RS_MASK  1 << 8
#define PIN_EBI_LCD_RS_PIO  PIOB
#define PIN_EBI_LCD_RS_ID  ID_PIOB
#define PIN_EBI_LCD_RS_TYPE PIO_PERIPH_B
#define PIN_EBI_LCD_RS_ATTR PIO_PULLUP

/** Backlight pin definition. */
#define BOARD_AAT31XX_SET_GPIO        PIO_PC19_IDX
#define BOARD_AAT31XX_SET_FLAGS       PIO_OUTPUT_0 | PIO_DEFAULT

/** Define HX8347A base address. */
#define BOARD_HX8347A_ADDR            0x62000000
/** Define HX8347A register select signal. */
#define BOARD_HX8347A_RS              (1 << 1)



//#define BOARD_NUM_OF_LED 0

//!// HSMCI pins definition.
/*! Number of slot connected on HSMCI interface */
#define SD_MMC_HSMCI_MEM_CNT          1
#define SD_MMC_HSMCI_SLOT_0_SIZE      8
#define PINS_HSMCI  {0x1f8, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}, \
		{1 << 3, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/** MCI MCCDA pin definition. */
#define PIN_HSMCI_MCCDA_GPIO       (PIO_PA4_IDX)
#define PIN_HSMCI_MCCDA_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCCK pin definition. */
#define PIN_HSMCI_MCCK_GPIO        (PIO_PA3_IDX)
#define PIN_HSMCI_MCCK_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCDA0 pin definition. */
#define PIN_HSMCI_MCDA0_GPIO       (PIO_PA5_IDX)
#define PIN_HSMCI_MCDA0_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCDA1 pin definition. */
#define PIN_HSMCI_MCDA1_GPIO       (PIO_PA6_IDX)
#define PIN_HSMCI_MCDA1_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCDA2 pin definition. */
#define PIN_HSMCI_MCDA2_GPIO       (PIO_PA7_IDX)
#define PIN_HSMCI_MCDA2_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCDA3 pin definition. */
#define PIN_HSMCI_MCDA3_GPIO       (PIO_PA8_IDX)
#define PIN_HSMCI_MCDA3_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** MCI MCDA4 pin definition. */
#define PIN_HSMCI_MCDA4_GPIO       (PIO_PC28_IDX)
#define PIN_HSMCI_MCDA4_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
/** MCI MCDA5 pin definition. */
#define PIN_HSMCI_MCDA5_GPIO       (PIO_PC29_IDX)
#define PIN_HSMCI_MCDA5_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
/** MCI MCDA6 pin definition. */
#define PIN_HSMCI_MCDA6_GPIO       (PIO_PC30_IDX)
#define PIN_HSMCI_MCDA6_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
/** MCI MCDA7 pin definition. */
#define PIN_HSMCI_MCDA7_GPIO       (PIO_PC31_IDX)
#define PIN_HSMCI_MCDA7_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)

//! SD/MMC card detect pin definition.
#define PIN_HSMCI_CD {PIO_PA25, PIOA, ID_PIOA, PIO_INPUT, PIO_PULLUP}
#define SD_MMC_0_CD_GPIO            (PIO_PA25_IDX)
#define SD_MMC_0_CD_PIO_ID          ID_PIOA
#define SD_MMC_0_CD_FLAGS           (PIO_INPUT | PIO_PULLUP)
#define SD_MMC_0_CD_DETECT_VALUE    0

//! Push button #0 definition.
#define PIN_PUSHBUTTON_1    {1 << 18, PIOA, ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
//! Push button #1 definition.
#define PIN_PUSHBUTTON_2    {1 << 19, PIOA, ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}

//! Push button #0 definition.
#define PUSHBUTTON_1_NAME    "USR-LEFT"
#define GPIO_PUSH_BUTTON_1    (PIO_PA18_IDX)
#define GPIO_PUSH_BUTTON_1_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEGLITCH | PIO_IT_RISE_EDGE)

#define PIN_PUSHBUTTON_1    {1 << 18, PIOA, ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
#define PIN_PUSHBUTTON_1_MASK 1 << 18
#define PIN_PUSHBUTTON_1_PIO PIOA
#define PIN_PUSHBUTTON_1_ID ID_PIOA
#define PIN_PUSHBUTTON_1_TYPE PIO_INPUT
#define PIN_PUSHBUTTON_1_ATTR PIO_DEGLITCH | PIO_PULLUP | PIO_IT_RISE_EDGE

//! Push button #1 definition.
#define PUSHBUTTON_2_NAME    "USR-RIGHT"
#define GPIO_PUSH_BUTTON_2    (PIO_PA19_IDX)
#define GPIO_PUSH_BUTTON_2_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEGLITCH | PIO_IT_FALL_EDGE)

#define PIN_PUSHBUTTON_2    {1 << 19, PIOA, ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
#define PIN_PUSHBUTTON_2_MASK 1 << 19
#define PIN_PUSHBUTTON_2_PIO PIOA
#define PIN_PUSHBUTTON_2_ID ID_PIOA
#define PIN_PUSHBUTTON_2_TYPE PIO_INPUT
#define PIN_PUSHBUTTON_2_ATTR PIO_DEGLITCH | PIO_PULLUP | PIO_IT_FALL_EDGE
//! List of all push button definitions.
#define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2

//! Timer Counter devices
#define PIN_TC0_TIOA0       (PIO_PA1_IDX)
#define PIN_TC0_TIOA0_MUX   (IOPORT_MODE_MUX_A)
#define PIN_TC0_TIOA0_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)

#define PIN_TC0_TIOA1       (PIO_PB5_IDX)
#define PIN_TC0_TIOA1_MUX   (IOPORT_MODE_MUX_A)
#define PIN_TC0_TIOA1_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)

#define PIN_TC0_TIOA1_PIO   PIOB
#define PIN_TC0_TIOA1_MASK  PIO_PB5
#define PIN_TC0_TIOA1_ID    ID_PIOB
#define PIN_TC0_TIOA1_TYPE  PIO_PERIPH_A
#define PIN_TC0_TIOA1_ATTR  PIO_DEFAULT

#define PIN_TC0_TIOA2       (PIO_PA30_IDX)
#define PIN_TC0_TIOA2_MUX   (IOPORT_MODE_MUX_B)
#define PIN_TC0_TIOA2_FLAGS (PIO_INPUT | PIO_DEFAULT)

#define PIN_TC0_TIOA2_PIO   PIOA
#define PIN_TC0_TIOA2_MASK  PIO_PA30
#define PIN_TC0_TIOA2_ID    ID_PIOA
#define PIN_TC0_TIOA2_TYPE  PIO_INPUT
#define PIN_TC0_TIOA2_ATTR  PIO_DEFAULT

/** SPI MISO pin definition. */
#define SPI_MISO_GPIO       (PIO_PA13_IDX)
#define SPI_MISO_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI MOSI pin definition. */
#define SPI_MOSI_GPIO       (PIO_PA14_IDX)
#define SPI_MOSI_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI SPCK pin definition. */
#define SPI_SPCK_GPIO       (PIO_PA15_IDX)
#define SPI_SPCK_FLAGS (PIO_PERIPH_A | PIO_DEFAULT)

/** SPI chip select 0 pin definition. (Only one configuration is possible) */
#define SPI_NPCS0_GPIO            (PIO_PA16_IDX)
#define SPI_NPCS0_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI chip select 1 pin definition. (multiple configurations are possible) */
#define SPI_NPCS1_PA0_GPIO        (PIO_PA0_IDX)
#define SPI_NPCS1_PA0_FLAGS       (PIO_PERIPH_B | PIO_DEFAULT)
#define SPI_NPCS1_PC3_GPIO        (PIO_PC3_IDX)
#define SPI_NPCS1_PC3_FLAGS       (PIO_PERIPH_B | PIO_DEFAULT)
#define SPI_NPCS1_PC19_GPIO       (PIO_PC19_IDX)
#define SPI_NPCS1_PC19_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
/** SPI chip select 2 pin definition. (multiple configurations are possible) */
#define SPI_NPCS2_PA1_GPIO        (PIO_PA1_IDX)
#define SPI_NPCS2_PA1_FLAGS       (PIO_PERIPH_B | PIO_DEFAULT)
#define SPI_NPCS2_PC4_GPIO        (PIO_PC4_IDX)
#define SPI_NPCS2_PC4_FLAGS       (PIO_PERIPH_B | PIO_DEFAULT)
#define SPI_NPCS2_PC14_GPIO       (PIO_PC14_IDX)
#define SPI_NPCS2_PC14_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
/** SPI chip select 3 pin definition. (multiple configurations are possible) */
#define SPI_NPCS3_PA19_GPIO       (PIO_PA19_IDX)
#define SPI_NPCS3_PA19_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
#define SPI_NPCS3_PC5_GPIO        (PIO_PC5_IDX)
#define SPI_NPCS3_PC5_FLAGS       (PIO_PERIPH_B | PIO_DEFAULT)


//! SSC pins definition.
/** SSC pin Transmitter Data (TD) */
#define PIN_SSC_TD        (PIO_PA26_IDX)
#define PIN_SSC_TD_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
/** SSC pin Transmitter Clock (TK) */
#define PIN_SSC_TK        (PIO_PA28_IDX)
#define PIN_SSC_TK_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
/** SSC pin Transmitter FrameSync (TF) */
#define PIN_SSC_TF        (PIO_PA30_IDX)
#define PIN_SSC_TF_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
/** SSC pin Receiver Data (RD) */
#define PIN_SSC_RD        (PIO_PA27_IDX)
#define PIN_SSC_RD_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
/** SSC pin Receiver Clock (RK) */
#define PIN_SSC_RK        (PIO_PA29_IDX)
#define PIN_SSC_RK_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
/** SSC pin Receiver FrameSync (RF) */
#define PIN_SSC_RF        (PIO_PA31_IDX)
#define PIN_SSC_RF_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)

//! PCK0
#define PIN_PCK0        (PIO_PA21_IDX)
#define PIN_PCK0_MUX    (IOPORT_MODE_MUX_B)
#define PIN_PCK0_FLAGS  (PIO_PERIPH_B | PIO_DEFAULT)

#define PIN_PCK_0_MASK PIO_PA21
#define PIN_PCK_0_PIO PIOA
#define PIN_PCK_0_ID ID_PIOA
#define PIN_PCK_0_TYPE PIO_PERIPH_B
#define PIN_PCK_0_ATTR PIO_DEFAULT

/** NandFlash pins definition: OE. */
#define PIN_EBI_NANDOE    (PIO_PB17_IDX)
#define PIN_EBI_NANDOE_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/** NandFlash pins definition: WE. */
#define PIN_EBI_NANDWE    (PIO_PB18_IDX)
#define PIN_EBI_NANDWE_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/** NandFlash pins definition: CLE. */
#define PIN_EBI_NANDCLE    (PIO_PB22_IDX)
#define PIN_EBI_NANDCLE_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/** NandFlash pins definition: ALE. */
#define PIN_EBI_NANDALE    (PIO_PB21_IDX)
#define PIN_EBI_NANDALE_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/** NandFlash pins definition: DATA. */
#define PIN_EBI_NANDIO_0    (PIO_PB9_IDX)
#define PIN_EBI_NANDIO_0_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_1    (PIO_PB10_IDX)
#define PIN_EBI_NANDIO_1_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_2    (PIO_PB11_IDX)
#define PIN_EBI_NANDIO_2_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_3    (PIO_PB12_IDX)
#define PIN_EBI_NANDIO_3_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_4    (PIO_PB13_IDX)
#define PIN_EBI_NANDIO_4_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_5    (PIO_PB14_IDX)
#define PIN_EBI_NANDIO_5_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_6    (PIO_PB15_IDX)
#define PIN_EBI_NANDIO_6_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_7    (PIO_PB16_IDX)
#define PIN_EBI_NANDIO_7_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_8    (PIO_PB25_IDX)
#define PIN_EBI_NANDIO_8_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_9    (PIO_PB26_IDX)
#define PIN_EBI_NANDIO_9_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_10    (PIO_PB27_IDX)
#define PIN_EBI_NANDIO_10_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_11    (PIO_PB28_IDX)
#define PIN_EBI_NANDIO_11_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_12    (PIO_PB29_IDX)
#define PIN_EBI_NANDIO_12_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_13    (PIO_PB30_IDX)
#define PIN_EBI_NANDIO_13_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_14    (PIO_PB31_IDX)
#define PIN_EBI_NANDIO_14_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

#define PIN_EBI_NANDIO_15    (PIO_PB6_IDX)
#define PIN_EBI_NANDIO_15_FLAGS    (PIO_PERIPH_B | PIO_PULLUP)

/** Nandflash chip enable pin definition. */
#define PIN_NF_CE_IDX    (PIO_PC12_IDX)
#define PIN_NF_CE_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/** Nandflash ready/busy pin definition. */
#define PIN_NF_RB_IDX    (PIO_PB24_IDX)
#define PIN_NF_RB_FLAGS    (PIO_PERIPH_A | PIO_PULLUP)

/* Chip select number for nand */
#define BOARD_NAND_CS      1

/** Address for transferring command bytes to the nandflash. */
#define BOARD_NF_COMMAND_ADDR   0x60000000
/** Address for transferring address bytes to the nandflash. */
#define BOARD_NF_ADDRESS_ADDR   0x61200000
/** Address for transferring data bytes to the nandflash. */
#define BOARD_NF_DATA_ADDR      0x61000000
/* Bus width for NAND */
#define CONF_NF_BUSWIDTH    16
/* SMC NFC using five address cycle */
#define CONF_NF_NEED_FIVE_ADDRESS_CYCLES    1
/* Access timing for NAND */
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
/* Support DMA */
#define CONF_NF_USE_DMA
#ifdef CONF_NF_USE_DMA
/* DMA channel used for NF */
#define CONF_NF_DMA_CHANNEL    0
#endif

/** TWI0 pins definition */
#define TWI0_DATA_GPIO   PIO_PA9_IDX
#define TWI0_DATA_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
#define TWI0_CLK_GPIO    PIO_PA10_IDX
#define TWI0_CLK_FLAGS   (PIO_PERIPH_A | PIO_DEFAULT)

/** TWI1 pins definition */
#define TWI1_DATA_GPIO   PIO_PA24_IDX
#define TWI1_DATA_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
#define TWI1_CLK_GPIO    PIO_PA25_IDX
#define TWI1_CLK_FLAGS   (PIO_PERIPH_A | PIO_DEFAULT)

//! USART0
#define PIN_USART0_RXD    {0x1 << 19, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_RXD_IDX        (PIO_PA19_IDX)
#define PIN_USART0_RXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART0_TXD    {0x1 << 18, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_TXD_IDX        (PIO_PA18_IDX)
#define PIN_USART0_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART0_CTS    {0x1 << 8, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_CTS_IDX        (PIO_PA8_IDX)
#define PIN_USART0_CTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART0_RTS    {0x1 << 7, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_RTS_IDX        (PIO_PA7_IDX)
#define PIN_USART0_RTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART0_SCK    {0x1 << 17, PIOA,ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_SCK_IDX        (PIO_PA17_IDX)
#define PIN_USART0_SCK_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)

//! USART1
#define PIN_USART1_RXD    {0x1 << 21, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_RXD_IDX        (PIO_PA21_IDX)
#define PIN_USART1_RXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART1_TXD    {0x1 << 20, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_TXD_IDX        (PIO_PA20_IDX)
#define PIN_USART1_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART1_CTS    {0x1 << 23, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
#define PIN_USART1_CTS_IDX        (PIO_PA23_IDX)
#define PIN_USART1_CTS_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
#define PIN_USART1_RTS    {0x1 << 22, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
#define PIN_USART1_RTS_IDX        (PIO_PA22_IDX)
#define PIN_USART1_RTS_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)
#define PIN_USART1_EN     {0x1 << 24, PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
#define PIN_USART1_EN_IDX         (PIO_PA24_IDX)
#define PIN_USART1_EN_FLAGS       (PIO_OUTPUT_0 | PIO_DEFAULT)
#define PIN_USART1_SCK    {0x1 << 24, PIOA, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
#define PIN_USART1_SCK_IDX        (PIO_PA24_IDX)
#define PIN_USART1_SCK_FLAGS      (PIO_PERIPH_B | PIO_DEFAULT)

//! USB VBus monitoring pin definition.
#define PIN_USB_VBUS    {1 << 0, PIOA, ID_PIOA, PIO_INPUT, PIO_DEFAULT}
#define USB_VBUS_FLAGS    (PIO_INPUT | PIO_DEBOUNCE | PIO_IT_EDGE)
#define USB_VBUS_PIN_IRQn (PIOA_IRQn)
#define USB_VBUS_PIN      (PIO_PA0_IDX)
#define USB_VBUS_PIO_ID   (ID_PIOA)
#define USB_VBUS_PIO_MASK (PIO_PA0)
/* This pin can not be used as fast wakeup source such as
 * USB_VBUS_WKUP PMC_FSMR_FSTT7 */

#define CONSOLE_UART               UART
#define CONSOLE_UART_ID            ID_UART

/* RE pin. */
#define PIN_RE_IDX                 PIN_USART1_CTS_IDX
#define PIN_RE_FLAGS               (PIO_OUTPUT_0 | PIO_DEFAULT)

/* IRDA SD pin. */
#define PIN_IRDA_SD_IDX            PIN_USART1_CTS_IDX
#define PIN_IRDA_SD_FLAGS          (PIO_OUTPUT_1 | PIO_DEFAULT)

/* TXD pin configuration. */
#define PIN_USART_TXD_IDX          PIN_USART1_TXD_IDX
#define PIN_USART_TXD_FLAGS        (PIO_PERIPH_A | PIO_DEFAULT)
#define PIN_USART_TXD_IO_FLAGS     (PIO_OUTPUT_0 | PIO_DEFAULT)

/* ISO7816 example relate PIN definition. */
#define ISO7816_USART_ID           ID_USART0
#define ISO7816_USART              USART0
#define PIN_ISO7816_RST_IDX        PIO_PA15_IDX
#define PIN_ISO7816_RST_FLAG       (PIO_OUTPUT_0 | PIO_DEFAULT)

/* WM8731 Slave address */
#define WM8731_SLAVE_ADDRESS        0x1b

/** TWI interface for WM8731 */
#define TWI_WM8731   TWI0

/* SSD1306 Slave address */
#define SSD1306_SLAVE_ADDRESS       0x3c

/** TWI interface for WM8731 */
#define TWI_SSD1306  TWI0

#endif  // _USER_BOARD_H_
