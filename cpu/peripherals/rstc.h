/**
 * \file
 *
 * \brief Reset Controller (RSTC) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_RSTC_H_
#define _CPU_PERIPHERALS_RSTC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup RSTC Reset Controller (RSTC) User Interface */

/** \defgroup RSTC_UI_REG User Interface Registers
 * \ingroup RSTC
 * \{
 */
#define RSTC_CR          (*(reg_wo_t*)(RSTC+0x0000)) //!< \ref RSTC_CR
#define RSTC_SR          (*(reg_ro_t*)(RSTC+0x0004)) //!< \ref RSTC_SR
#define RSTC_MR          (*(reg_rw_t*)(RSTC+0x0008)) //!< \ref RSTC_MR
/* \} */

/** \defgroup RSTC_CR Control Register Bit Definitions
 * \ingroup RSTC
 */

/** \defgroup RSTC_CR_PROCRST PROCRST: Processor Reset
 * \ingroup RSTC_CR
 * \{
 */
#define RSTC_CR_PROCRST     (0x1 << 0) //!< PROCRST Value
#define RSTC_CR_PROCRST_Pos (0)        //!< PROCRST Position
#define RSTC_CR_PROCRST_Len (1)        //!< PROCRST Field Length
#define RSTC_CR_PROCRST_Msk (0x1 << 0) //!< PROCRST Mask
/* \} */
/** \defgroup RSTC_CR_PERRST PERRST: Peripheral Reset
 * \ingroup RSTC_CR
 * \{
 */
#define RSTC_CR_PERRST     (0x1 << 2) //!< PERRST Value
#define RSTC_CR_PERRST_Pos (2)        //!< PERRST Position
#define RSTC_CR_PERRST_Len (1)        //!< PERRST Field Length
#define RSTC_CR_PERRST_Msk (0x1 << 2) //!< PERRST Mask
/* \} */
/** \defgroup RSTC_CR_EXTRST EXTRST: External Reset
 * \ingroup RSTC_CR
 * \{
 */
#define RSTC_CR_EXTRST     (0x1 << 3) //!< EXTRST Value
#define RSTC_CR_EXTRST_Pos (3)        //!< EXTRST Position
#define RSTC_CR_EXTRST_Len (1)        //!< EXTRST Field Length
#define RSTC_CR_EXTRST_Msk (0x1 << 3) //!< EXTRST Mask
/* \} */
/** \defgroup RSTC_CR_KEY KEY: Password (0xA5)
 * \ingroup RSTC_CR
 * \{
 */
#define RSTC_CR_KEY     (0xA5 << 24) //!< KEY Value
#define RSTC_CR_KEY_Pos (24)         //!< KEY Position
#define RSTC_CR_KEY_Len (8)          //!< KEY Field Length
#define RSTC_CR_KEY_Msk (0xFF << 24) //!< KEY Mask
/* \} */

/** \defgroup RSTC_SR Status Register Bit Definitions
 * \ingroup RSTC
 */

/** \defgroup RSTC_SR_URSTS URSTS: User Reset Status
 * \ingroup RSTC_SR
 * \{
 */
#define RSTC_SR_URSTS     (0x1 << 0) //!< URSTS Value
#define RSTC_SR_URSTS_Pos (0)        //!< URSTS Position
#define RSTC_SR_URSTS_Len (1)        //!< URSTS Field Length
#define RSTC_SR_URSTS_Msk (0x1 << 0) //!< URSTS Mask
/* \} */
/** \defgroup RSTC_SR_RSTTYP RSTTYP: Reset Type
 * \ingroup RSTC_SR
 * \{
 */
#define RSTC_SR_RSTTYP(v)  (((v) & 0x7) << 8) //!< RSTTYP Value
#define RSTC_SR_RSTTYP_Pos (8)                //!< RSTTYP Position
#define RSTC_SR_RSTTYP_Len (3)                //!< RSTTYP Field Length
#define RSTC_SR_RSTTYP_Msk (0x7 << 8)         //!< RSTTYP Mask
#define RSTC_SR_RSTTYP_GENERAL (0)            //!< RSTTYP General Reset - First power-up reset
#define RSTC_SR_RSTTYP_BACKUP (1)             //!< RSTTYP Backup Reset - Return from backup mode
#define RSTC_SR_RSTTYP_WATCHDOG (2)           //!< RSTTYP Watchdog Reset - Watchdog Fault occurred
#define RSTC_SR_RSTTYP_SOFTWARE (3)           //!< RSTTYP Software Reset - Processor reset required by the software
#define RSTC_SR_RSTTYP_USER (4)               //!< RSTTYP User Reset - NRST pin detected low
/* \} */
/** \defgroup RSTC_SR_NRSTL NRSTL: NRST Pin Level
 * \ingroup RSTC_SR
 * \{
 */
#define RSTC_SR_NRSTL     (0x1 << 16) //!< NRSTL Value
#define RSTC_SR_NRSTL_Pos (16)        //!< NRSTL Position
#define RSTC_SR_NRSTL_Len (1)         //!< NRSTL Field Length
#define RSTC_SR_NRSTL_Msk (0x1 << 16) //!< NRSTL Mask
/* \} */
/** \defgroup RSTC_SR_SRCMP SRCMP: Software Reset Command in Progress
 * \ingroup RSTC_SR
 * \{
 */
#define RSTC_SR_SRCMP     (0x1 << 17) //!< SRCMP Value
#define RSTC_SR_SRCMP_Pos (17)        //!< SRCMP Position
#define RSTC_SR_SRCMP_Len (1)         //!< SRCMP Field Length
#define RSTC_SR_SRCMP_Msk (0x1 << 17) //!< SRCMP Mask
/* \} */

/** \defgroup RSTC_MR Mode Register Bit Definitions
 * \ingroup RSTC
 */

/** \defgroup RSTC_MR_URSTEN URSTEN: User Reset Enable
 * \ingroup RSTC_MR
 * \{
 */
#define RSTC_MR_URSTEN     (0x1 << 0) //!< URSTEN Value
#define RSTC_MR_URSTEN_Pos (0)        //!< URSTEN Position
#define RSTC_MR_URSTEN_Len (1)        //!< URSTEN Field Length
#define RSTC_MR_URSTEN_Msk (0x1 << 0) //!< URSTEN Mask
/* \} */
/** \defgroup RSTC_MR_URSTIEN URSTIEN: User Reset Interrupt Enable
 * \ingroup RSTC_MR
 * \{
 */
#define RSTC_MR_URSTIEN     (0x1 << 4) //!< URSTIEN Value
#define RSTC_MR_URSTIEN_Pos (4)        //!< URSTIEN Position
#define RSTC_MR_URSTIEN_Len (1)        //!< URSTIEN Field Length
#define RSTC_MR_URSTIEN_Msk (0x1 << 4) //!< URSTIEN Mask
/* \} */
/** \defgroup RSTC_MR_ERSTL ERSTL: External Reset Length
 * \ingroup RSTC_MR
 * \{
 */
#define RSTC_MR_ERSTL(v)  (((v) & 0xF) << 8) //!< ERSTL Value
#define RSTC_MR_ERSTL_Pos (8)                //!< ERSTL Position
#define RSTC_MR_ERSTL_Len (4)                //!< ERSTL Field Length
#define RSTC_MR_ERSTL_Msk (0xF << 8)         //!< ERSTL Mask
/* \} */
/** \defgroup RSTC_MR_KEY KEY: Password
 * \ingroup RSTC_MR
 * \{
 */
#define RSTC_MR_KEY     (0xA5 << 24) //!< KEY Value
#define RSTC_MR_KEY_Pos (24)         //!< KEY Position
#define RSTC_MR_KEY_Len (8)          //!< KEY Field Length
#define RSTC_MR_KEY_Msk (0xFF << 24) //!< KEY Mask
/* \} */

#endif // _CPU_PERIPHERALS_RSTC_H_
