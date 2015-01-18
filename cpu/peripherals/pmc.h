/**
 * \file
 *
 * \brief Power Management Controller (PMC) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_PMC_H_
#define _CPU_PERIPHERALS_PMC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup PMC Power Management Controller (PMC) User Interface */

/** \defgroup PMC_UI_REG User Interface Registers
 * \ingroup PMC
 * \{
 */
#define PMC_SCER         (*(reg_wo_t*)(PMC+0x0000)) //!< \ref PMC_SCER
#define PMC_SCDR         (*(reg_wo_t*)(PMC+0x0004)) //!< \ref PMC_SCDR
#define PMC_SCSR         (*(reg_ro_t*)(PMC+0x0008)) //!< \ref PMC_SCSR
#define PMC_PCER         (*(reg_wo_t*)(PMC+0x0010)) //!< \ref PMC_PCER
#define PMC_PCDR         (*(reg_wo_t*)(PMC+0x0014)) //!< \ref PMC_PCDR
#define PMC_PCSR         (*(reg_ro_t*)(PMC+0x0018)) //!< \ref PMC_PCSR
#define CKGR_UCKR        (*(reg_rw_t*)(PMC+0x001C)) //!< \ref CKGR_UCKR
#define CKGR_MOR         (*(reg_rw_t*)(PMC+0x0020)) //!< \ref CKGR_MOR
#define CKGR_MCFR        (*(reg_ro_t*)(PMC+0x0024)) //!< \ref CKGR_MCFR
#define CKGR_PLLAR       (*(reg_rw_t*)(PMC+0x0028)) //!< \ref CKGR_PLLAR
#define PMC_MCKR         (*(reg_rw_t*)(PMC+0x0030)) //!< \ref PMC_MCKR
#define PMC_PCK0         (*(reg_rw_t*)(PMC+0x0040)) //!< \ref PMC_PCK0
#define PMC_PCK1         (*(reg_rw_t*)(PMC+0x0044)) //!< \ref PMC_PCK1
#define PMC_PCK2         (*(reg_rw_t*)(PMC+0x0048)) //!< \ref PMC_PCK2
#define PMC_IER          (*(reg_wo_t*)(PMC+0x0060)) //!< \ref PMC_IER
#define PMC_IDR          (*(reg_wo_t*)(PMC+0x0064)) //!< \ref PMC_IDR
#define PMC_SR           (*(reg_ro_t*)(PMC+0x0068)) //!< \ref PMC_SR
#define PMC_IMR          (*(reg_ro_t*)(PMC+0x006C)) //!< \ref PMC_IMR
#define PMC_FSMR         (*(reg_rw_t*)(PMC+0x0070)) //!< \ref PMC_FSMR
#define PMC_FSPR         (*(reg_rw_t*)(PMC+0x0074)) //!< \ref PMC_FSPR
#define PMC_FOCR         (*(reg_wo_t*)(PMC+0x0078)) //!< \ref PMC_FOCR
#define PMC_WPMR         (*(reg_rw_t*)(PMC+0x00E4)) //!< \ref PMC_WPMR
#define PMC_WPSR         (*(reg_ro_t*)(PMC+0x00E8)) //!< \ref PMC_WPSR
/* \} */

/** \defgroup PMC_SCER System Clock Enable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_SCER_PCK0 PCK0: Programmable Clock 0 Output Enable
 * \ingroup PMC_SCER
 * \{
 */
#define PMC_SCER_PCK0     (0x1 << 8) //!< PCK0 Value
#define PMC_SCER_PCK0_Pos (8)        //!< PCK0 Position
#define PMC_SCER_PCK0_Len (1)        //!< PCK0 Field Length
#define PMC_SCER_PCK0_Msk (0x1 << 8) //!< PCK0 Mask
/* \} */
/** \defgroup PMC_SCER_PCK1 PCK1: Programmable Clock 1 Output Enable
 * \ingroup PMC_SCER
 * \{
 */
#define PMC_SCER_PCK1     (0x1 << 9) //!< PCK1 Value
#define PMC_SCER_PCK1_Pos (9)        //!< PCK1 Position
#define PMC_SCER_PCK1_Len (1)        //!< PCK1 Field Length
#define PMC_SCER_PCK1_Msk (0x1 << 9) //!< PCK1 Mask
/* \} */
/** \defgroup PMC_SCER_PCK2 PCK2: Programmable Clock 2 Output Enable
 * \ingroup PMC_SCER
 * \{
 */
#define PMC_SCER_PCK2     (0x1 << 10) //!< PCK2 Value
#define PMC_SCER_PCK2_Pos (10)        //!< PCK2 Position
#define PMC_SCER_PCK2_Len (1)         //!< PCK2 Field Length
#define PMC_SCER_PCK2_Msk (0x1 << 10) //!< PCK2 Mask
/* \} */

/** \defgroup PMC_SCDR System Clock Disable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_SCDR_PCK0 PCK0: Programmable Clock 0 Output Disable
 * \ingroup PMC_SCDR
 * \{
 */
#define PMC_SCDR_PCK0     (0x1 << 8) //!< PCK0 Value
#define PMC_SCDR_PCK0_Pos (8)        //!< PCK0 Position
#define PMC_SCDR_PCK0_Len (1)        //!< PCK0 Field Length
#define PMC_SCDR_PCK0_Msk (0x1 << 8) //!< PCK0 Mask
/* \} */
/** \defgroup PMC_SCDR_PCK1 PCK1: Programmable Clock 1 Output Disable
 * \ingroup PMC_SCDR
 * \{
 */
#define PMC_SCDR_PCK1     (0x1 << 9) //!< PCK1 Value
#define PMC_SCDR_PCK1_Pos (9)        //!< PCK1 Position
#define PMC_SCDR_PCK1_Len (1)        //!< PCK1 Field Length
#define PMC_SCDR_PCK1_Msk (0x1 << 9) //!< PCK1 Mask
/* \} */
/** \defgroup PMC_SCDR_PCK2 PCK2: Programmable Clock 2 Output Disable
 * \ingroup PMC_SCDR
 * \{
 */
#define PMC_SCDR_PCK2     (0x1 << 10) //!< PCK2 Value
#define PMC_SCDR_PCK2_Pos (10)        //!< PCK2 Position
#define PMC_SCDR_PCK2_Len (1)         //!< PCK2 Field Length
#define PMC_SCDR_PCK2_Msk (0x1 << 10) //!< PCK2 Mask
/* \} */

/** \defgroup PMC_SCSR System Clock Status Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_SCSR_PCK0 PCK0: Programmable Clock 0 Output Status
 * \ingroup PMC_SCSR
 * \{
 */
#define PMC_SCSR_PCK0     (0x1 << 8) //!< PCK0 Value
#define PMC_SCSR_PCK0_Pos (8)        //!< PCK0 Position
#define PMC_SCSR_PCK0_Len (1)        //!< PCK0 Field Length
#define PMC_SCSR_PCK0_Msk (0x1 << 8) //!< PCK0 Mask
/* \} */
/** \defgroup PMC_SCSR_PCK1 PCK1: Programmable Clock 1 Output Status
 * \ingroup PMC_SCSR
 * \{
 */
#define PMC_SCSR_PCK1     (0x1 << 9) //!< PCK1 Value
#define PMC_SCSR_PCK1_Pos (9)        //!< PCK1 Position
#define PMC_SCSR_PCK1_Len (1)        //!< PCK1 Field Length
#define PMC_SCSR_PCK1_Msk (0x1 << 9) //!< PCK1 Mask
/* \} */
/** \defgroup PMC_SCSR_PCK2 PCK2: Programmable Clock 2 Output Status
 * \ingroup PMC_SCSR
 * \{
 */
#define PMC_SCSR_PCK2     (0x1 << 10) //!< PCK2 Value
#define PMC_SCSR_PCK2_Pos (10)        //!< PCK2 Position
#define PMC_SCSR_PCK2_Len (1)         //!< PCK2 Field Length
#define PMC_SCSR_PCK2_Msk (0x1 << 10) //!< PCK2 Mask
/* \} */

/** \defgroup PMC_PCER Peripheral Clock Enable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_PCDR Peripheral Clock Disable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_PCSR Peripheral Clock Status Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup CKGR_UCKR UTMI Clock Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup CKGR_UCKR_UPLLEN UPLLEN: UTMI PLL Enable
 * \ingroup CKGR_UCKR
 * \{
 */
#define CKGR_UCKR_UPLLEN     (0x1 << 16) //!< UPLLEN Value
#define CKGR_UCKR_UPLLEN_Pos (16)        //!< UPLLEN Position
#define CKGR_UCKR_UPLLEN_Len (1)         //!< UPLLEN Field Length
#define CKGR_UCKR_UPLLEN_Msk (0x1 << 16) //!< UPLLEN Mask
/* \} */
/** \defgroup CKGR_UCKR_UPLLCOUNT UPLLCOUNT: UTMI PLL Start-up Time
 * \ingroup CKGR_UCKR
 * \{
 */
#define CKGR_UCKR_UPLLCOUNT(v)  (((v) & 0xF) << 20) //!< UPLLCOUNT Value
#define CKGR_UCKR_UPLLCOUNT_Pos (20)                //!< UPLLCOUNT Position
#define CKGR_UCKR_UPLLCOUNT_Len (4)                 //!< UPLLCOUNT Field Length
#define CKGR_UCKR_UPLLCOUNT_Msk (0xF << 20)         //!< UPLLCOUNT Mask
/* \} */

/** \defgroup CKGR_MOR Main Oscillator Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup CKGR_MOR_MOSCXTEN MOSCXTEN: Main Crystal Oscillator Enable
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCXTEN     (0x1 << 0) //!< MOSCXTEN Value
#define CKGR_MOR_MOSCXTEN_Pos (0)        //!< MOSCXTEN Position
#define CKGR_MOR_MOSCXTEN_Len (1)        //!< MOSCXTEN Field Length
#define CKGR_MOR_MOSCXTEN_Msk (0x1 << 0) //!< MOSCXTEN Mask
/* \} */
/** \defgroup CKGR_MOR_MOSCXTBY MOSCXTBY: Main Crystal Oscillator Bypass
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCXTBY     (0x1 << 1) //!< MOSCXTBY Value
#define CKGR_MOR_MOSCXTBY_Pos (1)        //!< MOSCXTBY Position
#define CKGR_MOR_MOSCXTBY_Len (1)        //!< MOSCXTBY Field Length
#define CKGR_MOR_MOSCXTBY_Msk (0x1 << 1) //!< MOSCXTBY Mask
/* \} */
/** \defgroup CKGR_MOR_WAITMODE WAITMODE: Wait Mode Command
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_WAITMODE     (0x1 << 2) //!< WAITMODE Value
#define CKGR_MOR_WAITMODE_Pos (2)        //!< WAITMODE Position
#define CKGR_MOR_WAITMODE_Len (1)        //!< WAITMODE Field Length
#define CKGR_MOR_WAITMODE_Msk (0x1 << 2) //!< WAITMODE Mask
/* \} */
/** \defgroup CKGR_MOR_MOSCRCEN MOSCRCEN: Main On-Chip RC Oscillator Enable
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCRCEN     (0x1 << 3) //!< MOSCRCEN Value
#define CKGR_MOR_MOSCRCEN_Pos (3)        //!< MOSCRCEN Position
#define CKGR_MOR_MOSCRCEN_Len (1)        //!< MOSCRCEN Field Length
#define CKGR_MOR_MOSCRCEN_Msk (0x1 << 3) //!< MOSCRCEN Mask
/* \} */
/** \defgroup CKGR_MOR_MOSCRCF MOSCRCF: Main On-Chip RC Oscillator Frequency Selection
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCRCF(v)  (((v) & 0x7) << 4) //!< MOSCRCF Value
#define CKGR_MOR_MOSCRCF_Pos (4)                //!< MOSCRCF Position
#define CKGR_MOR_MOSCRCF_Len (3)                //!< MOSCRCF Field Length
#define CKGR_MOR_MOSCRCF_Msk (0x7 << 4)         //!< MOSCRCF Mask
/* \} */
/** \defgroup CKGR_MOR_MOSCXTST MOSCXTST: Main Crystal Oscillator Start-up Time
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCXTST(v)  (((v) & 0xFF) << 8) //!< MOSCXTST Value
#define CKGR_MOR_MOSCXTST_Pos (8)                 //!< MOSCXTST Position
#define CKGR_MOR_MOSCXTST_Len (8)                 //!< MOSCXTST Field Length
#define CKGR_MOR_MOSCXTST_Msk (0xFF << 8)         //!< MOSCXTST Mask
/* \} */
/** \defgroup CKGR_MOR_KEY KEY: Password
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_KEY     (0x37 << 16) //!< KEY Value
#define CKGR_MOR_KEY_Pos (16)         //!< KEY Position
#define CKGR_MOR_KEY_Len (8)          //!< KEY Field Length
#define CKGR_MOR_KEY_Msk (0xFF << 16) //!< KEY Mask
/* \} */
/** \defgroup CKGR_MOR_MOSCSEL MOSCSEL: Main Oscillator Selection
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_MOSCSEL     (0x1 << 24) //!< MOSCSEL Value
#define CKGR_MOR_MOSCSEL_Pos (24)        //!< MOSCSEL Position
#define CKGR_MOR_MOSCSEL_Len (1)         //!< MOSCSEL Field Length
#define CKGR_MOR_MOSCSEL_Msk (0x1 << 24) //!< MOSCSEL Mask
/* \} */
/** \defgroup CKGR_MOR_CFDEN CFDEN: Clock Failure Detector Enable
 * \ingroup CKGR_MOR
 * \{
 */
#define CKGR_MOR_CFDEN     (0x1 << 25) //!< CFDEN Value
#define CKGR_MOR_CFDEN_Pos (25)        //!< CFDEN Position
#define CKGR_MOR_CFDEN_Len (1)         //!< CFDEN Field Length
#define CKGR_MOR_CFDEN_Msk (0x1 << 25) //!< CFDEN Mask
/* \} */

/** \defgroup CKGR_MCFR Main Clock Frequency Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup CKGR_PLLAR PLLA Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup CKGR_PLLAR_DIVA DIVA: Divider
 * \ingroup CKGR_PLLAR
 * \{
 */
#define CKGR_PLLAR_DIVA(v)  (((v) & 0xFF) << 0) //!< PLLAR Value
#define CKGR_PLLAR_DIVA_Pos (0)                 //!< PLLAR Position
#define CKGR_PLLAR_DIVA_Len (8)                 //!< PLLAR Field Length
#define CKGR_PLLAR_DIVA_Msk (0xFF << 0)         //!< PLLAR Mask
/* \} */
/** \defgroup CKGR_PLLAR_PLLACOUNT PLLACOUNT: PLLA Counter
 * \ingroup CKGR_PLLAR
 * \{
 */
#define CKGR_PLLAR_PLLACOUNT(v)  (((v) & 0x3F) << 8) //!< PLLACOUNT Value
#define CKGR_PLLAR_PLLACOUNT_Pos (8)                 //!< PLLACOUNT Position
#define CKGR_PLLAR_PLLACOUNT_Len (6)                 //!< PLLACOUNT Field Length
#define CKGR_PLLAR_PLLACOUNT_Msk (0x3F << 8)         //!< PLLACOUNT Mask
/* \} */
/** \defgroup CKGR_PLLAR_MULA MULA: PLLA Multiplier
 * \ingroup CKGR_PLLAR
 * \{
 */
#define CKGR_PLLAR_MULA(v)  (((v) & 0x7FF) << 16) //!< MULA Value
#define CKGR_PLLAR_MULA_Pos (16)                  //!< MULA Position
#define CKGR_PLLAR_MULA_Len (11)                  //!< MULA Field Length
#define CKGR_PLLAR_MULA_Msk (0x7FF << 16)         //!< MULA Mask
/* \} */
/** \defgroup CKGR_PLLAR_ONE ONE: Must be set to 1
 * \ingroup CKGR_PLLAR
 * \{
 */
#define CKGR_PLLAR_ONE     (0x1 << 29) //!< ONE Value
#define CKGR_PLLAR_ONE_Pos (29)        //!< ONE Position
#define CKGR_PLLAR_ONE_Len (1)         //!< ONE Field Length
#define CKGR_PLLAR_ONE_Msk (0x1 << 29) //!< ONE Value
/* \} */

/** \defgroup PMC_MCKR Master Clock Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_MCKR_CSS CSS: Master Clock Source Selection
 * \ingroup PMC_MCKR
 * \{
 */
#define PMC_MCKR_CSS(v)  (((v) & 0x3) << 0) //!< CSS Value
#define PMC_MCKR_CSS_Pos (0)                //!< CSS Position
#define PMC_MCKR_CSS_Len (2)                //!< CSS Field Length
#define PMC_MCKR_CSS_Msk (0x3 << 0)         //!< CSS Mask
#define PMC_MCKR_CSS_SLOW_CLK (0)           //!< CSS_SLOW_CLK Value
#define PMC_MCKR_CSS_MAIN_CLK (1)           //!< CSS_MAIN_CLK Value
#define PMC_MCKR_CSS_PLLA_CLK (2)           //!< CSS_PLLA_CLK Value
#define PMC_MCKR_CSS_UPLL_CLK (3)           //!< CSS_UPLL_CLK Value
/* \} */
/** \defgroup PMC_MCKR_PRES PRES: Processor Clock Pre-scaler
 * \ingroup PMC_MCKR
 * \{
 */
#define PMC_MCKR_PRES(v)  (((v) & 0x7) << 4) //!< PRES Value
#define PMC_MCKR_PRES_Pos (4)                //!< PRES Position
#define PMC_MCKR_PRES_Len (3)                //!< PRES Field Length
#define PMC_MCKR_PRES_Msk (0x7 << 4)         //!< PRES Mask
#define PMC_MCKR_PRES_CLK_1  (0)             //!< PRES_CLK_1 Value
#define PMC_MCKR_PRES_CLK_2  (1)             //!< PRES_CLK_2 Value
#define PMC_MCKR_PRES_CLK_4  (2)             //!< PRES_CLK_4 Value
#define PMC_MCKR_PRES_CLK_8  (3)             //!< PRES_CLK_8 Value
#define PMC_MCKR_PRES_CLK_16 (4)             //!< PRES_CLK_16 Value
#define PMC_MCKR_PRES_CLK_32 (5)             //!< PRES_CLK_32 Value
#define PMC_MCKR_PRES_CLK_64 (6)             //!< PRES_CLK_64 Value
#define PMC_MCKR_PRES_CLK_3  (7)             //!< PRES_CLK_3 Value
/* \} */
/** \defgroup PMC_MCKR_UPLLDIV UPLLDIV: UPLL Divider
 * \ingroup PMC_MCKR
 * \{
 */
#define PMC_MCKR_UPLLDIV     (0x1 << 13) //!< UPLLDIV Value
#define PMC_MCKR_UPLLDIV_Pos (13)        //!< UPLLDIV Position
#define PMC_MCKR_UPLLDIV_Len (1)         //!< UPLLDIV Field Length
#define PMC_MCKR_UPLLDIV_Msk (0x1 << 13) //!< UPLLDIV Mask
/* \} */

/** \defgroup PMC_PCK0 Programmable Clock 0 Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_PCK1 Programmable Clock 1 Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_PCK2 Programmable Clock 2 Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_PCK_CSS CSS: Master Clock Source Selection
 * \ingroup PMC_PCK0
 * \ingroup PMC_PCK1
 * \ingroup PMC_PCK2
 * \{
 */
#define PMC_PCK_CSS(v)  (((v) & 0x7) << 0) //!< CSS Value
#define PMC_PCK_CSS_Pos (0)                //!< CSS Position
#define PMC_PCK_CSS_Len (3)                //!< CSS Field Length
#define PMC_PCK_CSS_Msk (0x7 << 0)         //!< CSS Mask
#define PMC_PCK_CSS_SLOW_CLK (0)           //!< CSS_SLOW_CLK Value
#define PMC_PCK_CSS_MAIN_CLK (1)           //!< CSS_MAIN_CLK Value
#define PMC_PCK_CSS_PLLA_CLK (2)           //!< CSS_PLLA_CLK Value
#define PMC_PCK_CSS_UPLL_CLK (3)           //!< CSS_UPLL_CLK Value
#define PMC_PCK_CSS_MCK      (4)           //!< CSS_MCK Value
/* \} */
/** \defgroup PMC_PCK_PRES PRES: Programmable Clock Pre-scaler
 * \ingroup PMC_PCK0
 * \ingroup PMC_PCK1
 * \ingroup PMC_PCK2 * \{
 */
#define PMC_PCK_PRES(v)  (((v) & 0x7) << 4) //!< PRES Value
#define PMC_PCK_PRES_Pos (4)                //!< PRES Position
#define PMC_PCK_PRES_Len (3)                //!< PRES Field Length
#define PMC_PCK_PRES_Msk (0x7 << 4)         //!< PRES Mask
#define PMC_PCK_PRES_CLK_1  (0)             //!< PRES_CLK_1 Value
#define PMC_PCK_PRES_CLK_2  (1)             //!< PRES_CLK_2 Value
#define PMC_PCK_PRES_CLK_4  (2)             //!< PRES_CLK_4 Value
#define PMC_PCK_PRES_CLK_8  (3)             //!< PRES_CLK_8 Value
#define PMC_PCK_PRES_CLK_16 (4)             //!< PRES_CLK_16 Value
#define PMC_PCK_PRES_CLK_32 (5)             //!< PRES_CLK_32 Value
#define PMC_PCK_PRES_CLK_64 (6)             //!< PRES_CLK_64 Value
/* \} */

/** \defgroup PMC_IER Interrupt Enable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_IDR Interrupt Disable Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_SR Status Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_SR_MOSCXTS MOSCXTS: Main XTAL Oscillator Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_MOSCXTS     (0x1 << 0) //!< MOSCXTS Value
#define PMC_SR_MOSCXTS_Pos (0)        //!< MOSCXTS Position
#define PMC_SR_MOSCXTS_Len (1)        //!< MOSCXTS Field Length
#define PMC_SR_MOSCXTS_Msk (0x1 << 0) //!< MOSCXTS Mask
/* \} */
/** \defgroup PMC_SR_LOCKA LOCKA: PLL A Lock Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_LOCKA     (0x1 << 1) //!< LOCKA Value
#define PMC_SR_LOCKA_Pos (1)        //!< LOCKA Position
#define PMC_SR_LOCKA_Len (1)        //!< LOCKA Field Length
#define PMC_SR_LOCKA_Msk (0x1 << 1) //!< LOCKA Mask
/* \} */
/** \defgroup PMC_SR_MCKRDY MCKRDY: Master Clock Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_MCKRDY     (0x1 << 3) //!< MCKRDY Value
#define PMC_SR_MCKRDY_Pos (3)        //!< MCKRDY Position
#define PMC_SR_MCKRDY_Len (1)        //!< MCKRDY Field Length
#define PMC_SR_MCKRDY_Msk (0x1 << 3) //!< MCKRDY Mask
/* \} */
/** \defgroup PMC_SR_LOCKU LOCKU: UTMI PLL Lock Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_LOCKU     (0x1 << 6) //!< LOCKU Value
#define PMC_SR_LOCKU_Pos (6)        //!< LOCKU Position
#define PMC_SR_LOCKU_Len (1)        //!< LOCKU Field Length
#define PMC_SR_LOCKU_Msk (0x1 << 6) //!< LOCKU Mask
/* \} */
/** \defgroup PMC_SR_OSCSELS OSCSELS: Slow Clock Oscillator Selection
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_OSCSELS     (0x1 << 7) //!< OSCSELS Value
#define PMC_SR_OSCSELS_Pos (7)        //!< OSCSELS Position
#define PMC_SR_OSCSELS_Len (1)        //!< OSCSELS Field Length
#define PMC_SR_OSCSELS_Msk (0x1 << 7) //!< OSCSELS Mask
/* \} */
/** \defgroup PMC_SR_PCKRDY0 PCKRDY0: Programmable Clock Ready Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_PCKRDY0     (0x1 << 8) //!< PCKRDY0 Value
#define PMC_SR_PCKRDY0_Pos (8)        //!< PCKRDY0 Position
#define PMC_SR_PCKRDY0_Len (1)        //!< PCKRDY0 Field Length
#define PMC_SR_PCKRDY0_Msk (0x1 << 8) //!< PCKRDY0 Mask
/* \} */
/** \defgroup PMC_SR_PCKRDY1 PCKRDY1: Programmable Clock Ready Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_PCKRDY1     (0x1 << 9) //!< PCKRDY1 Value
#define PMC_SR_PCKRDY1_Pos (9)        //!< PCKRDY1 Position
#define PMC_SR_PCKRDY1_Len (1)        //!< PCKRDY1 Field Length
#define PMC_SR_PCKRDY1_Msk (0x1 << 9) //!< PCKRDY1 Mask
/* \} */
/** \defgroup PMC_SR_PCKRDY2 PCKRDY2: Programmable Clock Ready Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_PCKRDY2     (0x1 << 10) //!< PCKRDY2 Value
#define PMC_SR_PCKRDY2_Pos (10)        //!< PCKRDY2 Position
#define PMC_SR_PCKRDY2_Len (1)         //!< PCKRDY2 Field Length
#define PMC_SR_PCKRDY2_Msk (0x1 << 10) //!< PCKRDY2 Mask
/* \} */
/** \defgroup PMC_SR_MOSCSELS MOSCSELS: Main Oscillator Selection Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_MOSCSELS     (0x1 << 16) //!< MOSCSELS Value
#define PMC_SR_MOSCSELS_Pos (16)        //!< MOSCSELS Position
#define PMC_SR_MOSCSELS_Len (1)         //!< MOSCSELS Field Length
#define PMC_SR_MOSCSELS_Msk (0x1 << 16) //!< MOSCSELS Mask
/* \} */
/** \defgroup PMC_SR_MOSCRCS MOSCRCS: Main On-Chip RC Oscillator Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_MOSCRCS     (0x1 << 17) //!< MOSCRCS Value
#define PMC_SR_MOSCRCS_Pos (17)        //!< MOSCRCS Position
#define PMC_SR_MOSCRCS_Len (1)         //!< MOSCRCS Field Length
#define PMC_SR_MOSCRCS_Msk (0x1 << 17) //!< MOSCRCS Mask
/* \} */
/** \defgroup PMC_SR_CFDEV CFDEV: Clock Failure Detector Event
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_CFDEV     (0x1 << 18) //!< CFDEV Value
#define PMC_SR_CFDEV_Pos (18)        //!< CFDEV Position
#define PMC_SR_CFDEV_Len (1)         //!< CFDEV Field Length
#define PMC_SR_CFDEV_Msk (0x1 << 18) //!< CFDEV Mask
/* \} */
/** \defgroup PMC_SR_CFDS CFDS: Clock Failure Detector Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_CFDS     (0x1 << 19) //!< CFDS Value
#define PMC_SR_CFDS_Pos (19)        //!< CFDS Position
#define PMC_SR_CFDS_Len (1)         //!< CFDS Field Length
#define PMC_SR_CFDS_Msk (0x1 << 19) //!< CFDS Mask
/* \} */
/** \defgroup PMC_SR_FOS FOS: Clock Failure Detector Fault Output Status
 * \ingroup PMC_SR
 * \{
 */
#define PMC_SR_FOS     (0x1 << 20) //!< FOS Value
#define PMC_SR_FOS_Pos (20)        //!< FOS Position
#define PMC_SR_FOS_Len (1)         //!< FOS Field Length
#define PMC_SR_FOS_Msk (0x1 << 20) //!< FOS Mask
/* \} */

/** \defgroup PMC_IMR Interrupt Mask Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_FSMR Fast Start-up Mode Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_FSPR Fast Start-up Polarity Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_FOCR Fault Output Clear Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_WPMR Write Protect Mode Register Bit Definitions
 * \ingroup PMC
 */

/** \defgroup PMC_WPSR Write Protect Status Register Bit Definitions
 * \ingroup PMC
 */

#endif // _CPU_PERIPHERALS_PMC_H_
