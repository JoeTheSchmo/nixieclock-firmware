/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CPU_CORTEX_M3_NVIC_H_
#define _CPU_CORTEX_M3_NVIC_H_

#include "types.h"

/** \defgroup NVIC Nested Vectored Interrupt Controller (NVIC) User Interface */

/** \defgroup NVIC_UI_REG User Interface Registers
 * \ingroup NVIC
 * \{
 */
#define ISER0            (*(reg_rw_t*)(0xE000E100)) //!< \ref ISER0
#define ICER0            (*(reg_rw_t*)(0xE000E180)) //!< \ref ICER0
#define ISPR0            (*(reg_rw_t*)(0xE000E200)) //!< \ref ISPR0
#define ICPR0            (*(reg_rw_t*)(0xE000E280)) //!< \ref ICPR0
#define IABR0            (*(reg_ro_t*)(0xE000E300)) //!< \ref IABR0
#define IPR(n)           (*(reg_rw_t*)(0xE000E400+(((n & 0x1F) / 4) * 0x4))) //!< \ref IPR
#define IPR0             (*(reg_rw_t*)(0xE000E400)) //!< \ref IPR0
#define IPR1             (*(reg_rw_t*)(0xE000E404)) //!< \ref IPR1
#define IPR2             (*(reg_rw_t*)(0xE000E408)) //!< \ref IPR2
#define IPR3             (*(reg_rw_t*)(0xE000E40C)) //!< \ref IPR3
#define IPR4             (*(reg_rw_t*)(0xE000E410)) //!< \ref IPR4
#define IPR5             (*(reg_rw_t*)(0xE000E414)) //!< \ref IPR5
#define IPR6             (*(reg_rw_t*)(0xE000E418)) //!< \ref IPR6
#define IPR7             (*(reg_rw_t*)(0xE000E41C)) //!< \ref IPR7
#define STIR             (*(reg_wo_t*)(0xE000E41C)) //!< \ref STIR
/* \} */

/** \defgroup ISER0 Interrupt Set Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup ISER0_SETENA SETENA: Interrupt set-enable bits
 * \ingroup ISER0
 * \{
 */
#define ISER0_SETENA(i)  (0x1 << ((i) & 0x1F)) //!< SETENA Value
#define ISER0_SETENA_Pos (0)                   //!< SETENA Position
#define ISER0_SETENA_Len (31)                  //!< SETENA Field Length
#define ISER0_SETENA_Msk (0xFFFFFFFF << 0)     //!< SETENA Mask
/* \} */

/** \defgroup ICER0 Interrupt Clear Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup ICER0_CLRENA CLRENA: Interrupt clear-enable bits
 * \ingroup ICER0
 * \{
 */
#define ICER0_CLRENA(i)  (0x1 << ((i) & 0x1F)) //!< CLRENA Value
#define ICER0_CLRENA_Pos (0)                   //!< CLRENA Position
#define ICER0_CLRENA_Len (31)                  //!< CLRENA Field Length
#define ICER0_CLRENA_Msk (0xFFFFFFFF << 0)     //!< CLRENA Mask
/* \} */

/** \defgroup ISPR0 Interrupt Set Pending Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup ISPR0_SETPEND SETPEND: Interrupt set-pending bits
 * \ingroup ISPR0
 * \{
 */
#define ISPR0_SETPEND(i)  (0x1 << ((i) & 0x1F)) //!< SETPEND Value
#define ISPR0_SETPEND_Pos (0)                   //!< SETPEND Position
#define ISPR0_SETPEND_Len (31)                  //!< SETPEND Field Length
#define ISPR0_SETPEND_Msk (0xFFFFFFFF << 0)     //!< SETPEND Mask
/* \} */

/** \defgroup ICPR0 Interrupt Clear Pending Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup ICPR0_CLRPEND CLRPEND: Interrupt clear-pending bits
 * \ingroup ICPR0
 * \{
 */
#define ICPR0_CLRPEND(i)  (0x1 << ((i) & 0x1F)) //!< CLRPEND Value
#define ICPR0_CLRPEND_Pos (0)                   //!< CLRPEND Position
#define ICPR0_CLRPEND_Len (31)                  //!< CLRPEND Field Length
#define ICPR0_CLRPEND_Msk (0xFFFFFFFF << 0)     //!< CLRPEND Mask
/* \} */

/** \defgroup IABR0 Interrupt Active Bit Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IABR0_ACTIVE ACTIVE: Interrupt active flags
 * \ingroup IABR0
 * \{
 */
#define IABR0_ACTIVE(i)  (0x1 << ((i) & 0x1F)) //!< ACTIVE Value
#define IABR0_ACTIVE_Pos (0)                   //!< ACTIVE Position
#define IABR0_ACTIVE_Len (31)                  //!< ACTIVE Field Length
#define IABR0_ACTIVE_Msk (0xFFFFFFFF << 0)     //!< ACTIVE Mask
/* \} */

/** \defgroup IPR Interrupt Priority Registers Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR_IP IP: Interrupt n Priority
 * \ingroup IPR
 * \{
 */
#define IPR_IP(n, p)  (((p) & 0xF) << IPR_IP_Pos(n)) //!< IP Value
#define IPR_IP_Pos(n) ((((n) & 0x3) * 8) + 4)        //!< IP Position
#define IPR_IP_Len(n) (4)                            //!< IP Field Length
#define IPR_IP_Msk(n) (0xF << IPR_IP_Pos(n))         //!< IP Mask
/* \} */

/** \defgroup IPR0 Interrupt Priority Register 0 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR0_IP0 IP0: Interrupt 0 Priority
 * \ingroup IPR0
 * \{
 */
#define IPR0_IP0(p)  (((p) & 0xF) << 4) //!< IP0 Value
#define IPR0_IP0_Pos (4)                //!< IP0 Position
#define IPR0_IP0_Len (4)                //!< IP0 Field Length
#define IPR0_IP0_Msk (0xF << 4)         //!< IP0 Mask
/* \} */
/** \defgroup IPR0_IP1 IP1: Interrupt 1 Priority
 * \ingroup IPR0
 * \{
 */
#define IPR0_IP1(p)  (((p) & 0xF) << 12) //!< IP1 Value
#define IPR0_IP1_Pos (12)                //!< IP1 Position
#define IPR0_IP1_Len (4)                 //!< IP1 Field Length
#define IPR0_IP1_Msk (0xF << 12)         //!< IP1 Mask
/* \} */
/** \defgroup IPR0_IP2 IP2: Interrupt 2 Priority
 * \ingroup IPR0
 * \{
 */
#define IPR0_IP2(p)  (((p) & 0xF) << 20) //!< IP2 Value
#define IPR0_IP2_Pos (20)                //!< IP2 Position
#define IPR0_IP2_Len (4)                 //!< IP2 Field Length
#define IPR0_IP2_Msk (0xF << 20)         //!< IP2 Mask
/* \} */
/** \defgroup IPR0_IP3 IP3: Interrupt 3 Priority
 * \ingroup IPR0
 * \{
 */
#define IPR0_IP3(p)  (((p) & 0xF) << 28) //!< IP3 Value
#define IPR0_IP3_Pos (28)                //!< IP3 Position
#define IPR0_IP3_Len (4)                 //!< IP3 Field Length
#define IPR0_IP3_Msk (0xF << 28)         //!< IP3 Mask
/* \} */

/** \defgroup IPR1 Interrupt Priority Register 1 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR1_IP4 IP4: Interrupt 4 Priority
 * \ingroup IPR1
 * \{
 */
#define IPR1_IP4(p)  (((p) & 0xF) << 4) //!< IP4 Value
#define IPR1_IP4_Pos (4)                //!< IP4 Position
#define IPR1_IP4_Len (4)                //!< IP4 Field Length
#define IPR1_IP4_Msk (0xF << 4)         //!< IP4 Mask
/* \} */
/** \defgroup IPR1_IP5 IP5: Interrupt 5 Priority
 * \ingroup IPR1
 * \{
 */
#define IPR1_IP5(p)  (((p) & 0xF) << 12) //!< IP5 Value
#define IPR1_IP5_Pos (12)                //!< IP5 Position
#define IPR1_IP5_Len (4)                 //!< IP5 Field Length
#define IPR1_IP5_Msk (0xF << 12)         //!< IP5 Mask
/* \} */
/** \defgroup IPR1_IP6 IP6: Interrupt 6 Priority
 * \ingroup IPR1
 * \{
 */
#define IPR1_IP6(p)  (((p) & 0xF) << 20) //!< IP6 Value
#define IPR1_IP6_Pos (20)                //!< IP6 Position
#define IPR1_IP6_Len (4)                 //!< IP6 Field Length
#define IPR1_IP6_Msk (0xF << 20)         //!< IP6 Mask
/* \} */
/** \defgroup IPR1_IP7 IP7: Interrupt 7 Priority
 * \ingroup IPR1
 * \{
 */
#define IPR1_IP7(p)  (((p) & 0xF) << 28) //!< IP7 Value
#define IPR1_IP7_Pos (28)                //!< IP7 Position
#define IPR1_IP7_Len (4)                 //!< IP7 Field Length
#define IPR1_IP7_Msk (0xF << 28)         //!< IP7 Mask
/* \} */

/** \defgroup IPR2 Interrupt Priority Register 2 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR2_IP8 IP8: Interrupt 8 Priority
 * \ingroup IPR2
 * \{
 */
#define IPR2_IP8(p)  (((p) & 0xF) << 4) //!< IP8 Value
#define IPR2_IP8_Pos (4)                //!< IP8 Position
#define IPR2_IP8_Len (4)                //!< IP8 Field Length
#define IPR2_IP8_Msk (0xF << 4)         //!< IP8 Mask
/* \} */
/** \defgroup IPR2_IP9 IP9: Interrupt 9 Priority
 * \ingroup IPR2
 * \{
 */
#define IPR2_IP9(p)  (((p) & 0xF) << 12) //!< IP9 Value
#define IPR2_IP9_Pos (12)                //!< IP9 Position
#define IPR2_IP9_Len (4)                 //!< IP9 Field Length
#define IPR2_IP9_Msk (0xF << 12)         //!< IP9 Mask
/* \} */
/** \defgroup IPR2_IP10 IP10: Interrupt 10 Priority
 * \ingroup IPR2
 * \{
 */
#define IPR2_IP10(p)  (((p) & 0xF) << 20) //!< IP10 Value
#define IPR2_IP10_Pos (20)                //!< IP10 Position
#define IPR2_IP10_Len (4)                 //!< IP10 Field Length
#define IPR2_IP10_Msk (0xF << 20)         //!< IP10 Mask
/* \} */
/** \defgroup IPR2_IP11 IP11: Interrupt 11 Priority
 * \ingroup IPR2
 * \{
 */
#define IPR2_IP11(p)  (((p) & 0xF) << 28) //!< IP11 Value
#define IPR2_IP11_Pos (28)                //!< IP11 Position
#define IPR2_IP11_Len (4)                 //!< IP11 Field Length
#define IPR2_IP11_Msk (0xF << 28)         //!< IP11 Mask
/* \} */

/** \defgroup IPR3 Interrupt Priority Register 3 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR3_IP12 IP12: Interrupt 12 Priority
 * \ingroup IPR3
 * \{
 */
#define IPR3_IP12(p)  (((p) & 0xF) << 4) //!< IP12 Value
#define IPR3_IP12_Pos (4)                //!< IP12 Position
#define IPR3_IP12_Len (4)                //!< IP12 Field Length
#define IPR3_IP12_Msk (0xF << 4)         //!< IP12 Mask
/* \} */
/** \defgroup IPR3_IP13 IP13: Interrupt 13 Priority
 * \ingroup IPR3
 * \{
 */
#define IPR3_IP13(p)  (((p) & 0xF) << 12) //!< IP13 Value
#define IPR3_IP13_Pos (12)                //!< IP13 Position
#define IPR3_IP13_Len (4)                 //!< IP13 Field Length
#define IPR3_IP13_Msk (0xF << 12)         //!< IP13 Mask
/* \} */
/** \defgroup IPR3_IP14 IP14: Interrupt 14 Priority
 * \ingroup IPR3
 * \{
 */
#define IPR3_IP14(p)  (((p) & 0xF) << 20) //!< IP14 Value
#define IPR3_IP14_Pos (20)                //!< IP14 Position
#define IPR3_IP14_Len (4)                 //!< IP14 Field Length
#define IPR3_IP14_Msk (0xF << 20)         //!< IP14 Mask
/* \} */
/** \defgroup IPR3_IP15 IP15: Interrupt 15 Priority
 * \ingroup IPR3
 * \{
 */
#define IPR3_IP15(p)  (((p) & 0xF) << 28) //!< IP15 Value
#define IPR3_IP15_Pos (28)                //!< IP15 Position
#define IPR3_IP15_Len (4)                 //!< IP15 Field Length
#define IPR3_IP15_Msk (0xF << 28)         //!< IP15 Mask
/* \} */

/** \defgroup IPR4 Interrupt Priority Register 4 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR4_IP16 IP16: Interrupt 16 Priority
 * \ingroup IPR4
 * \{
 */
#define IPR4_IP16(p)  (((p) & 0xF) << 4) //!< IP16 Value
#define IPR4_IP16_Pos (4)                //!< IP16 Position
#define IPR4_IP16_Len (4)                //!< IP16 Field Length
#define IPR4_IP16_Msk (0xF << 4)         //!< IP16 Mask
/* \} */
/** \defgroup IPR4_IP17 IP17: Interrupt 17 Priority
 * \ingroup IPR4
 * \{
 */
#define IPR4_IP17(p)  (((p) & 0xF) << 12) //!< IP17 Value
#define IPR4_IP17_Pos (12)                //!< IP17 Position
#define IPR4_IP17_Len (4)                 //!< IP17 Field Length
#define IPR4_IP17_Msk (0xF << 12)         //!< IP17 Mask
/* \} */
/** \defgroup IPR4_IP18 IP18: Interrupt 18 Priority
 * \ingroup IPR4
 * \{
 */
#define IPR4_IP18(p)  (((p) & 0xF) << 20) //!< IP18 Value
#define IPR4_IP18_Pos (20)                //!< IP18 Position
#define IPR4_IP18_Len (4)                 //!< IP18 Field Length
#define IPR4_IP18_Msk (0xF << 20)         //!< IP18 Mask
/* \} */
/** \defgroup IPR4_IP19 IP19: Interrupt 19 Priority
 * \ingroup IPR4
 * \{
 */
#define IPR4_IP19(p)  (((p) & 0xF) << 28) //!< IP19 Value
#define IPR4_IP19_Pos (28)                //!< IP19 Position
#define IPR4_IP19_Len (4)                 //!< IP19 Field Length
#define IPR4_IP19_Msk (0xF << 28)         //!< IP19 Mask
/* \} */

/** \defgroup IPR5 Interrupt Priority Register 5 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR5_IP20 IP20: Interrupt 20 Priority
 * \ingroup IPR5
 * \{
 */
#define IPR5_IP20(p)  (((p) & 0xF) << 4) //!< IP20 Value
#define IPR5_IP20_Pos (4)                //!< IP20 Position
#define IPR5_IP20_Len (4)                //!< IP20 Field Length
#define IPR5_IP20_Msk (0xF << 4)         //!< IP20 Mask
/* \} */
/** \defgroup IPR5_IP21 IP21: Interrupt 21 Priority
 * \ingroup IPR5
 * \{
 */
#define IPR5_IP21(p)  (((p) & 0xF) << 12) //!< IP21 Value
#define IPR5_IP21_Pos (12)                //!< IP21 Position
#define IPR5_IP21_Len (4)                 //!< IP21 Field Length
#define IPR5_IP21_Msk (0xF << 12)         //!< IP21 Mask
/* \} */
/** \defgroup IPR5_IP22 IP22: Interrupt 22 Priority
 * \ingroup IPR5
 * \{
 */
#define IPR5_IP22(p)  (((p) & 0xF) << 20) //!< IP22 Value
#define IPR5_IP22_Pos (20)                //!< IP22 Position
#define IPR5_IP22_Len (4)                 //!< IP22 Field Length
#define IPR5_IP22_Msk (0xF << 20)         //!< IP22 Mask
/* \} */
/** \defgroup IPR5_IP23 IP23: Interrupt 23 Priority
 * \ingroup IPR5
 * \{
 */
#define IPR5_IP23(p)  (((p) & 0xF) << 28) //!< IP23 Value
#define IPR5_IP23_Pos (28)                //!< IP23 Position
#define IPR5_IP23_Len (4)                 //!< IP23 Field Length
#define IPR5_IP23_Msk (0xF << 28)         //!< IP23 Mask
/* \} */

/** \defgroup IPR6 Interrupt Priority Register 6 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR6_IP24 IP24: Interrupt 24 Priority
 * \ingroup IPR6
 * \{
 */
#define IPR6_IP24(p)  (((p) & 0xF) << 4) //!< IP24 Value
#define IPR6_IP24_Pos (4)                //!< IP24 Position
#define IPR6_IP24_Len (4)                //!< IP24 Field Length
#define IPR6_IP24_Msk (0xF << 4)         //!< IP24 Mask
/* \} */
/** \defgroup IPR6_IP25 IP25: Interrupt 25 Priority
 * \ingroup IPR6
 * \{
 */
#define IPR6_IP25(p)  (((p) & 0xF) << 12) //!< IP25 Value
#define IPR6_IP25_Pos (12)                //!< IP25 Position
#define IPR6_IP25_Len (4)                 //!< IP25 Field Length
#define IPR6_IP25_Msk (0xF << 12)         //!< IP25 Mask
/* \} */
/** \defgroup IPR6_IP26 IP26: Interrupt 26 Priority
 * \ingroup IPR6
 * \{
 */
#define IPR6_IP26(p)  (((p) & 0xF) << 20) //!< IP26 Value
#define IPR6_IP26_Pos (20)                //!< IP26 Position
#define IPR6_IP26_Len (4)                 //!< IP26 Field Length
#define IPR6_IP26_Msk (0xF << 20)         //!< IP26 Mask
/* \} */
/** \defgroup IPR6_IP27 IP27: Interrupt 27 Priority
 * \ingroup IPR6
 * \{
 */
#define IPR6_IP27(p)  (((p) & 0xF) << 28) //!< IP27 Value
#define IPR6_IP27_Pos (28)                //!< IP27 Position
#define IPR6_IP27_Len (4)                 //!< IP27 Field Length
#define IPR6_IP27_Msk (0xF << 28)         //!< IP27 Mask
/* \} */

/** \defgroup IPR7 Interrupt Priority Register 7 Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup IPR7_IP28 IP28: Interrupt 28 Priority
 * \ingroup IPR7
 * \{
 */
#define IPR7_IP28(p)  (((p) & 0xF) << 4) //!< IP28 Value
#define IPR7_IP28_Pos (4)                //!< IP28 Position
#define IPR7_IP28_Len (4)                //!< IP28 Field Length
#define IPR7_IP28_Msk (0xF << 4)         //!< IP28 Mask
/* \} */
/** \defgroup IPR7_IP29 IP29: Interrupt 29 Priority
 * \ingroup IPR7
 * \{
 */
#define IPR7_IP29(p)  (((p) & 0xF) << 12) //!< IP29 Value
#define IPR7_IP29_Pos (12)                //!< IP29 Position
#define IPR7_IP29_Len (4)                 //!< IP29 Field Length
#define IPR7_IP29_Msk (0xF << 12)         //!< IP29 Mask
/* \} */
/** \defgroup IPR7_IP30 IP30: Interrupt 30 Priority
 * \ingroup IPR7
 * \{
 */
#define IPR7_IP30(p)  (((p) & 0xF) << 20) //!< IP30 Value
#define IPR7_IP30_Pos (20)                //!< IP30 Position
#define IPR7_IP30_Len (4)                 //!< IP30 Field Length
#define IPR7_IP30_Msk (0xF << 20)         //!< IP30 Mask
/* \} */
/** \defgroup IPR7_IP31 IP31: Interrupt 31 Priority
 * \ingroup IPR7
 * \{
 */
#define IPR7_IP31(p)  (((p) & 0xF) << 28) //!< IP31 Value
#define IPR7_IP31_Pos (28)                //!< IP31 Position
#define IPR7_IP31_Len (4)                 //!< IP31 Field Length
#define IPR7_IP31_Msk (0xF << 28)         //!< IP31 Mask
/* \} */

/** \defgroup STIR Software Trigger Interrupt Register Bit Definitions
 * \ingroup NVIC
 */

/** \defgroup STIR_INTID INTID: Interrupt ID of the SGI
 * \ingroup STIR
 * \{
 */
#define STIR_INTID(n)  (((n) & 0x1FF) << 0) //!< INTID Value
#define STIR_INTID_Pos (0)                  //!< INTID Position
#define STIR_INTID_Len (9)                  //!< INTID Field Length
#define STIR_INTID_Msk (0x1FF << 9)         //!< INTID Mask
/* \} */

#endif // _CPU_CORTEX_M3_NVIC_H_
