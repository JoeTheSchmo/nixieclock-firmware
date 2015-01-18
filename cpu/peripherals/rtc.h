/**
 * \file
 *
 * \brief Real Time Clock (RTC) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_RTC_H_
#define _CPU_PERIPHERALS_RTC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup RTC Real Time Clock (RTC) User Interface */

/** \defgroup RTC_UI_REG User Interface Registers
 * \ingroup RTC
 * \{
 */
#define RTC_CR           (*(reg_rw_t*)(RTC+0x0000)) //!< \ref RTC_CR
#define RTC_MR           (*(reg_rw_t*)(RTC+0x0004)) //!< \ref RTC_MR
#define RTC_TIMR         (*(reg_rw_t*)(RTC+0x0008)) //!< \ref RTC_TIMR
#define RTC_CALR         (*(reg_rw_t*)(RTC+0x000C)) //!< \ref RTC_CALR
#define RTC_TIMALR       (*(reg_rw_t*)(RTC+0x0010)) //!< \ref RTC_TIMALR
#define RTC_CALALR       (*(reg_rw_t*)(RTC+0x0014)) //!< \ref RTC_CALALR
#define RTC_SR           (*(reg_ro_t*)(RTC+0x0018)) //!< \ref RTC_SR
#define RTC_SCCR         (*(reg_wo_t*)(RTC+0x001C)) //!< \ref RTC_SCCR
#define RTC_IER          (*(reg_wo_t*)(RTC+0x0020)) //!< \ref RTC_IER
#define RTC_IDR          (*(reg_wo_t*)(RTC+0x0024)) //!< \ref RTC_IDR
#define RTC_IMR          (*(reg_ro_t*)(RTC+0x0028)) //!< \ref RTC_IMR
#define RTC_VER          (*(reg_ro_t*)(RTC+0x002C)) //!< \ref RTC_VER
#define RTC_WPMR         (*(reg_rw_t*)(RTC+0x00E4)) //!< \ref RTC_WPMR
/* \} */

/** \defgroup RTC_CR Control Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_CR_UPDTIM UPDTIM: Update Request Time Register
 * \ingroup RTC_CR
 * \{
 */
#define RTC_CR_UPDTIM     (0x1 << 0) //!< UPDTIM Value
#define RTC_CR_UPDTIM_Pos (0)        //!< UPDTIM Position
#define RTC_CR_UPDTIM_Len (1)        //!< UPDTIM Field Length
#define RTC_CR_UPDTIM_Msk (0x1 << 0) //!< UPDTIM Mask
/* \} */
/** \defgroup RTC_CR_UPDCAL UDPCAL: Update Request Calendar Register
 * \ingroup RTC_CR
 * \{
 */
#define RTC_CR_UPDCAL     (0x1 << 1) //!< UPDCAL Value
#define RTC_CR_UPDCAL_Pos (1)        //!< UPDCAL Position
#define RTC_CR_UPDCAL_Len (1)        //!< UPDCAL Field Length
#define RTC_CR_UPDCAL_Msk (0x1 << 1) //!< UPDCAL Mask
/* \} */
/** \defgroup RTC_CR_TIMEVSEL TIMEVSEL: Time Event Selection
 * \ingroup RTC_CR
 * \{
 */
#define RTC_CR_TIMEVSEL(v)  (((v) & 0x3) << 8) //!< TIMEVSEL Value
#define RTC_CR_TIMEVSEL_Pos (8)                //!< TIMEVSEL Position
#define RTC_CR_TIMEVSEL_Len (2)                //!< TIMEVSEL Field Length
#define RTC_CR_TIMEVSEL_Msk (0x3 << 8)         //!< TIMEVSEL Mask
#define RTC_CR_TIMEVSEL_MINUTE (0)             //!< TIMEVSEL_MINUTE Value
#define RTC_CR_TIMEVSEL_HOUR (1)               //!< TIMEVSEL_HOUR Value
#define RTC_CR_TIMEVSEL_MIDNIGHT (2)           //!< TIMEVSEL_MIDNIGHT Value
#define RTC_CR_TIMEVSEL_NOON (3)               //!< TIMEVSEL_NOON Value
/* \} */
/** \defgroup RTC_CR_CALEVSEL CALEVSEL: Calendar Event Selection
 * \ingroup RTC_CR
 * \{
 */
#define RTC_CR_CALEVSEL(v)  (((v) & 0x3) << 16) //!< CALEVSEL Value
#define RTC_CR_CALEVSEL_Pos (16)                //!< CALEVSEL Position
#define RTC_CR_CALEVSEL_Len (2)                 //!< CALEVSEL Field Length
#define RTC_CR_CALEVSEL_Msk (0x3 << 16)         //!< CALEVSEL Mask
#define RTC_CR_CALEVSEL_WEEK (0)                //!< CALEVSEL_WEEK Value
#define RTC_CR_CALEVSEL_MONTH (1)               //!< CALEVSEL_MONTH Value
#define RTC_CR_CALEVSEL_YEAR (2)                //!< CALEVSEL_YEAR Value
/* \} */

/** \defgroup RTC_MR Mode Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_MR_HRMOD HRMOD: 12/24 Hour Mode
 * \ingroup RTC_MR
 * \{
 */
#define RTC_MR_HRMOD     (0x1 << 0) //!< HRMOD Value
#define RTC_MR_HRMOD_Pos (0)        //!< HRMOD Position
#define RTC_MR_HRMOD_Len (1)        //!< HRMOD Field Length
#define RTC_MR_HRMOD_Msk (0x1 << 0) //!< HRMOD Mask
/* \} */

/** \defgroup RTC_TIMR Time Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_TIMR_SEC SEC: Current Second
 * \ingroup RTC_TIMR
 * \{
 */
#define RTC_TIMR_SEC(v)  (((v) & 0x7F) << 0) //!< SEC Value
#define RTC_TIMR_SEC_Pos (0)                 //!< SEC Position
#define RTC_TIMR_SEC_Len (7)                 //!< SEC Field Length
#define RTC_TIMR_SEC_Msk (0x7F << 0)         //!< SEC Mask
/* \} */
/** \defgroup RTC_TIMR_MIN MIN: Current Minute
 * \ingroup RTC_TIMR
 * \{
 */
#define RTC_TIMR_MIN(v)  (((v) & 0x7F) << 8) //!< MIN Value
#define RTC_TIMR_MIN_Pos (8)                 //!< MIN Position
#define RTC_TIMR_MIN_Len (7)                 //!< MIN Field Length
#define RTC_TIMR_MIN_Msk (0x7F << 8)         //!< MIN Mask
/* \} */
/** \defgroup RTC_TIMR_HOUR HOUR: Current Hour
 * \ingroup RTC_TIMR
 * \{
 */
#define RTC_TIMR_HOUR(v)  (((v) & 0x3F) << 16) //!< HOUR Value
#define RTC_TIMR_HOUR_Pos (16)                 //!< HOUR Position
#define RTC_TIMR_HOUR_Len (6)                  //!< HOUR Field Length
#define RTC_TIMR_HOUR_Msk (0x3F << 16)         //!< HOUR Mask
/* \} */
/** \defgroup RTC_TIMR_AMPM AMPM: Ante Meridiem Post Meridiem Indicator
 * \ingroup RTC_TIMR
 * \{
 */
#define RTC_TIMR_AMPM     (0x1 << 22) //!< AMPM Value
#define RTC_TIMR_AMPM_Pos (22)        //!< AMPM Position
#define RTC_TIMR_AMPM_Len (1)         //!< AMPM Field Length
#define RTC_TIMR_AMPM_Msk (0x1 << 22) //!< AMPM Mask
/* \} */

/** \defgroup RTC_CALR Calendar Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_CALR_CENT CENT: Current Century (19-20)
 * \ingroup RTC_CALR
 * \{
 */
#define RTC_CALR_CENT(v)  (((v) & 0x7F) << 0) //!< CENT Value
#define RTC_CALR_CENT_Pos (0)                 //!< CENT Position
#define RTC_CALR_CENT_Len (7)                 //!< CENT Field Length
#define RTC_CALR_CENT_Msk (0x7F << 0)         //!< CENT Mask
/* \} */
/** \defgroup RTC_CALR_YEAR YEAR: Current Year (0 - 99)
 * \ingroup RTC_CALR
 * \{
 */
#define RTC_CALR_YEAR(v)  (((v) & 0xFF) << 8) //!< YEAR Value
#define RTC_CALR_YEAR_Pos (8)                 //!< YEAR Position
#define RTC_CALR_YEAR_Len (8)                 //!< YEAR Field Length
#define RTC_CALR_YEAR_Msk (0xFF << 8)         //!< YEAR Mask
/* \} */
/** \defgroup RTC_CALR_MONTH MONTH: Current Month (1 - 12)
 * \ingroup RTC_CALR
 * \{
 */
#define RTC_CALR_MONTH(v)  (((v) & 0x1F) << 16) //!< MONTH Value
#define RTC_CALR_MONTH_Pos (16)                 //!< MONTH Position
#define RTC_CALR_MONTH_Len (5)                  //!< MONTH Field Length
#define RTC_CALR_MONTH_Msk (0x1F << 16)         //!< MONTH Mask
/* \} */
/** \defgroup RTC_CALR_DAY DAY: Current Day in Current Week (1 - 7)
 * \ingroup RTC_CALR
 * \{
 */
#define RTC_CALR_DAY(v)  (((v) & 0x7) << 21) //!< DAY Value
#define RTC_CALR_DAY_Pos (21)                //!< DAY Position
#define RTC_CALR_DAY_Len (3)                 //!< DAY Field Length
#define RTC_CALR_DAY_Msk (0x7 << 21)         //!< DAY Mask
/* \} */
/** \defgroup RTC_CALR_DATE DATE: Current Day in Current Month (1 - 31)
 * \ingroup RTC_CALR
 * \{
 */
#define RTC_CALR_DATE(v)  (((v) & 0x3F) << 24) //!< DATE Value
#define RTC_CALR_DATE_Pos (24)                 //!< DATE Position
#define RTC_CALR_DATE_Len (6)                  //!< DATE Field Length
#define RTC_CALR_DATE_Msk (0x3F << 24)         //!< DATE Mask
/* \} */

/** \defgroup RTC_TIMALR Time Alarm Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_TIMALR_SEC SEC: Second Alarm
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_SEC(v)  (((v) & 0x7F) << 0) //!< SEC Value
#define RTC_TIMALR_SEC_Pos (0)                 //!< SEC Position
#define RTC_TIMALR_SEC_Len (7)                 //!< SEC Field Length
#define RTC_TIMALR_SEC_Msk (0x7F << 0)         //!< SEC Mask
/* \} */
/** \defgroup RTC_TIMALR_SECEN SECEN: Second Alarm Enable
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_SECEN     (0x1 << 7) //!< SECEN Value
#define RTC_TIMALR_SECEN_Pos (7)        //!< SECEN Position
#define RTC_TIMALR_SECEN_Len (1)        //!< SECEN Field Length
#define RTC_TIMALR_SECEN_Msk (0x1 << 7) //!< SECEN Mask
/* \} */
/** \defgroup RTC_TIMALR_MIN MIN: Minute Alarm
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_MIN(v)  (((v) & 0x7F) << 8) //!< MIN Value
#define RTC_TIMALR_MIN_Pos (8)                 //!< MIN Position
#define RTC_TIMALR_MIN_Len (7)                 //!< MIN Field Length
#define RTC_TIMALR_MIN_Msk (0x7F << 8)         //!< MIN Mask
/* \} */
/** \defgroup RTC_TIMALR_MINEN MINEN: Minute Alarm Enable
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_MINEN     (0x1 << 15) //!< MINEN Value
#define RTC_TIMALR_MINEN_Pos (15)        //!< MINEN Position
#define RTC_TIMALR_MINEN_Len (1)         //!< MINEN Field Length
#define RTC_TIMALR_MINEN_Msk (0x1 << 15) //!< MINEN Mask
/* \} */
/** \defgroup RTC_TIMALR_HOUR HOUR: Hour Alarm
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_HOUR(v)  (((v) & 0x3F) << 16) //!< HOUR Value
#define RTC_TIMALR_HOUR_Pos (16)                 //!< HOUR Position
#define RTC_TIMALR_HOUR_Len (6)                  //!< HOUR Field Length
#define RTC_TIMALR_HOUR_Msk (0x3F << 16)         //!< HOUR Mask
/* \} */
/** \defgroup RTC_TIMALR_AMPM AMPM: AM/PM Indicator
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_AMPM     (0x1 << 22) //!< AMPM Value
#define RTC_TIMALR_AMPM_Pos (22)        //!< AMPM Position
#define RTC_TIMALR_AMPM_Len (1)         //!< AMPM Field Length
#define RTC_TIMALR_AMPM_Msk (0x1 << 22) //!< AMPM Mask
/* \} */
/** \defgroup RTC_TIMALR_HOUREN HOUREN: Hour Alarm Enable
 * \ingroup RTC_TIMALR
 * \{
 */
#define RTC_TIMALR_HOUREN     (0x1 << 23) //!< HOUREN Value
#define RTC_TIMALR_HOUREN_Pos (23)        //!< HOUREN Position
#define RTC_TIMALR_HOUREN_Len (1)         //!< HOUREN Field Length
#define RTC_TIMALR_HOUREN_Msk (0x1 << 23) //!< HOUREN Mask
/* \} */

/** \defgroup RTC_CALALR Calendar Alarm Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_CALALR_MONTH MONTH: Month Alarm
 * \ingroup RTC_CALALR
 * \{
 */
#define RTC_CALALR_MONTH(v)  (((v) & 0x1F) << 16) //!< MONTH Value
#define RTC_CALALR_MONTH_Pos (16)                 //!< MONTH Position
#define RTC_CALALR_MONTH_Len (5)                  //!< MONTH Field Length
#define RTC_CALALR_MONTH_Msk (0x1F << 16)         //!< MONTH Mask
/* \} */
/** \defgroup RTC_CALALR_MTHEN MTHEN: Month Alarm Enable
 * \ingroup RTC_CALALR
 * \{
 */
#define RTC_CALALR_MTHEN     (0x1 << 23) //!< MTHEN Value
#define RTC_CALALR_MTHEN_Pos (23)        //!< MTHEN Position
#define RTC_CALALR_MTHEN_Len (1)         //!< MTHEN Field Length
#define RTC_CALALR_MTHEN_Msk (0x1 << 23) //!< MTHEN Mask
/* \} */
/** \defgroup RTC_CALALR_DATE DATE: Date Alarm
 * \ingroup RTC_CALALR
 * \{
 */
#define RTC_CALALR_DATE(v)  (((v) & 0x3F) << 24) //!< DATE Value
#define RTC_CALALR_DATE_Pos (24)                 //!< DATE Position
#define RTC_CALALR_DATE_Len (6)                  //!< DATE Field Length
#define RTC_CALALR_DATE_Msk (0x3F << 24)         //!< DATE Mask
/* \} */
/** \defgroup RTC_CALALR_DATEN DATEEN: Date Alarm Enable
 * \ingroup RTC_CALALR
 * \{
 */
#define RTC_CALALR_DATEN     (0x1 << 31) //!< DATEN Value
#define RTC_CALALR_DATEN_Pos (31)        //!< DATEN Position
#define RTC_CALALR_DATEN_Len (1)         //!< DATEN Field Length
#define RTC_CALALR_DATEN_Msk (0x1 << 31) //!< DATEN Mask
/* \} */

/** \defgroup RTC_SR Status Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_SR_ACKUPD ACKUPD: Acknowledge for Update
 * \ingroup RTC_SR
 * \{
 */
#define RTC_SR_ACKUPD     (0x1 << 0) //!< ACKUPD Value
#define RTC_SR_ACKUPD_Pos (0)        //!< ACKUPD Position
#define RTC_SR_ACKUPD_Len (1)        //!< ACKUPD Field Length
#define RTC_SR_ACKUPD_Msk (0x1 << 0) //!< ACKUPD Mask
/* \} */
/** \defgroup RTC_SR_ALARM ALARM: Alarm Flag
 * \ingroup RTC_SR
 * \{
 */
#define RTC_SR_ALARM     (0x1 << 1) //!< ALARM Value
#define RTC_SR_ALARM_Pos (1)        //!< ALARM Position
#define RTC_SR_ALARM_Len (1)        //!< ALARM Field Length
#define RTC_SR_ALARM_Msk (0x1 << 1) //!< ALARM Mask
/* \} */
/** \defgroup RTC_SR_SEC SEC: Second Event
 * \ingroup RTC_SR
 * \{
 */
#define RTC_SR_SEC     (0x1 << 2) //!< SEC Value
#define RTC_SR_SEC_Pos (2)        //!< SEC Position
#define RTC_SR_SEC_Len (1)        //!< SEC Field Length
#define RTC_SR_SEC_Msk (0x1 << 2) //!< SEC Mask
/* \} */
/** \defgroup RTC_SR_TIMEV TIMEV: Time Event
 * \ingroup RTC_SR
 * \{
 */
#define RTC_SR_TIMEV     (0x1 << 3) //!< TIMEV Value
#define RTC_SR_TIMEV_Pos (3)        //!< TIMEV Position
#define RTC_SR_TIMEV_Len (1)        //!< TIMEV Field Length
#define RTC_SR_TIMEV_Msk (0x1 << 3) //!< TIMEV Mask
/* \} */
/** \defgroup RTC_SR_CALEV CALV: Calendar Event
 * \ingroup RTC_SR
 * \{
 */
#define RTC_SR_CALEV     (0x1 << 4) //!< CALEV Value
#define RTC_SR_CALEV_Pos (4)        //!< CALEV Position
#define RTC_SR_CALEV_Len (1)        //!< CALEV Field Length
#define RTC_SR_CALEV_Msk (0x1 << 4) //!< CALEV Mask
/* \} */

/** \defgroup RTC_SCCR Status Clear Command Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_SCCR_ACKCLR ACKCLR: Acknowledge Clear
 * \ingroup RTC_SCCR
 * \{
 */
#define RTC_SCCR_ACKCLR     (0x1 << 0) //!< ACKCLR Value
#define RTC_SCCR_ACKCLR_Pos (0)        //!< ACKCLR Position
#define RTC_SCCR_ACKCLR_Len (1)        //!< ACKCLR Field Length
#define RTC_SCCR_ACKCLR_Msk (0x1 << 0) //!< ACKCLR Mask
/* \} */
/** \defgroup RTC_SCCR_ALRCLR ALRCLR: Alarm Clear
 * \ingroup RTC_SCCR
 * \{
 */
#define RTC_SCCR_ALRCLR     (0x1 << 1) //!< ALRCLR Value
#define RTC_SCCR_ALRCLR_Pos (1)        //!< ALRCLR Position
#define RTC_SCCR_ALRCLR_Len (1)        //!< ALRCLR Field Length
#define RTC_SCCR_ALRCLR_Msk (0x1 << 1) //!< ALRCLR Mask
/* \} */
/** \defgroup RTC_SCCR_SECCLR SECCLR: Second Clear
 * \ingroup RTC_SCCR
 * \{
 */
#define RTC_SCCR_SECCLR     (0x1 << 2) //!< SECCLR Value
#define RTC_SCCR_SECCLR_Pos (2)        //!< SECCLR Position
#define RTC_SCCR_SECCLR_Len (1)        //!< SECCLR Field Length
#define RTC_SCCR_SECCLR_Msk (0x1 << 2) //!< SECCLR Mask
/* \} */
/** \defgroup RTC_SCCR_TIMCLR TIMCLR: Time Clear
 * \ingroup RTC_SCCR
 * \{
 */
#define RTC_SCCR_TIMCLR     (0x1 << 3) //!< TIMCLR Value
#define RTC_SCCR_TIMCLR_Pos (3)        //!< TIMCLR Position
#define RTC_SCCR_TIMCLR_Len (1)        //!< TIMCLR Field Length
#define RTC_SCCR_TIMCLR_Msk (0x1 << 3) //!< TIMCLR Mask
/* \} */
/** \defgroup RTC_SCCR_CALCLR CALCLR: Calendar Clear
 * \ingroup RTC_SCCR
 * \{
 */
#define RTC_SCCR_CALCLR     (0x1 << 4) //!< CALCLR Value
#define RTC_SCCR_CALCLR_Pos (4)        //!< CALCLR Position
#define RTC_SCCR_CALCLR_Len (1)        //!< CALCLR Field Length
#define RTC_SCCR_CALCLR_Msk (0x1 << 4) //!< CALCLR Mask
/* \} */

/** \defgroup RTC_IER Interrupt Enable Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_IER_ACKEN ACKEN: Acknowledge Update Interrupt Enable
 * \ingroup RTC_IER
 * \{
 */
#define RTC_IER_ACKEN     (0x1 << 0) //!< ACKEN Value
#define RTC_IER_ACKEN_Pos (0)        //!< ACKEN Position
#define RTC_IER_ACKEN_Len (1)        //!< ACKEN Field Length
#define RTC_IER_ACKEN_Msk (0x1 << 0) //!< ACKEN Mask
/* \} */
/** \defgroup RTC_IER_ALREN ALREN: Alarm Interrupt Enable
 * \ingroup RTC_IER
 * \{
 */
#define RTC_IER_ALREN     (0x1 << 1) //!< ALREN Value
#define RTC_IER_ALREN_Pos (1)        //!< ALREN Position
#define RTC_IER_ALREN_Len (1)        //!< ALREN Field Length
#define RTC_IER_ALREN_Msk (0x1 << 1) //!< ALREN Mask
/* \} */
/** \defgroup RTC_IER_SECEN SECEN: Second Event Interrupt Enable
 * \ingroup RTC_IER
 * \{
 */
#define RTC_IER_SECEN     (0x1 << 2) //!< SECEN Value
#define RTC_IER_SECEN_Pos (2)        //!< SECEN Position
#define RTC_IER_SECEN_Len (1)        //!< SECEN Field Length
#define RTC_IER_SECEN_Msk (0x1 << 2) //!< SECEN Mask
/* \} */
/** \defgroup RTC_IER_TIMEN TIMEN: Time Event Interrupt Enable
 * \ingroup RTC_IER
 * \{
 */
#define RTC_IER_TIMEN     (0x1 << 3) //!< TIMEN Value
#define RTC_IER_TIMEN_Pos (3)        //!< TIMEN Position
#define RTC_IER_TIMEN_Len (1)        //!< TIMEN Field Length
#define RTC_IER_TIMEN_Msk (0x1 << 3) //!< TIMEN Mask
/* \} */
/** \defgroup RTC_IER_CALEN CALEN: Calendar Event Interrupt Enable
 * \ingroup RTC_IER
 * \{
 */
#define RTC_IER_CALEN     (0x1 << 4) //!< CALEN Value
#define RTC_IER_CALEN_Pos (4)        //!< CALEN Position
#define RTC_IER_CALEN_Len (1)        //!< CALEN Field Length
#define RTC_IER_CALEN_Msk (0x1 << 4) //!< CALEN Mask
/* \} */

/** \defgroup RTC_IDR Interrupt Disable Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_IDR_ACKDIS ACKEN: Acknowledge Update Interrupt Disable
 * \ingroup RTC_IDR
 * \{
 */
#define RTC_IDR_ACKDIS     (0x1 << 0) //!< ACKDIS Value
#define RTC_IDR_ACKDIS_Pos (0)        //!< ACKDIS Position
#define RTC_IDR_ACKDIS_Len (1)        //!< ACKDIS Field Length
#define RTC_IDR_ACKDIS_Msk (0x1 << 0) //!< ACKDIS Mask
/* \} */
/** \defgroup RTC_IDR_ALRDIS ALREN: Alarm Interrupt Disable
 * \ingroup RTC_IDR
 * \{
 */
#define RTC_IDR_ALRDIS     (0x1 << 1) //!< ALRDIS Value
#define RTC_IDR_ALRDIS_Pos (1)        //!< ALRDIS Position
#define RTC_IDR_ALRDIS_Len (1)        //!< ALRDIS Field Length
#define RTC_IDR_ALRDIS_Msk (0x1 << 1) //!< ALRDIS Mask
/* \} */
/** \defgroup RTC_IDR_SECDIS SECEN: Second Event Interrupt Disable
 * \ingroup RTC_IDR
 * \{
 */
#define RTC_IDR_SECDIS     (0x1 << 2) //!< SECDIS Value
#define RTC_IDR_SECDIS_Pos (2)        //!< SECDIS Position
#define RTC_IDR_SECDIS_Len (1)        //!< SECDIS Field Length
#define RTC_IDR_SECDIS_Msk (0x1 << 2) //!< SECDIS Mask
/* \} */
/** \defgroup RTC_IDR_TIMDIS TIMEN: Time Event Interrupt Disable
 * \ingroup RTC_IDR
 * \{
 */
#define RTC_IDR_TIMDIS     (0x1 << 3) //!< TIMDIS Value
#define RTC_IDR_TIMDIS_Pos (3)        //!< TIMDIS Position
#define RTC_IDR_TIMDIS_Len (1)        //!< TIMDIS Field Length
#define RTC_IDR_TIMDIS_Msk (0x1 << 3) //!< TIMDIS Mask
/* \} */
/** \defgroup RTC_IDR_CALDIS CALEN: Calendar Event Interrupt Disable
 * \ingroup RTC_IDR
 * \{
 */
#define RTC_IDR_CALDIS     (0x1 << 4) //!< CALDIS Value
#define RTC_IDR_CALDIS_Pos (4)        //!< CALDIS Position
#define RTC_IDR_CALDIS_Len (1)        //!< CALDIS Field Length
#define RTC_IDR_CALDIS_Msk (0x1 << 4) //!< CALDIS Mask
/* \} */

/** \defgroup RTC_IMR Interrupt Mask Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_IMR_ACK ACKEN: Acknowledge Update Interrupt Mask
 * \ingroup RTC_IMR
 * \{
 */
#define RTC_IMR_ACK     (0x1 << 0) //!< ACK Value
#define RTC_IMR_ACK_Pos (0)        //!< ACK Position
#define RTC_IMR_ACK_Len (1)        //!< ACK Field Length
#define RTC_IMR_ACK_Msk (0x1 << 0) //!< ACK Mask
/* \} */
/** \defgroup RTC_IMR_ALR ALREN: Alarm Interrupt Mask
 * \ingroup RTC_IMR
 * \{
 */
#define RTC_IMR_ALR     (0x1 << 1) //!< ALR Value
#define RTC_IMR_ALR_Pos (1)        //!< ALR Position
#define RTC_IMR_ALR_Len (1)        //!< ALR Field Length
#define RTC_IMR_ALR_Msk (0x1 << 1) //!< ALR Mask
/* \} */
/** \defgroup RTC_IMR_SEC SECEN: Second Event Interrupt Mask
 * \ingroup RTC_IMR
 * \{
 */
#define RTC_IMR_SEC     (0x1 << 2) //!< SEC Value
#define RTC_IMR_SEC_Pos (2)        //!< SEC Position
#define RTC_IMR_SEC_Len (1)        //!< SEC Field Length
#define RTC_IMR_SEC_Msk (0x1 << 2) //!< SEC Mask
/* \} */
/** \defgroup RTC_IMR_TIM TIMEN: Time Event Interrupt Mask
 * \ingroup RTC_IMR
 * \{
 */
#define RTC_IMR_TIM     (0x1 << 3) //!< TIM Value
#define RTC_IMR_TIM_Pos (3)        //!< TIM Position
#define RTC_IMR_TIM_Len (1)        //!< TIM Field Length
#define RTC_IMR_TIM_Msk (0x1 << 3) //!< TIM Mask
/* \} */
/** \defgroup RTC_IMR_CAL CALEN: Calendar Event Interrupt Mask
 * \ingroup RTC_IMR
 * \{
 */
#define RTC_IMR_CAL     (0x1 << 4) //!< CAL Value
#define RTC_IMR_CAL_Pos (4)        //!< CAL Position
#define RTC_IMR_CAL_Len (1)        //!< CAL Field Length
#define RTC_IMR_CAL_Msk (0x1 << 4) //!< CAL Mask
/* \} */

/** \defgroup RTC_VER Valid Entry Register Bit Definitions
 * \ingroup RTC
 */

/** \defgroup RTC_VER_NVTIM NVTIM: Non-valid Time
 * \ingroup RTC_VER
 * \{
 */
#define RTC_VER_NVTIM     (0x1 << 0) //!< NVTIM Value
#define RTC_VER_NVTIM_Pos (0)        //!< NVTIM Position
#define RTC_VER_NVTIM_Len (1)        //!< NVTIM Field Length
#define RTC_VER_NVTIM_Msk (0x1 << 0) //!< NVTIM Mask
/* \} */
/** \defgroup RTC_VER_NVCAL NVCAL: Non-valid Calendar
 * \ingroup RTC_VER
 * \{
 */
#define RTC_VER_NVCAL     (0x1 << 1) //!< NVCAL Value
#define RTC_VER_NVCAL_Pos (1)        //!< NVCAL Position
#define RTC_VER_NVCAL_Len (1)        //!< NVCAL Field Length
#define RTC_VER_NVCAL_Msk (0x1 << 1) //!< NVCAL Mask
/* \} */
/** \defgroup RTC_VER_NVTIMALR NVTIMALR: Non-valid Time Alarm
 * \ingroup RTC_VER
 * \{
 */
#define RTC_VER_NVTIMALR     (0x1 << 2) //!< NVTIMALR Value
#define RTC_VER_NVTIMALR_Pos (2)        //!< NVTIMALR Position
#define RTC_VER_NVTIMALR_Len (1)        //!< NVTIMALR Field Length
#define RTC_VER_NVTIMALR_Msk (0x1 << 2) //!< NVTIMALR Mask
/* \} */
/** \defgroup RTC_VER_NVCALALR NVCALALR: Non-valid Calendar Alarm
 * \ingroup RTC_VER
 * \{
 */
#define RTC_VER_NVCALALR     (0x1 << 3) //!< NVCALALR Value
#define RTC_VER_NVCALALR_Pos (3)        //!< NVCALALR Position
#define RTC_VER_NVCALALR_Len (1)        //!< NVCALALR Field Length
#define RTC_VER_NVCALALR_Msk (0x1 << 3) //!< NVCALALR Mask
/* \} */

/** \defgroup RTC_WPMR Write Protect Mode Register Bit Definitions
 * \ingroup RTC
 */

#endif // _CPU_PERIPHERALS_RTC_H_
