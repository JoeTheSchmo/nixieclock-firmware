/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_CORTEX_M3_SCB_H_
#define _CPU_CORTEX_M3_SCB_H_

#include "types.h"

/** \defgroup SCB System Control Block (SCB) User Interface */

/** \defgroup SCB_UI_REG User Interface Registers
 * \ingroup SCB
 * \{
 */
#define ACTLR            (*(reg_rw_t*)(0xE000E008)) //!< \ref ACTLR
#define CPUID            (*(reg_ro_t*)(0xE000ED00)) //!< \ref CPUID
#define ICSR             (*(reg_rw_t*)(0xE000ED04)) //!< \ref ICSR
#define VTOR             (*(reg_rw_t*)(0xE000ED08)) //!< \ref VTOR
#define AIRCR            (*(reg_rw_t*)(0xE000ED0C)) //!< \ref AIRCR
#define SCR              (*(reg_rw_t*)(0xE000ED10)) //!< \ref SCR
#define CCR              (*(reg_rw_t*)(0xE000ED14)) //!< \ref CCR
#define SHPR1            (*(reg_rw_t*)(0xE000ED18)) //!< \ref SHPR1
#define SHPR2            (*(reg_rw_t*)(0xE000ED1C)) //!< \ref SHPR2
#define SHPR3            (*(reg_rw_t*)(0xE000ED20)) //!< \ref SHPR3
#define SHCRS            (*(reg_rw_t*)(0xE000ED24)) //!< \ref SHCRS
#define CFSR             (*(reg_rw_t*)(0xE000ED28)) //!< \ref CFSR
/*
#define MMSR             (*(reg_rw_t*)(0xE000ED28)) //!< \ref MMSR
#define BFSR             (*(reg_rw_t*)(0xE000ED29)) //!< \ref BFSR
#define UFSR             (*(reg_rw_t*)(0xE000ED2A)) //!< \ref UFSR
*/
#define HFSR             (*(reg_rw_t*)(0xE000ED2C)) //!< \ref HFSR
#define MMAR             (*(reg_rw_t*)(0xE000ED34)) //!< \ref MMAR
#define BFAR             (*(reg_rw_t*)(0xE000ED38)) //!< \ref BFAR
#define AFSR             (*(reg_rw_t*)(0xE000ED3C)) //!< \ref AFSR
/* \} */

/** \defgroup ACTLR Auxiliary Control Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup CPUID CPUID Base Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup ICSR Interrupt Control and State Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup VTOR Vector Table Offset Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup AIRCR Application Interrupt and Reset Control Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SCR System Control Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SCR_SLEEPONEXIT SLEEPONEXIT: Indicates sleep-on-exit when returning from Handler mode to Thread mode
 * \ingroup SCR
 * \{
 */
#define SCR_SLEEPONEXIT     (0x1 << 1) //!< SLEEPONEXIT Value
#define SCR_SLEEPONEXIT_Pos (1)        //!< SLEEPONEXIT Position
#define SCR_SLEEPONEXIT_Len (1)        //!< SLEEPONEXIT Field Length
#define SCR_SLEEPONEXIT_Msk (0x1 << 1) //!< SLEEPONEXIT Mask
/* \} */

/** \defgroup SCR_SLEEPDEEP SLEEPDEEP: Controls whether the processor uses sleep or deep sleep as its low power mode
 * \ingroup SCR
 * \{
 */
#define SCR_SLEEPDEEP     (0x1 << 2) //!< SLEEPDEEP Value
#define SCR_SLEEPDEEP_Pos (2)        //!< SLEEPDEEP Position
#define SCR_SLEEPDEEP_Len (1)        //!< SLEEPDEEP Field Length
#define SCR_SLEEPDEEP_Msk (0x1 << 2) //!< SLEEPDEEP Mask
/* \} */

/** \defgroup SCR_SEVONPEND SEVONPEND: Send Event on Pending bit
 * \ingroup SCR
 * \{
 */
#define SCR_SEVONPEND     (0x1 << 4) //!< SEVONPEND Value
#define SCR_SEVONPEND_Pos (4)        //!< SEVONPEND Position
#define SCR_SEVONPEND_Len (1)        //!< SEVONPEND Field Length
#define SCR_SEVONPEND_Msk (0x1 << 4) //!< SEVONPEND Mask
/* \} */

/** \defgroup CCR Configuration and Control Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SHPR1 System Handler Priority Register 1 Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SHPR2 System Handler Priority Register 2 Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SHPR3 System Handler Priority Register 3 Bit Definitions
 * \ingroup SCB
 */

/** \defgroup SHCRS System Handler Control and State Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup CFSR Configurable Fault Status Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup HFSR Hard Fault Status Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup MMAR Memory Management Fault Address Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup BFAR Bus Fault Address Register Bit Definitions
 * \ingroup SCB
 */

/** \defgroup AFSR Auxiliary Fault Status Register Bit Definitions
 * \ingroup SCB
 */

#endif // _CPU_CORTEX_M3_SCB_H_