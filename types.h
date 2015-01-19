/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _TYPES_H_
#define _TYPES_H_

// Signed Numeric Types
typedef __INT8_TYPE__   int8_t;
typedef __INT16_TYPE__  int16_t;
typedef __INT32_TYPE__  int32_t;

// Unsigned Numeric Types
typedef __UINT8_TYPE__  uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;

// Size Types
typedef __UINT32_TYPE__ size_t;
typedef __INT32_TYPE__  ssize_t;

// Register Types
typedef volatile const uint32_t reg_ro_t;
typedef volatile       uint32_t reg_wo_t;
typedef volatile       uint32_t reg_rw_t;

// Interrupt Types
typedef void (*vector_t)(void);

#endif // _TYPES_H_
