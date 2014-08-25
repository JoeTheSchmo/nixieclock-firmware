/**
 * \file
 *
 * \brief Enhanced Embedded Flash Controller (EEFC) User Interface
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_EEFC_H_
#define _CPU_PERIPHERALS_EEFC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup EEFC Enhanced Embedded Flash Controller (EEFC) User Interface */

/** \defgroup EEFC_UI_REG User Interface Registers
 * \ingroup EEFC
 * \{
 */
#define EEFC_FMR(EEFC) (*(reg_rw_t*)(EEFC+0x0000)) //!< \ref EEFC_FMR
#define EEFC_FCR(EEFC) (*(reg_wo_t*)(EEFC+0x0004)) //!< \ref EEFC_FCR
#define EEFC_FSR(EEFC) (*(reg_ro_t*)(EEFC+0x0008)) //!< \ref EEFC_FSR
#define EEFC_FRR(EEFC) (*(reg_ro_t*)(EEFC+0x000C)) //!< \ref EEFC_FRR
/* \} */

/** \defgroup EEFC_FMR Flash Mode Register Bit Definitions
 * \ingroup EEFC
 */

/** \defgroup EEFC_FMR_FRDY FRDY: Ready Interrupt Enable
 * \ingroup EEFC_FMR
 * \{
 */
#define EEFC_FMR_FRDY     (0x1 << 0) //!< FRDY Value
#define EEFC_FMR_FRDY_Pos (0)        //!< FRDY Position
#define EEFC_FMR_FRDY_Len (1)        //!< FRDY Field Length
#define EEFC_FMR_FRDY_Msk (0x1 << 0) //!< FRDY Mask
/* \} */
/** \defgroup EEFC_FMR_FWS FWS: Flash Wait State
 * \ingroup EEFC_FMR
 * \{
 */
#define EEFC_FMR_FWS(v)  (((v) & 0xF) << 8) //!< FWS Value
#define EEFC_FMR_FWS_Pos (8)                //!< FWS Position
#define EEFC_FMR_FWS_Len (4)                //!< FWS Field Length
#define EEFC_FMR_FWS_Msk (0xF << 8)         //!< FWS Mask
/* \} */
/** \defgroup EEFC_FMR_SCOD SCOD: Sequential Code Optimization Disable
 * \ingroup EEFC_FMR
 * \{
 */
#define EEFC_FMR_SCOD     (0x1 << 16) //!< SCOD Value
#define EEFC_FMR_SCOD_Pos (16)        //!< SCOD Position
#define EEFC_FMR_SCOD_Len (1)         //!< SCOD Field Length
#define EEFC_FMR_SCOD_Msk (0x1 << 16) //!< SCOD Mask
/* \} */
/** \defgroup EEFC_FMR_FAM FAM: Flash Access Mode
 * \ingroup EEFC_FMR
 * \{
 */
#define EEFC_FMR_FAM     (0x1 << 24) //!< FAM Value
#define EEFC_FMR_FAM_Pos (24)        //!< FAM Position
#define EEFC_FMR_FAM_Len (1)         //!< FAM Field Length
#define EEFC_FMR_FAM_Msk (0x1 << 24) //!< FAM Mask
/* \} */

/** \defgroup EEFC_FCR Flash Command Register Bit Definitions
 * \ingroup EEFC
 */

/** \defgroup EEFC_FCR_FCMD FCMD: Flash Command
 * \ingroup EEFC_FCR
 * \{
 */
#define EEFC_FCR_FCMD(v)  (((v) & 0x00FF) << 0) //!< FCMD Value
#define EEFC_FCR_FCMD_Pos (0)                   //!< FCMD Position
#define EEFC_FCR_FCMD_Len (8)                   //!< FCMD Field Length
#define EEFC_FCR_FCMD_Msk (0xFF << 0)           //!< FCMD Mask
/* \} */
/** \defgroup EFC_FCR_FARG FARG: Flash Command Argument
 * \ingroup EEFC_FCR
 * \{
 */
#define EEFC_FCR_FARG(v)  (((v) & 0xFFFF) << 8) //!< FARG Value
#define EEFC_FCR_FARG_Pos (8)                   //!< FARG Position
#define EEFC_FCR_FARG_Len (16)                  //!< FARG Field Length
#define EEFC_FCR_FARG_Msk (0xFFFF << 8)         //!< FARG Mask
/* \} */
/** \defgroup EEFC_FCR_FKEY FKEY: Flash Writing Protection Key
 * \ingroup EEFC_FCR
 * \{
 */
#define EEFC_FCR_FKEY     (0x5A << 24) //!< FKEY Value
#define EEFC_FCR_FKEY_Pos (24)         //!< FKEY Position
#define EEFC_FCR_FKEY_Len (8)          //!< FKEY Field Length
#define EEFC_FCR_FKEY_Msk (0xFF << 24) //!< FKEY Mask
/* \} */

/** \defgroup EEFC_FSR Flash Status Register Bit Definitions
 * \ingroup EEFC
 */

/** \defgroup EEFC_FSR_FRDY FRDY: Flash Ready Status
 * \ingroup EEFC_FSR
 * \{
 */
#define EEFC_FSR_FRDY     (0x1 << 0) //!< FRDY Value
#define EEFC_FSR_FRDY_Pos (0)        //!< FRDY Position
#define EEFC_FSR_FRDY_Len (1)        //!< FRDY Field Length
#define EEFC_FSR_FRDY_Msk (0x1 << 0) //!< FRDY Mask
/* \} */
/** \defgroup EEFC_FSR_FCMDE FCMDE: Flash Command Error Status
 * \ingroup EEFC_FSR
 * \{
 */
#define EEFC_FSR_FCMDE     (0x1 << 1) //!< FCMDE Value
#define EEFC_FSR_FCMDE_Pos (1)        //!< FCMDE Position
#define EEFC_FSR_FCMDE_Len (1)        //!< FCMDE Field Length
#define EEFC_FSR_FCMDE_Msk (0x1 << 1) //!< FCMDE Mask
/* \} */
/** \defgroup EEFC_FSR_FLOCKE FLOCKE: Flash Lock Error Status
 * \ingroup EEFC_FSR
 * \{
 */
#define EEFC_FSR_FLOCKE     (0x1 << 2) //!< FLOCKE Value
#define EEFC_FSR_FLOCKE_Pos (2)        //!< FLOCKE Position
#define EEFC_FSR_FLOCKE_Len (1)        //!< FLOCKE Field Length
#define EEFC_FSR_FLOCKE_Msk (0x1 << 2) //!< FLOCKE Mask
/* \} */

/** \defgroup EEFC_FRR Flash Result Register Bit Definitions
 * \ingroup EEFC
 */

/** \defgroup EEFC_FRR_FVALUE FVALUE: Flash Result Value
 * \ingroup EEFC_FRR
 * \{
 */
#define EEFC_FRR_FVALUE(v)  (((v) & 0xFFFFFFFF) << 0) //!< FVALUE Value
#define EEFC_FRR_FVALUE_Pos (0)                       //!< FVALUE Position
#define EEFC_FRR_FVALUE_Len (1)                       //!< FVALUE Field Length
#define EEFC_FRR_FVALUE_Msk (0xFFFFFFFF << 0)         //!< FVALUE Mask
/* \} */

#endif // _CPU_PERIPHERALS_EEFC_H_
