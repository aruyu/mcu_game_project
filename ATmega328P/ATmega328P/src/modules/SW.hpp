/*
 *    NOTE        - SW.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.05.30
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "MCU.hpp"

#define REVERSAL 0
#define NONREVERSAL 1
#define SENSOR 2

#define SW_OFF 0x00
#define SW_0 0x01
#define SW_1 0x02
#define SW_2 0x04
#define SW_3 0x08
#define SW_4 0x10
#define SW_5 0x20
#define SW_6 0x40
#define SW_7 0x80

typedef volatile unsigned int NonOptimal;
//using NonOptimal = volatile unsigned int;


/*
//==========================================
            CLASS - SW (Switch)
==========================================//
*/

class SW
{

private:
  int8_t m_SwitchPort;
  int8_t m_SwitchMode;

public:
  SW(int8_t switchPort, int8_t switchMode)
  {
    m_SwitchPort = switchPort;
    m_SwitchMode = switchMode;
  }
  void setMax(uint8_t maxValue);
  void init(void);

  NonOptimal newData;
  NonOptimal oldData;
  NonOptimal result;
  uint8_t maxData;

};