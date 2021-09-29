/*
 *    NOTE        - Frame.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"


/*
//==========================================
              CLASS - Frame
==========================================//
*/

class Frame
{

public:
  Frame(){};
  ~Frame(){};

  static void update(void);

  static uint32_t presentTime;
  static uint32_t pastBeat;
  static uint32_t pastTick;

  static int8_t tickFrame;
  static int8_t fourFrames;
  static int8_t sixFrames;

  static int8_t beatFrame;
  static int8_t secondFrame;
  static int16_t secondTime;

};