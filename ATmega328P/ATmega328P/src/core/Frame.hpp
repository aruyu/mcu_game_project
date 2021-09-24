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

  static void updateFrame(void);

  static int8_t frameRate;
  static int8_t fourFrames;
  static int8_t sixFrames;
  static int8_t tickFrame;
  static int8_t secondFrame;

};