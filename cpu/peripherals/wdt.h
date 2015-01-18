/**
 * \file
 *
 * \brief Watchdog Timer (WDT) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_WDT_H_
#define _CPU_PERIPHERALS_WDT_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup WDT Watchdog Timer (WDT) User Interface */

/** \defgroup WDT_UI_REG User Interface Registers
 * \ingroup WDT
 * \{
 */
#define WDT_CR   (*(reg_wo_t*)(WDT+0x0000)) //!< \ref WDT_CR
#define WDT_MR   (*(reg_rw_t*)(WDT+0x0004)) //!< \ref WDT_MR
#define WDT_SR   (*(reg_ro_t*)(WDT+0x0008)) //!< \ref WDT_SR
/* \} */

/** \defgroup WDT_CR Control Register Bit Definitions
 * \ingroup WDT
 */

/** \defgroup WDT_CR_WDRSTT WDRSTT : Watchdog Reset
 * \ingroup WDT_CR
 * \{
 */
#define WDT_CR_WDRSTT     (0x1 << 0) //!< WDRSTT Value
#define WDT_CR_WDRSTT_Pos (0)        //!< WDRSTT Position
#define WDT_CR_WDRSTT_Len (1)        //!< WDRSTT Field Length
#define WDT_CR_WDRSTT_Msk (0x1 << 0) //!< WDRSTT Mask
/* \} */
/** \defgroup WDT_CR_KEY KEY: Password
 * \ingroup WDT_CR
 * \{
 */
#define WDT_CR_KEY     (0xA5 << 24) //!< KEY Value
#define WDT_CR_KEY_Pos (24)         //!< KEY Position
#define WDT_CR_KEY_Len (8)          //!< KEY Field Length
#define WDT_CR_KEY_Msk (0xFF << 24) //!< KEY Mask
/* \} */

/** \defgroup WDT_MR Mode Register Bit Definitions
 * \ingroup WDT
 */

/** \defgroup WDT_MR_WDV WDV: Watchdog Counter Value
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDV(v)  (((v) & 0xFFF) << 0) //!< WDV Value
#define WDT_MR_WDV_Pos (0)                  //!< WDV Position
#define WDT_MR_WDV_Len (12)                 //!< WDV Field Length
#define WDT_MR_WDV_Msk (0xFFF << 0)         //!< WDV Mask
/* \} */
/** \defgroup WDT_MR_WDRFIEN WDRFIEN: Watchdog Fault Interrupt Enable
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDRFIEN     (0x1 << 12) //!< WDRFIEN Value
#define WDT_MR_WDRFIEN_Pos (12)        //!< WDRFIEN Position
#define WDT_MR_WDRFIEN_Len (1)         //!< WDRFIEN Field Length
#define WDT_MR_WDRFIEN_Msk (0x1 << 12) //!< WDRFIEN Mask
/* \} */
/** \defgroup WDT_MR_WDRSTEN WDRSTEN: Watchdog Reset Enable
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDRSTEN     (0x1 << 13) //!< WDRSTEN Value
#define WDT_MR_WDRSTEN_Pos (13)        //!< WDRSTEN Position
#define WDT_MR_WDRSTEN_Len (1)         //!< WDRSTEN Field Length
#define WDT_MR_WDRSTEN_Msk (0x1 << 13) //!< WDRSTEN Mask
/* \} */
/** \defgroup WDT_MR_WDRPROC WDRPROC: Watchdog Reset Processor
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDRPROC     (0x1 << 14) //!< WDRPROC Value
#define WDT_MR_WDRPROC_Pos (14)        //!< WDRPROC Position
#define WDT_MR_WDRPROC_Len (1)         //!< WDRPROC Field Length
#define WDT_MR_WDRPROC_Msk (0x1 << 14) //!< WDRPROC Mask
/* \} */
/** \defgroup WDT_MR_WDDIS WDDIS: Watchdog Disable
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDDIS     (0x1 << 15) //!< WDDIS Value
#define WDT_MR_WDDIS_Pos (15)        //!< WDDIS Position
#define WDT_MR_WDDIS_Len (1)         //!< WDDIS Field Length
#define WDT_MR_WDDIS_Msk (0x1 << 15) //!< WDDIS Mask
/* \} */
/** \defgroup WDT_MR_WDD WDD: Watchdog Delta Value
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDD(v)  (((v) & 0xFFF) << 16) //!< WDD Value
#define WDT_MR_WDD_Pos (16)                  //!< WDD Position
#define WDT_MR_WDD_Len (12)                  //!< WDD Field Length
#define WDT_MR_WDD_Msk (0xFFF << 16)         //!< WDD Mask
/* \} */
/** \defgroup WDT_MR_WDDBGHLT WDDBGHLT: Watchdog Debug Halt
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDDBGHLT     (0x1 << 28) //!< WDDBGHLT Value
#define WDT_MR_WDDBGHLT_Pos (28)        //!< WDDBGHLT Position
#define WDT_MR_WDDBGHLT_Len (1)         //!< WDDBGHLT Field Length
#define WDT_MR_WDDBGHLT_Msk (0x1 << 28) //!< WDDBGHLT Mask
/* \} */
/** \defgroup WDT_MR_WDIDLEHLT WDIDLEHLT: Watchdog Idle Halt
 * \ingroup WDT_MR
 * \{
 */
#define WDT_MR_WDIDLEHLT     (0x1 << 29) //!< WDIDLEHLT Value
#define WDT_MR_WDIDLEHLT_Pos (29)        //!< WDIDLEHLT Position
#define WDT_MR_WDIDLEHLT_Len (1)         //!< WDIDLEHLT Field Length
#define WDT_MR_WDIDLEHLT_Msk (0x1 << 29) //!< WDIDLEHLT Mask
/* \} */

/** \defgroup WDT_SR Status Register Bit Definitions
 * \ingroup WDT
 */

/** \defgroup WDT_SR_WDUNF WDUNF: Watchdog Underflow
 * \ingroup WDT_SR
 * \{
 */
#define WDT_SR_WDUNF     (0x1 << 0) //!< WDUNF Value
#define WDT_SR_WDUNF_Pos (0)        //!< WDUNF Position
#define WDT_SR_WDUNF_Len (1)        //!< WDUNF Field Length
#define WDT_SR_WDUNF_Msk (0x1 << 0) //!< WDUNF Mask
/* \} */
/** \defgroup WDT_SR_WDERR WDERR: Watchdog Error
 * \ingroup WDT_SR
 * \{
 */
#define WDT_SR_WDERR     (0x1 << 1) //!< WDERR Value
#define WDT_SR_WDERR_Pos (1)        //!< WDERR Position
#define WDT_SR_WDERR_Len (1)        //!< WDERR Field Length
#define WDT_SR_WDERR_Msk (0x1 << 1) //!< WDERR Mask
/* \} */

#endif // _CPU_PERIPHERALS_WDT_H_
