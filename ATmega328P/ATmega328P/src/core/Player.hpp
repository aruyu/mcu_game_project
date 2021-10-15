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
#include "../assets/CharDown.hpp"
#include "../assets/CharRun.hpp"
#include "../assets/CharStand.hpp"
#include "../assets/CharUp.hpp"

#include "Frame.hpp"


/*
//==========================================
              CLASS - Player
==========================================//
*/

class Player : private TFT
{

private:
  int8_t m_Temp;
  int8_t m_JumpTemp;
  int8_t m_JumpSpeed;
  int8_t m_JumpHeight;
  bool m_IsReset;
  bool m_IsUp;
  bool m_IsDrawed;

  void running(void);
  void jumping(void);

public:
  Player() : TFT() { m_JumpSpeed = 6; m_IsReset = false; m_IsUp = false; isJump = false; }
  ~Player(){};

  void init(void);
  void start(void);
  void setSpeed(int8_t speed) { m_JumpSpeed = speed; }

  bool isJump;
  
};