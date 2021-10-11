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
  static void init(void);

  static uint16_t scoreTime;
  static uint32_t presentTime;
  static uint32_t pastTick;
  static uint32_t pastFrame;
  static uint32_t pastBeat;

  static int8_t oneTick;
  static int8_t twoTick;
  static int8_t secondFrame;
  static int8_t fourFrames;
  static int8_t sixFrames;
  static int8_t sixteenBeats;

};