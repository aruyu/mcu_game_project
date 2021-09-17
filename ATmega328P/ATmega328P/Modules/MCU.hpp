/*
 *    NOTE        - MCU.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.05.30
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define OFF 0
#define ON 1
#define LOW 0
#define HIGH 1
#define IN 0
#define OUT 1

#define B 0
#define C 1
#define D 2
#define OC0A 3
#define OC0B 4
#define OC1A 5
#define OC1B 6
#define OC2A 7
#define OC2B 8

#define MAINTAIN 0
#define DOWN 1
#define UP 2
#define OVF 3
#define COMP 4
#define CORRECT 5
#define FAST 6

#define COMA1 7
#define COMB1 5

#define _OCR0A 0xFF   // Compare with 0xFF	Timer0
#define _OCR2A 0xA0   // Compare with 0xA0	Timer2
#define _OCR1AH 0x3D
#define _OCR1AL 0x09  // Compare with 0x3D09	Timer1


/*
//==========================================
              NAMESPACE - MCU
==========================================//
*/

namespace MCU
{

  uint8_t insertBit(uint8_t bitValue, bool isHigh);

  namespace Features
  {
    uint8_t hex(uint8_t decimal);
    uint8_t ASKII(uint8_t decimal);
  }

  namespace Setting
  {
    void beginPort(uint8_t port, bool isOutput);
    void beginINT(uint8_t INTIndex, uint8_t INTMode);
    void beginPCINT(uint8_t PCINTIndex);
    void beginTimer(uint8_t timerIndex, uint8_t timerMode);
    void beginPWM(uint8_t PWMIndex, uint8_t PWMMode);
    void beginSPI(void);
  }

}