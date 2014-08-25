/**
 * \file
 *
 * \brief Serial Peripheral Interface (SPI) User Interface
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_SPI_H_
#define _CPU_PERIPHERALS_SPI_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup SPI Serial Peripheral Interface (SPI) User Interface */

/** \defgroup SPI_UI_REG User Interface Registers
 * \ingroup SPI
 * \{
 */
#define SPI_CR   (*(reg_wo_t*)(SPI+0x0000)) //!< \ref SPI_CR
#define SPI_MR   (*(reg_rw_t*)(SPI+0x0004)) //!< \ref SPI_MR
#define SPI_RDR  (*(reg_ro_t*)(SPI+0x0008)) //!< \ref SPI_RDR
#define SPI_TDR  (*(reg_wo_t*)(SPI+0x000C)) //!< \ref SPI_TDR
#define SPI_SR   (*(reg_ro_t*)(SPI+0x0010)) //!< \ref SPI_SR
#define SPI_IER  (*(reg_wo_t*)(SPI+0x0014)) //!< \ref SPI_IER
#define SPI_IDR  (*(reg_wo_t*)(SPI+0x0018)) //!< \ref SPI_IDR
#define SPI_IMR  (*(reg_ro_t*)(SPI+0x001C)) //!< \ref SPI_IMR
#define SPI_CSR0 (*(reg_rw_t*)(SPI+0x0030)) //!< \ref SPI_CSR0
#define SPI_CSR1 (*(reg_rw_t*)(SPI+0x0034)) //!< \ref SPI_CSR1
#define SPI_CSR2 (*(reg_rw_t*)(SPI+0x0038)) //!< \ref SPI_CSR2
#define SPI_CSR3 (*(reg_rw_t*)(SPI+0x003C)) //!< \ref SPI_CSR3
#define SPI_WPMR (*(reg_wo_t*)(SPI+0x00E4)) //!< \ref SPI_WPMR
#define SPI_WPSR (*(reg_ro_t*)(SPI+0x00E8)) //!< \ref SPI_WPSR
/* \} */

/** \defgroup SPI_CR Control Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_CR_SPIEN SPIEN: SPI Enable
 * \ingroup SPI_CR
 * \{
 */
#define SPI_CR_SPIEN     (0x1 << 0) //!< SPIEN Value
#define SPI_CR_SPIEN_Pos (0)        //!< SPIEN Position
#define SPI_CR_SPIEN_Len (1)        //!< SPIEN Field Length
#define SPI_CR_SPIEN_Msk (0x1 << 0) //!< SPIEN Mask
/* \} */
/** \defgroup SPI_CR_SPIDIS SPIDIS: SPI Disable
 * \ingroup SPI_CR
 * \{
 */
#define SPI_CR_SPIDIS     (0x1 << 1) //!< SPIDIS Value
#define SPI_CR_SPIDIS_Pos (1)        //!< SPIDIS Position
#define SPI_CR_SPIDIS_Len (1)        //!< SPIDIS Field Length
#define SPI_CR_SPIDIS_Msk (0x1 << 1) //!< SPIDIS Mask
/* \} */
/** \defgroup SPI_CR_SWRST SWRST: SPI Software Reset
 * \ingroup SPI_CR
 * \{
 */
#define SPI_CR_SWRST     (0x1 << 7) //!< SWRST Value
#define SPI_CR_SWRST_Pos (7)        //!< SWRST Position
#define SPI_CR_SWRST_Len (1)        //!< SWRST Field Length
#define SPI_CR_SWRST_Msk (0x1 << 7) //!< SWRST Mask
/* \} */
/** \defgroup SPI_CR_LASTXFER LASTXFER: Last Transfer
 * \ingroup SPI_CR
 * \{
 */
#define SPI_CR_LASTXFER     (0x1 << 24) //!< LASTXFER Value
#define SPI_CR_LASTXFER_Pos (24)        //!< LASTXFER Position
#define SPI_CR_LASTXFER_Len (1)         //!< LASTXFER Field Length
#define SPI_CR_LASTXFER_Msk (0x1 << 24) //!< LASTXFER Mask
/* \} */

/** \defgroup SPI_MR Mode Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_MR_MSTR MSTR: Master/Slave Mode
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_MSTR     (0x1 << 0) //!< MSTR Value
#define SPI_MR_MSTR_Pos (0)        //!< MSTR Position
#define SPI_MR_MSTR_Len (1)        //!< MSTR Field Length
#define SPI_MR_MSTR_Msk (0x1 << 0) //!< MSTR Mask
/* \} */
/** \defgroup SPI_MR_PS PS: Peripheral Select
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_PS     (0x1 << 1) //!< PS Value
#define SPI_MR_PS_Pos (1)        //!< PS Position
#define SPI_MR_PS_Len (1)        //!< PS Field Length
#define SPI_MR_PS_Msk (0x1 << 1) //!< PS Mask
/* \} */
/** \defgroup SPI_MR_PCSDEC PCSDEC: Chip Select Decode
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_PCSDEC     (0x1 << 2) //!< PCSDEC Value
#define SPI_MR_PCSDEC_Pos (2)        //!< PCSDEC Position
#define SPI_MR_PCSDEC_Len (1)        //!< PCSDEC Field Length
#define SPI_MR_PCSDEC_Msk (0x1 << 2) //!< PCSDEC Mask
/* \} */
/** \defgroup SPI_MR_MODFDIS MODFDIS: Mode Faulty Detection
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_MODFDIS     (0x1 << 4) //!< MODFDIS Value
#define SPI_MR_MODFDIS_Pos (4)        //!< MODFDIS Position
#define SPI_MR_MODFDIS_Len (1)        //!< MODFDIS Field Length
#define SPI_MR_MODFDIS_Msk (0x1 << 4) //!< MODFDIS Mask
/* \} */
/** \defgroup SPI_MR_WDRBT WDRBT: Wait Data Read Before Transfer
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_WDRBT     (0x1 << 5) //!< WDRBT Value
#define SPI_MR_WDRBT_Pos (5)        //!< WDRBT Position
#define SPI_MR_WDRBT_Len (1)        //!< WDRBT Field Length
#define SPI_MR_WDRBT_Msk (0x1 << 5) //!< WDRBT Mask
/* \} */
/** \defgroup SPI_MR_LLB LLB: Local Loop-back Enable
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_LLB     (0x1 << 7) //!< LLB Value
#define SPI_MR_LLB_Pos (7)        //!< LLB Position
#define SPI_MR_LLB_Len (1)        //!< LLB Field Length
#define SPI_MR_LLB_Msk (0x1 << 7) //!< LLB Mask
/* \} */
/** \defgroup SPI_MR_PCS PCS: Peripheral Chip Select
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_PCS(v)  (((v) & 0xF) << 16) //!< PCS Value
#define SPI_MR_PCS_Pos (16)                //!< PCS Position
#define SPI_MR_PCS_Len (4)                 //!< PCS Field Length
#define SPI_MR_PCS_Msk (0xF << 16)         //!< PCS Mask
/* \} */
/** \defgroup SPI_MR_DLYBCS DLYBCS: Delay Between Chip Selects
 * \ingroup SPI_MR
 * \{
 */
#define SPI_MR_DLYBCS(v)  (((v) & 0xFF) << 24) //!< DLYBCS Value
#define SPI_MR_DLYBCS_Pos (24)                 //!< DLYBCS Position
#define SPI_MR_DLYBCS_Len (4)                  //!< DLYBCS Field Length
#define SPI_MR_DLYBCS_Msk (0xFF << 24)         //!< DLYBCS Mask
/* \} */

/** \defgroup SPI_RDR Receive Data Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_RDR_RD RD: Receive Data
 * \ingroup SPI_RDR
 * \{
 */
#define SPI_RDR_RD(v)  (((v) & 0xFFFF) << 0) //!< RD Value
#define SPI_RDR_RD_Pos (0)                   //!< RD Position
#define SPI_RDR_RD_Len (16)                  //!< RD Field Length
#define SPI_RDR_RD_Msk (0xFFFF << 0)         //!< RD Mask
/* \} */
/** \defgroup SPI_RDR_PCS PCS: Peripheral Chip Select
 * \ingroup SPI_RDR
 * \{
 */
#define SPI_RDR_PCS(v)  (((v) & 0xF) << 16) //!< PCS Value
#define SPI_RDR_PCS_Pos (16)                //!< PCS Position
#define SPI_RDR_PCS_Len (4)                 //!< PCS Field Length
#define SPI_RDR_PCS_Msk (0xF << 16)         //!< PCS Mask
/* \} */

/** \defgroup SPI_TDR Transmit Data Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_TDR_TD TD: Transmit Data
 * \ingroup SPI_TDR
 * \{
 */
#define SPI_TDR_TD(v)  (((v) & 0xFFFF) << 0) //!< TD Value
#define SPI_TDR_TD_Pos (0)                   //!< TD Position
#define SPI_TDR_TD_Len (16)                  //!< TD Field Length
#define SPI_TDR_TD_Msk (0xFFFF << 0)         //!< TD Mask
/* \} */
/** \defgroup SPI_TDR_PCS PCS: Peripheral Chip Select
 * \ingroup SPI_TDR
 * \{
 */
#define SPI_TDR_PCS(v)  (((v) & 0xF) << 16) //!< PCS Value
#define SPI_TDR_PCS_Pos (16)                //!< PCS Position
#define SPI_TDR_PCS_Len (4)                 //!< PCS Field Length
#define SPI_TDR_PCS_Msk (0xF << 16)         //!< PCS Mask
/* \} */
/** \defgroup SPI_TDR_LASTXFER LASTXFER: Last Transfer
 * \ingroup SPI_TDR
 * \{
 */
#define SPI_TDR_LASTXFER     (0x1 << 24) //!< LASTXFER Value
#define SPI_TDR_LASTXFER_Pos (24)        //!< LASTXFER Position
#define SPI_TDR_LASTXFER_Len (1)         //!< LASTXFER Field Length
#define SPI_TDR_LASTXFER_Msk (0x1 << 24) //!< LASTXFER Mask
/* \} */

/** \defgroup SPI_SR Status Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_SR_RDRF RDRF: Receive Data Register Full
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_RDRF     (0x1 << 0) //!< RDRF Value
#define SPI_SR_RDRF_Pos (0)        //!< RDRF Position
#define SPI_SR_RDRF_Len (1)        //!< RDRF Field Length
#define SPI_SR_RDRF_Msk (0x1 << 0) //!< RDRF Mask
/* \} */
/** \defgroup SPI_SR_TDRE TDRE: Transmit Data Register Empty
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_TDRE     (0x1 << 1) //!< TDRE Value
#define SPI_SR_TDRE_Pos (1)        //!< TDRE Position
#define SPI_SR_TDRE_Len (1)        //!< TDRE Field Length
#define SPI_SR_TDRE_Msk (0x1 << 1) //!< TDRE Mask
/* \} */
/** \defgroup SPI_SR_MODF MODF: Mode Fault Error
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_MODF     (0x1 << 2) //!< MODF Value
#define SPI_SR_MODF_Pos (2)        //!< MODF Position
#define SPI_SR_MODF_Len (1)        //!< MODF Field Length
#define SPI_SR_MODF_Msk (0x1 << 2) //!< MODF Mask
/* \} */
/** \defgroup SPI_SR_OVRES OVRES: Overrun Error Status
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_OVRES     (0x1 << 3) //!< OVRES Value
#define SPI_SR_OVRES_Pos (3)        //!< OVRES Position
#define SPI_SR_OVRES_Len (1)        //!< OVRES Field Length
#define SPI_SR_OVRES_Msk (0x1 << 3) //!< OVRES Mask
/* \} */
/** \defgroup SPI_SR_NSSR NSSR: NSS Rising
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_NSSR     (0x1 << 8) //!< NSSR Value
#define SPI_SR_NSSR_Pos (8)        //!< NSSR Position
#define SPI_SR_NSSR_Len (1)        //!< NSSR Field Length
#define SPI_SR_NSSR_Msk (0x1 << 8) //!< NSSR Mask
/* \} */
/** \defgroup SPI_SR_TXEMPTY TXEMPTY: Transmission Registers Empty
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define SPI_SR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define SPI_SR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SPI_SR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup SPI_SR_UNDES UDES: Under-run Error Status (Slave Mode Only)
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_UNDES     (0x1 << 10) //!< UNDES Value
#define SPI_SR_UNDES_Pos (10)        //!< UNDES Position
#define SPI_SR_UNDES_Len (1)         //!< UNDES Field Length
#define SPI_SR_UNDES_Msk (0x1 << 10) //!< UNDES Mask
/* \} */
/** \defgroup SPI_SR_SPIENS SPIENS: SPI Enable Status
 * \ingroup SPI_SR
 * \{
 */
#define SPI_SR_SPIENS     (0x1 << 16) //!< SPIENS Value
#define SPI_SR_SPIENS_Pos (16)        //!< SPIENS Position
#define SPI_SR_SPIENS_Len (1)         //!< SPIENS Field Length
#define SPI_SR_SPIENS_Msk (0x1 << 16) //!< SPIENS Mask
/* \} */

/** \defgroup SPI_IER Interrupt Enable Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_IER_RDRF RDRF: Receive Data Register Full Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_RDRF     (0x1 << 0) //!< RDRF Value
#define SPI_IER_RDRF_Pos (0)        //!< RDRF Position
#define SPI_IER_RDRF_Len (1)        //!< RDRF Field Length
#define SPI_IER_RDRF_Msk (0x1 << 0) //!< RDRF Mask
/* \} */
/** \defgroup SPI_IER_TDRE TDRE: SPI Transmit Data Register Empty Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_TDRE     (0x1 << 1) //!< TDRE Value
#define SPI_IER_TDRE_Pos (1)        //!< TDRE Position
#define SPI_IER_TDRE_Len (1)        //!< TDRE Field Length
#define SPI_IER_TDRE_Msk (0x1 << 1) //!< TDRE Mask
/* \} */
/** \defgroup SPI_IER_MODF MODF: Mode Fault Error Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_MODF     (0x1 << 2) //!< MODF Value
#define SPI_IER_MODF_Pos (2)        //!< MODF Position
#define SPI_IER_MODF_Len (1)        //!< MODF Field Length
#define SPI_IER_MODF_Msk (0x1 << 2) //!< MODF Mask
/* \} */
/** \defgroup SPI_IER_OVRES OVRES: Overrun Error Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_OVRES     (0x1 << 3) //!< OVRES Value
#define SPI_IER_OVRES_Pos (3)        //!< OVRES Position
#define SPI_IER_OVRES_Len (1)        //!< OVRES Field Length
#define SPI_IER_OVRES_Msk (0x1 << 3) //!< OVRES Mask
/* \} */
/** \defgroup SPI_IER_NSSR NSSR: NSS Rising Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_NSSR     (0x1 << 8) //!< NSSR Value
#define SPI_IER_NSSR_Pos (8)        //!< NSSR Position
#define SPI_IER_NSSR_Len (1)        //!< NSSR Field Length
#define SPI_IER_NSSR_Msk (0x1 << 8) //!< NSSR Mask
/* \} */
/** \defgroup SPI_IER_TXEMPTY TXEMPTY: Transmission Registers Empty Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define SPI_IER_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define SPI_IER_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SPI_IER_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup SPI_IER_UNDES UNDES: Under-run Error Interrupt Enable
 * \ingroup SPI_IER
 * \{
 */
#define SPI_IER_UNDES     (0x1 << 10) //!< UNDES Value
#define SPI_IER_UNDES_Pos (10)        //!< UNDES Position
#define SPI_IER_UNDES_Len (1)         //!< UNDES Field Length
#define SPI_IER_UNDES_Msk (0x1 << 10) //!< UNDES Mask
/* \} */

/** \defgroup SPI_IDR Interrupt Disable Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_IDR_RDRF RDRF: Receive Data Register Full Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_RDRF     (0x1 << 0) //!< RDRF Value
#define SPI_IDR_RDRF_Pos (0)        //!< RDRF Position
#define SPI_IDR_RDRF_Len (1)        //!< RDRF Field Length
#define SPI_IDR_RDRF_Msk (0x1 << 0) //!< RDRF Mask
/* \} */
/** \defgroup SPI_IDR_TDRE TDRE: SPI Transmit Data Register Empty Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_TDRE     (0x1 << 1) //!< TDRE Value
#define SPI_IDR_TDRE_Pos (1)        //!< TDRE Position
#define SPI_IDR_TDRE_Len (1)        //!< TDRE Field Length
#define SPI_IDR_TDRE_Msk (0x1 << 1) //!< TDRE Mask
/* \} */
/** \defgroup SPI_IDR_MODF MODF: Mode Fault Error Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_MODF     (0x1 << 2) //!< MODF Value
#define SPI_IDR_MODF_Pos (2)        //!< MODF Position
#define SPI_IDR_MODF_Len (1)        //!< MODF Field Length
#define SPI_IDR_MODF_Msk (0x1 << 2) //!< MODF Mask
/* \} */
/** \defgroup SPI_IDR_OVRES OVRES: Overrun Error Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_OVRES     (0x1 << 3) //!< OVRES Value
#define SPI_IDR_OVRES_Pos (3)        //!< OVRES Position
#define SPI_IDR_OVRES_Len (1)        //!< OVRES Field Length
#define SPI_IDR_OVRES_Msk (0x1 << 3) //!< OVRES Mask
/* \} */
/** \defgroup SPI_IDR_NSSR NSSR: NSS Rising Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_NSSR     (0x1 << 8) //!< NSSR Value
#define SPI_IDR_NSSR_Pos (8)        //!< NSSR Position
#define SPI_IDR_NSSR_Len (1)        //!< NSSR Field Length
#define SPI_IDR_NSSR_Msk (0x1 << 8) //!< NSSR Mask
/* \} */
/** \defgroup SPI_IDR_TXEMPTY TXEMPTY: Transmission Registers Empty Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define SPI_IDR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define SPI_IDR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SPI_IDR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup SPI_IDR_UNDES UNDES: Under-run Error Interrupt Disable
 * \ingroup SPI_IDR
 * \{
 */
#define SPI_IDR_UNDES     (0x1 << 10) //!< UNDES Value
#define SPI_IDR_UNDES_Pos (10)        //!< UNDES Position
#define SPI_IDR_UNDES_Len (1)         //!< UNDES Field Length
#define SPI_IDR_UNDES_Msk (0x1 << 10) //!< UNDES Mask
/* \} */

/** \defgroup SPI_IMR Interrupt Mask Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_IMR_RDRF RDRF: Receive Data Register Full Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_RDRF     (0x1 << 0) //!< RDRF Value
#define SPI_IMR_RDRF_Pos (0)        //!< RDRF Position
#define SPI_IMR_RDRF_Len (1)        //!< RDRF Field Length
#define SPI_IMR_RDRF_Msk (0x1 << 0) //!< RDRF Mask
/* \} */
/** \defgroup SPI_IMR_TDRE TDRE: SPI Transmit Data Register Empty Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_TDRE     (0x1 << 1) //!< TDRE Value
#define SPI_IMR_TDRE_Pos (1)        //!< TDRE Position
#define SPI_IMR_TDRE_Len (1)        //!< TDRE Field Length
#define SPI_IMR_TDRE_Msk (0x1 << 1) //!< TDRE Mask
/* \} */
/** \defgroup SPI_IMR_MODF MODF: Mode Fault Error Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_MODF     (0x1 << 2) //!< MODF Value
#define SPI_IMR_MODF_Pos (2)        //!< MODF Position
#define SPI_IMR_MODF_Len (1)        //!< MODF Field Length
#define SPI_IMR_MODF_Msk (0x1 << 2) //!< MODF Mask
/* \} */
/** \defgroup SPI_IMR_OVRES OVRES: Overrun Error Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_OVRES     (0x1 << 3) //!< OVRES Value
#define SPI_IMR_OVRES_Pos (3)        //!< OVRES Position
#define SPI_IMR_OVRES_Len (1)        //!< OVRES Field Length
#define SPI_IMR_OVRES_Msk (0x1 << 3) //!< OVRES Mask
/* \} */
/** \defgroup SPI_IMR_NSSR NSSR: NSS Rising Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_NSSR     (0x1 << 8) //!< NSSR Value
#define SPI_IMR_NSSR_Pos (8)        //!< NSSR Position
#define SPI_IMR_NSSR_Len (1)        //!< NSSR Field Length
#define SPI_IMR_NSSR_Msk (0x1 << 8) //!< NSSR Mask
/* \} */
/** \defgroup SPI_IMR_TXEMPTY TXEMPTY: Transmission Registers Empty Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_TXEMPTY     (0x1 << 9) //!< TXEMPTY Value
#define SPI_IMR_TXEMPTY_Pos (9)        //!< TXEMPTY Position
#define SPI_IMR_TXEMPTY_Len (1)        //!< TXEMPTY Field Length
#define SPI_IMR_TXEMPTY_Msk (0x1 << 9) //!< TXEMPTY Mask
/* \} */
/** \defgroup SPI_IMR_UNDES UNDES: Under-run Error Interrupt Mask
 * \ingroup SPI_IMR
 * \{
 */
#define SPI_IMR_UNDES     (0x1 << 10) //!< UNDES Value
#define SPI_IMR_UNDES_Pos (10)        //!< UNDES Position
#define SPI_IMR_UNDES_Len (1)         //!< UNDES Field Length
#define SPI_IMR_UNDES_Msk (0x1 << 10) //!< UNDES Mask
/* \} */

/** \defgroup SPI_CSR0 Chip Select Register 0 Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_CSR1 Chip Select Register 1 Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_CSR2 Chip Select Register 2 Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_CSR3 Chip Select Register 3 Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_CSR_CPOL CPOL: Clock Polarity
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_CPOL     (0x1 << 0) //!< CPOL Value
#define SPI_CSR_CPOL_Pos (0)        //!< CPOL Position
#define SPI_CSR_CPOL_Len (1)        //!< CPOL Field Length
#define SPI_CSR_CPOL_Msk (0x1 << 0) //!< CPOL Mask
/* \} */
/** \defgroup SPI_CSR_NCPHA NCPHA: Clock Phase
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_NCPHA     (0x1 << 1) //!< NCPHA Value
#define SPI_CSR_NCPHA_Pos (1)        //!< NCPHA Position
#define SPI_CSR_NCPHA_Len (1)        //!< NCPHA Field Length
#define SPI_CSR_NCPHA_Msk (0x1 << 1) //!< NCPHA Mask
/* \} */
/** \defgroup SPI_CSR_CSNAAT CSNAAT: Chip Select Not Active After Transfer (Ignored if CSAAT = 1)
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_CSNAAT     (0x1 << 2) //!< CSNAAT Value
#define SPI_CSR_CSNAAT_Pos (2)        //!< CSNAAT Position
#define SPI_CSR_CSNAAT_Len (1)        //!< CSNAAT Field Length
#define SPI_CSR_CSNAAT_Msk (0x1 << 2) //!< CSNAAT Mask
/* \} */
/** \defgroup SPI_CSR_CSAAT CSAAT: Chip Select Active After Transfer
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_CSAAT     (0x1 << 3) //!< CSAAT Value
#define SPI_CSR_CSAAT_Pos (3)        //!< CSAAT Position
#define SPI_CSR_CSAAT_Len (1)        //!< CSAAT Field Length
#define SPI_CSR_CSAAT_Msk (0x1 << 3) //!< CSAAT Mask
/* \} */
/** \defgroup SPI_CSR_BITS BITS: Bits Per Transfer
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_BITS(v)  (((v) & 0x0F) << 4) //!< BITS Value
#define SPI_CSR_BITS_Pos (4)                 //!< BITS Position
#define SPI_CSR_BITS_Len (4)                 //!< BITS Field Length
#define SPI_CSR_BITS_Msk (0xF << 4)          //!< BITS Mask
/* \} */
/** \defgroup SPI_CSR_SCBR SCBR: Serial Clock Baud Rate
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_SCBR(v)  (((v) & 0xFF) << 8) //!< SCBR Value
#define SPI_CSR_SCBR_Pos (8)                 //!< SCBR Position
#define SPI_CSR_SCBR_Len (8)                 //!< SCBR Field Length
#define SPI_CSR_SCBR_Msk (0xFF << 8)          //!< SCBR Mask
/* \} */
/** \defgroup SPI_CSR_DLYBS DLYBS: Delay Before SPCK
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_DLYBS(v)  (((v) & 0xFF) << 16) //!< DLYBS Value
#define SPI_CSR_DLYBS_Pos (16)                 //!< DLYBS Position
#define SPI_CSR_DLYBS_Len (8)                  //!< DLYBS Field Length
#define SPI_CSR_DLYBS_Msk (0x1 << 16)          //!< DLYBS Mask
/* \} */
/** \defgroup SPI_CSR_DLYBCT DLYBCT: Delay Between Consecutive Transfers
 * \ingroup SPI_CSR0
 * \ingroup SPI_CSR1
 * \ingroup SPI_CSR2
 * \ingroup SPI_CSR3
 * \{
 */
#define SPI_CSR_DLYBCT(v)  (((v) & 0xFF) << 24) //!< DLYBCT Value
#define SPI_CSR_DLYBCT_Pos (24)                 //!< DLYBCT Position
#define SPI_CSR_DLYBCT_Len (8)                  //!< DLYBCT Field Length
#define SPI_CSR_DLYBCT_Msk (0x1 << 24)          //!< DLYBCT Mask
/* \} */

/** \defgroup SPI_WPMR Write Protection Control Register Bit Definitions
 * \ingroup SPI
 */

/** \defgroup SPI_WPSR Write Protection Status Register Bit Definitions
 * \ingroup SPI
 */

#endif // _CPU_PERIPHERALS_SPI_H_
