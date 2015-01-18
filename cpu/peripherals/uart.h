/**
 * \file
 *
 * \brief Universal Asynchronous Receiver Transceiver (UART) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_UART_H_
#define _CPU_PERIPHERALS_UART_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup UART Universal Asynchronous Receiver Transceiver (UART) User Interface */

/** \defgroup UART_UI_REG User Interface Registers
 * \ingroup UART
 * \{
 */
#define UART_CR          (*(reg_wo_t*)(UART+0x0000)) //!< \ref UART_CR
#define UART_MR          (*(reg_rw_t*)(UART+0x0004)) //!< \ref UART_MR
#define UART_IER         (*(reg_wo_t*)(UART+0x0008)) //!< \ref UART_IER
#define UART_IDR         (*(reg_wo_t*)(UART+0x000C)) //!< \ref UART_IDR
#define UART_IMR         (*(reg_ro_t*)(UART+0x0010)) //!< \ref UART_IMR
#define UART_SR          (*(reg_ro_t*)(UART+0x0014)) //!< \ref UART_SR
#define UART_RHR         (*(reg_ro_t*)(UART+0x0018)) //!< \ref UART_RHR
#define UART_THR         (*(reg_wo_t*)(UART+0x001C)) //!< \ref UART_THR
#define UART_BRGR        (*(reg_rw_t*)(UART+0x0020)) //!< \ref UART_BRGR
/* \} */

/** \defgroup UART_CR Control Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_CR_RSTRX RSTRX: Reset Receiver
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_RSTRX     (0x1 << 2) //!< RSTRX Value
#define UART_CR_RSTRX_Pos (2)        //!< RSTRX Position
#define UART_CR_RSTRX_Len (1)        //!< RSTRX Field Length
#define UART_CR_RSTRX_Msk (0x1 << 2) //!< RSTRX Mask
/* \} */
/** \defgroup UART_CR_RSTTX RSTTX: Reset Transmitter
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_RSTTX     (0x1 << 3) //!< RSTTX Value
#define UART_CR_RSTTX_Pos (3)        //!< RSTTX Position
#define UART_CR_RSTTX_Len (1)        //!< RSTTX Field Length
#define UART_CR_RSTTX_Msk (0x1 << 3) //!< RSTTX Mask
/* \} */
/** \defgroup UART_CR_RXEN RXEN: Receiver Enable
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_RXEN     (0x1 << 4) //!< RXEN Value
#define UART_CR_RXEN_Pos (4)        //!< RXEN Position
#define UART_CR_RXEN_Len (1)        //!< RXEN Field Length
#define UART_CR_RXEN_Msk (0x1 << 4) //!< RXEN Mask
/* \} */
/** \defgroup UART_CR_RXDIS RXDIS: Receiver Disable
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_RXDIS     (0x1 << 5) //!< RXDIS Value
#define UART_CR_RXDIS_Pos (5)        //!< RXDIS Position
#define UART_CR_RXDIS_Len (1)        //!< RXDIS Field Length
#define UART_CR_RXDIS_Msk (0x1 << 5) //!< RXDIS Mask
/* \} */
/** \defgroup UART_CR_TXEN TXEN: Transmitter Enable
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_TXEN     (0x1 << 6) //!< TXEN Value
#define UART_CR_TXEN_Pos (6)        //!< TXEN Position
#define UART_CR_TXEN_Len (1)        //!< TXEN Field Length
#define UART_CR_TXEN_Msk (0x1 << 6) //!< TXEN Mask
/* \} */
/** \defgroup UART_CR_TXDIS TXDIS: Transmitter Disable
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_TXDIS     (0x1 << 7) //!< TXDIS Value
#define UART_CR_TXDIS_Pos (7)        //!< TXDIS Position
#define UART_CR_TXDIS_Len (1)        //!< TXDIS Field Length
#define UART_CR_TXDIS_Msk (0x1 << 7) //!< TXDIS Mask
/* \} */
/** \defgroup UART_CR_RSTSTA RSTSTA: Reset Status Bits
 * \ingroup UART_CR
 * \{
 */
#define UART_CR_RSTSTA     (0x1 << 8) //!< RSTSTA Value
#define UART_CR_RSTSTA_Pos (8)        //!< RSTSTA Position
#define UART_CR_RSTSTA_Len (1)        //!< RSTSTA Field Length
#define UART_CR_RSTSTA_Msk (0x1 << 8) //!< RSTSTA Mask
/* \} */

/** \defgroup UART_MR Mode Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_MR_PAR PAR: Parity Type
 * \ingroup UART_MR
 * \{
 */
#define UART_MR_PAR(v)  (((v) & 0xE) << 9) //!< PAR Value
#define UART_MR_PAR_Pos (9)                //!< PAR Position
#define UART_MR_PAR_Len (3)                //!< PAR Field Length
#define UART_MR_PAR_Msk (0xE << 9)         //!< PAR Mask
#define UART_MR_PAR_EVEN  (0)              //!< PAR_EVEN Value
#define UART_MR_PAR_ODD   (1)              //!< PAR_ODD Value
#define UART_MR_PAR_SPACE (2)              //!< PAR_SPACE Value
#define UART_MR_PAR_MARK  (3)              //!< PAR_MARK Value
#define UART_MR_PAR_NO    (4)              //!< PAR_NO Value
/* \} */
/** \defgroup UART_MR_CHMODE CHMODE: Channel Mode
 * \ingroup UART_MR
 * \{
 */
#define UART_MR_CHMODE(v)  (((v) & 0x3) << 14) //!< CHMODE Value
#define UART_MR_CHMODE_Pos (14)                //!< CHMODE Position
#define UART_MR_CHMODE_Len (2)                 //!< CHMODE Field Length
#define UART_MR_CHMODE_Msk (0x3 << 14)         //!< CHMODE Mask
#define UART_MR_CHMODE_NORMAL (0)              //!< CHMODE_NORMAL Value
#define UART_MR_CHMODE_AUTOMATIC (1)           //!< CHMODE_AUTOMATIC Value
#define UART_MR_CHMODE_LOCAL_LOOPBACK (2)      //!< CHMODE_LOCAL_LOOPBACK Value
#define UART_MR_CHMODE_REMOTE_LOOPBACK (3)     //!< CHMODE_REMOTE_LOOPBACK Value
/* \} */

/** \defgroup UART_IER Interrupt Enable Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_IER_RXRDY RXRDY: Enable RXRDY Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_RXRDY     (0x1 << 0) //!< RXRDY Value
#define UART_IER_RXRDY_Pos (0)        //!< RXRDY Position
#define UART_IER_RXRDY_Len (1)        //!< RXRDY Field Length
#define UART_IER_RXRDY_Msk (0x1 << 0) //!< RXRDY Mask
/* \} */
/** \defgroup UART_IER_TXRDY TXRDY: Enable TXRDY Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_TXRDY     (0x1 << 1) //!< TXRDY Value
#define UART_IER_TXRDY_Pos (1)        //!< TXRDY Position
#define UART_IER_TXRDY_Len (1)        //!< TXRDY Field Length
#define UART_IER_TXRDY_Msk (0x1 << 1) //!< TXRDY Mask
/* \} */
/** \defgroup UART_IER_ENDRX ENDRX: Enable End of Receive Transfer Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_ENDRX     (0x1 << 3) //!< ENDRX Value
#define UART_IER_ENDRX_Pos (3)        //!< ENDRX Position
#define UART_IER_ENDRX_Len (1)        //!< ENDRX Field Length
#define UART_IER_ENDRX_Msk (0x1 << 3) //!< ENDRX Mask
/* \} */
/** \defgroup UART_IER_ENDTX ENDTX: Enable End of Transmit Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_ENDTX     (0x1 << 4) //!< ENDTX Value
#define UART_IER_ENDTX_Pos (4)        //!< ENDTX Position
#define UART_IER_ENDTX_Len (1)        //!< ENDTX Field Length
#define UART_IER_ENDTX_Msk (0x1 << 4) //!< ENDTX Mask
/* \} */
/** \defgroup UART_IER_OVRE OVRE: Enable Overrun Error Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_OVRE     (0x1 << 5) //!< OVRE Value
#define UART_IER_OVRE_Pos (5)        //!< OVRE Position
#define UART_IER_OVRE_Len (1)        //!< OVRE Field Length
#define UART_IER_OVRE_Msk (0x1 << 5) //!< OVRE Mask
/* \} */
/** \defgroup UART_IER_FRAME FRAME: Enable Framing Error Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_FRAME     (0x1 << 6) //!< FRAME Value
#define UART_IER_FRAME_Pos (6)        //!< FRAME Position
#define UART_IER_FRAME_Len (1)        //!< FRAME Field Length
#define UART_IER_FRAME_Msk (0x1 << 6) //!< FRAME Mask
/* \} */
/** \defgroup UART_IER_PARE PARE: Enable Parity Error Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_PARE     (0x1 << 7) //!< PARE Value
#define UART_IER_PARE_Pos (7)        //!< PARE Position
#define UART_IER_PARE_Len (1)        //!< PARE Field Length
#define UART_IER_PARE_Msk (0x1 << 7) //!< PARE Mask
/* \} */
/** \defgroup UART_IER_TXEMPTY TXEMPTY: Enable TXEMPTY Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define UART_IER_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define UART_IER_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define UART_IER_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup UART_IER_TXBUFE TXBUFE: Enable Buffer Empty Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_TXBUFE     (0x1 << 11) //!< TXBUFE Value
#define UART_IER_TXBUFE_Pos (11)        //!< TXBUFE Position
#define UART_IER_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define UART_IER_TXBUFE_Msk (0x1 << 11) //!< TXBUFE Mask
/* \} */
/** \defgroup UART_IER_RXBUFF RXBUFF: Enable Buffer Full Interrupt
 * \ingroup UART_IER
 * \{
 */
#define UART_IER_RXBUFF     (0x1 << 12) //!< RXBUFF Value
#define UART_IER_RXBUFF_Pos (12)        //!< RXBUFF Position
#define UART_IER_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define UART_IER_RXBUFF_Msk (0x1 << 12) //!< RXBUFF Mask
/* \} */

/** \defgroup UART_IDR Interrupt Disable Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_IDR_RXRDY RXRDY: Disable RXRDY Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_RXRDY     (0x1 << 0) //!< RXRDY Value
#define UART_IDR_RXRDY_Pos (0)        //!< RXRDY Position
#define UART_IDR_RXRDY_Len (1)        //!< RXRDY Field Length
#define UART_IDR_RXRDY_Msk (0x1 << 0) //!< RXRDY Mask
/* \} */
/** \defgroup UART_IDR_TXRDY TXRDY: Disable TXRDY Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_TXRDY     (0x1 << 1) //!< TXRDY Value
#define UART_IDR_TXRDY_Pos (1)        //!< TXRDY Position
#define UART_IDR_TXRDY_Len (1)        //!< TXRDY Field Length
#define UART_IDR_TXRDY_Msk (0x1 << 1) //!< TXRDY Mask
/* \} */
/** \defgroup UART_IDR_ENDRX ENDRX: Disable End of Receive Transfer Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_ENDRX     (0x1 << 3) //!< ENDRX Value
#define UART_IDR_ENDRX_Pos (3)        //!< ENDRX Position
#define UART_IDR_ENDRX_Len (1)        //!< ENDRX Field Length
#define UART_IDR_ENDRX_Msk (0x1 << 3) //!< ENDRX Mask
/* \} */
/** \defgroup UART_IDR_ENDTX ENDTX: Disable End of Transmit Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_ENDTX     (0x1 << 4) //!< ENDTX Value
#define UART_IDR_ENDTX_Pos (4)        //!< ENDTX Position
#define UART_IDR_ENDTX_Len (1)        //!< ENDTX Field Length
#define UART_IDR_ENDTX_Msk (0x1 << 4) //!< ENDTX Mask
/* \} */
/** \defgroup UART_IDR_OVRE OVRE: Disable Overrun Error Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_OVRE     (0x1 << 5) //!< OVRE Value
#define UART_IDR_OVRE_Pos (5)        //!< OVRE Position
#define UART_IDR_OVRE_Len (1)        //!< OVRE Field Length
#define UART_IDR_OVRE_Msk (0x1 << 5) //!< OVRE Mask
/* \} */
/** \defgroup UART_IDR_FRAME FRAME: Disable Framing Error Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_FRAME     (0x1 << 6) //!< FRAME Value
#define UART_IDR_FRAME_Pos (6)        //!< FRAME Position
#define UART_IDR_FRAME_Len (1)        //!< FRAME Field Length
#define UART_IDR_FRAME_Msk (0x1 << 6) //!< FRAME Mask
/* \} */
/** \defgroup UART_IDR_PARE PARE: Disable Parity Error Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_PARE     (0x1 << 7) //!< PARE Value
#define UART_IDR_PARE_Pos (7)        //!< PARE Position
#define UART_IDR_PARE_Len (1)        //!< PARE Field Length
#define UART_IDR_PARE_Msk (0x1 << 7) //!< PARE Mask
/* \} */
/** \defgroup UART_IDR_TXEMPTY TXEMPTY: Disable TXEMPTY Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define UART_IDR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define UART_IDR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define UART_IDR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup UART_IDR_TXBUFE TXBUFE: Disable Buffer Empty Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_TXBUFE     (0x1 << 11) //!< TXBUFE Value
#define UART_IDR_TXBUFE_Pos (11)        //!< TXBUFE Position
#define UART_IDR_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define UART_IDR_TXBUFE_Msk (0x1 << 11) //!< TXBUFE Mask
/* \} */
/** \defgroup UART_IDR_RXBUFF RXBUFF: Disable Buffer Full Interrupt
 * \ingroup UART_IDR
 * \{
 */
#define UART_IDR_RXBUFF     (0x1 << 12) //!< RXBUFF Value
#define UART_IDR_RXBUFF_Pos (12)        //!< RXBUFF Position
#define UART_IDR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define UART_IDR_RXBUFF_Msk (0x1 << 12) //!< RXBUFF Mask
/* \} */

/** \defgroup UART_IMR Interrupt Mask Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_IMR_RXRDY RXRDY: Mask RXRDY Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_RXRDY     (0x1 << 0) //!< RXRDY Value
#define UART_IMR_RXRDY_Pos (0)        //!< RXRDY Position
#define UART_IMR_RXRDY_Len (1)        //!< RXRDY Field Length
#define UART_IMR_RXRDY_Msk (0x1 << 0) //!< RXRDY Mask
/* \} */
/** \defgroup UART_IMR_TXRDY TXRDY: Disable TXRDY Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_TXRDY     (0x1 << 1) //!< TXRDY Value
#define UART_IMR_TXRDY_Pos (1)        //!< TXRDY Position
#define UART_IMR_TXRDY_Len (1)        //!< TXRDY Field Length
#define UART_IMR_TXRDY_Msk (0x1 << 1) //!< TXRDY Mask
/* \} */
/** \defgroup UART_IMR_ENDRX ENDRX: Mask End of Receive Transfer Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_ENDRX     (0x1 << 3) //!< ENDRX Value
#define UART_IMR_ENDRX_Pos (3)        //!< ENDRX Position
#define UART_IMR_ENDRX_Len (1)        //!< ENDRX Field Length
#define UART_IMR_ENDRX_Msk (0x1 << 3) //!< ENDRX Mask
/* \} */
/** \defgroup UART_IMR_ENDTX ENDTX: Mask End of Transmit Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_ENDTX     (0x1 << 4) //!< ENDTX Value
#define UART_IMR_ENDTX_Pos (4)        //!< ENDTX Position
#define UART_IMR_ENDTX_Len (1)        //!< ENDTX Field Length
#define UART_IMR_ENDTX_Msk (0x1 << 4) //!< ENDTX Mask
/* \} */
/** \defgroup UART_IMR_OVRE OVRE: Mask Overrun Error Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_OVRE     (0x1 << 5) //!< OVRE Value
#define UART_IMR_OVRE_Pos (5)        //!< OVRE Position
#define UART_IMR_OVRE_Len (1)        //!< OVRE Field Length
#define UART_IMR_OVRE_Msk (0x1 << 5) //!< OVRE Mask
/* \} */
/** \defgroup UART_IMR_FRAME FRAME: Mask Framing Error Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_FRAME     (0x1 << 6) //!< FRAME Value
#define UART_IMR_FRAME_Pos (6)        //!< FRAME Position
#define UART_IMR_FRAME_Len (1)        //!< FRAME Field Length
#define UART_IMR_FRAME_Msk (0x1 << 6) //!< FRAME Mask
/* \} */
/** \defgroup UART_IMR_PARE PARE: Mask Parity Error Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_PARE     (0x1 << 7) //!< PARE Value
#define UART_IMR_PARE_Pos (7)        //!< PARE Position
#define UART_IMR_PARE_Len (1)        //!< PARE Field Length
#define UART_IMR_PARE_Msk (0x1 << 7) //!< PARE Mask
/* \} */
/** \defgroup UART_IMR_TXEMPTY TXEMPTY: Mask TXEMPTY Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define UART_IMR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define UART_IMR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define UART_IMR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup UART_IMR_TXBUFE TXBUFE: Mask TXBUFE Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_TXBUFE     (0x1 << 11) //!< TXBUFE Value
#define UART_IMR_TXBUFE_Pos (11)        //!< TXBUFE Position
#define UART_IMR_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define UART_IMR_TXBUFE_Msk (0x1 << 11) //!< TXBUFE Mask
/* \} */
/** \defgroup UART_IMR_RXBUFF RXBUFF: Mask RXBUFF Interrupt
 * \ingroup UART_IMR
 * \{
 */
#define UART_IMR_RXBUFF     (0x1 << 12) //!< RXBUFF Value
#define UART_IMR_RXBUFF_Pos (12)        //!< RXBUFF Position
#define UART_IMR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define UART_IMR_RXBUFF_Msk (0x1 << 12) //!< RXBUFF Mask
/* \} */

/** \defgroup UART_SR Status Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_SR_RXRDY RXRDY: Receiver Ready
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_RXRDY     (0x1 << 0) //!< RXRDY Value
#define UART_SR_RXRDY_Pos (0)        //!< RXRDY Position
#define UART_SR_RXRDY_Len (1)        //!< RXRDY Field Length
#define UART_SR_RXRDY_Msk (0x1 << 0) //!< RXRDY Mask
/* \} */
/** \defgroup UART_SR_TXRDY TXRDY: Transmitter Ready
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_TXRDY     (0x1 << 1) //!< TXRDY Value
#define UART_SR_TXRDY_Pos (1)        //!< TXRDY Position
#define UART_SR_TXRDY_Len (1)        //!< TXRDY Field Length
#define UART_SR_TXRDY_Msk (0x1 << 1) //!< TXRDY Mask
/* \} */
/** \defgroup UART_SR_ENDRX ENDRX: End of Receiver Transfer
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_ENDRX     (0x1 << 3) //!< ENDRX Value
#define UART_SR_ENDRX_Pos (3)        //!< ENDRX Position
#define UART_SR_ENDRX_Len (1)        //!< ENDRX Field Length
#define UART_SR_ENDRX_Msk (0x1 << 3) //!< ENDRX Mask
/* \} */
/** \defgroup UART_SR_ENDTX ENDTX: End of Transmitter Transfer
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_ENDTX     (0x1 << 4) //!< ENDTX Value
#define UART_SR_ENDTX_Pos (4)        //!< ENDTX Position
#define UART_SR_ENDTX_Len (1)        //!< ENDTX Field Length
#define UART_SR_ENDTX_Msk (0x1 << 4) //!< ENDTX Mask
/* \} */
/** \defgroup UART_SR_OVRE OVRE: Overrun Error
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_OVRE     (0x1 << 5) //!< OVRE Value
#define UART_SR_OVRE_Pos (5)        //!< OVRE Position
#define UART_SR_OVRE_Len (1)        //!< OVRE Field Length
#define UART_SR_OVRE_Msk (0x1 << 5) //!< OVRE Mask
/* \} */
/** \defgroup UART_SR_FRAME FRAME: Framing Error
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_FRAME     (0x1 << 6) //!< FRAME Value
#define UART_SR_FRAME_Pos (6)        //!< FRAME Position
#define UART_SR_FRAME_Len (1)        //!< FRAME Field Length
#define UART_SR_FRAME_Msk (0x1 << 6) //!< FRAME Mask
/* \} */
/** \defgroup UART_SR_PARE PARE: Parity Error
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_PARE     (0x1 << 7) //!< PARE Value
#define UART_SR_PARE_Pos (7)        //!< PARE Position
#define UART_SR_PARE_Len (1)        //!< PARE Field Length
#define UART_SR_PARE_Msk (0x1 << 7) //!< PARE Mask
/* \} */
/** \defgroup UART_SR_TXEMPTY TXEMPTY: Transmitter Empty
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define UART_SR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define UART_SR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define UART_SR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup UART_SR_TXBUFE TXBUFE: Transmission Buffer Empty
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_TXBUFE     (0x1 << 11) //!< TXBUFE Value
#define UART_SR_TXBUFE_Pos (11)        //!< TXBUFE Position
#define UART_SR_TXBUFE_Len (1)         //!< TXBUFE Field Length
#define UART_SR_TXBUFE_Msk (0x1 << 11) //!< TXBUFE Mask
/* \} */
/** \defgroup UART_SR_RXBUFF RXBUFF: Receive Buffer Full
 * \ingroup UART_SR
 * \{
 */
#define UART_SR_RXBUFF     (0x1 << 12) //!< RXBUFF Value
#define UART_SR_RXBUFF_Pos (12)        //!< RXBUFF Position
#define UART_SR_RXBUFF_Len (1)         //!< RXBUFF Field Length
#define UART_SR_RXBUFF_Msk (0x1 << 12) //!< RXBUFF Mask
/* \} */

/** \defgroup UART_RHR Receive Holding Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_RHR_RXCHR RXCHR: Received Character
 * \ingroup UART_RHR
 * \{
 */
#define UART_RHR_RXCHR(v)  (((v) & 0xFF) << 0) //!< RXCHR Value
#define UART_RHR_RXCHR_Pos (0)                 //!< RXCHR Position
#define UART_RHR_RXCHR_Len (8)                 //!< RXCHR Field Length
#define UART_RHR_RXCHR_Msk (0xFF << 0)         //!< RXCHR Mask
/* \} */

/** \defgroup UART_THR Transmit Holding Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_THR_TXCHR TXCHR: Character to be Transmitted
 * \ingroup UART_THR
 * \{
 */
#define UART_THR_TXCHR(v)  (((v) & 0xFF) << 0) //!< TXCHR Value
#define UART_THR_TXCHR_Pos (0)                 //!< TXCHR Position
#define UART_THR_TXCHR_Len (8)                 //!< TXCHR Field Length
#define UART_THR_TXCHR_Msk (0xFF << 0)         //!< TXCHR Mask
/* \} */

/** \defgroup UART_BRGR Baud Rate Generator Register Bit Definitions
 * \ingroup UART
 */

/** \defgroup UART_BRGR_CD UART_BRGR_CD: Clock Divisor
 * \ingroup UART_BRGR
 * \{
 */
#define UART_BRGR_CD(v)  (((v) & 0xFFFF) << 0) //!< CD Value
#define UART_BRGR_CD_Pos (0)                   //!< CD Position
#define UART_BRGR_CD_Len (16)                  //!< CD Field Length
#define UART_BRGR_CD_Msk (0xFFFF << 0)         //!< CD Mask
/* \} */

#endif // _CPU_PERIPHERALS_UART_H_
