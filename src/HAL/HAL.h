/*
 * Hardware Abstraction Layer (HAL) for OnStep
 * 
 * Copyright (C) 2018 Khalid Baheyeldin
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HAL_H
#define _HAL_H

#if defined(__AVR_ATmega2560__)
  // Arduino Mega 2560
  #include "HAL_Mega2560/HAL_Mega2560.h"

#elif defined(__MK20DX256__)
  // Teensy 3.2
  #include "HAL_Teensy_3/HAL_Teensy_3.h"

#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)
  // Teensy 3.5 or 3.6
  #include "HAL_Teensy_3/HAL_Teensy_3.h"
  // We use the same HAL for Teensy 3.2, but add this define
  #define SER4_AVAILABLE

#elif defined(__TM4C123GH6PM__) || defined(__LM4F120H5QR__) || defined(__TM4C1294NCPDT__) || defined(__TM4C1294XNCZAD__)
  // TI Tiva C
  #include "HAL_Tiva_C/HAL_Tiva_C.h"

#elif defined(__STM32F1__)
  // STM32F1 board
  #include "HAL_STM32F1/HAL_STM32F1.h"

#else
  #error "Unsupported Platform! If this is a new platform, it needs the appropriate entries in the HAL directory."
#endif

#endif // _HAL_H
