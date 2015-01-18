/**
 * \file
 *
 * \brief Parallel Input/Output Controller (PIO) User Interface
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_PERIPHERALS_PIO_H_
#define _CPU_PERIPHERALS_PIO_H_

#include "cpu/common.h"
#include "types.h"

/** \defgroup PIO Parallel Input/Output Controller (PIO) User Interface */

/** \defgroup PIO_UI_REG User Interface Registers
 * \ingroup PIO
 * \{
 */
#define PIO_PER(PIO)     (*(reg_wo_t*)(PIO+0x0000)) //!< PIO Enable Register
#define PIO_PDR(PIO)     (*(reg_wo_t*)(PIO+0x0004)) //!< PIO Disable Register
#define PIO_PSR(PIO)     (*(reg_ro_t*)(PIO+0x0008)) //!< PIO Status Register
#define PIO_OER(PIO)     (*(reg_wo_t*)(PIO+0x0010)) //!< Output Enable Register
#define PIO_ODR(PIO)     (*(reg_wo_t*)(PIO+0x0014)) //!< Output Disable Register
#define PIO_OSR(PIO)     (*(reg_ro_t*)(PIO+0x0018)) //!< Output Status Register
#define PIO_IFER(PIO)    (*(reg_wo_t*)(PIO+0x0020)) //!< Glitch Input Filter Enable Register
#define PIO_IFDR(PIO)    (*(reg_wo_t*)(PIO+0x0024)) //!< Glitch Input Filter Disable Register
#define PIO_IFSR(PIO)    (*(reg_ro_t*)(PIO+0x0028)) //!< Glitch Input Filter Status Register
#define PIO_SODR(PIO)    (*(reg_wo_t*)(PIO+0x0030)) //!< Set Output Data Register
#define PIO_CODR(PIO)    (*(reg_wo_t*)(PIO+0x0034)) //!< Clear Output Data Register
#define PIO_ODSR(PIO)    (*(reg_rw_t*)(PIO+0x0038)) //!< Output Data Status Register
#define PIO_PDSR(PIO)    (*(reg_ro_t*)(PIO+0x003C)) //!< Pin Data Status Register
#define PIO_IER(PIO)     (*(reg_wo_t*)(PIO+0x0040)) //!< Interrupt Enable Register
#define PIO_IDR(PIO)     (*(reg_wo_t*)(PIO+0x0044)) //!< Interrupt Disable Register
#define PIO_IMR(PIO)     (*(reg_ro_t*)(PIO+0x0048)) //!< Interrupt Mask Register
#define PIO_ISR(PIO)     (*(reg_ro_t*)(PIO+0x004C)) //!< Interrupt Status Register
#define PIO_MDER(PIO)    (*(reg_wo_t*)(PIO+0x0050)) //!< Multi-driver Enable Register
#define PIO_MDDR(PIO)    (*(reg_wo_t*)(PIO+0x0054)) //!< Multi-driver Disable Register
#define PIO_MDSR(PIO)    (*(reg_ro_t*)(PIO+0x0058)) //!< Multi-driver Status Register
#define PIO_PUDR(PIO)    (*(reg_wo_t*)(PIO+0x0060)) //!< Pull-up Disable Register
#define PIO_PUER(PIO)    (*(reg_wo_t*)(PIO+0x0064)) //!< Pull-up Enable Register
#define PIO_PUSR(PIO)    (*(reg_ro_t*)(PIO+0x0068)) //!< Pad Pull-up Status Register
#define PIO_ABSR(PIO)    (*(reg_rw_t*)(PIO+0x0070)) //!< Peripheral AB Select Register
#define PIO_SCIFSR(PIO)  (*(reg_wo_t*)(PIO+0x0080)) //!< System Clock Glitch Input Filter Select Register
#define PIO_DIFSR(PIO)   (*(reg_wo_t*)(PIO+0x0084)) //!< Debouncing Input Filter Select Register
#define PIO_IFDGSR(PIO)  (*(reg_ro_t*)(PIO+0x0088)) //!< Glitch or Debouncing Input Filter Clock Selection Status Register
#define PIO_SCDR(PIO)    (*(reg_rw_t*)(PIO+0x008C)) //!< Slow Clock Divider Debouncing Register
#define PIO_OWER(PIO)    (*(reg_wo_t*)(PIO+0x00A0)) //!< Output Write Enable
#define PIO_OWDR(PIO)    (*(reg_wo_t*)(PIO+0x00A4)) //!< Output Write Disable
#define PIO_OWSR(PIO)    (*(reg_ro_t*)(PIO+0x00A8)) //!< Output Write Status Register
#define PIO_AIMER(PIO)   (*(reg_wo_t*)(PIO+0x00B0)) //!< Additional Interrupt Modes Enable Register
#define PIO_AIMDR(PIO)   (*(reg_wo_t*)(PIO+0x00B4)) //!< Additional Interrupt Modes Disables Register
#define PIO_AIMMR(PIO)   (*(reg_ro_t*)(PIO+0x00B8)) //!< Additional Interrupt Modes Mask Register
#define PIO_ESR(PIO)     (*(reg_wo_t*)(PIO+0x00C0)) //!< Edge Select Register
#define PIO_LSR(PIO)     (*(reg_wo_t*)(PIO+0x00C4)) //!< Level Select Register
#define PIO_ELSR(PIO)    (*(reg_ro_t*)(PIO+0x00C8)) //!< Edge/Level Status Register
#define PIO_FELLSR(PIO)  (*(reg_wo_t*)(PIO+0x00D0)) //!< Falling Edge/Low Level Select Register
#define PIO_REHLSR(PIO)  (*(reg_wo_t*)(PIO+0x00D4)) //!< Rising Edge/ High Level Select Register
#define PIO_FRLHSR(PIO)  (*(reg_ro_t*)(PIO+0x00D8)) //!< Fall/Rise - Low/High Status Register
#define PIO_LOCKSR(PIO)  (*(reg_ro_t*)(PIO+0x00E0)) //!< Lock Status
#define PIO_WPMR(PIO)    (*(reg_rw_t*)(PIO+0x00E4)) //!< Write Protect Mode Register
#define PIO_WPSR(PIO)    (*(reg_ro_t*)(PIO+0x00E8)) //!< Write Protect Status Register
/* \} */

#endif // _CPU_PERIPHERALS_PIO_H_
