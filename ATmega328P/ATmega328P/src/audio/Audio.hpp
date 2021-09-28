/*
 *    NOTE        - Audio.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.28
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"


/*
//==========================================
              CLASS - Audio
==========================================//
*/

class Audio
{

public:
  Audio(){};
  ~Audio(){};

  static void sound(int8_t tonicSolFa, int8_t octaves, int8_t beatValue);
  static void stopSound(int8_t beatValue);

};