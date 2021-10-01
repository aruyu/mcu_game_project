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
  SW(){};
  ~SW(){};

  static bool interrupt0;
  static bool interrupt1;
  static bool PCInterrupt8;
  static bool PCInterrupt9;
  static bool PCInterrupt10;
  static bool PCInterrupt11;
  static bool PCInterrupt12;
  static bool PCInterrupt13;

};