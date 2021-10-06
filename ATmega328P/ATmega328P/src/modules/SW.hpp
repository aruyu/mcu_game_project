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

#define SW_OFF 0x00
#define SW_LEFT 0x01
#define SW_DOWN 0x02
#define SW_RIGHT 0x04
#define SW_UP 0x08
#define SW_START 0x10
#define SW_SELECT 0x20


/*
//==========================================
            CLASS - SW (Switch)
==========================================//
*/

class SW
{

public:
  SW(){};
  ~SW(){};

  static void update(void);
  static void init(void);
  static volatile uint8_t result;
  static volatile uint8_t newData;
  static volatile uint8_t oldData;

  static bool interrupt0;
  static bool interrupt1;
  static bool up;
  static bool down;
  static bool left;
  static bool right;
  static bool start;
  static bool select;

};