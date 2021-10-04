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
#include "../modules/SW.hpp"
#include "../modules/TFT.hpp"
#include "../assets/CharStand.hpp"
#include "../assets/CharRun.hpp"
#include "../assets/CharUp.hpp"
#include "../assets/CharDown.hpp"

#include "Frame.hpp"


/*
//==========================================
              CLASS - Player
==========================================//
*/

class Player : private TFT
{

private:
  int8_t m_JumpSpeed;
  int8_t m_JumpTemp;
  int8_t m_JumpHeight;
  bool mIs_Reset;
  bool mIs_Jump;
  bool mIs_Up;

  void running(void);
  void jumping(void);
  void dead(void);

public:
  Player() : TFT() { mIs_Up = false; mIs_Jump = false; mIs_Reset = false; }
  ~Player(){};

  void startPlayer(void);
  
};