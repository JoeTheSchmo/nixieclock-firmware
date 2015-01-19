/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_COMMON_H_
#define _CPU_COMMON_H_

/** \defgroup SAM3U4E Atmel SAM3U4E */

/** \defgroup SAM3U4E_PADDR Peripheral Address Table
 * \ingroup SAM3U4E
 * \{
 */
#define MCI    ((void*)(0x40000000U)) //!< MCI Base Address
#define SSC    ((void*)(0x40004000U)) //!< SSC Base Address
#define SPI    ((void*)(0x40008000U)) //!< SPI Base Address
#define TC0    ((void*)(0x40080000U)) //!< TC0 Base Address
#define TC1    ((void*)(0x40000040U)) //!< TC1 Base Address
#define TC2    ((void*)(0x40000080U)) //!< TC2 Base Address
#define TWI0   ((void*)(0x40084000U)) //!< TWI0 Base Address
#define TWI1   ((void*)(0x40088000U)) //!< TWI1 Base Address
#define PWM    ((void*)(0x4008C000U)) //!< PWM Base Address
#define USART0 ((void*)(0x40090000U)) //!< USART0 Base Address
#define USART1 ((void*)(0x40094000U)) //!< USART1 Base Address
#define USART2 ((void*)(0x40098000U)) //!< USART2 Base Address
#define USART3 ((void*)(0x4009C000U)) //!< USART3 Base Address
#define UDPHS  ((void*)(0x400A4000U)) //!< UDPHS Base Address
#define ADC12B ((void*)(0x400A8000U)) //!< ADC12B Base Address
#define ADC    ((void*)(0x400AC000U)) //!< ADC Base Address
#define DMAC   ((void*)(0x400B0000U)) //!< DMAC Base Address
/* \} */


/** \defgroup SAM3U4E_SADDR System Controller Address Table
 * \ingroup SAM3U4E
 * \{
 */
#define SMC    ((void*)(0x400E0000U)) //!< SMC Base Address
#define MATRIX ((void*)(0x400E0200U)) //!< MATRIX Base Address
#define PMC    ((void*)(0x400E0400U)) //!< PMC Base Address
#define UART   ((void*)(0x400E0600U)) //!< UART Base Address
#define CHIPID ((void*)(0x400E0740U)) //!< CHIPID Base Address
#define EEFC0  ((void*)(0x400E0800U)) //!< EEFC0 Base Address
#define EEFC1  ((void*)(0x400E0A00U)) //!< EEFC1 Base Address
#define PIOA   ((void*)(0x400E0C00U)) //!< PIOA Base Address
#define PIOB   ((void*)(0x400E0E00U)) //!< PIOB Base Address
#define PIOC   ((void*)(0x400E1000U)) //!< PIOC Base Address
#define RSTC   ((void*)(0x400E1200U)) //!< RSTC Base Address
#define SUPC   ((void*)(0x400E1210U)) //!< SUPC Base Address
#define RTT    ((void*)(0x400E1230U)) //!< RTT Base Address
#define WDT    ((void*)(0x400E1250U)) //!< WDT Base Address
#define RTC    ((void*)(0x400E1260U)) //!< RTC Base Address
#define GPBR   ((void*)(0x400E1290U)) //!< GPBR Base Address
/* \} */

/** \defgroup SAM3U4E_PID Peripheral Identifiers
 * \ingroup SAM3U4E
 * \{
 */
#define PMC_ID_SUPC    0 //!< SUPC Peripheral ID
#define PMC_ID_RSTC    1 //!< RSTC Peripheral ID
#define PMC_ID_RTC     2 //!< RTC Peripheral ID
#define PMC_ID_RTT     3 //!< RTT Peripheral ID
#define PMC_ID_WDT     4 //!< WDT Peripheral ID
#define PMC_ID_PMC     5 //!< PMC Peripheral ID
#define PMC_ID_EEFC0   6 //!< EEFC0 Peripheral ID
#define PMC_ID_EEFC1   7 //!< EEFC1 Peripheral ID
#define PMC_ID_UART    8 //!< UART Peripheral ID
#define PMC_ID_SMC     9 //!< SMC Peripheral ID
#define PMC_ID_PIOA   10 //!< PIOA Peripheral ID
#define PMC_ID_PIOB   11 //!< PIOB Peripheral ID
#define PMC_ID_PIOC   12 //!< PIOC Peripheral ID
#define PMC_ID_USART0 13 //!< USART0 Peripheral ID
#define PMC_ID_USART1 14 //!< USART1 Peripheral ID
#define PMC_ID_USART2 15 //!< USART2 Peripheral ID
#define PMC_ID_USART3 16 //!< USART3 Peripheral ID
#define PMC_ID_HSMCI  17 //!< HSMCI Peripheral ID
#define PMC_ID_TWI0   18 //!< TWI0 Peripheral ID
#define PMC_ID_TWI1   19 //!< TWI1 Peripheral ID
#define PMC_ID_SPI    20 //!< SPI Peripheral ID
#define PMC_ID_SSC    21 //!< SSC Peripheral ID
#define PMC_ID_TC0    22 //!< TC0 Peripheral ID
#define PMC_ID_TC1    23 //!< TC1 Peripheral ID
#define PMC_ID_TC2    24 //!< TC2 Peripheral ID
#define PMC_ID_PWM    25 //!< PWM Peripheral ID
#define PMC_ID_ADC12B 26 //!< ADC12B Peripheral ID
#define PMC_ID_ADC    27 //!< ADC Peripheral ID
#define PMC_ID_DMAC   28 //!< DMAC Peripheral ID
#define PMC_ID_UDPHS  29 //!< UDPHS Peripheral ID
/* \} */

#endif // _CPU_COMMON_H_
