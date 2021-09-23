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

  void updateFrame(void);

  static uint8_t frameRate;
  static uint8_t fourFrames;
  static uint8_t sixFrames;
  static uint16_t tickFrame;
  static uint16_t secondFrame;

};