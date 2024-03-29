﻿/*
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
#include <avr/eeprom.h>
#include <util/delay.h>

#define OFF 0
#define ON 1
#define LOW 0
#define HIGH 1
#define IN 0
#define OUT 1

#define OVF 0
#define COMP 1
#define CORRECT 0
#define FAST 1
#define MAINTAIN 0
#define DOWN 1
#define UP 2

#define _OCR0A 0xFF   // Compare with 255   Timer0
#define _OCR2A 0xF9   // Compare with 249   Timer2 (1ms in 64 Prescaler)
#define _OCR1AH 0x00
#define _OCR1AL 0xFF  // Compare with 15624 Timer1 (1s in 1024 Prescaler)

enum PinNumber
{
  B, C, D, OC0A, OC0B, OC1A, OC1B, OC2A, OC2B
};


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
    uint8_t hex(int8_t decimal);
    uint8_t ASCII(int8_t decimal);
  }

  namespace Setting
  {
    void beginPin(int8_t port, int8_t pinNumber);
    void beginPort(int8_t port, bool isOutput);
    void beginINT(int8_t INTIndex, int8_t INTMode);
    void beginPCINT(int8_t PCINTIndex);
    void beginTimer(int8_t timerIndex, bool timerMode);
    void beginPWM(int8_t PWMIndex, bool PWMMode);
    void beginSPI(void);
  }

}