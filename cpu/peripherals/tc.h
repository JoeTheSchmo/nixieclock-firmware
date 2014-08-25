/**
 * \file
 *
 * \brief Timer Counter (TC) User Interface
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_TC_H_
#define _CPU_PERIPHERALS_TC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup TC Timer Counter (TC) User Interface */

/** \defgroup TC_UI_REG User Interface Registers
 * \ingroup TC
 * \{
 */
#define TC_CCR(TC)       (*(reg_wo_t*)(TC +0x0000)) //!< \ref TC_CCR
#define TC_CMR(TC)       (*(reg_rw_t*)(TC +0x0004)) //!< \ref TC_CMR_CM \ref TC_CMR_WM
#define TC_CV(TC)        (*(reg_ro_t*)(TC +0x0010)) //!< \ref TC_CV
#define TC_RA(TC)        (*(reg_rw_t*)(TC +0x0014)) //!< \ref TC_RA
#define TC_RB(TC)        (*(reg_rw_t*)(TC +0x0018)) //!< \ref TC_RB
#define TC_RC(TC)        (*(reg_rw_t*)(TC +0x001C)) //!< \ref TC_RC
#define TC_SR(TC)        (*(reg_ro_t*)(TC +0x0020)) //!< \ref TC_SR
#define TC_IER(TC)       (*(reg_wo_t*)(TC +0x0024)) //!< \ref TC_IER
#define TC_IDR(TC)       (*(reg_wo_t*)(TC +0x0028)) //!< \ref TC_IDR
#define TC_IMR(TC)       (*(reg_ro_t*)(TC +0x002C)) //!< \ref TC_IMR
#define TC_BCR           (*(reg_wo_t*)(TC0+0x00C0)) //!< \ref TC_BCR
#define TC_BMR           (*(reg_rw_t*)(TC0+0x00C4)) //!< \ref TC_BMR
#define TC_QIER          (*(reg_wo_t*)(TC0+0x00C8)) //!< \ref TC_QIER
#define TC_QIDR          (*(reg_wo_t*)(TC0+0x00CC)) //!< \ref TC_QIDR
#define TC_QIMR          (*(reg_ro_t*)(TC0+0x00D0)) //!< \ref TC_QIMR
#define TC_QISR          (*(reg_ro_t*)(TC0+0x00D4)) //!< \ref TC_QISR
/* \} */

/** \defgroup TC_CCR Channel Control Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_CCR_CLKEN CLKEN: Counter Clock Enable Command
 * \ingroup TC_CCR
 * \{
 */
#define TC_CCR_CLKEN     (0x1 << 0) //!< CLKEN Value
#define TC_CCR_CLKEN_Pos (0)        //!< CLKEN Position
#define TC_CCR_CLKEN_Len (1)        //!< CLKEN Field Length
#define TC_CCR_CLKEN_Msk (0x1 << 0) //!< CLKEN Mask
/* \} */
/** \defgroup TC_CCR_CLKDIS CLKDIS: Counter Clock Disable Command
 * \ingroup TC_CCR
 * \{
 */
#define TC_CCR_CLKDIS     (0x1 << 1) //!< CLKDIS Value
#define TC_CCR_CLKDIS_Pos (1)        //!< CLKDIS Position
#define TC_CCR_CLKDIS_Len (1)        //!< CLKDIS Field Length
#define TC_CCR_CLKDIS_Msk (0x1 << 1) //!< CLKDIS Mask
/* \} */
/** \defgroup TC_CCR_SWTRG SWTRG: Software Trigger Command
 * \ingroup TC_CCR
 * \{
 */
#define TC_CCR_SWTRG     (0x1 << 2) //!< SWTRG Value
#define TC_CCR_SWTRG_Pos (2)        //!< SWTRG Position
#define TC_CCR_SWTRG_Len (1)        //!< SWTRG Field Length
#define TC_CCR_SWTRG_Msk (0x1 << 2) //!< SWTRG Mask
/* \} */

/** \defgroup TC_CMR_CM Channel Mode (Capture Mode) Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_CMR_CM_TCCLKS TCCLKS: Clock Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_TCCLKS(v)  (((v) & 0x7) << 0) //!< CM_TCCLKS Value
#define TC_CMR_CM_TCCLKS_Pos (0)                //!< CM_TCCLKS Position
#define TC_CMR_CM_TCCLKS_Len (3)                //!< CM_TCCLKS Field Length
#define TC_CMR_CM_TCCLKS_Msk (0x7 << 0)         //!< CM_TCCLKS Mask
#define TC_CMR_CM_TCCLKS_TIMER_CLOCK1 (0)       //!< CM_TCCLKS_TIMER_CLOCK1 Value
#define TC_CMR_CM_TCCLKS_TIMER_CLOCK2 (1)       //!< CM_TCCLKS_TIMER_CLOCK2 Value
#define TC_CMR_CM_TCCLKS_TIMER_CLOCK3 (2)       //!< CM_TCCLKS_TIMER_CLOCK3 Value
#define TC_CMR_CM_TCCLKS_TIMER_CLOCK4 (3)       //!< CM_TCCLKS_TIMER_CLOCK4 Value
#define TC_CMR_CM_TCCLKS_TIMER_CLOCK5 (4)       //!< CM_TCCLKS_TIMER_CLOCK5 Value
#define TC_CMR_CM_TCCLKS_XC0 (5)                //!< CM_TCCLKS_XC0 Value
#define TC_CMR_CM_TCCLKS_XC1 (6)                //!< CM_TCCLKS_XC1 Value
#define TC_CMR_CM_TCCLKS_XC2 (7)                //!< CM_TCCLKS_XC2 Value
/* \} */
/** \defgroup TC_CMR_CM_CLKI CLKI: Clock Invert
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_CLKI     (0x1 << 3) //!< CM_CLKI Value
#define TC_CMR_CM_CLKI_Pos (3)        //!< CM_CLKI Position
#define TC_CMR_CM_CLKI_Len (1)        //!< CM_CLKI Field Length
#define TC_CMR_CM_CLKI_Msk (0x1 << 3) //!< CM_CLKI Mask
/* \} */
/** \defgroup TC_CMR_CM_BURST BURST: Burst Signal Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_BURST(v)  (((v) & 0x3) << 4) //!< CM_BURST Value
#define TC_CMR_CM_BURST_Pos (4)                //!< CM_BURST Position
#define TC_CMR_CM_BURST_Len (2)                //!< CM_BURST Field Length
#define TC_CMR_CM_BURST_Msk (0x3 << 4)         //!< CM_BURST Mask
#define TC_CMR_CM_BURST_NONE (0)               //!< CM_BURST_NONE Value
#define TC_CMR_CM_BURST_XC0 (1)                //!< CM_BURST_XC0 Value
#define TC_CMR_CM_BURST_XC1 (2)                //!< CM_BURST_XC1 Value
#define TC_CMR_CM_BURST_XC2 (3)                //!< CM_BURST_XC2 Value
/* \} */
/** \defgroup TC_CMR_CM_LDBSTOP LDBSTOP: Counter Clock Stopped with RB Loading
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_LDBSTOP     (0x1 << 6) //!< CM_LDBSTOP Value
#define TC_CMR_CM_LDBSTOP_Pos (6)        //!< CM_LDBSTOP Position
#define TC_CMR_CM_LDBSTOP_Len (1)        //!< CM_LDBSTOP Field Length
#define TC_CMR_CM_LDBSTOP_Msk (0x1 << 6) //!< CM_LDBSTOP Mask
/* \} */
/** \defgroup TC_CMR_CM_LDBDIS LDBDIS: Counter Clock Disable with RB Loading
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_LDBDIS     (0x1 << 7) //!< CM_LDBDIS Value
#define TC_CMR_CM_LDBDIS_Pos (7)        //!< CM_LDBDIS Position
#define TC_CMR_CM_LDBDIS_Len (1)        //!< CM_LDBDIS Field Length
#define TC_CMR_CM_LDBDIS_Msk (0x1 << 7) //!< CM_LDBDIS Mask
/* \} */
/** \defgroup TC_CMR_CM_ETRGEDG ETRGEDG: External Trigger Edge Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_ETRGEDG(v)  (((v) & 0x3) << 8) //!< CM_ETRGEDG Value
#define TC_CMR_CM_ETRGEDG_Pos (8)                //!< CM_ETRGEDG Position
#define TC_CMR_CM_ETRGEDG_Len (2)                //!< CM_ETRGEDG Field Length
#define TC_CMR_CM_ETRGEDG_Msk (0x3 << 8)         //!< CM_ETRGEDG Mask
#define TC_CMR_CM_ETRGEDG_NONE (0)               //!< CM_ETRGEDG_NONE Value
#define TC_CMR_CM_ETRGEDG_RISING (1)             //!< CM_ETRGEDG_RISING Value
#define TC_CMR_CM_ETRGEDG_FALLING (2)            //!< CM_ETRGEDG_FALLING Value
#define TC_CMR_CM_ETRGEDG_EDGE (3)               //!< CM_ETRGEDG_EDGE Value
/* \} */
/** \defgroup TC_CMR_CM_ABETRG ABETRG: TIOA or TIOB External Trigger Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_ABETRG     (0x1 << 10) //!< CM_ABETRG Value
#define TC_CMR_CM_ABETRG_Pos (10)        //!< CM_ABETRG Position
#define TC_CMR_CM_ABETRG_Len (1)         //!< CM_ABETRG Field Length
#define TC_CMR_CM_ABETRG_Msk (0x1 << 10) //!< CM_ABETRG Mask
/* \} */
/** \defgroup TC_CMR_CM_CPCTRG CPCTRG: RC Compare Trigger Enable
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_CPCTRG     (0x1 << 14) //!< CM_CPCTRG Value
#define TC_CMR_CM_CPCTRG_Pos (14)        //!< CM_CPCTRG Position
#define TC_CMR_CM_CPCTRG_Len (1)         //!< CM_CPCTRG Field Length
#define TC_CMR_CM_CPCTRG_Msk (0x1 << 14) //!< CM_CPCTRG Mask
/* \} */
/** \defgroup TC_CMR_CM_WAVE WAVE: Waveform Mode
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_WAVE     (0x1 << 15) //!< CM_WAVE Value
#define TC_CMR_CM_WAVE_Pos (15)        //!< CM_WAVE Position
#define TC_CMR_CM_WAVE_Len (1)         //!< CM_WAVE Field Length
#define TC_CMR_CM_WAVE_Msk (0x1 << 15) //!< CM_WAVE Mask
/* \} */
/** \defgroup TC_CMR_CM_LDRA LDRA: RA Loading Edge Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_LDRA(v)  (((v) & 0x3) << 16) //!< CM_LDRA Value
#define TC_CMR_CM_LDRA_Pos (16)                //!< CM_LDRA Position
#define TC_CMR_CM_LDRA_Len (2)                 //!< CM_LDRA Field Length
#define TC_CMR_CM_LDRA_Msk (0x3 << 16)         //!< CM_LDRA Mask
#define TC_CMR_CM_LDRA_NONE (0)                //!< CM_LDRA_NONE Value
#define TC_CMR_CM_LDRA_RISING (1)              //!< CM_LDRA_RISING Value
#define TC_CMR_CM_LDRA_FALLING (2)             //!< CM_LDRA_FALLING Value
#define TC_CMR_CM_LDRA_EDGE (3)                //!< CM_LDRA_EDGE Value
/* \} */
/** \defgroup TC_CMR_CM_LDRB LDRB: RB Loading Edge Selection
 * \ingroup TC_CMR_CM
 * \{
 */
#define TC_CMR_CM_LDRB(v)  (((v) & 0x3) << 18) //!< CM_LDRB Value
#define TC_CMR_CM_LDRB_Pos (18)                //!< CM_LDRB Position
#define TC_CMR_CM_LDRB_Len (2)                 //!< CM_LDRB Field Length
#define TC_CMR_CM_LDRB_Msk (0x3 << 18)         //!< CM_LDRB Mask
#define TC_CMR_CM_LDRB_NONE (0)                //!< CM_LDRB_NONE Value
#define TC_CMR_CM_LDRB_RISING (1)              //!< CM_LDRB_RISING Value
#define TC_CMR_CM_LDRB_FALLING (2)             //!< CM_LDRB_FALLING Value
#define TC_CMR_CM_LDRB_EDGE (3)                //!< CM_LDRB_EDGE Value
/* \} */

/** \defgroup TC_CMR_WM Channel Mode (Wave Mode) Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_CMR_WM_TCCLKS TCCLKS: Clock Selection
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_TCCLKS(v)  (((v) & 0x7) << 0) //!< WM_TCCLKS Value
#define TC_CMR_WM_TCCLKS_Pos (0)                //!< WM_TCCLKS Position
#define TC_CMR_WM_TCCLKS_Len (3)                //!< WM_TCCLKS Field Length
#define TC_CMR_WM_TCCLKS_Msk (0x7 << 0)         //!< WM_TCCLKS Mask
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK1 (0)       //!< WM_TCCLKS_TIMER_CLOCK1 Value
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK2 (1)       //!< WM_TCCLKS_TIMER_CLOCK2 Value
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK3 (2)       //!< WM_TCCLKS_TIMER_CLOCK3 Value
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK4 (3)       //!< WM_TCCLKS_TIMER_CLOCK4 Value
#define TC_CMR_WM_TCCLKS_TIMER_CLOCK5 (4)       //!< WM_TCCLKS_TIMER_CLOCK5 Value
#define TC_CMR_WM_TCCLKS_XC0 (5)                //!< WM_TCCLKS_XC0 Value
#define TC_CMR_WM_TCCLKS_XC1 (6)                //!< WM_TCCLKS_XC1 Value
#define TC_CMR_WM_TCCLKS_XC2 (7)                //!< WM_TCCLKS_XC2 Value
/* \} */
/** \defgroup TC_CMR_WM_CLKI CLKI: Clock Invert
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_CLKI     (0x1 << 3) //!< WM_CLKI Value
#define TC_CMR_WM_CLKI_Pos (3)        //!< WM_CLKI Position
#define TC_CMR_WM_CLKI_Len (1)        //!< WM_CLKI Field Length
#define TC_CMR_WM_CLKI_Msk (0x1 << 3) //!< WM_CLKI Mask
/* \} */
/** \defgroup TC_CMR_WM_BURST BURST: Burst Signal Selection
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_BURST(v)  (((v) & 0x3) << 4) //!< WM_BURST Value
#define TC_CMR_WM_BURST_Pos (4)                //!< WM_BURST Position
#define TC_CMR_WM_BURST_Len (2)                //!< WM_BURST Field Length
#define TC_CMR_WM_BURST_Msk (0x3 << 4)         //!< WM_BURST Mask
#define TC_CMR_WM_BURST_NONE (0)               //!< WM_BURST_NONE Value
#define TC_CMR_WM_BURST_XC0 (1)                //!< WM_BURST_XC0 Value
#define TC_CMR_WM_BURST_XC1 (2)                //!< WM_BURST_XC1 Value
#define TC_CMR_WM_BURST_XC2 (3)                //!< WM_BURST_XC2 Value
/* \} */
/** \defgroup TC_CMR_WM_CPCSTOP CPCSTOP: Counter Clock Stopped with RC Compare
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_CPCSTOP     (0x1 << 6) //!< WM_CPCSTOP Value
#define TC_CMR_WM_CPCSTOP_Pos (6)        //!< WM_CPCSTOP Position
#define TC_CMR_WM_CPCSTOP_Len (1)        //!< WM_CPCSTOP Field Length
#define TC_CMR_WM_CPCSTOP_Msk (0x1 << 6) //!< WM_CPCSTOP Mask
/* \} */
/** \defgroup TC_CMR_WM_CPCDIS CPCDIS: Counter Clock Disable with RC Compare
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_CPCDIS     (0x1 << 7) //!< WM_CPCDIS Value
#define TC_CMR_WM_CPCDIS_Pos (7)        //!< WM_CPCDIS Position
#define TC_CMR_WM_CPCDIS_Len (1)        //!< WM_CPCDIS Field Length
#define TC_CMR_WM_CPCDIS_Msk (0x1 << 7) //!< WM_CPCDIS Mask
/* \} */
/** \defgroup TC_CMR_WM_EEVTEDG EEVTEDG: External Event Edge Selection
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_EEVTEDG(v)  (((v) & 3) << 8) //!< WM_EEVTEDG Value
#define TC_CMR_WM_EEVTEDG_Pos (8)              //!< WM_EEVTEDG Position
#define TC_CMR_WM_EEVTEDG_Len (2)              //!< WM_EEVTEDG Field Length
#define TC_CMR_WM_EEVTEDG_Msk (0x3 << 8)       //!< WM_EEVTEDG Mask
#define TC_CMR_WM_EEVTEDG_NONE (0)             //!< WM_EEVTEDG_NONE Value
#define TC_CMR_WM_EEVTEDG_RISING (1)           //!< WM_EEVTEDG_RISING Value
#define TC_CMR_WM_EEVTEDG_FALLING (2)          //!< WM_EEVTEDG_FALLING Value
#define TC_CMR_WM_EEVTEDG_EDGE (3)             //!< WM_EEVTEDG_EDGE Value
/* \} */
/** \defgroup TC_CMR_WM_EEVT EEVT: External Event Selection
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_EEVT(v)  (((v) & 0x3) << 10) //!< WM_EEVT Value
#define TC_CMR_WM_EEVT_Pos (10)                //!< WM_EEVT Position
#define TC_CMR_WM_EEVT_Len (2)                 //!< WM_EEVT Field Length
#define TC_CMR_WM_EEVT_Msk (0x3 << 10)         //!< WM_EEVT Mask
#define TC_CMR_WM_EEVT_TIOB (0)                //!< WM_EEVT_TIOB Value
#define TC_CMR_WM_EEVT_XC0 (1)                 //!< WM_EEVT_XC0 Value
#define TC_CMR_WM_EEVT_XC1 (2)                 //!< WM_EEVT_XC1 Value
#define TC_CMR_WM_EEVT_XC2 (3)                 //!< WM_EEVT_XC2 Value
/* \} */
/** \defgroup TC_CMR_WM_ENETRG ENETRG: External Event Trigger Enable
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_ENETRG     (0x1 << 12) //!< WM_ENETRG Value
#define TC_CMR_WM_ENETRG_Pos (12)        //!< WM_ENETRG Position
#define TC_CMR_WM_ENETRG_Len (1)         //!< WM_ENETRG Field Length
#define TC_CMR_WM_ENETRG_Msk (0x1 << 12) //!< WM_ENETRG Mask
/* \} */
/** \defgroup TC_CMR_WM_WAVESEL WAVESEL: Waveform Selection
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_WAVESEL(v)  (((v) & 0x3) << 13) //!< WM_WAVESEL Value
#define TC_CMR_WM_WAVESEL_Pos (13)                //!< WM_WAVESEL Position
#define TC_CMR_WM_WAVESEL_Len (2)                 //!< WM_WAVESEL Field Length
#define TC_CMR_WM_WAVESEL_Msk (0x3 << 13)         //!< WM_WAVESEL Mask
#define TC_CMR_WM_WAVESEL_UP (0)                  //!< WM_WAVESEL_UP Value
#define TC_CMR_WM_WAVESEL_UPDOWN (1)              //!< WM_WAVESEL_UPDOWN Value
#define TC_CMR_WM_WAVESEL_UP_RC (2)               //!< WM_WAVESEL_UP_RC Value
#define TC_CMR_WM_WAVESEL_UPDOWN_RC (3)           //!< WM_WAVESEL_UPDOWN_RC Value
/* \} */
/** \defgroup TC_CMR_WM_WAVE WAVE: Waveform Mode
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_WAVE     (0x1 << 15) //!< WM_WAVE Value
#define TC_CMR_WM_WAVE_Pos (15)        //!< WM_WAVE Position
#define TC_CMR_WM_WAVE_Len (1)         //!< WM_WAVE Field Length
#define TC_CMR_WM_WAVE_Msk (0x1 << 15) //!< WM_WAVE Mask
/* \} */
/** \defgroup TC_CMR_WM_ACPA ACPA: RA Compare Effect on TIOA
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_ACPA(v)  (((v) & 0x3) << 16) //!< WM_ACPA Value
#define TC_CMR_WM_ACPA_Pos (16)                //!< WM_ACPA Position
#define TC_CMR_WM_ACPA_Len (2)                 //!< WM_ACPA Field Length
#define TC_CMR_WM_ACPA_Msk (0x3 << 16)         //!< WM_ACPA Mask
#define TC_CMR_WM_ACPA_NONE (0)                //!< WM_ACPA_NONE Value
#define TC_CMR_WM_ACPA_SET (1)                 //!< WM_ACPA_SET Value
#define TC_CMR_WM_ACPA_CLEAR (2)               //!< WM_ACPA_CLEAR Value
#define TC_CMR_WM_ACPA_TOGGLE (3)              //!< WM_ACPA_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_ACPC ACPC: RC Compare Effect on TIOA
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_ACPC(v)  (((v) & 0x3) << 18) //!< WM_ACPC Value
#define TC_CMR_WM_ACPC_Pos (18)                //!< WM_ACPC Position
#define TC_CMR_WM_ACPC_Len (2)                 //!< WM_ACPC Field Length
#define TC_CMR_WM_ACPC_Msk (0x3 << 18)         //!< WM_ACPC Mask
#define TC_CMR_WM_ACPC_NONE (0)                //!< WM_ACPC_NONE Value
#define TC_CMR_WM_ACPC_SET (1)                 //!< WM_ACPC_SET Value
#define TC_CMR_WM_ACPC_CLEAR (2)               //!< WM_ACPC_CLEAR Value
#define TC_CMR_WM_ACPC_TOGGLE (3)              //!< WM_ACPC_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_AEEVT AEEVT: External Event Effect on TIOA
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_AEEVT(v)  (((v) & 0x3) << 20) //!< WM_AEEVT Value
#define TC_CMR_WM_AEEVT_Pos (20)                //!< WM_AEEVT Position
#define TC_CMR_WM_AEEVT_Len (2)                 //!< WM_AEEVT Field Length
#define TC_CMR_WM_AEEVT_Msk (0x3 << 20)         //!< WM_AEEVT Mask
#define TC_CMR_WM_AEEVT_NONE (0)                //!< WM_AEEVT_NONE Value
#define TC_CMR_WM_AEEVT_SET (1)                 //!< WM_AEEVT_SET Value
#define TC_CMR_WM_AEEVT_CLAER (2)               //!< WM_AEEVT_CLAER Value
#define TC_CMR_WM_AEEVT_TOGGLE (3)              //!< WM_AEEVT_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_ASWTRG ASWTRG: Software Trigger Effect on TIOA
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_ASWTRG(v)  (((v) & 0x3) << 22) //!< WM_ASWTRG Value
#define TC_CMR_WM_ASWTRG_Pos (22)                //!< WM_ASWTRG Position
#define TC_CMR_WM_ASWTRG_Len (2)                 //!< WM_ASWTRG Field Length
#define TC_CMR_WM_ASWTRG_Msk (0x3 << 22)         //!< WM_ASWTRG Mask
#define TC_CMR_WM_ASWTRG_NONE (0)                //!< WM_ASWTRG_NONE Value
#define TC_CMR_WM_ASWTRG_SET (1)                 //!< WM_ASWTRG_SET Value
#define TC_CMR_WM_ASWTRG_CLEAR (2)               //!< WM_ASWTRG_CLEAR Value
#define TC_CMR_WM_ASWTRG_TOGGLE (3)              //!< WM_ASWTRG_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_BCPB BCPB: RB Compare Effect on TIOB
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_BCPB(v)  (((v) & 0x3) << 24) //!< WM_BCPB Value
#define TC_CMR_WM_BCPB_Pos (24)                //!< WM_BCPB Position
#define TC_CMR_WM_BCPB_Len (2)                 //!< WM_BCPB Field Length
#define TC_CMR_WM_BCPB_Msk (0x3 << 24)         //!< WM_BCPB Mask
#define TC_CMR_WM_BCPB_NONE (0)                //!< WM_BCPB_NONE Value
#define TC_CMR_WM_BCPB_SET (1)                 //!< WM_BCPB_SET Value
#define TC_CMR_WM_BCPB_CLEAR (2)               //!< WM_BCPB_CLEAR Value
#define TC_CMR_WM_BCPB_TOGGLE (3)              //!< WM_BCPB_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_BCPC BCPC: RC Compare Effect on TIOB
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_BCPC(v)  (((v) & 0x3) << 26) //!< WM_BCPC Value
#define TC_CMR_WM_BCPC_Pos (26)                //!< WM_BCPC Position
#define TC_CMR_WM_BCPC_Len (2)                 //!< WM_BCPC Field Length
#define TC_CMR_WM_BCPC_Msk (0x3 << 26)         //!< WM_BCPC Mask
#define TC_CMR_WM_BCPC_NONE (0)                //!< WM_BCPC_NONE Value
#define TC_CMR_WM_BCPC_SET (1)                 //!< WM_BCPC_SET Value
#define TC_CMR_WM_BCPC_CLEAR (2)               //!< WM_BCPC_CLEAR Value
#define TC_CMR_WM_BCPC_TOGGLE (3)              //!< WM_BCPC_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_BEEVT BEEVT: External Event Effect on TIOB
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_BEEVT(v)  (((v) & 0x3) << 28) //!< WM_BEEVT Value
#define TC_CMR_WM_BEEVT_Pos (28)                //!< WM_BEEVT Position
#define TC_CMR_WM_BEEVT_Len (2)                 //!< WM_BEEVT Field Length
#define TC_CMR_WM_BEEVT_Msk (0x3 << 28)         //!< WM_BEEVT Mask
#define TC_CMR_WM_BEEVT_NONE (0)                //!< WM_BEEVT_NONE Value
#define TC_CMR_WM_BEEVT_SET (1)                 //!< WM_BEEVT_SET Value
#define TC_CMR_WM_BEEVT_CLEAR (2)               //!< WM_BEEVT_CLEAR Value
#define TC_CMR_WM_BEEVT_TOGGLE (3)              //!< WM_BEEVT_TOGGLE Value
/* \} */
/** \defgroup TC_CMR_WM_BSWTRG BSWTRG: Software Trigger Effect on TIOB
 * \ingroup TC_CMR_WM
 * \{
 */
#define TC_CMR_WM_BSWTRG(v)  (((v) & 0x3) << 30) //!< WM_BSWTRG Value
#define TC_CMR_WM_BSWTRG_Pos (30)                //!< WM_BSWTRG Position
#define TC_CMR_WM_BSWTRG_Len (2)                 //!< WM_BSWTRG Field Length
#define TC_CMR_WM_BSWTRG_Msk (0x3 << 30)         //!< WM_BSWTRG Mask
#define TC_CMR_WM_BSWTRG_NONE (0)                //!< WM_BSWTRG_NONE Value
#define TC_CMR_WM_BSWTRG_SET (1)                 //!< WM_BSWTRG_SET Value
#define TC_CMR_WM_BSWTRG_CLEAR (2)               //!< WM_BSWTRG_CLEAR Value
#define TC_CMR_WM_BSWTRG_TOGGLE (3)              //!< WM_BSWTRG_TOGGLE Value
/* \} */

/** \defgroup TC_CV Counter Value Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_RA Register A Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_RB Register B Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_RC Register C Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_SR Status Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_SR_COVFS COVFS: Counter Overflow Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_COVFS     (0x1 << 0) //!< COVFS Value
#define TC_SR_COVFS_Pos (0)        //!< COVFS Position
#define TC_SR_COVFS_Len (1)        //!< COVFS Field Length
#define TC_SR_COVFS_Msk (0x1 << 0) //!< COVFS Mask
/* \} */
/** \defgroup TC_SR_LOVRS LOVRS: Load Overrun Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_LOVRS     (0x1 << 1) //!< LOVRS Value
#define TC_SR_LOVRS_Pos (1)        //!< LOVRS Position
#define TC_SR_LOVRS_Len (1)        //!< LOVRS Field Length
#define TC_SR_LOVRS_Msk (0x1 << 1) //!< LOVRS Mask
/* \} */
/** \defgroup TC_SR_CPAS CPAS: RA Compare Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_CPAS     (0x1 << 2) //!< CPAS Value
#define TC_SR_CPAS_Pos (2)        //!< CPAS Position
#define TC_SR_CPAS_Len (1)        //!< CPAS Field Length
#define TC_SR_CPAS_Msk (0x1 << 2) //!< CPAS Mask
/* \} */
/** \defgroup TC_SR_CPBS CPBS: RB Compare Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_CPBS     (0x1 << 3) //!< CPBS Value
#define TC_SR_CPBS_Pos (3)        //!< CPBS Position
#define TC_SR_CPBS_Len (1)        //!< CPBS Field Length
#define TC_SR_CPBS_Msk (0x1 << 3) //!< CPBS Mask
/* \} */
/** \defgroup TC_SR_CPCS CPCS: RC Compare Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_CPCS     (0x1 << 4) //!< CPCS Value
#define TC_SR_CPCS_Pos (4)        //!< CPCS Position
#define TC_SR_CPCS_Len (1)        //!< CPCS Field Length
#define TC_SR_CPCS_Msk (0x1 << 4) //!< CPCS Mask
/* \} */
/** \defgroup TC_SR_LDRAS LDRAS: RA Loading Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_LDRAS     (0x1 << 5) //!< LDRAS Value
#define TC_SR_LDRAS_Pos (5)        //!< LDRAS Position
#define TC_SR_LDRAS_Len (1)        //!< LDRAS Field Length
#define TC_SR_LDRAS_Msk (0x1 << 5) //!< LDRAS Mask
/* \} */
/** \defgroup TC_SR_LDRBS LDRBS: RB Loading Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_LDRBS     (0x1 << 6) //!< LDRBS Value
#define TC_SR_LDRBS_Pos (6)        //!< LDRBS Position
#define TC_SR_LDRBS_Len (1)        //!< LDRBS Field Length
#define TC_SR_LDRBS_Msk (0x1 << 6) //!< LDRBS Mask
/* \} */
/** \defgroup TC_SR_ETRGS ETRGS: External Trigger Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_ETRGS     (0x1 << 7) //!< ETRGS Value
#define TC_SR_ETRGS_Pos (7)        //!< ETRGS Position
#define TC_SR_ETRGS_Len (1)        //!< ETRGS Field Length
#define TC_SR_ETRGS_Msk (0x1 << 7) //!< ETRGS Mask
/* \} */
/** \defgroup TC_SR_CLKSTA CLKSTA: Clock Enabling Status
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_CLKSTA     (0x1 << 16) //!< CLKSTA Value
#define TC_SR_CLKSTA_Pos (16)        //!< CLKSTA Position
#define TC_SR_CLKSTA_Len (1)         //!< CLKSTA Field Length
#define TC_SR_CLKSTA_Msk (0x1 << 16) //!< CLKSTA Mask
/* \} */
/** \defgroup TC_SR_MTIOA MTIOA: TIOA Mirror
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_MTIOA     (0x1 << 17) //!< MTIOA Value
#define TC_SR_MTIOA_Pos (17)        //!< MTIOA Position
#define TC_SR_MTIOA_Len (1)         //!< MTIOA Field Length
#define TC_SR_MTIOA_Msk (0x1 << 17) //!< MTIOA Mask
/* \} */
/** \defgroup TC_SR_MTIOB MTIOB: TIOB Mirror
 * \ingroup TC_SR
 * \{
 */
#define TC_SR_MTIOB     (0x1 << 18) //!< MTIOB Value
#define TC_SR_MTIOB_Pos (18)        //!< MTIOB Position
#define TC_SR_MTIOB_Len (1)         //!< MTIOB Field Length
#define TC_SR_MTIOB_Msk (0x1 << 18) //!< MTIOB Mask
/* \} */

/** \defgroup TC_IER Interrupt Enable Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_IER_COVFS COVFS: Counter Overflow
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_COVFS     (0x1 << 0) //!< COVFS Value
#define TC_IER_COVFS_Pos (0)        //!< COVFS Position
#define TC_IER_COVFS_Len (1)        //!< COVFS Field Length
#define TC_IER_COVFS_Msk (0x1 << 0) //!< COVFS Mask
/* \} */
/** \defgroup TC_IER_LOVRS LOVRS: Load Overrun
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_LOVRS     (0x1 << 1) //!< LOVRS Value
#define TC_IER_LOVRS_Pos (1)        //!< LOVRS Position
#define TC_IER_LOVRS_Len (1)        //!< LOVRS Field Length
#define TC_IER_LOVRS_Msk (0x1 << 1) //!< LOVRS Mask
/* \} */
/** \defgroup TC_IER_CPAS CPAS: RA Compare
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_CPAS     (0x1 << 2) //!< CPAS Value
#define TC_IER_CPAS_Pos (2)        //!< CPAS Position
#define TC_IER_CPAS_Len (1)        //!< CPAS Field Length
#define TC_IER_CPAS_Msk (0x1 << 2) //!< CPAS Mask
/* \} */
/** \defgroup TC_IER_CPBS CPBS: RB Compare
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_CPBS     (0x1 << 3) //!< CPBS Value
#define TC_IER_CPBS_Pos (3)        //!< CPBS Position
#define TC_IER_CPBS_Len (1)        //!< CPBS Field Length
#define TC_IER_CPBS_Msk (0x1 << 3) //!< CPBS Mask
/* \} */
/** \defgroup TC_IER_CPCS CPCS: RC Compare
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_CPCS     (0x1 << 4) //!< CPCS Value
#define TC_IER_CPCS_Pos (4)        //!< CPCS Position
#define TC_IER_CPCS_Len (1)        //!< CPCS Field Length
#define TC_IER_CPCS_Msk (0x1 << 4) //!< CPCS Mask
/* \} */
/** \defgroup TC_IER_LDRAS LDRAS: RA Loading
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_LDRAS     (0x1 << 5) //!< LDRAS Value
#define TC_IER_LDRAS_Pos (5)        //!< LDRAS Position
#define TC_IER_LDRAS_Len (1)        //!< LDRAS Field Length
#define TC_IER_LDRAS_Msk (0x1 << 5) //!< LDRAS Mask
/* \} */
/** \defgroup TC_IER_LDRBS LDRBS: RB Loading
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_LDRBS     (0x1 << 6) //!< LDRBS Value
#define TC_IER_LDRBS_Pos (6)        //!< LDRBS Position
#define TC_IER_LDRBS_Len (1)        //!< LDRBS Field Length
#define TC_IER_LDRBS_Msk (0x1 << 6) //!< LDRBS Mask
/* \} */
/** \defgroup TC_IER_ETRGS ETRGS: External Trigger
 * \ingroup TC_IER
 * \{
 */
#define TC_IER_ETRGS     (0x1 << 7) //!< ETRGS Value
#define TC_IER_ETRGS_Pos (7)        //!< ETRGS Position
#define TC_IER_ETRGS_Len (1)        //!< ETRGS Field Length
#define TC_IER_ETRGS_Msk (0x1 << 7) //!< ETRGS Mask
/* \} */

/** \defgroup TC_IDR Interrupt Disable Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_IDR_COVFS COVFS: Counter Overflow
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_COVFS     (0x1 << 0) //!< COVFS Value
#define TC_IDR_COVFS_Pos (0)        //!< COVFS Position
#define TC_IDR_COVFS_Len (1)        //!< COVFS Field Length
#define TC_IDR_COVFS_Msk (0x1 << 0) //!< COVFS Mask
/* \} */
/** \defgroup TC_IDR_LOVRS LOVRS: Load Overrun
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_LOVRS     (0x1 << 1) //!< LOVRS Value
#define TC_IDR_LOVRS_Pos (1)        //!< LOVRS Position
#define TC_IDR_LOVRS_Len (1)        //!< LOVRS Field Length
#define TC_IDR_LOVRS_Msk (0x1 << 1) //!< LOVRS Mask
/* \} */
/** \defgroup TC_IDR_CPAS CPAS: RA Compare
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_CPAS     (0x1 << 2) //!< CPAS Value
#define TC_IDR_CPAS_Pos (2)        //!< CPAS Position
#define TC_IDR_CPAS_Len (1)        //!< CPAS Field Length
#define TC_IDR_CPAS_Msk (0x1 << 2) //!< CPAS Mask
/* \} */
/** \defgroup TC_IDR_CPBS CPBS: RB Compare
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_CPBS     (0x1 << 3) //!< CPBS Value
#define TC_IDR_CPBS_Pos (3)        //!< CPBS Position
#define TC_IDR_CPBS_Len (1)        //!< CPBS Field Length
#define TC_IDR_CPBS_Msk (0x1 << 3) //!< CPBS Mask
/* \} */
/** \defgroup TC_IDR_CPCS CPCS: RC Compare
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_CPCS     (0x1 << 4) //!< CPCS Value
#define TC_IDR_CPCS_Pos (4)        //!< CPCS Position
#define TC_IDR_CPCS_Len (1)        //!< CPCS Field Length
#define TC_IDR_CPCS_Msk (0x1 << 4) //!< CPCS Mask
/* \} */
/** \defgroup TC_IDR_LDRAS LDRAS: RA Loading
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_LDRAS     (0x1 << 5) //!< LDRAS Value
#define TC_IDR_LDRAS_Pos (5)        //!< LDRAS Position
#define TC_IDR_LDRAS_Len (1)        //!< LDRAS Field Length
#define TC_IDR_LDRAS_Msk (0x1 << 5) //!< LDRAS Mask
/* \} */
/** \defgroup TC_IDR_LDRBS LDRBS: RB Loading
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_LDRBS     (0x1 << 6) //!< LDRBS Value
#define TC_IDR_LDRBS_Pos (6)        //!< LDRBS Position
#define TC_IDR_LDRBS_Len (1)        //!< LDRBS Field Length
#define TC_IDR_LDRBS_Msk (0x1 << 6) //!< LDRBS Mask
/* \} */
/** \defgroup TC_IDR_ETRGS ETRGS: External Trigger
 * \ingroup TC_IDR
 * \{
 */
#define TC_IDR_ETRGS     (0x1 << 7) //!< ETRGS Value
#define TC_IDR_ETRGS_Pos (7)        //!< ETRGS Position
#define TC_IDR_ETRGS_Len (1)        //!< ETRGS Field Length
#define TC_IDR_ETRGS_Msk (0x1 << 7) //!< ETRGS Mask
/* \} */

/** \defgroup TC_IMR Interrupt Mask Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_IMR_COVFS COVFS: Counter Overflow
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_COVFS     (0x1 << 0) //!< COVFS Value
#define TC_IMR_COVFS_Pos (0)        //!< COVFS Position
#define TC_IMR_COVFS_Len (1)        //!< COVFS Field Length
#define TC_IMR_COVFS_Msk (0x1 << 0) //!< COVFS Mask
/* \} */
/** \defgroup TC_IMR_LOVRS LOVRS: Load Overrun
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_LOVRS     (0x1 << 1) //!< LOVRS Value
#define TC_IMR_LOVRS_Pos (1)        //!< LOVRS Position
#define TC_IMR_LOVRS_Len (1)        //!< LOVRS Field Length
#define TC_IMR_LOVRS_Msk (0x1 << 1) //!< LOVRS Mask
/* \} */
/** \defgroup TC_IMR_CPAS CPAS: RA Compare
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_CPAS     (0x1 << 2) //!< CPAS Value
#define TC_IMR_CPAS_Pos (2)        //!< CPAS Position
#define TC_IMR_CPAS_Len (1)        //!< CPAS Field Length
#define TC_IMR_CPAS_Msk (0x1 << 2) //!< CPAS Mask
/* \} */
/** \defgroup TC_IMR_CPBS CPBS: RB Compare
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_CPBS     (0x1 << 3) //!< CPBS Value
#define TC_IMR_CPBS_Pos (3)        //!< CPBS Position
#define TC_IMR_CPBS_Len (1)        //!< CPBS Field Length
#define TC_IMR_CPBS_Msk (0x1 << 3) //!< CPBS Mask
/* \} */
/** \defgroup TC_IMR_CPCS CPCS: RC Compare
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_CPCS     (0x1 << 4) //!< CPCS Value
#define TC_IMR_CPCS_Pos (4)        //!< CPCS Position
#define TC_IMR_CPCS_Len (1)        //!< CPCS Field Length
#define TC_IMR_CPCS_Msk (0x1 << 4) //!< CPCS Mask
/* \} */
/** \defgroup TC_IMR_LDRAS LDRAS: RA Loading
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_LDRAS     (0x1 << 5) //!< LDRAS Value
#define TC_IMR_LDRAS_Pos (5)        //!< LDRAS Position
#define TC_IMR_LDRAS_Len (1)        //!< LDRAS Field Length
#define TC_IMR_LDRAS_Msk (0x1 << 5) //!< LDRAS Mask
/* \} */
/** \defgroup TC_IMR_LDRBS LDRBS: RB Loading
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_LDRBS     (0x1 << 6) //!< LDRBS Value
#define TC_IMR_LDRBS_Pos (6)        //!< LDRBS Position
#define TC_IMR_LDRBS_Len (1)        //!< LDRBS Field Length
#define TC_IMR_LDRBS_Msk (0x1 << 6) //!< LDRBS Mask
/* \} */
/** \defgroup TC_IMR_ETRGS ETRGS: External Trigger
 * \ingroup TC_IMR
 * \{
 */
#define TC_IMR_ETRGS     (0x1 << 7) //!< ETRGS Value
#define TC_IMR_ETRGS_Pos (7)        //!< ETRGS Position
#define TC_IMR_ETRGS_Len (1)        //!< ETRGS Field Length
#define TC_IMR_ETRGS_Msk (0x1 << 7) //!< ETRGS Mask
/* \} */

/** \defgroup TC_BCR Block Control Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_BCR_SYNC SYNC: Synchro Command
 * \ingroup TC_BCR
 * \{
 */
#define TC_BCR_SYNC     (0x1 << 0) //!< SYNC Value
#define TC_BCR_SYNC_Pos (0)        //!< SYNC Position
#define TC_BCR_SYNC_Len (1)        //!< SYNC Field Length
#define TC_BCR_SYNC_Msk (0x1 << 0) //!< SYNC Mask
/* \} */

/** \defgroup TC_BMR Block Mode Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_BMR_TC0XC0S TC0XC0S: External Clock Signal 0 Selection
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_TC0XC0S(v)  (((v) & 0x3) << 0) //!< TC0XC0S Value
#define TC_BMR_TC0XC0S_Pos (0)                //!< TC0XC0S Position
#define TC_BMR_TC0XC0S_Len (2)                //!< TC0XC0S Field Length
#define TC_BMR_TC0XC0S_Msk (0x3 << 0)         //!< TC0XC0S Mask
#define TC_BMR_TC0XC0S_TCLK0 (0)              //!< TC0XC0S_TCLK0 Signal Connected to XC0: TCLK0
#define TC_BMR_TC0XC0S_TIOA1 (2)              //!< TC0XC0S_TIOA1 Signal Connected to XC0: TIOA1
#define TC_BMR_TC0XC0S_TIOA2 (3)              //!< TC0XC0S_TIOA2 Signal Connected to XC0: TIOA2
/* \} */
/** \defgroup TC_BMR_TC1XC1S TC1XC1S: External Clock Signal 1 Selection
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_TC1XC1S(v)  (((v) & 0x3) << 2) //!< TC1XC1S Value
#define TC_BMR_TC1XC1S_Pos (2)                //!< TC1XC1S Position
#define TC_BMR_TC1XC1S_Len (2)                //!< TC1XC1S Field Length
#define TC_BMR_TC1XC1S_Msk (0x3 << 2)         //!< TC1XC1S Mask
#define TC_BMR_TC1XC1S_TCLK1 (0)              //!< TC1XC1S_TCLK1 Signal Connected to XC1: TCLK1
#define TC_BMR_TC1XC1S_TIOA0 (2)              //!< TC1XC1S_TIOA0 Signal Connected to XC1: TIOA0
#define TC_BMR_TC1XC1S_TIOA2 (3)              //!< TC1XC1S_TIOA2 Signal Connected to XC1: TIOA2
/* \} */
/** \defgroup TC_BMR_TC2XC2S TC2XC2S: External Clock Signal 0 Selection
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_TC2XC2S(v)  (((v) & 0x3) << 4) //!< TC2XC2S Value
#define TC_BMR_TC2XC2S_Pos (4)                //!< TC2XC2S Position
#define TC_BMR_TC2XC2S_Len (2)                //!< TC2XC2S Field Length
#define TC_BMR_TC2XC2S_Msk (0x3 << 4)         //!< TC2XC2S Mask
#define TC_BMR_TC2XC2S_TCLK2 (0)              //!< TC2XC2S_TCLK2 Signal Connected to XC2: TCLK2
#define TC_BMR_TC2XC2S_TIOA1 (2)              //!< TC2XC2S_TIOA1 Signal Connected to XC2: TIOA1
#define TC_BMR_TC2XC2S_TIOA2 (3)              //!< TC2XC2S_TIOA2 Signal Connected to XC2: TIOA2
/* \} */
/** \defgroup TC_BMR_QDEN QDEN: Quadrature Decoder Enabled
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_QDEN     (0x1 << 8) //!< QDEN Value
#define TC_BMR_QDEN_Pos (8)        //!< QDEN Position
#define TC_BMR_QDEN_Len (1)        //!< QDEN Field Length
#define TC_BMR_QDEN_Msk (0x1 << 8) //!< QDEN Mask
/* \} */
/** \defgroup TC_BMR_POSEN POSEN: Position Enabled
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_POSEN     (0x1 << 9) //!< POSEN Value
#define TC_BMR_POSEN_Pos (9)        //!< POSEN Position
#define TC_BMR_POSEN_Len (1)        //!< POSEN Field Length
#define TC_BMR_POSEN_Msk (0x1 << 9) //!< POSEN Mask
/* \} */
/** \defgroup TC_BMR_SPEEDEN SPEEDEN: Speed Enabled
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_SPEEDEN     (0x1 << 10) //!< SPEEDEN Value
#define TC_BMR_SPEEDEN_Pos (10)        //!< SPEEDEN Position
#define TC_BMR_SPEEDEN_Len (1)         //!< SPEEDEN Field Length
#define TC_BMR_SPEEDEN_Msk (0x1 << 10) //!< SPEEDEN Mask
/* \} */
/** \defgroup TC_BMR_QDTRANS QDTRANS: Quadrature Decoding Transparent
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_QDTRANS     (0x1 << 11) //!< QDTRANS Value
#define TC_BMR_QDTRANS_Pos (11)        //!< QDTRANS Position
#define TC_BMR_QDTRANS_Len (1)         //!< QDTRANS Field Length
#define TC_BMR_QDTRANS_Msk (0x1 << 11) //!< QDTRANS Mask
/* \} */
/** \defgroup TC_BMR_EDGPHA EDGPHA: Edge on PHA Count Mode
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_EDGPHA     (0x1 << 12) //!< EDGPHA Value
#define TC_BMR_EDGPHA_Pos (12)        //!< EDGPHA Position
#define TC_BMR_EDGPHA_Len (1)         //!< EDGPHA Field Length
#define TC_BMR_EDGPHA_Msk (0x1 << 12) //!< EDGPHA Mask
/* \} */
/** \defgroup TC_BMR_INVA INVA: Inverted PHA
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_INVA     (0x1 << 13) //!< INVA Value
#define TC_BMR_INVA_Pos (13)        //!< INVA Position
#define TC_BMR_INVA_Len (1)         //!< INVA Field Length
#define TC_BMR_INVA_Msk (0x1 << 13) //!< INVA Mask
/* \} */
/** \defgroup TC_BMR_INVB INVB: Inverted PHB
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_INVB     (0x1 << 14) //!< INVB Value
#define TC_BMR_INVB_Pos (14)        //!< INVB Position
#define TC_BMR_INVB_Len (1)         //!< INVB Field Length
#define TC_BMR_INVB_Msk (0x1 << 14) //!< INVB Mask
/* \} */
/** \defgroup TC_BMR_INVIDX INVIDX: Inverted Index
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_INVIDX     (0x1 << 15) //!< INVIDX Value
#define TC_BMR_INVIDX_Pos (15)        //!< INVIDX Position
#define TC_BMR_INVIDX_Len (1)         //!< INVIDX Field Length
#define TC_BMR_INVIDX_Msk (0x1 << 15) //!< INVIDX Mask
/* \} */
/** \defgroup TC_BMR_SWAP SWAP: Swap PHA and PBB
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_SWAP     (0x1 << 16) //!< SWAP Value
#define TC_BMR_SWAP_Pos (16)        //!< SWAP Position
#define TC_BMR_SWAP_Len (1)         //!< SWAP Field Length
#define TC_BMR_SWAP_Msk (0x1 << 16) //!< SWAP Mask
/* \} */
/** \defgroup TC_BMR_IDXPHB IDXPHB: Index Pin is PHB Pin
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_IDXPHB     (0x1 << 17) //!< IDXPHB Value
#define TC_BMR_IDXPHB_Pos (17)        //!< IDXPHB Position
#define TC_BMR_IDXPHB_Len (1)         //!< IDXPHB Field Length
#define TC_BMR_IDXPHB_Msk (0x1 << 17) //!< IDXPHB Mask
/* \} */
/** \defgroup TC_BMR_FILTER FILTER: Filter using MAXFLT Value
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_FILTER     (0x1 << 19) //!< FILTER Value
#define TC_BMR_FILTER_Pos (19)        //!< FILTER Position
#define TC_BMR_FILTER_Len (1)         //!< FILTER Field Length
#define TC_BMR_FILTER_Msk (0x1 << 19) //!< FILTER Mask
/* \} */
/** \defgroup TC_BMR_MAXFILT MAXFILT: Maximum Filter
 * \ingroup TC_BMR
 * \{
 */
#define TC_BMR_MAXFILT(v)  (((v) & 0x3F) << 20) //!< MAXFILT Value
#define TC_BMR_MAXFILT_Pos (20)                 //!< MAXFILT Position
#define TC_BMR_MAXFILT_Len (6)                  //!< MAXFILT Field Length
#define TC_BMR_MAXFILT_Msk (0x3F << 20)         //!< MAXFILT Mask
/* \} */

/** \defgroup TC_QIER QDEC Interrupt Enable Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_QIDR QDEC Interrupt Disable Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_QIMR QDEC Interrupt Mask Register Bit Definitions
 * \ingroup TC
 */

/** \defgroup TC_QISR QDEC Interrupt Status Register Bit Definitions
 * \ingroup TC
 */

#endif // _CPU_PERIPHERALS_TC_H_
