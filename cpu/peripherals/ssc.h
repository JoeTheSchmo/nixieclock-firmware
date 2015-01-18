/**
 * \file
 *
 * \brief Synchronous Serial Controller (SSC) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_SUPC_H_
#define _CPU_PERIPHERALS_SUPC_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup SSC Synchronous Serial Controller (SSC) User Interface */

/** \defgroup SSC_UI_REG User Interface Registers
 * \ingroup SSC
 * \{
 */
#define SSC_CR           (*(reg_wo_t*)(SSC+0x0000)) //!< \ref SSC_CR
#define SSC_CMR          (*(reg_rw_t*)(SSC+0x0004)) //!< \ref SSC_CMR
#define SSC_RCMR         (*(reg_rw_t*)(SSC+0x0010)) //!< \ref SSC_RCMR
#define SSC_RFMR         (*(reg_rw_t*)(SSC+0x0013)) //!< \ref SSC_RFMR
#define SSC_TCMR         (*(reg_rw_t*)(SSC+0x0018)) //!< \ref SSC_TCMR
#define SSC_TFMR         (*(reg_rw_t*)(SSC+0x001C)) //!< \ref SSC_TFMR
#define SSC_RHR          (*(reg_ro_t*)(SSC+0x0020)) //!< \ref SSC_RHR
#define SSC_THR          (*(reg_wo_t*)(SSC+0x0024)) //!< \ref SSC_THR
#define SSC_RSHR         (*(reg_ro_t*)(SSC+0x0030)) //!< \ref SSC_RSHR
#define SSC_TSHR         (*(reg_rw_t*)(SSC+0x0034)) //!< \ref SSC_TSHR
#define SSC_RC0R         (*(reg_rw_t*)(SSC+0x0038)) //!< \ref SSC_RC0R
#define SSC_RC1R         (*(reg_rw_t*)(SSC+0x003C)) //!< \ref SSC_RC1R
#define SSC_SR           (*(reg_ro_t*)(SSC+0x0040)) //!< \ref SSC_SR
#define SSC_IER          (*(reg_wo_t*)(SSC+0x0044)) //!< \ref SSC_IER
#define SSC_IDR          (*(reg_wo_t*)(SSC+0x0048)) //!< \ref SSC_IDR
#define SSC_IMR          (*(reg_ro_t*)(SSC+0x004C)) //!< \ref SSC_IMR
#define SSC_WPMR         (*(reg_rw_t*)(SSC+0x00E4)) //!< \ref SSC_WPMR
#define SSC_WPSR         (*(reg_ro_t*)(SSC+0x00E8)) //!< \ref SSC_WPSR
/* \} */

/** \defgroup SSC_CR Control Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_CR_RXEN RXEN: Receive Enable
 * \ingroup SSC_CR
 * \{
 */
#define SSC_CR_RXEN     (0x1 << 0) //!< RXEN Value
#define SSC_CR_RXEN_Pos (0)        //!< RXEN Position
#define SSC_CR_RXEN_Len (1)        //!< RXEN Field Length
#define SSC_CR_RXEN_Msk (0x1 << 0) //!< RXEN Mask
/* \} */

/** \defgroup SSC_CR_RXDIS RXDIS: Receive Enable
 * \ingroup SSC_CR
 * \{
 */
#define SSC_CR_RXDIS     (0x1 << 1) //!< RXDIS Value
#define SSC_CR_RXDIS_Pos (1)        //!< RXDIS Position
#define SSC_CR_RXDIS_Len (1)        //!< RXDIS Field Length
#define SSC_CR_RXDIS_Msk (0x1 << 1) //!< RXDIS Mask
/* \} */

/** \defgroup SSC_CR_TXEN TXEN: Receive Enable
 * \ingroup SSC_CR
 * \{
 */
#define SSC_CR_TXEN     (0x1 << 8) //!< TXEN Value
#define SSC_CR_TXEN_Pos (8)        //!< TXEN Position
#define SSC_CR_TXEN_Len (1)        //!< TXEN Field Length
#define SSC_CR_TXEN_Msk (0x1 << 8) //!< TXEN Mask
/* \} */

/** \defgroup SSC_CR_TXDIS TXDIS: Receive Enable
 * \ingroup SSC_CR
 * \{
 */
#define SSC_CR_TXDIS     (0x1 << 9) //!< TXDIS Value
#define SSC_CR_TXDIS_Pos (9)        //!< TXDIS Position
#define SSC_CR_TXDIS_Len (1)        //!< TXDIS Field Length
#define SSC_CR_TXDIS_Msk (0x1 << 9) //!< TXDIS Mask
/* \} */

/** \defgroup SSC_CR_SWRST SWRST: Receive Enable
 * \ingroup SSC_CR
 * \{
 */
#define SSC_CR_SWRST     (0x1 << 15) //!< SWRST Value
#define SSC_CR_SWRST_Pos (15)        //!< SWRST Position
#define SSC_CR_SWRST_Len (1)         //!< SWRST Field Length
#define SSC_CR_SWRST_Msk (0x1 << 15) //!< SWRST Mask
/* \} */

/** \defgroup SSC_CMR Clock Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_CMR_DIV DIV: Clock Divider
 * \ingroup SSC_CMR
 * \{
 */
#define SSC_CMR_DIV(v)  (((v) & 0xFFF) << 0) //!< DIV Value
#define SSC_CMR_DIV_Pos (0)                  //!< DIV Position
#define SSC_CMR_DIV_Len (12)                 //!< DIV Field Length
#define SSC_CMR_DIV_Msk (0xFFF << 0)         //!< DIV Mask
/* \} */

/** \defgroup SSC_RCMR Receive Clock Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RCMR_CKS CKS: Receive Clock Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_CKS(v)  (((v) & 0x3) << 0) //!< CKS Value
#define SSC_RCMR_CKS_Pos (0)                //!< CKS Position
#define SSC_RCMR_CKS_Len (2)                //!< CKS Field Length
#define SSC_RCMR_CKS_Msk (0x3 << 0)         //!< CKS Mask
/* \} */

/** \defgroup SSC_RCMR_CKO CKO: Receive Clock Output Mode Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_CKO(v)  (((v) & 0x7) << 2) //!< CKO Value
#define SSC_RCMR_CKO_Pos (2)                //!< CKO Position
#define SSC_RCMR_CKO_Len (3)                //!< CKO Field Length
#define SSC_RCMR_CKO_Msk (0x7 << 2)         //!< CKO Mask
/* \} */

/** \defgroup SSC_RCMR_CKI CKI: Receive Clock Inversion
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_CKI     (0x1 << 5) //!< CKI Value
#define SSC_RCMR_CKI_Pos (5)        //!< CKI Position
#define SSC_RCMR_CKI_Len (1)        //!< CKI Field Length
#define SSC_RCMR_CKI_Msk (0x1 << 5) //!< CKI Mask
/* \} */

/** \defgroup SSC_RCMR_CKG CKG: Receive Clock Gating Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_CKG(v)  (((v) & 0x3) << 6) //!< CKG Value
#define SSC_RCMR_CKG_Pos (6)                //!< CKG Position
#define SSC_RCMR_CKG_Len (2)                //!< CKG Field Length
#define SSC_RCMR_CKG_Msk (0x3 << 6)         //!< CKG Mask
/* \} */

/** \defgroup SSC_RCMR_START START: Receive Start Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_START(v)  (((v) & 0xF) << 8) //!< START Value
#define SSC_RCMR_START_Pos (8)                //!< START Position
#define SSC_RCMR_START_Len (4)                //!< START Field Length
#define SSC_RCMR_START_Msk (0xF << 8)         //!< START Mask
/* \} */

/** \defgroup SSC_RCMR_STOP STOP: Receive Stop Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_STOP     (0x1 << 12) //!< STOP Value
#define SSC_RCMR_STOP_Pos (12)        //!< STOP Position
#define SSC_RCMR_STOP_Len (1)         //!< STOP Field Length
#define SSC_RCMR_STOP_Msk (0x1 << 12) //!< STOP Mask
/* \} */

/** \defgroup SSC_RCMR_STTDLY STTDLY: Receive Start Delay
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_STTDLY(v)  (((v) & 0xFF) << 16) //!< STTDLY Value
#define SSC_RCMR_STTDLY_Pos (16)                 //!< STTDLY Position
#define SSC_RCMR_STTDLY_Len (8)                  //!< STTDLY Field Length
#define SSC_RCMR_STTDLY_Msk (0xFF << 16)         //!< STTDLY Mask
/* \} */

/** \defgroup SSC_RCMR_PERIOD PERIOD: Receive Period Divider Selection
 * \ingroup SSC_RCMR
 * \{
 */
#define SSC_RCMR_PERIOD(v)  (((v) & 0xFF) << 24) //!< PERIOD Value
#define SSC_RCMR_PERIOD_Pos (24)                 //!< PERIOD Position
#define SSC_RCMR_PERIOD_Len (8)                  //!< PERIOD Field Length
#define SSC_RCMR_PERIOD_Msk (0xFF << 24)         //!< PERIOD Mask
/* \} */

/** \defgroup SSC_RFMR Receive Frame Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RFMR_DATLEN DATLEN: Data Length
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_DATLEN(v)  (((v) & 0x1F) << 0) //!< DATLEN Value
#define SSC_RFMR_DATLEN_Pos (0)                 //!< DATLEN Position
#define SSC_RFMR_DATLEN_Len (5)                 //!< DATLEN Field Length
#define SSC_RFMR_DATLEN_Msk (0x1F << 0)         //!< DATLEN Mask
/* \} */

/** \defgroup SSC_RFMR_LOOP LOOP: Loop Mode
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_LOOP     (0x1 << 5) //!< LOOP Value
#define SSC_RFMR_LOOP_Pos (5)        //!< LOOP Position
#define SSC_RFMR_LOOP_Len (1)        //!< LOOP Field Length
#define SSC_RFMR_LOOP_Msk (0x1 << 5) //!< LOOP Mask
/* \} */

/** \defgroup SSC_RFMR_MSBF MSBF: Most Significant Bit First
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_MSBF     (0x1 << 7) //!< MSBF Value
#define SSC_RFMR_MSBF_Pos (7)        //!< MSBF Position
#define SSC_RFMR_MSBF_Len (1)        //!< MSBF Field Length
#define SSC_RFMR_MSBF_Msk (0x1 << 7) //!< MSBF Mask
/* \} */

/** \defgroup SSC_RFMR_DATNB DATNB: Data Length
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_DATNB(v)  (((v) & 0xF) << 8) //!< DATNB Value
#define SSC_RFMR_DATNB_Pos (8)                //!< DATNB Position
#define SSC_RFMR_DATNB_Len (4)                //!< DATNB Field Length
#define SSC_RFMR_DATNB_Msk (0xF << 8)         //!< DATNB Mask
/* \} */

/** \defgroup SSC_RFMR_FSLEN FSLEN: Receive Frame Sync Length
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_FSLEN(v)  (((v) & 0xF) << 16) //!< FSLEN Value
#define SSC_RFMR_FSLEN_Pos (16)                //!< FSLEN Position
#define SSC_RFMR_FSLEN_Len (4)                //!< FSLEN Field Length
#define SSC_RFMR_FSLEN_Msk (0xF << 16)         //!< FSLEN Mask
/* \} */

/** \defgroup SSC_RFMR_FSOS FSOS: Receive Frame Sync Output Selection
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_FSOS(v)  (((v) & 0x7) << 20) //!< FSOS Value
#define SSC_RFMR_FSOS_Pos (20)                //!< FSOS Position
#define SSC_RFMR_FSOS_Len (3)                 //!< FSOS Field Length
#define SSC_RFMR_FSOS_Msk (0x7 << 20)         //!< FSOS Mask
/* \} */

/** \defgroup SSC_RFMR_FSEDGE FSEDGE: Frame Sync Edge Detect
 * \ingroup SSC_RFMR
 * \{
 */
#define SSC_RFMR_FSEDGE     (0x1 << 24) //!< FSEDGE Value
#define SSC_RFMR_FSEDGE_Pos (24)        //!< FSEDGE Position
#define SSC_RFMR_FSEDGE_Len (1)         //!< FSEDGE Field Length
#define SSC_RFMR_FSEDGE_Msk (0x1 << 24) //!< FSEDGE Mask
/* \} */

/** \defgroup SSC_TCMR Transmit Clock Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_TCMR_CKS CKS: Transmit Clock Selection
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_CKS(v)  (((v) & 0x3) << 0) //!< CKS Value
#define SSC_TCMR_CKS_Pos (0)                //!< CKS Position
#define SSC_TCMR_CKS_Len (2)                //!< CKS Field Length
#define SSC_TCMR_CKS_Msk (0x3 << 0)         //!< CKS Mask
#define SSC_TCMR_CKS_MCK (0)                //!< Divided Clock
#define SSC_TCMR_CKS_TK  (1)                //!< TK Clock Signal
#define SSC_TCMR_CKS_RK  (2)                //!< RK Pin
/* \} */

/** \defgroup SSC_TCMR_CKO CKO: Transmit Clock Output Mode Selection
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_CKO(v)  (((v) & 0x7) << 2) //!< CKO Value
#define SSC_TCMR_CKO_Pos (2)                //!< CKO Position
#define SSC_TCMR_CKO_Len (3)                //!< CKO Field Length
#define SSC_TCMR_CKO_Msk (0x7 << 2)         //!< CKO Mask
#define SSC_TCMR_CKO_NONE       (0)         //!< None
#define SSC_TCMR_CKO_CONTINUOUS (1)         //!< Continuous Receive Clock
#define SSC_TCMR_CKO_TRANSFER   (2)         //!< Transmit Clock only during transfers
/* \} */

/** \defgroup SSC_TCMR_CKI CKI: Transmit Clock Inversion
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_CKI     (0x1 << 5) //!< CKI Value
#define SSC_TCMR_CKI_Pos (5)        //!< CKI Position
#define SSC_TCMR_CKI_Len (1)        //!< CKI Field Length
#define SSC_TCMR_CKI_Msk (0x1 << 5) //!< CKI Mask
/* \} */

/** \defgroup SSC_TCMR_CKG CKG: Transmit Clock Gating Selection
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_CKG(v)  (((v) & 0x3) << 6) //!< CKG Value
#define SSC_TCMR_CKG_Pos (6)                //!< CKG Position
#define SSC_TCMR_CKG_Len (2)                //!< CKG Field Length
#define SSC_TCMR_CKG_Msk (0x3 << 6)         //!< CKG Mask
#define SSC_TCMR_CKG_NONE       (0)         //!< None
#define SSC_TCMR_CKG_CONTINUOUS (1)         //!< Transmit Clock enabled only if TF Low
#define SSC_TCMR_CKG_TRANSFER   (2)         //!< Transmit Clock enabled only if TF High
/* \} */

/** \defgroup SSC_TCMR_START START: Transmit Start Selection
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_START(v)  (((v) & 0xF) << 8) //!< START Value
#define SSC_TCMR_START_Pos (8)                //!< START Position
#define SSC_TCMR_START_Len (4)                //!< START Field Length
#define SSC_TCMR_START_Msk (0xF << 8)         //!< START Mask
#define SSC_TCMR_START_CONTINUOUS (0)
#define SSC_TCMR_START_RECEIVE    (1)
#define SSC_TCMR_START_RF_LOW     (2)
#define SSC_TCMR_START_RF_HIGH    (3)
#define SSC_TCMR_START_RF_FALLING (4)
#define SSC_TCMR_START_RF_RISING  (5)
#define SSC_TCMR_START_RF_LEVEL   (6)
#define SSC_TCMR_START_RF_EDGE    (7)
#define SSC_TCMR_START_CMP_0      (8)
/* \} */
/* \} */

/** \defgroup SSC_TCMR_STTDLY STTDLY: Transmit Start Delay
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_STTDLY(v)  (((v) & 0xFF) << 16) //!< STTDLY Value
#define SSC_TCMR_STTDLY_Pos (16)                 //!< STTDLY Position
#define SSC_TCMR_STTDLY_Len (8)                  //!< STTDLY Field Length
#define SSC_TCMR_STTDLY_Msk (0xFF << 16)         //!< STTDLY Mask
/* \} */

/** \defgroup SSC_TCMR_PERIOD PERIOD: Transmit Period Divider Selection
 * \ingroup SSC_TCMR
 * \{
 */
#define SSC_TCMR_PERIOD(v)  (((v) & 0xFF) << 24) //!< PERIOD Value
#define SSC_TCMR_PERIOD_Pos (24)                 //!< PERIOD Position
#define SSC_TCMR_PERIOD_Len (8)                  //!< PERIOD Field Length
#define SSC_TCMR_PERIOD_Msk (0xFF << 24)         //!< PERIOD Mask
/* \} */

/** \defgroup SSC_TFMR Transmit Frame Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_TFMR_DATLEN DATLEN: Data Length
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_DATLEN(v)  (((v) & 0x1F) << 0) //!< DATLEN Value
#define SSC_TFMR_DATLEN_Pos (0)                 //!< DATLEN Position
#define SSC_TFMR_DATLEN_Len (5)                 //!< DATLEN Field Length
#define SSC_TFMR_DATLEN_Msk (0x1F << 0)         //!< DATLEN Mask
/* \} */

/** \defgroup SSC_TFMR_DATDEF DATDEF: Data Number per frame
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_DATDEF     (0x1 << 5) //!< DATDEF Value
#define SSC_TFMR_DATDEF_Pos (5)        //!< DATDEF Position
#define SSC_TFMR_DATDEF_Len (1)        //!< DATDEF Field Length
#define SSC_TFMR_DATDEF_Msk (0x1 << 5) //!< DATDEF Mask
/* \} */

/** \defgroup SSC_TFMR_MSBF MSBF: Most Significant Bit First
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_MSBF     (0x1 << 7) //!< MSBF Value
#define SSC_TFMR_MSBF_Pos (7)        //!< MSBF Position
#define SSC_TFMR_MSBF_Len (1)        //!< MSBF Field Length
#define SSC_TFMR_MSBF_Msk (0x1 << 7) //!< MSBF Mask
/* \} */

/** \defgroup SSC_TFMR_DATNB DATNB: Data Length
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_DATNB(v)  (((v) & 0xF) << 8) //!< DATNB Value
#define SSC_TFMR_DATNB_Pos (8)                //!< DATNB Position
#define SSC_TFMR_DATNB_Len (4)                //!< DATNB Field Length
#define SSC_TFMR_DATNB_Msk (0xF << 8)         //!< DATNB Mask
/* \} */

/** \defgroup SSC_TFMR_FSLEN FSLEN: Receive Frame Sync Length
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_FSLEN(v)  (((v) & 0xF) << 16) //!< FSLEN Value
#define SSC_TFMR_FSLEN_Pos (16)                //!< FSLEN Position
#define SSC_TFMR_FSLEN_Len (4)                //!< FSLEN Field Length
#define SSC_TFMR_FSLEN_Msk (0xF << 16)         //!< FSLEN Mask
/* \} */

/** \defgroup SSC_TFMR_FSOS FSOS: Receive Frame Sync Output Selection
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_FSOS(v)  (((v) & 0x7) << 20) //!< FSOS Value
#define SSC_TFMR_FSOS_Pos (20)                //!< FSOS Position
#define SSC_TFMR_FSOS_Len (3)                 //!< FSOS Field Length
#define SSC_TFMR_FSOS_Msk (0x7 << 20)         //!< FSOS Mask
#define SSC_TFMR_FSOS_NONE     (0)            //!< None
#define SSC_TFMR_FSOS_NEGATIVE (1)            //!< Negative Pulse
#define SSC_TFMR_FSOS_POSITIVE (2)            //!< Positive Pulse
#define SSC_TFMR_FSOS_LOW      (3)            //!< Driven Low during data transfer
#define SSC_TFMR_FSOS_HIGH     (4)            //!< Driven High during data transfer
#define SSC_TFMR_FSOS_TOGGLING (5)            //!< Toggling at each start of data transfer
/* \} */

/** \defgroup SSC_TFMR_FSDEN FSDEN: Frame Sync Data Enable
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_FSDEN     (0x1 << 23) //!< FSDEN Value
#define SSC_TFMR_FSDEN_Pos (23)        //!< FSDEN Position
#define SSC_TFMR_FSDEN_Len (1)         //!< FSDEN Field Length
#define SSC_TFMR_FSDEN_Msk (0x1 << 23) //!< FSDEN Mask
/* \} */

/** \defgroup SSC_TFMR_FSEDGE FSEDGE: Frame Sync Edge Detect
 * \ingroup SSC_TFMR
 * \{
 */
#define SSC_TFMR_FSEDGE(v)  (((v) & 0x01) << 24) //!< FSEDGE Value
#define SSC_TFMR_FSEDGE_Pos (24)                 //!< FSEDGE Position
#define SSC_TFMR_FSEDGE_Len (1)                  //!< FSEDGE Field Length
#define SSC_TFMR_FSEDGE_Msk (0x1 << 24)          //!< FSEDGE Mask
#define SSC_TFMR_FSEDGE_POSITIVE (0)             //!< Positive Edge Detection
#define SSC_TFMR_FSEDGE_NEGATIVE (1)             //!< Negative Edge Detection
/* \} */

/** \defgroup SSC_RHR Receive Holding Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RHR_RDAT RDAT: Receive Data
 * \ingroup SSC_RHR
 * \{
 */
#define SSC_RHR_RDAT(v)  (v)          //!< RDAT Value
#define SSC_RHR_RDAT_Pos (0)          //!< RDAT Position
#define SSC_RHR_RDAT_Len (32)         //!< RDAT Field Length
#define SSC_RHR_RDAT_Msk (0xFFFFFFFF) //!< RDAT Mask
/* \} */

/** \defgroup SSC_THR Transmit Holding Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_THR_TDAT TDAT: Transmit Data
 * \ingroup SSC_THR
 * \{
 */
#define SSC_THR_TDAT(v)  (v)          //!< TDAT Value
#define SSC_THR_TDAT_Pos (0)          //!< TDAT Position
#define SSC_THR_TDAT_Len (32)         //!< TDAT Field Length
#define SSC_THR_TDAT_Msk (0xFFFFFFFF) //!< TDAT Mask
/* \} */

/** \defgroup SSC_RSHR Receive Sync. Holding Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RSHR_RSDAT RSDAT: Receive Synchronization Data
 * \ingroup SSC_RSHR
 * \{
 */
#define SSC_RSHR_RSDAT(v)  (((v) 0xFFFF) << 0) //!< RSDAT Value
#define SSC_RSHR_RSDAT_Pos (0)                 //!< RSDAT Position
#define SSC_RSHR_RSDAT_Len (16)                //!< RSDAT Field Length
#define SSC_RSHR_RSDAT_Msk (0xFFFF << 0)       //!< RSDAT Mask
/* \} */

/** \defgroup SSC_TSHR Transmit Sync. Holding Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_TSHR_TSDAT TSDAT: Transmit Synchronization Data
 * \ingroup SSC_TSHR
 * \{
 */
#define SSC_TSHR_TSDAT(v)  (((v) 0xFFFF) << 0) //!< TSDAT Value
#define SSC_TSHR_TSDAT_Pos (0)                 //!< TSDAT Position
#define SSC_TSHR_TSDAT_Len (16)                //!< TSDAT Field Length
#define SSC_TSHR_TSDAT_Msk (0xFFFF << 0)       //!< TSDAT Mask
/* \} */

/** \defgroup SSC_RC0R Receive Compare 0 Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RC0R_CP0 CP0: Receive Compare Data 0
 * \ingroup SSC_RC0R
 * \{
 */
#define SSC_RC0R_CP0(v)  (((v) 0xFFFF) << 0) //!< CP0 Value
#define SSC_RC0R_CP0_Pos (0)                 //!< CP0 Position
#define SSC_RC0R_CP0_Len (16)                //!< CP0 Field Length
#define SSC_RC0R_CP0_Msk (0xFFFF << 0)       //!< CP0 Mask
/* \} */

/** \defgroup SSC_RC1R Receive Compare 1 Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_RC1R_CP1 CP1: Receive Compare Data 1
 * \ingroup SSC_RC1R
 * \{
 */
#define SSC_RC1R_CP1(v)  (((v) 0xFFFF) << 0) //!< CP1 Value
#define SSC_RC1R_CP1_Pos (0)                 //!< CP1 Position
#define SSC_RC1R_CP1_Len (16)                //!< CP1 Field Length
#define SSC_RC1R_CP1_Msk (0xFFFF << 0)       //!< CP1 Mask
/* \} */

/** \defgroup SSC_SR Status Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_SR_TXRDY TXRDY: Transmit Ready
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_TXRDY     (0x1 << 0) //!< TXRDY Value
#define SSC_SR_TXRDY_Pos (0)        //!< TXRDY Position
#define SSC_SR_TXRDY_Len (1)        //!< TXRDY Field Length
#define SSC_SR_TXRDY_Msk (0x1 << 0) //!< TXRDY Mask
/* \} */

/** \defgroup SSC_SR_TXEMPTY TXEMPTY: Transmit Empty
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_TXEMPTY     (0x1 << 1) //!< TXEMPTY Value
#define SSC_SR_TXEMPTY_Pos (1)        //!< TXEMPTY Position
#define SSC_SR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SSC_SR_TXEMPTY_Msk (0x1 << 1) //!< TXEMPTY Mask
/* \} */

/** \defgroup SSC_SR_RXRDY RXRDY: Receive Ready
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_RXRDY     (0x1 << 4) //!< RXRDY Value
#define SSC_SR_RXRDY_Pos (4)        //!< RXRDY Position
#define SSC_SR_RXRDY_Len (1)        //!< RXRDY Field Length
#define SSC_SR_RXRDY_Msk (0x1 << 4) //!< RXRDY Mask
/* \} */

/** \defgroup SSC_SR_OVRUN OVRUN: Receive Overrun
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_OVRUN     (0x1 << 5) //!< OVRUN Value
#define SSC_SR_OVRUN_Pos (5)        //!< OVRUN Position
#define SSC_SR_OVRUN_Len (1)        //!< OVRUN Field Length
#define SSC_SR_OVRUN_Msk (0x1 << 5) //!< OVRUN Mask
/* \} */

/** \defgroup SSC_SR_CP0 CP0: Compare 0
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_CP0     (0x1 << 8) //!< CP0 Value
#define SSC_SR_CP0_Pos (8)        //!< CP0 Position
#define SSC_SR_CP0_Len (1)        //!< CP0 Field Length
#define SSC_SR_CP0_Msk (0x1 << 8) //!< CP0 Mask
/* \} */

/** \defgroup SSC_SR_CP1 CP1: Compare 1
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_CP1     (0x1 << 9) //!< CP1 Value
#define SSC_SR_CP1_Pos (9)        //!< CP1 Position
#define SSC_SR_CP1_Len (1)        //!< CP1 Field Length
#define SSC_SR_CP1_Msk (0x1 << 9) //!< CP1 Mask
/* \} */

/** \defgroup SSC_SR_TXSYN TXSYN: Transmit Sync
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_TXSYN     (0x1 << 10) //!< TXSYN Value
#define SSC_SR_TXSYN_Pos (10)        //!< TXSYN Position
#define SSC_SR_TXSYN_Len (1)         //!< TXSYN Field Length
#define SSC_SR_TXSYN_Msk (0x1 << 10) //!< TXSYN Mask
/* \} */

/** \defgroup SSC_SR_RXSYN RXSYN: Receive Sync
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_RXSYN     (0x1 << 11) //!< RXSYN Value
#define SSC_SR_RXSYN_Pos (11)        //!< RXSYN Position
#define SSC_SR_RXSYN_Len (1)         //!< RXSYN Field Length
#define SSC_SR_RXSYN_Msk (0x1 << 11) //!< RXSYN Mask
/* \} */

/** \defgroup SSC_SR_TXEN TXEN: Transmit Enable
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_TXEN     (0x1 << 16) //!< TXEN Value
#define SSC_SR_TXEN_Pos (16)        //!< TXEN Position
#define SSC_SR_TXEN_Len (1)         //!< TXEN Field Length
#define SSC_SR_TXEN_Msk (0x1 << 16) //!< TXEN Mask
/* \} */

/** \defgroup SSC_SR_RXEN RXEN: Receive Enable
 * \ingroup SSC_SR
 * \{
 */
#define SSC_SR_RXEN     (0x1 << 17) //!< RXEN Value
#define SSC_SR_RXEN_Pos (17)        //!< RXEN Position
#define SSC_SR_RXEN_Len (1)         //!< RXEN Field Length
#define SSC_SR_RXEN_Msk (0x1 << 17) //!< RXEN Mask
/* \} */

/** \defgroup SSC_IER Interrupt Enable Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_IER_TXRDY TXRDY: Transmit Ready Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_TXRDY     (0x1 << 0) //!< TXRDY Value
#define SSC_IER_TXRDY_Pos (0)        //!< TXRDY Position
#define SSC_IER_TXRDY_Len (1)        //!< TXRDY Field Length
#define SSC_IER_TXRDY_Msk (0x1 << 0) //!< TXRDY Mask
/* \} */

/** \defgroup SSC_IER_TXEMPTY TXEMPTY: Transmit Empty Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_TXEMPTY     (0x1 << 1) //!< TXEMPTY Value
#define SSC_IER_TXEMPTY_Pos (1)        //!< TXEMPTY Position
#define SSC_IER_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SSC_IER_TXEMPTY_Msk (0x1 << 1) //!< TXEMPTY Mask
/* \} */

/** \defgroup SSC_IER_RXRDY RXRDY: Receive Ready Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_RXRDY     (0x1 << 4) //!< RXRDY Value
#define SSC_IER_RXRDY_Pos (4)        //!< RXRDY Position
#define SSC_IER_RXRDY_Len (1)        //!< RXRDY Field Length
#define SSC_IER_RXRDY_Msk (0x1 << 4) //!< RXRDY Mask
/* \} */

/** \defgroup SSC_IER_OVRUN OVRUN: Receive Overrun Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_OVRUN     (0x1 << 5) //!< OVRUN Value
#define SSC_IER_OVRUN_Pos (5)        //!< OVRUN Position
#define SSC_IER_OVRUN_Len (1)        //!< OVRUN Field Length
#define SSC_IER_OVRUN_Msk (0x1 << 5) //!< OVRUN Mask
/* \} */

/** \defgroup SSC_IER_CP0 CP0: Compare 0 Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_CP0     (0x1 << 8) //!< CP0 Value
#define SSC_IER_CP0_Pos (8)        //!< CP0 Position
#define SSC_IER_CP0_Len (1)        //!< CP0 Field Length
#define SSC_IER_CP0_Msk (0x1 << 8) //!< CP0 Mask
/* \} */

/** \defgroup SSC_IER_CP1 CP1: Compare 1 Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_CP1     (0x1 << 9) //!< CP1 Value
#define SSC_IER_CP1_Pos (9)        //!< CP1 Position
#define SSC_IER_CP1_Len (1)        //!< CP1 Field Length
#define SSC_IER_CP1_Msk (0x1 << 9) //!< CP1 Mask
/* \} */

/** \defgroup SSC_IER_TXSYN TXSYN: Transmit Sync Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_TXSYN     (0x1 << 10) //!< TXSYN Value
#define SSC_IER_TXSYN_Pos (10)        //!< TXSYN Position
#define SSC_IER_TXSYN_Len (1)         //!< TXSYN Field Length
#define SSC_IER_TXSYN_Msk (0x1 << 10) //!< TXSYN Mask
/* \} */

/** \defgroup SSC_IER_RXSYN RXSYN: Receive Sync Interrupt Enable
 * \ingroup SSC_IER
 * \{
 */
#define SSC_IER_RXSYN     (0x1 << 11) //!< RXSYN Value
#define SSC_IER_RXSYN_Pos (11)        //!< RXSYN Position
#define SSC_IER_RXSYN_Len (1)         //!< RXSYN Field Length
#define SSC_IER_RXSYN_Msk (0x1 << 11) //!< RXSYN Mask
/* \} */

/** \defgroup SSC_IDR Interrupt Disable Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_IDR_TXRDY TXRDY: Transmit Ready Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_TXRDY     (0x1 << 0) //!< TXRDY Value
#define SSC_IDR_TXRDY_Pos (0)        //!< TXRDY Position
#define SSC_IDR_TXRDY_Len (1)        //!< TXRDY Field Length
#define SSC_IDR_TXRDY_Msk (0x1 << 0) //!< TXRDY Mask
/* \} */

/** \defgroup SSC_IDR_TXEMPTY TXEMPTY: Transmit Empty Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_TXEMPTY     (0x1 << 1) //!< TXEMPTY Value
#define SSC_IDR_TXEMPTY_Pos (1)        //!< TXEMPTY Position
#define SSC_IDR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SSC_IDR_TXEMPTY_Msk (0x1 << 1) //!< TXEMPTY Mask
/* \} */

/** \defgroup SSC_IDR_RXRDY RXRDY: Receive Ready Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_RXRDY     (0x1 << 4) //!< RXRDY Value
#define SSC_IDR_RXRDY_Pos (4)        //!< RXRDY Position
#define SSC_IDR_RXRDY_Len (1)        //!< RXRDY Field Length
#define SSC_IDR_RXRDY_Msk (0x1 << 4) //!< RXRDY Mask
/* \} */

/** \defgroup SSC_IDR_OVRUN OVRUN: Receive Overrun Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_OVRUN     (0x1 << 5) //!< OVRUN Value
#define SSC_IDR_OVRUN_Pos (5)        //!< OVRUN Position
#define SSC_IDR_OVRUN_Len (1)        //!< OVRUN Field Length
#define SSC_IDR_OVRUN_Msk (0x1 << 5) //!< OVRUN Mask
/* \} */

/** \defgroup SSC_IDR_CP0 CP0: Compare 0 Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_CP0     (0x1 << 8) //!< CP0 Value
#define SSC_IDR_CP0_Pos (8)        //!< CP0 Position
#define SSC_IDR_CP0_Len (1)        //!< CP0 Field Length
#define SSC_IDR_CP0_Msk (0x1 << 8) //!< CP0 Mask
/* \} */

/** \defgroup SSC_IDR_CP1 CP1: Compare 1 Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_CP1     (0x1 << 9) //!< CP1 Value
#define SSC_IDR_CP1_Pos (9)        //!< CP1 Position
#define SSC_IDR_CP1_Len (1)        //!< CP1 Field Length
#define SSC_IDR_CP1_Msk (0x1 << 9) //!< CP1 Mask
/* \} */

/** \defgroup SSC_IDR_TXSYN TXSYN: Transmit Sync Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_TXSYN     (0x1 << 10) //!< TXSYN Value
#define SSC_IDR_TXSYN_Pos (10)        //!< TXSYN Position
#define SSC_IDR_TXSYN_Len (1)         //!< TXSYN Field Length
#define SSC_IDR_TXSYN_Msk (0x1 << 10) //!< TXSYN Mask
/* \} */

/** \defgroup SSC_IDR_RXSYN RXSYN: Receive Sync Interrupt Disable
 * \ingroup SSC_IDR
 * \{
 */
#define SSC_IDR_RXSYN     (0x1 << 11) //!< RXSYN Value
#define SSC_IDR_RXSYN_Pos (11)        //!< RXSYN Position
#define SSC_IDR_RXSYN_Len (1)         //!< RXSYN Field Length
#define SSC_IDR_RXSYN_Msk (0x1 << 11) //!< RXSYN Mask
/* \} */

/** \defgroup SSC_IMR Interrupt Mask Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_IMR_TXRDY TXRDY: Transmit Ready Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_TXRDY     (0x1 << 0) //!< TXRDY Value
#define SSC_IMR_TXRDY_Pos (0)        //!< TXRDY Position
#define SSC_IMR_TXRDY_Len (1)        //!< TXRDY Field Length
#define SSC_IMR_TXRDY_Msk (0x1 << 0) //!< TXRDY Mask
/* \} */

/** \defgroup SSC_IMR_TXEMPTY TXEMPTY: Transmit Empty Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_TXEMPTY     (0x1 << 1) //!< TXEMPTY Value
#define SSC_IMR_TXEMPTY_Pos (1)        //!< TXEMPTY Position
#define SSC_IMR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SSC_IMR_TXEMPTY_Msk (0x1 << 1) //!< TXEMPTY Mask
/* \} */

/** \defgroup SSC_IMR_RXRDY RXRDY: Receive Ready Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_RXRDY     (0x1 << 4) //!< RXRDY Value
#define SSC_IMR_RXRDY_Pos (4)        //!< RXRDY Position
#define SSC_IMR_RXRDY_Len (1)        //!< RXRDY Field Length
#define SSC_IMR_RXRDY_Msk (0x1 << 4) //!< RXRDY Mask
/* \} */

/** \defgroup SSC_IMR_OVRUN OVRUN: Receive Overrun Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_OVRUN     (0x1 << 5) //!< OVRUN Value
#define SSC_IMR_OVRUN_Pos (5)        //!< OVRUN Position
#define SSC_IMR_OVRUN_Len (1)        //!< OVRUN Field Length
#define SSC_IMR_OVRUN_Msk (0x1 << 5) //!< OVRUN Mask
/* \} */

/** \defgroup SSC_IMR_CP0 CP0: Compare 0 Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_CP0     (0x1 << 8) //!< CP0 Value
#define SSC_IMR_CP0_Pos (8)        //!< CP0 Position
#define SSC_IMR_CP0_Len (1)        //!< CP0 Field Length
#define SSC_IMR_CP0_Msk (0x1 << 8) //!< CP0 Mask
/* \} */

/** \defgroup SSC_IMR_CP1 CP1: Compare 1 Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_CP1     (0x1 << 9) //!< CP1 Value
#define SSC_IMR_CP1_Pos (9)        //!< CP1 Position
#define SSC_IMR_CP1_Len (1)        //!< CP1 Field Length
#define SSC_IMR_CP1_Msk (0x1 << 9) //!< CP1 Mask
/* \} */

/** \defgroup SSC_IMR_TXSYN TXSYN: Transmit Sync Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_TXSYN     (0x1 << 10) //!< TXSYN Value
#define SSC_IMR_TXSYN_Pos (10)        //!< TXSYN Position
#define SSC_IMR_TXSYN_Len (1)         //!< TXSYN Field Length
#define SSC_IMR_TXSYN_Msk (0x1 << 10) //!< TXSYN Mask
/* \} */

/** \defgroup SSC_IMR_RXSYN RXSYN: Receive Sync Interrupt Mask
 * \ingroup SSC_IMR
 * \{
 */
#define SSC_IMR_RXSYN     (0x1 << 11) //!< RXSYN Value
#define SSC_IMR_RXSYN_Pos (11)        //!< RXSYN Position
#define SSC_IMR_RXSYN_Len (1)         //!< RXSYN Field Length
#define SSC_IMR_RXSYN_Msk (0x1 << 11) //!< RXSYN Mask
/* \} */

/** \defgroup SSC_WPMR Write Protect Mode Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_WPMR_WPEN WPEN: Write Protect Enable
 * \ingroup SSC_WPMR
 * \{
 */
#define SSC_WPMR_WPEN     (0x1 << 0) //!< WPEN Value
#define SSC_WPMR_WPEN_Pos (0)        //!< WPEN Position
#define SSC_WPMR_WPEN_Len (1)        //!< WPEN Field Length
#define SSC_WPMR_WPEN_Msk (0x1 << 0) //!< WPEN Mask
/* \} */

/** \defgroup SSC_WPMR_WPKEY WPKEY: Write Protect Key
 * \ingroup SSC_WPMR
 * \{
 */
#define SSC_WPMR_WPKEY     (0x535343 << 8) //!< WPKEY Value
#define SSC_WPMR_WPKEY_Pos (8)             //!< WPKEY Position
#define SSC_WPMR_WPKEY_Len (24)            //!< WPKEY Field Length
#define SSC_WPMR_WPKEY_Msk (0xFFFFFF << 8) //!< WPKEY Mask
/* \} */

/** \defgroup SSC_WPSR Write Protect Status Register Bit Definitions
 * \ingroup SSC
 */

/** \defgroup SSC_WPSR_WPVS WPVS: Write Violation Status
 * \ingroup SSC_WPSR
 * \{
 */
#define SSC_WPSR_WPVS     (0x1 << 0) //!< WPVS Value
#define SSC_WPSR_WPVS_Pos (0)        //!< WPVS Position
#define SSC_WPSR_WPVS_Len (1)        //!< WPVS Field Length
#define SSC_WPSR_WPVS_Msk (0x1 << 0) //!< WPVS Mask
/* \} */

/** \defgroup SSC_WPSR_WPVSRC WPVSRC: Write Protect Violation Source
 * \ingroup SSC_WPSR
 * \{
 */
#define SSC_WPSR_WPVSRC(v)  (((v) & 0xFFFF) << 8) //!< WPVSRC Value
#define SSC_WPSR_WPVSRC_Pos (8)                   //!< WPVSRC Position
#define SSC_WPSR_WPVSRC_Len (16)                  //!< WPVSRC Field Length
#define SSC_WPSR_WPVSRC_Msk (0xFFFF << 8)         //!< WPVSRC Mask
/* \} */

#endif // _CPU_PERIPHERALS_SUPC_H_