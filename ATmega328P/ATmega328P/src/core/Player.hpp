/*
 *    NOTE        - Player.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"
#include "../modules/TFT.hpp"
#include "../assets/CharRun.hpp"

#include "Frame.hpp"


/*
//==========================================
              CLASS - Player
==========================================//
*/

class Player : public TFT
{

private:
  int8_t m_Life;
  bool mIs_Jump;

public:
  Player() : TFT() { m_Life = 3; }
  ~Player(){};

  void startPlayer(void);

};