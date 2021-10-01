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

private:
  uint32_t m_PastTick;
  uint32_t m_PastFrame;
  uint32_t m_PastBeat;

public:
  Frame(){};
  ~Frame(){};

  void update(void);
  void init(void);

  static uint16_t secondTime;
  static uint32_t presentTime;

  static int8_t oneTick;
  static int8_t fourFrames;
  static int8_t sixFrames;
  static int8_t sixteenBeats;

};