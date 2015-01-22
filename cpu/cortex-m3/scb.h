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

/** \defgroup AIRCR_VECTKEYSTAT VECTKEYSTAT: Confirmation value on read
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_VECTKEYSTAT     (0xFA050000) //!< VECTKEYSTAT Value
#define AIRCR_VECTKEYSTAT_Pos (16)         //!< VECTKEYSTAT Position
#define AIRCR_VECTKEYSTAT_Len (16)         //!< VECTKEYSTAT Field Length
#define AIRCR_VECTKEYSTAT_Msk (0xFFFF0000) //!< VECTKEYSTAT Mask
/* \} */

/** \defgroup AIRCR_VECTKEY VECTKEY: Password must be present on write
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_VECTKEY     (0x05FA0000) //!< VECTKEY Value
#define AIRCR_VECTKEY_Pos (16)         //!< VECTKEY Position
#define AIRCR_VECTKEY_Len (16)         //!< VECTKEY Field Length
#define AIRCR_VECTKEY_Msk (0xFFFF0000) //!< VECTKEY Mask
/* \} */

/** \defgroup AIRCR_ENDIANESS ENDIANESS: Data endianness bit
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_ENDIANESS     (1 << 15) //!< ENDIANESS Value
#define AIRCR_ENDIANESS_Pos (15)      //!< ENDIANESS Position
#define AIRCR_ENDIANESS_Len (1)       //!< ENDIANESS Field Length
#define AIRCR_ENDIANESS_Msk (1 << 15) //!< ENDIANESS Mask
/* \} */

/** \defgroup AIRCR_PRIGROUP PRIGROUP: Interrupt priority grouping field
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_PRIGROUP(v)  (((v) & 0x7) << 8) //!< PRIGROUP Value
#define AIRCR_PRIGROUP_Pos (8)                //!< PRIGROUP Position
#define AIRCR_PRIGROUP_Len (3)                //!< PRIGROUP Field Length
#define AIRCR_PRIGROUP_Msk (0x7 << 8)         //!< PRIGROUP Mask
/* \} */

/** \defgroup AIRCR_SYSRESETREQ SYSRESETREQ: System reset request
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_SYSRESETREQ     (1 << 2) //!< SYSRESETREQ Value
#define AIRCR_SYSRESETREQ_Pos (2)      //!< SYSRESETREQ Position
#define AIRCR_SYSRESETREQ_Len (1)      //!< SYSRESETREQ Field Length
#define AIRCR_SYSRESETREQ_Msk (1 << 2) //!< SYSRESETREQ Mask
/* \} */

/** \defgroup AIRCR_VECTCLRACTIVE VECTCLRACTIVE: Reserved for Debug use
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_VECTCLRACTIVE     (1 << 1) //!< VECTCLRACTIVE Value
#define AIRCR_VECTCLRACTIVE_Pos (1)      //!< VECTCLRACTIVE Position
#define AIRCR_VECTCLRACTIVE_Len (1)      //!< VECTCLRACTIVE Field Length
#define AIRCR_VECTCLRACTIVE_Msk (1 << 1) //!< VECTCLRACTIVE Mask
/* \} */

/** \defgroup AIRCR_VECTRESET VECTRESET: Reserved for Debug use
 * \ingroup AIRCR
 * \{
 */
#define AIRCR_VECTRESET     (1 << 0) //!< VECTRESET Value
#define AIRCR_VECTRESET_Pos (0)      //!< VECTRESET Position
#define AIRCR_VECTRESET_Len (1)      //!< VECTRESET Field Length
#define AIRCR_VECTRESET_Msk (1 << 0) //!< VECTRESET Mask
/* \} */

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