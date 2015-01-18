/**
 * \file
 *
 * \brief Supply Control (SUPC) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_SUPC_H_
#define _CPU_PERIPHERALS_SUPC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup SUPC Supply Controller (SUPC) User Interface */

/** \defgroup SUPC_UI_REG User Interface Registers
 * \ingroup SUPC
 * \{
 */
#define SUPC_CR          (*(reg_wo_t*)(SUPC+0x0000)) //!< \ref SUPC_CR
#define SUPC_SMMR        (*(reg_rw_t*)(SUPC+0x0004)) //!< \ref SUPC_SMMR
#define SUPC_MR          (*(reg_rw_t*)(SUPC+0x0008)) //!< \ref SUPC_MR
#define SUPC_WUMR        (*(reg_rw_t*)(SUPC+0x000C)) //!< \ref SUPC_WUMR
#define SUPC_WUIR        (*(reg_rw_t*)(SUPC+0x0010)) //!< \ref SUPC_WUIR
#define SUPC_SR          (*(reg_ro_t*)(SUPC+0x0014)) //!< \ref SUPC_SR
/* \} */

/** \defgroup SUPC_CR Control Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_CR_VROFF VROFF: Voltage Regulator Off
 * \ingroup SUPC_CR
 * \{
 */
#define SUPC_CR_VROFF     (0x1 << 2) //!< VROFF Value
#define SUPC_CR_VROFF_Pos (2)        //!< VROFF Position
#define SUPC_CR_VROFF_Len (1)        //!< VROFF Field Length
#define SUPC_CR_VROFF_Msk (0x1 << 2) //!< VROFF Mask
/* \} */

/** \defgroup SUPC_CR_XTALSEL XTALSEL: Crystal Oscillator Select
 * \ingroup SUPC_CR
 * \{
 */
#define SUPC_CR_XTALSEL     (0x1 << 3) //!< XTALSEL Value
#define SUPC_CR_XTALSEL_Pos (3)        //!< XTALSEL Position
#define SUPC_CR_XTALSEL_Len (1)        //!< XTALSEL Field Length
#define SUPC_CR_XTALSEL_Msk (0x1 << 3) //!< XTALSEL Mask
/* \} */

/** \defgroup SUPC_CR_KEY KEY: Password
 * \ingroup SUPC_CR
 * \{
 */
#define SUPC_CR_KEY     (0xA5 << 24) //!< KEY Value
#define SUPC_CR_KEY_Pos (24)         //!< KEY Position
#define SUPC_CR_KEY_Len (1)          //!< KEY Field Length
#define SUPC_CR_KEY_Msk (0xFF << 24) //!< KEY Mask
/* \} */

/** \defgroup SUPC_SMMR Supply Monitor Mode Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_SMMR_SMTH SMTH: Supply Monitor Threshold
 * \ingroup SUPC_SMMR
 * \{
 */
#define SUPC_SMMR_SMTH(v)  (((v) & 0xF) << 0) //!< SMTH Value
#define SUPC_SMMR_SMTH_Pos (0)                //!< SMTH Position
#define SUPC_SMMR_SMTH_Len (4)                //!< SMTH Field Length
#define SUPC_SMMR_SMTH_Msk (0xF << 0)         //!< SMTH Mask
#define SUPC_SMMR_SMTH_1_9V (0x0)             //!< 1.9V
#define SUPC_SMMR_SMTH_2_0V (0x1)             //!< 2.0V
#define SUPC_SMMR_SMTH_2_1V (0x2)             //!< 2.1V
#define SUPC_SMMR_SMTH_2_2V (0x3)             //!< 2.2V
#define SUPC_SMMR_SMTH_2_3V (0x4)             //!< 2.3V
#define SUPC_SMMR_SMTH_2_4V (0x5)             //!< 2.4V
#define SUPC_SMMR_SMTH_2_5V (0x6)             //!< 2.5V
#define SUPC_SMMR_SMTH_2_6V (0x7)             //!< 2.6V
#define SUPC_SMMR_SMTH_2_7V (0x8)             //!< 2.7V
#define SUPC_SMMR_SMTH_2_8V (0x9)             //!< 2.8V
#define SUPC_SMMR_SMTH_2_9V (0xA)             //!< 2.9V
#define SUPC_SMMR_SMTH_3_0V (0xB)             //!< 3.0V
#define SUPC_SMMR_SMTH_3_1V (0xC)             //!< 3.1V
#define SUPC_SMMR_SMTH_3_2V (0xD)             //!< 3.2V
#define SUPC_SMMR_SMTH_3_3V (0xE)             //!< 3.3V
#define SUPC_SMMR_SMTH_3_4V (0xF)             //!< 3.4V
/* \} */

/** \defgroup SUPC_SMMR_SMSMPL SMSMPL: Supply Monitor Sampling Period
 * \ingroup SUPC_SMMR
 * \{
 */
#define SUPC_SMMR_SMSMPL(v)  (((v) & 0x7) << 8) //!< SMSMPL Value
#define SUPC_SMMR_SMSMPL_Pos (8)                //!< SMSMPL Position
#define SUPC_SMMR_SMSMPL_Len (3)                //!< SMSMPL Field Length
#define SUPC_SMMR_SMSMPL_Msk (0xF << 8)         //!< SMSMPL Mask
#define SUPC_SMMR_SMSMPL_SMD       (0x0)        //!< Supply Monitor disabled
#define SUPC_SMMR_SMSMPL_DSM       (0x1)        //!< Continuous Supply Monitor
#define SUPC_SMMR_SMSMPL_32_SCLK   (0x2)        //!< Supply Monitor enabled one SLCK period every 32 SLCK periods
#define SUPC_SMMR_SMSMPL_256_SCLK  (0x3)        //!< Supply Monitor enabled one SLCK period every 256 SLCK periods
#define SUPC_SMMR_SMSMPL_2048_SCLK (0x4)        //!< Supply Monitor enabled one SLCK period every 2,048 SLCK periods
/* \} */

/** \defgroup SUPC_SMMR_SMRSTEN SMRSTEN: Supply Monitor Reset Enable
 * \ingroup SUPC_SMMR
 * \{
 */
#define SUPC_SMMR_SMRSTEN     (0x1 << 12) //!< SMRSTEN Value
#define SUPC_SMMR_SMRSTEN_Pos (12)        //!< SMRSTEN Position
#define SUPC_SMMR_SMRSTEN_Len (1)         //!< SMRSTEN Field Length
#define SUPC_SMMR_SMRSTEN_Msk (0xF << 12) //!< SMRSTEN Mask
/* \} */

/** \defgroup SUPC_SMMR_SMIEN SMIEN: Supply Monitor Interrupt Enable
 * \ingroup SUPC_SMMR
 * \{
 */
#define SUPC_SMMR_SMIEN     (0x1 << 13) //!< SMIEN Value
#define SUPC_SMMR_SMIEN_Pos (13)        //!< SMIEN Position
#define SUPC_SMMR_SMIEN_Len (1)         //!< SMIEN Field Length
#define SUPC_SMMR_SMIEN_Msk (0xF << 13) //!< SMIEN Mask
/* \} */

/** \defgroup SUPC_MR Mode Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_MR_BODRSTEN BODRSTEN: Brownout Detector Reset Enable
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_BODRSTEN     (0x1 << 12) //!< BODRSTEN Value
#define SUPC_MR_BODRSTEN_Pos (12)        //!< BODRSTEN Position
#define SUPC_MR_BODRSTEN_Len (1)         //!< BODRSTEN Field Length
#define SUPC_MR_BODRSTEN_Msk (0x1 << 12) //!< BODRSTEN Mask
/* \} */

/** \defgroup SUPC_MR_BODDIS BODDIS: Brownout Detector Reset Disable
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_BODDIS     (0x1 << 13) //!< BODDIS Value
#define SUPC_MR_BODDIS_Pos (13)        //!< BODDIS Position
#define SUPC_MR_BODDIS_Len (1)         //!< BODDIS Field Length
#define SUPC_MR_BODDIS_Msk (0x1 << 13) //!< BODDIS Mask
/* \} */

/** \defgroup SUPC_MR_VDDIORDY VDDIORDY: VDDIO Ready
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_VDDIORDY     (0x1 << 14) //!< VDDIORDY Value
#define SUPC_MR_VDDIORDY_Pos (14)        //!< VDDIORDY Position
#define SUPC_MR_VDDIORDY_Len (1)         //!< VDDIORDY Field Length
#define SUPC_MR_VDDIORDY_Msk (0x1 << 14) //!< VDDIORDY Mask
/* \} */

/** \defgroup SUPC_MR_ONREG ONREG: Voltage Regulator Enable
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_ONREG     (0x1 << 14) //!< ONREG Value
#define SUPC_MR_ONREG_Pos (14)        //!< ONREG Position
#define SUPC_MR_ONREG_Len (1)         //!< ONREG Field Length
#define SUPC_MR_ONREG_Msk (0x1 << 14) //!< ONREG Mask
/* \} */

/** \defgroup SUPC_MR_OSCBYPASS OSCBYPASS: Oscillator Bypass
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_OSCBYPASS     (0x1 << 20) //!< OSCBYPASS Value
#define SUPC_MR_OSCBYPASS_Pos (20)        //!< OSCBYPASS Position
#define SUPC_MR_OSCBYPASS_Len (1)         //!< OSCBYPASS Field Length
#define SUPC_MR_OSCBYPASS_Msk (0x1 << 20) //!< OSCBYPASS Mask
/* \} */

/** \defgroup SUPC_MR_KEY KEY: Password Key
 * \ingroup SUPC_MR
 * \{
 */
#define SUPC_MR_KEY     (0xA5 << 24) //!< KEY Value
#define SUPC_MR_KEY_Pos (24)        //!< KEY Position
#define SUPC_MR_KEY_Len (1)         //!< KEY Field Length
#define SUPC_MR_KEY_Msk (0xFF << 24) //!< KEY Mask
/* \} */

/** \defgroup SUPC_WUMR Wake Up Mode Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_WUMR_FWUPEN FWUPEN: Force Wake Up Enable
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_FWUPEN     (0x1 << 0) //!< FWUPEN Value
#define SUPC_WUMR_FWUPEN_Pos (0)        //!< FWUPEN Position
#define SUPC_WUMR_FWUPEN_Len (1)        //!< FWUPEN Field Length
#define SUPC_WUMR_FWUPEN_Msk (0x1 << 0) //!< FWUPEN Mask
/* \} */

/** \defgroup SUPC_WUMR_SMEN SMEN: Supply Monitor Wake Up Enable
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_SMEN     (0x1 << 1) //!< SMEN Value
#define SUPC_WUMR_SMEN_Pos (1)        //!< SMEN Position
#define SUPC_WUMR_SMEN_Len (1)        //!< SMEN Field Length
#define SUPC_WUMR_SMEN_Msk (0x1 << 1) //!< SMEN Mask
/* \} */

/** \defgroup SUPC_WUMR_RTTEN RTTEN: Real Time Timer Wake Up Enable
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_RTTEN     (0x1 << 2) //!< RTTEN Value
#define SUPC_WUMR_RTTEN_Pos (2)        //!< RTTEN Position
#define SUPC_WUMR_RTTEN_Len (1)        //!< RTTEN Field Length
#define SUPC_WUMR_RTTEN_Msk (0x1 << 2) //!< RTTEN Mask
/* \} */

/** \defgroup SUPC_WUMR_RTCEN RTCEN: Real Time Clock Wake Up Enable
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_RTCEN     (0x1 << 3) //!< RTCEN Value
#define SUPC_WUMR_RTCEN_Pos (3)        //!< RTCEN Position
#define SUPC_WUMR_RTCEN_Len (1)        //!< RTCEN Field Length
#define SUPC_WUMR_RTCEN_Msk (0x1 << 3) //!< RTCEN Mask
/* \} */

/** \defgroup SUPC_WUMR_FWUPDBC FWUPDBC: Force Wake Up Debouncer Period
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_FWUPDBC(v)  (((v) & 0x7) << 8) //!< FWUPDBC Value
#define SUPC_WUMR_FWUPDBC_Pos (8)                //!< FWUPDBC Position
#define SUPC_WUMR_FWUPDBC_Len (3)                //!< FWUPDBC Field Length
#define SUPC_WUMR_FWUPDBC_Msk (0x1 << 8)         //!< FWUPDBC Mask
#define SUPC_WUMR_FWUPDBC_IMMEDIATE  (0)         //!< Immediate, no debouncing, detected active at least on one Slow Clock edge.
#define SUPC_WUMR_FWUPDBC_3_SCLK     (1)         //!< FWUP shall be low for at least 3 SLCK periods
#define SUPC_WUMR_FWUPDBC_32_SCLK    (2)         //!< FWUP shall be low for at least 32 SLCK periods
#define SUPC_WUMR_FWUPDBC_512_SCLK   (3)         //!< FWUP shall be low for at least 512 SLCK periods
#define SUPC_WUMR_FWUPDBC_4096_SCLK  (4)         //!< FWUP shall be low for at least 4,096 SLCK periods
#define SUPC_WUMR_FWUPDBC_32768_SCLK (5)         //!< FWUP shall be low for at least 32,768 SLCK periods
/* \} */

/** \defgroup SUPC_WUMR_WKUPDBC WKUPDBC: Wake Up Inputs Debouncer Period
 * \ingroup SUPC_WUMR
 * \{
 */
#define SUPC_WUMR_WKUPDBC(v)  (((v) & 0x7) << 8) //!< WKUPDBC Value
#define SUPC_WUMR_WKUPDBC_Pos (8)                //!< WKUPDBC Position
#define SUPC_WUMR_WKUPDBC_Len (3)                //!< WKUPDBC Field Length
#define SUPC_WUMR_WKUPDBC_Msk (0x1 << 8)         //!< WKUPDBC Mask
#define SUPC_WUMR_WKUPDBC_IMMEDIATE  (0)         //!< Immediate, no debouncing, detected active at least on one Slow Clock edge.
#define SUPC_WUMR_WKUPDBC_3_SCLK     (1)         //!< WKUP shall be in its active state for at least 3 SLCK periods
#define SUPC_WUMR_WKUPDBC_32_SCLK    (2)         //!< WKUP shall be in its active state for at least 32 SLCK periods
#define SUPC_WUMR_WKUPDBC_512_SCLK   (3)         //!< WKUP shall be in its active state for at least 512 SLCK periods
#define SUPC_WUMR_WKUPDBC_4096_SCLK  (4)         //!< WKUP shall be in its active state for at least 4,096 SLCK periods
#define SUPC_WUMR_WKUPDBC_32768_SCLK (5)         //!< WKUP shall be in its active state for at least 32,768 SLCK periods
/* \} */

/** \defgroup SUPC_WUIR Wake Up Inputs Mode Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_WUIR_WKUPEN0 WKUPEN0: Wake Up Input Enable 0
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN0     (0x1 << 0) //!< WKUPEN0 Value
#define SUPC_WUIR_WKUPEN0_Pos (0)        //!< WKUPEN0 Position
#define SUPC_WUIR_WKUPEN0_Len (1)        //!< WKUPEN0 Field Length
#define SUPC_WUIR_WKUPEN0_Msk (0x1 << 0) //!< WKUPEN0 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN1 WKUPEN1: Wake Up Input Enable 1
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN1     (0x1 << 1) //!< WKUPEN1 Value
#define SUPC_WUIR_WKUPEN1_Pos (1)        //!< WKUPEN1 Position
#define SUPC_WUIR_WKUPEN1_Len (1)        //!< WKUPEN1 Field Length
#define SUPC_WUIR_WKUPEN1_Msk (0x1 << 1) //!< WKUPEN1 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN2 WKUPEN2: Wake Up Input Enable 2
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN2     (0x1 << 2) //!< WKUPEN2 Value
#define SUPC_WUIR_WKUPEN2_Pos (2)        //!< WKUPEN2 Position
#define SUPC_WUIR_WKUPEN2_Len (1)        //!< WKUPEN2 Field Length
#define SUPC_WUIR_WKUPEN2_Msk (0x1 << 2) //!< WKUPEN2 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN3 WKUPEN3: Wake Up Input Enable 3
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN3     (0x1 << 3) //!< WKUPEN3 Value
#define SUPC_WUIR_WKUPEN3_Pos (3)        //!< WKUPEN3 Position
#define SUPC_WUIR_WKUPEN3_Len (1)        //!< WKUPEN3 Field Length
#define SUPC_WUIR_WKUPEN3_Msk (0x1 << 3) //!< WKUPEN3 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN4 WKUPEN4: Wake Up Input Enable 4
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN4     (0x1 << 4) //!< WKUPEN4 Value
#define SUPC_WUIR_WKUPEN4_Pos (4)        //!< WKUPEN4 Position
#define SUPC_WUIR_WKUPEN4_Len (1)        //!< WKUPEN4 Field Length
#define SUPC_WUIR_WKUPEN4_Msk (0x1 << 4) //!< WKUPEN4 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN5 WKUPEN5: Wake Up Input Enable 5
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN5     (0x1 << 5) //!< WKUPEN5 Value
#define SUPC_WUIR_WKUPEN5_Pos (5)        //!< WKUPEN5 Position
#define SUPC_WUIR_WKUPEN5_Len (1)        //!< WKUPEN5 Field Length
#define SUPC_WUIR_WKUPEN5_Msk (0x1 << 5) //!< WKUPEN5 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN6 WKUPEN6: Wake Up Input Enable 6
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN6     (0x1 << 6) //!< WKUPEN6 Value
#define SUPC_WUIR_WKUPEN6_Pos (6)        //!< WKUPEN6 Position
#define SUPC_WUIR_WKUPEN6_Len (1)        //!< WKUPEN6 Field Length
#define SUPC_WUIR_WKUPEN6_Msk (0x1 << 6) //!< WKUPEN6 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN7 WKUPEN7: Wake Up Input Enable 7
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN7     (0x1 << 7) //!< WKUPEN7 Value
#define SUPC_WUIR_WKUPEN7_Pos (7)        //!< WKUPEN7 Position
#define SUPC_WUIR_WKUPEN7_Len (1)        //!< WKUPEN7 Field Length
#define SUPC_WUIR_WKUPEN7_Msk (0x1 << 7) //!< WKUPEN7 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN8 WKUPEN8: Wake Up Input Enable 8
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN8     (0x1 << 8) //!< WKUPEN8 Value
#define SUPC_WUIR_WKUPEN8_Pos (8)        //!< WKUPEN8 Position
#define SUPC_WUIR_WKUPEN8_Len (1)        //!< WKUPEN8 Field Length
#define SUPC_WUIR_WKUPEN8_Msk (0x1 << 8) //!< WKUPEN8 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN9 WKUPEN9: Wake Up Input Enable 9
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN9     (0x1 << 9) //!< WKUPEN9 Value
#define SUPC_WUIR_WKUPEN9_Pos (9)        //!< WKUPEN9 Position
#define SUPC_WUIR_WKUPEN9_Len (1)        //!< WKUPEN9 Field Length
#define SUPC_WUIR_WKUPEN9_Msk (0x1 << 9) //!< WKUPEN9 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN10 WKUPEN10: Wake Up Input Enable 10
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN10     (0x1 << 10) //!< WKUPEN10 Value
#define SUPC_WUIR_WKUPEN10_Pos (10)        //!< WKUPEN10 Position
#define SUPC_WUIR_WKUPEN10_Len (1)         //!< WKUPEN10 Field Length
#define SUPC_WUIR_WKUPEN10_Msk (0x1 << 10) //!< WKUPEN10 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN11 WKUPEN11: Wake Up Input Enable 11
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN11     (0x1 << 11) //!< WKUPEN11 Value
#define SUPC_WUIR_WKUPEN11_Pos (11)        //!< WKUPEN11 Position
#define SUPC_WUIR_WKUPEN11_Len (1)         //!< WKUPEN11 Field Length
#define SUPC_WUIR_WKUPEN11_Msk (0x1 << 11) //!< WKUPEN11 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN12 WKUPEN12: Wake Up Input Enable 12
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN12     (0x1 << 12) //!< WKUPEN12 Value
#define SUPC_WUIR_WKUPEN12_Pos (12)        //!< WKUPEN12 Position
#define SUPC_WUIR_WKUPEN12_Len (1)         //!< WKUPEN12 Field Length
#define SUPC_WUIR_WKUPEN12_Msk (0x1 << 12) //!< WKUPEN12 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN13 WKUPEN13: Wake Up Input Enable 13
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN13     (0x1 << 13) //!< WKUPEN13 Value
#define SUPC_WUIR_WKUPEN13_Pos (13)        //!< WKUPEN13 Position
#define SUPC_WUIR_WKUPEN13_Len (1)         //!< WKUPEN13 Field Length
#define SUPC_WUIR_WKUPEN13_Msk (0x1 << 13) //!< WKUPEN13 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN14 WKUPEN14: Wake Up Input Enable 14
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN14     (0x1 << 14) //!< WKUPEN14 Value
#define SUPC_WUIR_WKUPEN14_Pos (14)        //!< WKUPEN14 Position
#define SUPC_WUIR_WKUPEN14_Len (1)         //!< WKUPEN14 Field Length
#define SUPC_WUIR_WKUPEN14_Msk (0x1 << 14) //!< WKUPEN14 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPEN15 WKUPEN15: Wake Up Input Enable 15
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPEN15     (0x1 << 15) //!< WKUPEN15 Value
#define SUPC_WUIR_WKUPEN15_Pos (15)        //!< WKUPEN15 Position
#define SUPC_WUIR_WKUPEN15_Len (1)         //!< WKUPEN15 Field Length
#define SUPC_WUIR_WKUPEN15_Msk (0x1 << 15) //!< WKUPEN15 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT0 WKUPT0: Wake Up Input Transition 0
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT0     (0x1 << 16) //!< WKUPT0 Value
#define SUPC_WUIR_WKUPT0_Pos (16)        //!< WKUPT0 Position
#define SUPC_WUIR_WKUPT0_Len (1)         //!< WKUPT0 Field Length
#define SUPC_WUIR_WKUPT0_Msk (0x1 << 16) //!< WKUPT0 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT1 WKUPT1: Wake Up Input Transition 1
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT1     (0x1 << 17) //!< WKUPT1 Value
#define SUPC_WUIR_WKUPT1_Pos (17)        //!< WKUPT1 Position
#define SUPC_WUIR_WKUPT1_Len (1)         //!< WKUPT1 Field Length
#define SUPC_WUIR_WKUPT1_Msk (0x1 << 17) //!< WKUPT1 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT2 WKUPT2: Wake Up Input Transition 2
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT2     (0x1 << 18) //!< WKUPT2 Value
#define SUPC_WUIR_WKUPT2_Pos (18)        //!< WKUPT2 Position
#define SUPC_WUIR_WKUPT2_Len (1)         //!< WKUPT2 Field Length
#define SUPC_WUIR_WKUPT2_Msk (0x1 << 18) //!< WKUPT2 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT3 WKUPT3: Wake Up Input Transition 3
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT3     (0x1 << 19) //!< WKUPT3 Value
#define SUPC_WUIR_WKUPT3_Pos (19)        //!< WKUPT3 Position
#define SUPC_WUIR_WKUPT3_Len (1)         //!< WKUPT3 Field Length
#define SUPC_WUIR_WKUPT3_Msk (0x1 << 19) //!< WKUPT3 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT4 WKUPT4: Wake Up Input Transition 4
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT4     (0x1 << 20) //!< WKUPT4 Value
#define SUPC_WUIR_WKUPT4_Pos (20)        //!< WKUPT4 Position
#define SUPC_WUIR_WKUPT4_Len (1)         //!< WKUPT4 Field Length
#define SUPC_WUIR_WKUPT4_Msk (0x1 << 20) //!< WKUPT4 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT5 WKUPT5: Wake Up Input Transition 5
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT5     (0x1 << 21) //!< WKUPT5 Value
#define SUPC_WUIR_WKUPT5_Pos (21)        //!< WKUPT5 Position
#define SUPC_WUIR_WKUPT5_Len (1)         //!< WKUPT5 Field Length
#define SUPC_WUIR_WKUPT5_Msk (0x1 << 21) //!< WKUPT5 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT6 WKUPT6: Wake Up Input Transition 6
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT6     (0x1 << 22) //!< WKUPT6 Value
#define SUPC_WUIR_WKUPT6_Pos (22)        //!< WKUPT6 Position
#define SUPC_WUIR_WKUPT6_Len (1)         //!< WKUPT6 Field Length
#define SUPC_WUIR_WKUPT6_Msk (0x1 << 22) //!< WKUPT6 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT7 WKUPT7: Wake Up Input Transition 7
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT7     (0x1 << 23) //!< WKUPT7 Value
#define SUPC_WUIR_WKUPT7_Pos (23)        //!< WKUPT7 Position
#define SUPC_WUIR_WKUPT7_Len (1)         //!< WKUPT7 Field Length
#define SUPC_WUIR_WKUPT7_Msk (0x1 << 23) //!< WKUPT7 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT8 WKUPT8: Wake Up Input Transition 8
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT8     (0x1 << 24) //!< WKUPT8 Value
#define SUPC_WUIR_WKUPT8_Pos (24)        //!< WKUPT8 Position
#define SUPC_WUIR_WKUPT8_Len (1)         //!< WKUPT8 Field Length
#define SUPC_WUIR_WKUPT8_Msk (0x1 << 24) //!< WKUPT8 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT9 WKUPT9: Wake Up Input Transition 9
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT9     (0x1 << 25) //!< WKUPT9 Value
#define SUPC_WUIR_WKUPT9_Pos (25)        //!< WKUPT9 Position
#define SUPC_WUIR_WKUPT9_Len (1)         //!< WKUPT9 Field Length
#define SUPC_WUIR_WKUPT9_Msk (0x1 << 25) //!< WKUPT9 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT10 WKUPT10: Wake Up Input Transition 10
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT10     (0x1 << 26) //!< WKUPT10 Value
#define SUPC_WUIR_WKUPT10_Pos (26)        //!< WKUPT10 Position
#define SUPC_WUIR_WKUPT10_Len (1)         //!< WKUPT10 Field Length
#define SUPC_WUIR_WKUPT10_Msk (0x1 << 26) //!< WKUPT10 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT11 WKUPT11: Wake Up Input Transition 11
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT11     (0x1 << 27) //!< WKUPT11 Value
#define SUPC_WUIR_WKUPT11_Pos (27)        //!< WKUPT11 Position
#define SUPC_WUIR_WKUPT11_Len (1)         //!< WKUPT11 Field Length
#define SUPC_WUIR_WKUPT11_Msk (0x1 << 27) //!< WKUPT11 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT12 WKUPT12: Wake Up Input Transition 12
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT12     (0x1 << 28) //!< WKUPT12 Value
#define SUPC_WUIR_WKUPT12_Pos (28)        //!< WKUPT12 Position
#define SUPC_WUIR_WKUPT12_Len (1)         //!< WKUPT12 Field Length
#define SUPC_WUIR_WKUPT12_Msk (0x1 << 28) //!< WKUPT12 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT13 WKUPT13: Wake Up Input Transition 13
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT13     (0x1 << 29) //!< WKUPT13 Value
#define SUPC_WUIR_WKUPT13_Pos (29)        //!< WKUPT13 Position
#define SUPC_WUIR_WKUPT13_Len (1)         //!< WKUPT13 Field Length
#define SUPC_WUIR_WKUPT13_Msk (0x1 << 29) //!< WKUPT13 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT14 WKUPT14: Wake Up Input Transition 14
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT14     (0x1 << 30) //!< WKUPT14 Value
#define SUPC_WUIR_WKUPT14_Pos (30)        //!< WKUPT14 Position
#define SUPC_WUIR_WKUPT14_Len (1)         //!< WKUPT14 Field Length
#define SUPC_WUIR_WKUPT14_Msk (0x1 << 30) //!< WKUPT14 Mask
/* \} */

/** \defgroup SUPC_WUIR_WKUPT15 WKUPT15: Wake Up Input Transition 15
 * \ingroup SUPC_WUIR
 * \{
 */
#define SUPC_WUIR_WKUPT15     (0x1 << 31) //!< WKUPT15 Value
#define SUPC_WUIR_WKUPT15_Pos (31)        //!< WKUPT15 Position
#define SUPC_WUIR_WKUPT15_Len (1)         //!< WKUPT15 Field Length
#define SUPC_WUIR_WKUPT15_Msk (0x1 << 31) //!< WKUPT15 Mask
/* \} */

/** \defgroup SUPC_SR Status Register Bit Definitions
 * \ingroup SUPC
 */

/** \defgroup SUPC_SR_FWUPS FWUPS: FWUP Wake Up Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_FWUPS     (0x1 << 0) //!< FWUPS Value
#define SUPC_SR_FWUPS_Pos (0)        //!< FWUPS Position
#define SUPC_SR_FWUPS_Len (1)        //!< FWUPS Field Length
#define SUPC_SR_FWUPS_Msk (0x1 << 0) //!< FWUPS Mask
/* \} */

/** \defgroup SUPC_SR_WKUPS WKUPS: WKUP Wake Up Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPS     (0x1 << 1) //!< WKUPS Value
#define SUPC_SR_WKUPS_Pos (1)        //!< WKUPS Position
#define SUPC_SR_WKUPS_Len (1)        //!< WKUPS Field Length
#define SUPC_SR_WKUPS_Msk (0x1 << 1) //!< WKUPS Mask
/* \} */

/** \defgroup SUPC_SR_SMWS SMWS: Supply Monitor Detection Wake Up Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_SMWS     (0x1 << 2) //!< SMWS Value
#define SUPC_SR_SMWS_Pos (2)        //!< SMWS Position
#define SUPC_SR_SMWS_Len (1)        //!< SMWS Field Length
#define SUPC_SR_SMWS_Msk (0x1 << 2) //!< SMWS Mask
/* \} */

/** \defgroup SUPC_SR_BODRSTS BODRSTS: Brownout Detector Reset Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_BODRSTS     (0x1 << 3) //!< BODRSTS Value
#define SUPC_SR_BODRSTS_Pos (3)        //!< BODRSTS Position
#define SUPC_SR_BODRSTS_Len (1)        //!< BODRSTS Field Length
#define SUPC_SR_BODRSTS_Msk (0x1 << 3) //!< BODRSTS Mask
/* \} */

/** \defgroup SUPC_SR_SMRSTS SMRSTS: Supply Monitor Reset Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_SMRSTS     (0x1 << 4) //!< SMRSTS Value
#define SUPC_SR_SMRSTS_Pos (4)        //!< SMRSTS Position
#define SUPC_SR_SMRSTS_Len (1)        //!< SMRSTS Field Length
#define SUPC_SR_SMRSTS_Msk (0x1 << 4) //!< SMRSTS Mask
/* \} */

/** \defgroup SUPC_SR_SMS SMS: Supply Monitor Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_SMS     (0x1 << 5) //!< SMS Value
#define SUPC_SR_SMS_Pos (5)        //!< SMS Position
#define SUPC_SR_SMS_Len (1)        //!< SMS Field Length
#define SUPC_SR_SMS_Msk (0x1 << 5) //!< SMS Mask
/* \} */

/** \defgroup SUPC_SR_SMOS SMOS: Supply Monitor Output Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_SMOS     (0x1 << 6) //!< SMOS Value
#define SUPC_SR_SMOS_Pos (6)        //!< SMOS Position
#define SUPC_SR_SMOS_Len (1)        //!< SMOS Field Length
#define SUPC_SR_SMOS_Msk (0x1 << 6) //!< SMOS Mask
/* \} */

/** \defgroup SUPC_SR_OSCSEL OSCSEL: 32kHz Oscillator Selection Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_OSCSEL     (0x1 << 7) //!< OSCSEL Value
#define SUPC_SR_OSCSEL_Pos (7)        //!< OSCSEL Position
#define SUPC_SR_OSCSEL_Len (1)        //!< OSCSEL Field Length
#define SUPC_SR_OSCSEL_Msk (0x1 << 7) //!< OSCSEL Mask
/* \} */

/** \defgroup SUPC_SR_FWUPDIS FWUPDIS: FWUP Input Status
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_FWUPDIS     (0x1 << 12) //!< FWUPDIS Value
#define SUPC_SR_FWUPDIS_Pos (12)        //!< FWUPDIS Position
#define SUPC_SR_FWUPDIS_Len (1)         //!< FWUPDIS Field Length
#define SUPC_SR_FWUPDIS_Msk (0x1 << 12) //!< FWUPDIS Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 0
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS0     (0x1 << 16) //!< WKUPIS0 Value
#define SUPC_SR_WKUPIS0_Pos (16)        //!< WKUPIS0 Position
#define SUPC_SR_WKUPIS0_Len (1)         //!< WKUPIS0 Field Length
#define SUPC_SR_WKUPIS0_Msk (0x1 << 16) //!< WKUPIS0 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 1
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS1     (0x1 << 17) //!< WKUPIS1 Value
#define SUPC_SR_WKUPIS1_Pos (17)        //!< WKUPIS1 Position
#define SUPC_SR_WKUPIS1_Len (1)         //!< WKUPIS1 Field Length
#define SUPC_SR_WKUPIS1_Msk (0x1 << 17) //!< WKUPIS1 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 2
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS2     (0x1 << 18) //!< WKUPIS2 Value
#define SUPC_SR_WKUPIS2_Pos (18)        //!< WKUPIS2 Position
#define SUPC_SR_WKUPIS2_Len (1)         //!< WKUPIS2 Field Length
#define SUPC_SR_WKUPIS2_Msk (0x1 << 18) //!< WKUPIS2 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 3
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS3     (0x1 << 19) //!< WKUPIS3 Value
#define SUPC_SR_WKUPIS3_Pos (19)        //!< WKUPIS3 Position
#define SUPC_SR_WKUPIS3_Len (1)         //!< WKUPIS3 Field Length
#define SUPC_SR_WKUPIS3_Msk (0x1 << 19) //!< WKUPIS3 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 4
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS4     (0x1 << 20) //!< WKUPIS4 Value
#define SUPC_SR_WKUPIS4_Pos (20)        //!< WKUPIS4 Position
#define SUPC_SR_WKUPIS4_Len (1)         //!< WKUPIS4 Field Length
#define SUPC_SR_WKUPIS4_Msk (0x1 << 20) //!< WKUPIS4 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 5
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS5     (0x1 << 21) //!< WKUPIS5 Value
#define SUPC_SR_WKUPIS5_Pos (21)        //!< WKUPIS5 Position
#define SUPC_SR_WKUPIS5_Len (1)         //!< WKUPIS5 Field Length
#define SUPC_SR_WKUPIS5_Msk (0x1 << 21) //!< WKUPIS5 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 6
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS6     (0x1 << 22) //!< WKUPIS6 Value
#define SUPC_SR_WKUPIS6_Pos (22)        //!< WKUPIS6 Position
#define SUPC_SR_WKUPIS6_Len (1)         //!< WKUPIS6 Field Length
#define SUPC_SR_WKUPIS6_Msk (0x1 << 22) //!< WKUPIS6 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 7
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS7     (0x1 << 23) //!< WKUPIS7 Value
#define SUPC_SR_WKUPIS7_Pos (23)        //!< WKUPIS7 Position
#define SUPC_SR_WKUPIS7_Len (1)         //!< WKUPIS7 Field Length
#define SUPC_SR_WKUPIS7_Msk (0x1 << 23) //!< WKUPIS7 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 8
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS8     (0x1 << 24) //!< WKUPIS8 Value
#define SUPC_SR_WKUPIS8_Pos (24)        //!< WKUPIS8 Position
#define SUPC_SR_WKUPIS8_Len (1)         //!< WKUPIS8 Field Length
#define SUPC_SR_WKUPIS8_Msk (0x1 << 24) //!< WKUPIS8 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 9
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS9     (0x1 << 25) //!< WKUPIS9 Value
#define SUPC_SR_WKUPIS9_Pos (25)        //!< WKUPIS9 Position
#define SUPC_SR_WKUPIS9_Len (1)         //!< WKUPIS9 Field Length
#define SUPC_SR_WKUPIS9_Msk (0x1 << 25) //!< WKUPIS9 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 10
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS10     (0x1 << 26) //!< WKUPIS10 Value
#define SUPC_SR_WKUPIS10_Pos (26)        //!< WKUPIS10 Position
#define SUPC_SR_WKUPIS10_Len (1)         //!< WKUPIS10 Field Length
#define SUPC_SR_WKUPIS10_Msk (0x1 << 26) //!< WKUPIS10 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 11
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS11     (0x1 << 27) //!< WKUPIS11 Value
#define SUPC_SR_WKUPIS11_Pos (27)        //!< WKUPIS11 Position
#define SUPC_SR_WKUPIS11_Len (1)         //!< WKUPIS11 Field Length
#define SUPC_SR_WKUPIS11_Msk (0x1 << 27) //!< WKUPIS11 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 12
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS12     (0x1 << 28) //!< WKUPIS12 Value
#define SUPC_SR_WKUPIS12_Pos (28)        //!< WKUPIS12 Position
#define SUPC_SR_WKUPIS12_Len (1)         //!< WKUPIS12 Field Length
#define SUPC_SR_WKUPIS12_Msk (0x1 << 28) //!< WKUPIS12 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 13
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS13     (0x1 << 29) //!< WKUPIS13 Value
#define SUPC_SR_WKUPIS13_Pos (29)        //!< WKUPIS13 Position
#define SUPC_SR_WKUPIS13_Len (1)         //!< WKUPIS13 Field Length
#define SUPC_SR_WKUPIS13_Msk (0x1 << 29) //!< WKUPIS13 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 14
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS14     (0x1 << 30) //!< WKUPIS14 Value
#define SUPC_SR_WKUPIS14_Pos (30)        //!< WKUPIS14 Position
#define SUPC_SR_WKUPIS14_Len (1)         //!< WKUPIS14 Field Length
#define SUPC_SR_WKUPIS14_Msk (0x1 << 30) //!< WKUPIS14 Mask
/* \} */

/** \defgroup SUPC_SR_WKUPIS0 WKUPIS0: WKUP Input Status 15
 * \ingroup SUPC_SR
 * \{
 */
#define SUPC_SR_WKUPIS15     (0x1 << 31) //!< WKUPIS15 Value
#define SUPC_SR_WKUPIS15_Pos (31)        //!< WKUPIS15 Position
#define SUPC_SR_WKUPIS15_Len (1)         //!< WKUPIS15 Field Length
#define SUPC_SR_WKUPIS15_Msk (0x1 << 31) //!< WKUPIS15 Mask
/* \} */

#endif // _CPU_PERIPHERALS_SUPC_H_
