/**
 * \file
 *
 * \brief Two-wire Interface (TWI) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_TWI_H_
#define _CPU_PERIPHERALS_TWI_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup TWI Two-wire Interface (TWI) User Interface */

/** \defgroup TWI_UI_REG User Interface Registers
 * \ingroup TWI
 * \{
 */
#define TWI_CR(TWI)      (*(reg_wo_t*)(TWI+0x0000)) //!< \ref TWI_CR
#define TWI_MMR(TWI)     (*(reg_rw_t*)(TWI+0x0004)) //!< \ref TWI_MMR
#define TWI_SMR(TWI)     (*(reg_rw_t*)(TWI+0x0008)) //!< \ref TWI_SMR
#define TWI_IADR(TWI)    (*(reg_rw_t*)(TWI+0x000C)) //!< \ref TWI_IADR
#define TWI_CWGR(TWI)    (*(reg_rw_t*)(TWI+0x0010)) //!< \ref TWI_CWGR
#define TWI_SR(TWI)      (*(reg_ro_t*)(TWI+0x0020)) //!< \ref TWI_SR
#define TWI_IER(TWI)     (*(reg_wo_t*)(TWI+0x0024)) //!< \ref TWI_IER
#define TWI_IDR(TWI)     (*(reg_wo_t*)(TWI+0x0028)) //!< \ref TWI_IDR
#define TWI_IMR(TWI)     (*(reg_ro_t*)(TWI+0x002C)) //!< \ref TWI_IMR
#define TWI_RHR(TWI)     (*(reg_ro_t*)(TWI+0x0030)) //!< \ref TWI_RHR
#define TWI_THR(TWI)     (*(reg_wo_t*)(TWI+0x0034)) //!< \ref TWI_THR
/* \} */

/** \defgroup TWI_CR Control Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_CR_START START: Send a START Condition
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_START     (0x1 << 0) //!< START Value
#define TWI_CR_START_Pos (0)        //!< START Position
#define TWI_CR_START_Len (1)        //!< START Field Length
#define TWI_CR_START_Msk (0x1 << 0) //!< START Mask
/* \} */
/** \defgroup TWI_CR_STOP STOP: Send a STOP Condition
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_STOP     (0x1 << 1) //!< STOP Value
#define TWI_CR_STOP_Pos (1)        //!< STOP Position
#define TWI_CR_STOP_Len (1)        //!< STOP Field Length
#define TWI_CR_STOP_Msk (0x1 << 1) //!< STOP Mask
/* \} */
/** \defgroup TWI_CR_MSEN MSEN: TWI Master Mode Enabled
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_MSEN     (0x1 << 2) //!< MSEN Value
#define TWI_CR_MSEN_Pos (2)        //!< MSEN Position
#define TWI_CR_MSEN_Len (1)        //!< MSEN Field Length
#define TWI_CR_MSEN_Msk (0x1 << 2) //!< MSEN Mask
/* \} */
/** \defgroup TWI_CR_MSDIS MSDIS: TWI Master Mode Disabled
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_MSDIS     (0x1 << 3) //!< MSDIS Value
#define TWI_CR_MSDIS_Pos (3)        //!< MSDIS Position
#define TWI_CR_MSDIS_Len (1)        //!< MSDIS Field Length
#define TWI_CR_MSDIS_Msk (0x1 << 3) //!< MSDIS Mask
/* \} */
/** \defgroup TWI_CR_SVEN SVEN: TWI Slave Mode Enabled
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_SVEN     (0x1 << 4) //!< SVEN Value
#define TWI_CR_SVEN_Pos (4)        //!< SVEN Position
#define TWI_CR_SVEN_Len (1)        //!< SVEN Field Length
#define TWI_CR_SVEN_Msk (0x1 << 4) //!< SVEN Mask
/* \} */
/** \defgroup TWI_CR_SVDIS SVDIS: TWI Slave Mode Disabled
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_SVDIS     (0x1 << 5) //!< SVDIS Value
#define TWI_CR_SVDIS_Pos (5)        //!< SVDIS Position
#define TWI_CR_SVDIS_Len (1)        //!< SVDIS Field Length
#define TWI_CR_SVDIS_Msk (0x1 << 5) //!< SVDIS Mask
/* \} */
/** \defgroup TWI_CR_QUICK QUICK: SMBUS Quick Command
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_QUICK     (0x1 << 6) //!< QUICK Value
#define TWI_CR_QUICK_Pos (6)        //!< QUICK Position
#define TWI_CR_QUICK_Len (1)        //!< QUICK Field Length
#define TWI_CR_QUICK_Msk (0x1 << 6) //!< QUICK Mask
/* \} */
/** \defgroup TWI_CR_SWRST SWRST: Software Reset
 * \ingroup TWI_CR
 * \{
 */
#define TWI_CR_SWRST     (0x1 << 7) //!< SWRST Value
#define TWI_CR_SWRST_Pos (7)        //!< SWRST Position
#define TWI_CR_SWRST_Len (1)        //!< SWRST Field Length
#define TWI_CR_SWRST_Msk (0x1 << 7) //!< SWRST Mask
/* \} */

/** \defgroup TWI_MMR Master Mode Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_MMR_IADRSZ IADRSZ: Internal Device Address Size
 * \ingroup TWI_MMR
 * \{
 */
#define TWI_MMR_IADRSZ(v)  (((v) & 0x3) << 8) //!< IADRSZ Value
#define TWI_MMR_IADRSZ_Pos (8)                //!< IADRSZ Position
#define TWI_MMR_IADRSZ_Len (2)                //!< IADRSZ Field Size
#define TWI_MMR_IADRSZ_Msk (0x3 << 8)         //!< IADRSZ Mask
#define TWI_MMR_IADRSZ_NONE (0)               //!< No internal device address
#define TWI_MMR_IADRSZ_1_BYTE (1)             //!< One-byte internal device address
#define TWI_MMR_IADRSZ_2_BYTE (2)             //!< Two-byte internal device address
#define TWI_MMR_IADRSZ_3_BYTE (3)             //!< Three-byte internal device address
/* \} */
/** \defgroup TWI_MMR_MREAD MREAD: Master Read Direction
 * \ingroup TWI_MMR
 * \{
 */
#define TWI_MMR_MREAD     (0x1 << 12) //!< MREAD Value
#define TWI_MMR_MREAD_Pos (12)        //!< MREAD Position
#define TWI_MMR_MREAD_Len (1)         //!< MREAD Field Length
#define TWI_MMR_MREAD_Msk (0x1 << 12) //!< MREAD Mask
/* \} */
/** \defgroup TWI_MMR_DADR DADR: Device Address
 * \ingroup TWI_MMR
 * \{
 */
#define TWI_MMR_DADR(v)  (((v) & 0x7F) << 16) //!< DADR Value
#define TWI_MMR_DADR_Pos (16)                 //!< DADR Position
#define TWI_MMR_DADR_Len (7)                  //!< DADR Field Length
#define TWI_MMR_DADR_Msk (0x7F << 16)         //!< DADR Mask
/* \} */

/** \defgroup TWI_SMR Slave Mode Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_SMR_SADR SADR: Slave Address
 * \ingroup TWI_SMR
 * \{
 */
#define TWI_SMR_SADR(v)  (((v) & 0x7F) << 16) //!< SADR Value
#define TWI_SMR_SADR_Pos (16)                 //!< SADR Position
#define TWI_SMR_SADR_Len (7)                  //!< SADR Field Length
#define TWI_SMR_SADR_Msk (0x7F << 16)         //!< SADR Mask
/* \} */

/** \defgroup TWI_IADR Internal Address Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_IADR_IADR IADR: Internal Address
 * \ingroup TWI_IADR
 * \{
 */
#define TWI_IADR_IADR(v)  (((v) & 0xFFFFFF) << 0) //!< IADR Value
#define TWI_IADR_IADR_Pos (0)                     //!< IADR Position
#define TWI_IADR_IADR_Len (24)                    //!< IADR Field Length
#define TWI_IADR_IADR_Msk (0xFFFFFF << 0)         //!< IADR Mask
/* \} */

/** \defgroup TWI_CWGR Clock Waveform Generator Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_CWGR_CLDIV CLDIV: Clock Low Divider
 * \ingroup TWI_CWGR
 * \{
 */
#define TWI_CWGR_CLDIV(v)  (((v) & 0xFF) << 0) //!< CLDIV Value
#define TWI_CWGR_CLDIV_Pos (0)                 //!< CLDIV Position
#define TWI_CWGR_CLDIV_Len (8)                 //!< CLDIV Field Length
#define TWI_CWGR_CLDIV_Msk (0xFF << 0)         //!< CLDIV Mask
/* \} */
/** \defgroup TWI_CWGR_CHDIV CHDIV: Clock High Divider
 * \ingroup TWI_CWGR
 * \{
 */
#define TWI_CWGR_CHDIV(v)  (((v) & 0xFF) << 8) //!< CHDIV Value
#define TWI_CWGR_CHDIV_Pos (8)                 //!< CHDIV Position
#define TWI_CWGR_CHDIV_Len (8)                 //!< CHDIV Field Length
#define TWI_CWGR_CHDIV_Msk (0xFF << 8)         //!< CHDIV Mask
/* \} */
/** \defgroup TWI_CWGR_CKDIV CKDIV: Clock Divider
 * \ingroup TWI_CWGR
 * \{
 */
#define TWI_CWGR_CKDIV(v)  (((v) & 0x7) << 16) //!< CKDIV Value
#define TWI_CWGR_CKDIV_Pos (16)                //!< CKDIV Position
#define TWI_CWGR_CKDIV_Len (3)                 //!< CKDIV Field Length
#define TWI_CWGR_CKDIV_Msk (0x7 << 16)         //!< CKDIV Mask
/* \} */

/** \defgroup TWI_SR Status Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_SR_TXCOMP TXCOMP: Transmission Completed
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_TXCOMP     (0x1 << 0) //!< TXCOMP Value
#define TWI_SR_TXCOMP_Pos (0)        //!< TXCOMP Position
#define TWI_SR_TXCOMP_Len (1)        //!< TXCOMP Field Length
#define TWI_SR_TXCOMP_Msk (0x1 << 0) //!< TXCOMP Mask
/* \} */
/** \defgroup TWI_SR_RXRDY RXRDY: Receive Holding Register Ready
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_RXRDY     (0x1 << 1) //!< RXRDY Value
#define TWI_SR_RXRDY_Pos (1)        //!< RXRDY Position
#define TWI_SR_RXRDY_Len (1)        //!< RXRDY Field Length
#define TWI_SR_RXRDY_Msk (0x1 << 1) //!< RXRDY Mask
/* \} */
/** \defgroup TWI_SR_TXRDY TXRDY: Transmit Holding Register Ready
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_TXRDY     (0x1 << 2) //!< TXRDY Value
#define TWI_SR_TXRDY_Pos (2)        //!< TXRDY Position
#define TWI_SR_TXRDY_Len (1)        //!< TXRDY Field Length
#define TWI_SR_TXRDY_Msk (0x1 << 2) //!< TXRDY Mask
/* \} */
/** \defgroup TWI_SR_SVREAD SVREAD: Slave Read
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_SVREAD     (0x1 << 3) //!< SVREAD Value
#define TWI_SR_SVREAD_Pos (3)        //!< SVREAD Position
#define TWI_SR_SVREAD_Len (1)        //!< SVREAD Field Length
#define TWI_SR_SVREAD_Msk (0x1 << 3) //!< SVREAD Mask
/* \} */
/** \defgroup TWI_SR_SVACC SVACC: Slave Access
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_SVACC     (0x1 << 4) //!< SVACC Value
#define TWI_SR_SVACC_Pos (4)        //!< SVACC Position
#define TWI_SR_SVACC_Len (1)        //!< SVACC Field Length
#define TWI_SR_SVACC_Msk (0x1 << 4) //!< SVACC Mask
/* \} */
/** \defgroup TWI_SR_GACC GACC: General Call Access
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_GACC     (0x1 << 5) //!< GACC Value
#define TWI_SR_GACC_Pos (5)        //!< GACC Position
#define TWI_SR_GACC_Len (1)        //!< GACC Field Length
#define TWI_SR_GACC_Msk (0x1 << 5) //!< GACC Mask
/* \} */
/** \defgroup TWI_SR_OVRE OVRE: Overrun Error
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_OVRE     (0x1 << 6) //!< OVRE Value
#define TWI_SR_OVRE_Pos (6)        //!< OVRE Position
#define TWI_SR_OVRE_Len (1)        //!< OVRE Field Length
#define TWI_SR_OVRE_Msk (0x1 << 6) //!< OVRE Mask
/* \} */
/** \defgroup TWI_SR_NACK NACK: Not Acknowledged
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_NACK     (0x1 << 8) //!< NACK Value
#define TWI_SR_NACK_Pos (8)        //!< NACK Position
#define TWI_SR_NACK_Len (1)        //!< NACK Field Length
#define TWI_SR_NACK_Msk (0x1 << 8) //!< NACK Mask
/* \} */
/** \defgroup TWI_SR_ARBLST ARBLST: Arbitration Lost
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_ARBLST     (0x1 << 9) //!< ARBLST Value
#define TWI_SR_ARBLST_Pos (9)        //!< ARBLST Position
#define TWI_SR_ARBLST_Len (1)        //!< ARBLST Field Length
#define TWI_SR_ARBLST_Msk (0x1 << 9) //!< ARBLST Mask
/* \} */
/** \defgroup TWI_SR_SCLWS SCLWS: Clock Wait State
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_SCLWS     (0x1 << 10) //!< SCLWS Value
#define TWI_SR_SCLWS_Pos (10)        //!< SCLWS Position
#define TWI_SR_SCLWS_Len (1)         //!< SCLWS Field Length
#define TWI_SR_SCLWS_Msk (0x1 << 10) //!< SCLWS Mask
/* \} */
/** \defgroup TWI_SR_EOSACC EOSACC: End Of Slave Access
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_EOSACC     (0x1 << 11) //!< EOSACC Value
#define TWI_SR_EOSACC_Pos (11)        //!< EOSACC Position
#define TWI_SR_EOSACC_Len (1)         //!< EOSACC Field Length
#define TWI_SR_EOSACC_Msk (0x1 << 11) //!< EOSACC Mask
/* \} */
/** \defgroup TWI_SR_ENDRX ENDRX: End of RX Buffer
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_ENDRX     (0x1 << 12) //!< ENDRX Value
#define TWI_SR_ENDRX_Pos (12)        //!< ENDRX Position
#define TWI_SR_ENDRX_Len (1)         //!< ENDRX Field Length
#define TWI_SR_ENDRX_Msk (0x1 << 12) //!< ENDRX Mask
/* \} */
/** \defgroup TWI_SR_ENDTX ENDTX: End of TX Buffer
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_ENDTX     (0x1 << 13) //!< ENDTX Value
#define TWI_SR_ENDTX_Pos (13)        //!< ENDTX Position
#define TWI_SR_ENDTX_Len (1)         //!< ENDTX Field Length
#define TWI_SR_ENDTX_Msk (0x1 << 13) //!< ENDTX Mask
/* \} */
/** \defgroup TWI_SR_RXBUFF RXBUFF: RX Buffer Full
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_RXBUFF     (0x1 << 14) //!< RXBUFF Value
#define TWI_SR_RXBUFF_Pos (14)        //!< RXBUFF Position
#define TWI_SR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define TWI_SR_RXBUFF_Msk (0x1 << 14) //!< RXBUFF Mask
/* \} */
/** \defgroup TWI_SR_BUFE TXBUFE: TX Buffer Empty
 * \ingroup TWI_SR
 * \{
 */
#define TWI_SR_BUFE     (0x1 << 15) //!< BUFE Value
#define TWI_SR_BUFE_Pos (15)        //!< BUFE Position
#define TWI_SR_BUFE_Len (1)         //!< BUFE Field Length
#define TWI_SR_BUFE_Msk (0x1 << 15) //!< BUFE Mask
/* \} */

/** \defgroup TWI_IER Interrupt Enable Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_IER_TXCOMP TXCOMP: Transmission Completed Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_TXCOMP     (0x1 << 0) //!< TXCOMP Value
#define TWI_IER_TXCOMP_Pos (0)        //!< TXCOMP Position
#define TWI_IER_TXCOMP_Len (1)        //!< TXCOMP Field Length
#define TWI_IER_TXCOMP_Msk (0x1 << 0) //!< TXCOMP Mask
/* \} */
/** \defgroup TWI_IER_RXRDY RXRDY: Receive Holding Register Ready Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_RXRDY     (0x1 << 1) //!< RXRDY Value
#define TWI_IER_RXRDY_Pos (1)        //!< RXRDY Position
#define TWI_IER_RXRDY_Len (1)        //!< RXRDY Field Length
#define TWI_IER_RXRDY_Msk (0x1 << 1) //!< RXRDY Mask
/* \} */
/** \defgroup TWI_IER_TXRDY TXRDY: Transmit Holding Register Ready Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_TXRDY     (0x1 << 2) //!< TXRDY Value
#define TWI_IER_TXRDY_Pos (2)        //!< TXRDY Position
#define TWI_IER_TXRDY_Len (1)        //!< TXRDY Field Length
#define TWI_IER_TXRDY_Msk (0x1 << 2) //!< TXRDY Mask
/* \} */
/** \defgroup TWI_IER_SVACC SVACC: Slave Access Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_SVACC     (0x1 << 4) //!< SVACC Value
#define TWI_IER_SVACC_Pos (4)        //!< SVACC Position
#define TWI_IER_SVACC_Len (1)        //!< SVACC Field Length
#define TWI_IER_SVACC_Msk (0x1 << 4) //!< SVACC Mask
/* \} */
/** \defgroup TWI_IER_GACC GACC: General Call Access Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_GACC     (0x1 << 5) //!< GACC Value
#define TWI_IER_GACC_Pos (5)        //!< GACC Position
#define TWI_IER_GACC_Len (1)        //!< GACC Field Length
#define TWI_IER_GACC_Msk (0x1 << 5) //!< GACC Mask
/* \} */
/** \defgroup TWI_IER_OVRE OVRE: Overrun Error Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_OVRE     (0x1 << 6) //!< OVRE Value
#define TWI_IER_OVRE_Pos (6)        //!< OVRE Position
#define TWI_IER_OVRE_Len (1)        //!< OVRE Field Length
#define TWI_IER_OVRE_Msk (0x1 << 6) //!< OVRE Mask
/* \} */
/** \defgroup TWI_IER_NACK NACK: Not Acknowledge Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_NACK     (0x1 << 8) //!< NACK Value
#define TWI_IER_NACK_Pos (8)        //!< NACK Position
#define TWI_IER_NACK_Len (1)        //!< NACK Field Length
#define TWI_IER_NACK_Msk (0x1 << 8) //!< NACK Mask
/* \} */
/** \defgroup TWI_IER_ARBLST ARBLST: Arbitration Lost Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_ARBLST     (0x1 << 9) //!< ARBLST Value
#define TWI_IER_ARBLST_Pos (9)        //!< ARBLST Position
#define TWI_IER_ARBLST_Len (1)        //!< ARBLST Field Length
#define TWI_IER_ARBLST_Msk (0x1 << 9) //!< ARBLST Mask
/* \} */
/** \defgroup TWI_IER_SCL SCL_WS: Clock Wait State Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_SCL_WS     (0x1 << 10) //!< SCL_WS Value
#define TWI_IER_SCL_WS_Pos (10)        //!< SCL_WS Position
#define TWI_IER_SCL_WS_Len (1)         //!< SCL_WS Field Length
#define TWI_IER_SCL_WS_Msk (0x1 << 10) //!< SCL_WS Mask
/* \} */
/** \defgroup TWI_IER_EOSACC EOSACC: End of Slave Access Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_EOSACC     (0x1 << 11) //!< EOSACC Value
#define TWI_IER_EOSACC_Pos (11)        //!< EOSACC Position
#define TWI_IER_EOSACC_Len (1)         //!< EOSACC Field Length
#define TWI_IER_EOSACC_Msk (0x1 << 11) //!< EOSACC Mask
/* \} */
/** \defgroup TWI_IER_ENDRX ENDRX: End of Receive Buffer Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_ENDRX     (0x1 << 12) //!< ENDRX Value
#define TWI_IER_ENDRX_Pos (12)        //!< ENDRX Position
#define TWI_IER_ENDRX_Len (1)         //!< ENDRX Field Length
#define TWI_IER_ENDRX_Msk (0x1 << 12) //!< ENDRX Mask
/* \} */
/** \defgroup TWI_IER_ENDTX ENDTX: End of Transmit Buffer Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_ENDTX     (0x1 << 13) //!< ENDTX Value
#define TWI_IER_ENDTX_Pos (13)        //!< ENDTX Position
#define TWI_IER_ENDTX_Len (1)         //!< ENDTX Field Length
#define TWI_IER_ENDTX_Msk (0x1 << 13) //!< ENDTX Mask
/* \} */
/** \defgroup TWI_IER_RXBUFF RXBUFF: Receive Buffer Full Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_RXBUFF     (0x1 << 14) //!< RXBUFF Value
#define TWI_IER_RXBUFF_Pos (14)        //!< RXBUFF Position
#define TWI_IER_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define TWI_IER_RXBUFF_Msk (0x1 << 14) //!< RXBUFF Mask
/* \} */
/** \defgroup TWI_IER_TXBUFE TXBUFE: Transmit Buffer Empty Interrupt Enable
 * \ingroup TWI_IER
 * \{
 */
#define TWI_IER_TXBUFE     (0x1 << 15) //!< TXBUFE Value
#define TWI_IER_TXBUFE_Pos (15)        //!< TXBUFE Position
#define TWI_IER_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define TWI_IER_TXBUFE_Msk (0x1 << 15) //!< TXBUFE Mask
/* \} */

/** \defgroup TWI_IDR Interrupt Disable Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_IDR_TXCOMP TXCOMP: Transmission Completed Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_TXCOMP     (0x1 << 0) //!< TXCOMP Value
#define TWI_IDR_TXCOMP_Pos (0)        //!< TXCOMP Position
#define TWI_IDR_TXCOMP_Len (1)        //!< TXCOMP Field Length
#define TWI_IDR_TXCOMP_Msk (0x1 << 0) //!< TXCOMP Mask
/* \} */
/** \defgroup TWI_IDR_RXRDY RXRDY: Receive Holding Register Ready Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_RXRDY     (0x1 << 1) //!< RXRDY Value
#define TWI_IDR_RXRDY_Pos (1)        //!< RXRDY Position
#define TWI_IDR_RXRDY_Len (1)        //!< RXRDY Field Length
#define TWI_IDR_RXRDY_Msk (0x1 << 1) //!< RXRDY Mask
/* \} */
/** \defgroup TWI_IDR_TXRDY TXRDY: Transmit Holding Register Ready Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_TXRDY     (0x1 << 2) //!< TXRDY Value
#define TWI_IDR_TXRDY_Pos (2)        //!< TXRDY Position
#define TWI_IDR_TXRDY_Len (1)        //!< TXRDY Field Length
#define TWI_IDR_TXRDY_Msk (0x1 << 2) //!< TXRDY Mask
/* \} */
/** \defgroup TWI_IDR_SVACC SVACC: Slave Access Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_SVACC     (0x1 << 4) //!< SVACC Value
#define TWI_IDR_SVACC_Pos (4)        //!< SVACC Position
#define TWI_IDR_SVACC_Len (1)        //!< SVACC Field Length
#define TWI_IDR_SVACC_Msk (0x1 << 4) //!< SVACC Mask
/* \} */
/** \defgroup TWI_IDR_GACC GACC: General Call Access Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_GACC     (0x1 << 5) //!< GACC Value
#define TWI_IDR_GACC_Pos (5)        //!< GACC Position
#define TWI_IDR_GACC_Len (1)        //!< GACC Field Length
#define TWI_IDR_GACC_Msk (0x1 << 5) //!< GACC Mask
/* \} */
/** \defgroup TWI_IDR_OVRE OVRE: Overrun Error Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_OVRE     (0x1 << 6) //!< OVRE Value
#define TWI_IDR_OVRE_Pos (6)        //!< OVRE Position
#define TWI_IDR_OVRE_Len (1)        //!< OVRE Field Length
#define TWI_IDR_OVRE_Msk (0x1 << 6) //!< OVRE Mask
/* \} */
/** \defgroup TWI_IDR_NACK NACK: Not Acknowledge Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_NACK     (0x1 << 8) //!< NACK Value
#define TWI_IDR_NACK_Pos (8)        //!< NACK Position
#define TWI_IDR_NACK_Len (1)        //!< NACK Field Length
#define TWI_IDR_NACK_Msk (0x1 << 8) //!< NACK Mask
/* \} */
/** \defgroup TWI_IDR_ARBLST ARBLST: Arbitration Lost Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_ARBLST     (0x1 << 9) //!< ARBLST Value
#define TWI_IDR_ARBLST_Pos (9)        //!< ARBLST Position
#define TWI_IDR_ARBLST_Len (1)        //!< ARBLST Field Length
#define TWI_IDR_ARBLST_Msk (0x1 << 9) //!< ARBLST Mask
/* \} */
/** \defgroup TWI_IDR_SCL SCL_WS: Clock Wait State Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_SCL_WS     (0x1 << 10) //!< SCL_WS Value
#define TWI_IDR_SCL_WS_Pos (10)        //!< SCL_WS Position
#define TWI_IDR_SCL_WS_Len (1)         //!< SCL_WS Field Length
#define TWI_IDR_SCL_WS_Msk (0x1 << 10) //!< SCL_WS Mask
/* \} */
/** \defgroup TWI_IDR_EOSACC EOSACC: End of Slave Access Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_EOSACC     (0x1 << 11) //!< EOSACC Value
#define TWI_IDR_EOSACC_Pos (11)        //!< EOSACC Position
#define TWI_IDR_EOSACC_Len (1)         //!< EOSACC Field Length
#define TWI_IDR_EOSACC_Msk (0x1 << 11) //!< EOSACC Mask
/* \} */
/** \defgroup TWI_IDR_ENDRX ENDRX: End of Receive Buffer Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_ENDRX     (0x1 << 12) //!< ENDRX Value
#define TWI_IDR_ENDRX_Pos (12)        //!< ENDRX Position
#define TWI_IDR_ENDRX_Len (1)         //!< ENDRX Field Length
#define TWI_IDR_ENDRX_Msk (0x1 << 12) //!< ENDRX Mask
/* \} */
/** \defgroup TWI_IDR_ENDTX ENDTX: End of Transmit Buffer Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_ENDTX     (0x1 << 13) //!< ENDTX Value
#define TWI_IDR_ENDTX_Pos (13)        //!< ENDTX Position
#define TWI_IDR_ENDTX_Len (1)         //!< ENDTX Field Length
#define TWI_IDR_ENDTX_Msk (0x1 << 13) //!< ENDTX Mask
/* \} */
/** \defgroup TWI_IDR_RXBUFF RXBUFF: Receive Buffer Full Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_RXBUFF     (0x1 << 14) //!< RXBUFF Value
#define TWI_IDR_RXBUFF_Pos (14)        //!< RXBUFF Position
#define TWI_IDR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define TWI_IDR_RXBUFF_Msk (0x1 << 14) //!< RXBUFF Mask
/* \} */
/** \defgroup TWI_IDR_TXBUFE TXBUFE: Transmit Buffer Empty Interrupt Disable
 * \ingroup TWI_IDR
 * \{
 */
#define TWI_IDR_TXBUFE     (0x1 << 15) //!< TXBUFE Value
#define TWI_IDR_TXBUFE_Pos (15)        //!< TXBUFE Position
#define TWI_IDR_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define TWI_IDR_TXBUFE_Msk (0x1 << 15) //!< TXBUFE Mask
/* \} */

/** \defgroup TWI_IMR Interrupt Mask Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_IMR_TXCOMP TXCOMP: Transmission Completed Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_TXCOMP     (0x1 << 0) //!< TXCOMP Value
#define TWI_IMR_TXCOMP_Pos (0)        //!< TXCOMP Position
#define TWI_IMR_TXCOMP_Len (1)        //!< TXCOMP Field Length
#define TWI_IMR_TXCOMP_Msk (0x1 << 0) //!< TXCOMP Mask
/* \} */
/** \defgroup TWI_IMR_RXRDY RXRDY: Receive Holding Register Ready Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_RXRDY     (0x1 << 1) //!< RXRDY Value
#define TWI_IMR_RXRDY_Pos (1)        //!< RXRDY Position
#define TWI_IMR_RXRDY_Len (1)        //!< RXRDY Field Length
#define TWI_IMR_RXRDY_Msk (0x1 << 1) //!< RXRDY Mask
/* \} */
/** \defgroup TWI_IMR_TXRDY TXRDY: Transmit Holding Register Ready Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_TXRDY     (0x1 << 2) //!< TXRDY Value
#define TWI_IMR_TXRDY_Pos (2)        //!< TXRDY Position
#define TWI_IMR_TXRDY_Len (1)        //!< TXRDY Field Length
#define TWI_IMR_TXRDY_Msk (0x1 << 2) //!< TXRDY Mask
/* \} */
/** \defgroup TWI_IMR_SVACC SVACC: Slave Access Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_SVACC     (0x1 << 4) //!< SVACC Value
#define TWI_IMR_SVACC_Pos (4)        //!< SVACC Position
#define TWI_IMR_SVACC_Len (1)        //!< SVACC Field Length
#define TWI_IMR_SVACC_Msk (0x1 << 4) //!< SVACC Mask
/* \} */
/** \defgroup TWI_IMR_GACC GACC: General Call Access Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_GACC     (0x1 << 5) //!< GACC Value
#define TWI_IMR_GACC_Pos (5)        //!< GACC Position
#define TWI_IMR_GACC_Len (1)        //!< GACC Field Length
#define TWI_IMR_GACC_Msk (0x1 << 5) //!< GACC Mask
/* \} */
/** \defgroup TWI_IMR_OVRE OVRE: Overrun Error Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_OVRE     (0x1 << 6) //!< OVRE Value
#define TWI_IMR_OVRE_Pos (6)        //!< OVRE Position
#define TWI_IMR_OVRE_Len (1)        //!< OVRE Field Length
#define TWI_IMR_OVRE_Msk (0x1 << 6) //!< OVRE Mask
/* \} */
/** \defgroup TWI_IMR_NACK NACK: Not Acknowledge Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_NACK     (0x1 << 8) //!< NACK Value
#define TWI_IMR_NACK_Pos (8)        //!< NACK Position
#define TWI_IMR_NACK_Len (1)        //!< NACK Field Length
#define TWI_IMR_NACK_Msk (0x1 << 8) //!< NACK Mask
/* \} */
/** \defgroup TWI_IMR_ARBLST ARBLST: Arbitration Lost Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_ARBLST     (0x1 << 9) //!< ARBLST Value
#define TWI_IMR_ARBLST_Pos (9)        //!< ARBLST Position
#define TWI_IMR_ARBLST_Len (1)        //!< ARBLST Field Length
#define TWI_IMR_ARBLST_Msk (0x1 << 9) //!< ARBLST Mask
/* \} */
/** \defgroup TWI_IMR_SCL SCL_WS: Clock Wait State Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_SCL_WS     (0x1 << 10) //!< SCL_WS Value
#define TWI_IMR_SCL_WS_Pos (10)        //!< SCL_WS Position
#define TWI_IMR_SCL_WS_Len (1)         //!< SCL_WS Field Length
#define TWI_IMR_SCL_WS_Msk (0x1 << 10) //!< SCL_WS Mask
/* \} */
/** \defgroup TWI_IMR_EOSACC EOSACC: End of Slave Access Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_EOSACC     (0x1 << 11) //!< EOSACC Value
#define TWI_IMR_EOSACC_Pos (11)        //!< EOSACC Position
#define TWI_IMR_EOSACC_Len (1)         //!< EOSACC Field Length
#define TWI_IMR_EOSACC_Msk (0x1 << 11) //!< EOSACC Mask
/* \} */
/** \defgroup TWI_IMR_ENDRX ENDRX: End of Receive Buffer Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_ENDRX     (0x1 << 12) //!< ENDRX Value
#define TWI_IMR_ENDRX_Pos (12)        //!< ENDRX Position
#define TWI_IMR_ENDRX_Len (1)         //!< ENDRX Field Length
#define TWI_IMR_ENDRX_Msk (0x1 << 12) //!< ENDRX Mask
/* \} */
/** \defgroup TWI_IMR_ENDTX ENDTX: End of Transmit Buffer Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_ENDTX     (0x1 << 13) //!< ENDTX Value
#define TWI_IMR_ENDTX_Pos (13)        //!< ENDTX Position
#define TWI_IMR_ENDTX_Len (1)         //!< ENDTX Field Length
#define TWI_IMR_ENDTX_Msk (0x1 << 13) //!< ENDTX Mask
/* \} */
/** \defgroup TWI_IMR_RXBUFF RXBUFF: Receive Buffer Full Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_RXBUFF     (0x1 << 14) //!< RXBUFF Value
#define TWI_IMR_RXBUFF_Pos (14)        //!< RXBUFF Position
#define TWI_IMR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define TWI_IMR_RXBUFF_Msk (0x1 << 14) //!< RXBUFF Mask
/* \} */
/** \defgroup TWI_IMR_TXBUFE TXBUFE: Transmit Buffer Empty Interrupt Mask
 * \ingroup TWI_IMR
 * \{
 */
#define TWI_IMR_TXBUFE     (0x1 << 15) //!< TXBUFE Value
#define TWI_IMR_TXBUFE_Pos (15)        //!< TXBUFE Position
#define TWI_IMR_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define TWI_IMR_TXBUFE_Msk (0x1 << 15) //!< TXBUFE Mask
/* \} */

/** \defgroup TWI_RHR Receive Holding Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_RHR_RXDATA RXDATA: Master or Slave Receive Holding Data
 * \ingroup TWI_RHR
 * \{
 */
#define TWI_RHR_RXDATA(v)  (((v) & 0xFF) << 0) //!< RXDATA Value
#define TWI_RHR_RXDATA_Pos (0)                 //!< RXDATA Position
#define TWI_RHR_RXDATA_Len (8)                 //!< RXDATA Field Length
#define TWI_RHR_RXDATA_Msk (0xFF << 0)         //!< RXDATA Mask
/* \} */

/** \defgroup TWI_THR Transmit Holding Register Bit Definitions
 * \ingroup TWI
 */

/** \defgroup TWI_THR_TXDATA TXDATA: Master or Slave Transmit Holding Data
 * \ingroup TWI_THR
 * \{
 */
#define TWI_THR_TXDATA(v)  (((v) & 0xFF) << 0) //!< TXDATA Value
#define TWI_THR_TXDATA_Pos (0)                 //!< TXDATA Position
#define TWI_THR_TXDATA_Len (8)                 //!< TXDATA Field Length
#define TWI_THR_TXDATA_Msk (0xFF << 0)         //!< TXDATA Mask
/* \} */

#endif // _CPU_PERIPHERALS_TWI_H_
