/*
 *    NOTE        - Game.hpp
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
#include "../assets/FontASCII.hpp"
#include "../assets/GroundTile.hpp"
#include "../assets/LogoAtmel.hpp"
#include "../assets/TitleMenu.hpp"

#include "Font.hpp"
#include "Frame.hpp"
#include "Object.hpp"
#include "Player.hpp"


/*
//==========================================
                CLASS - Game
==========================================//
*/

class Game : private Font
{

private:
  int8_t m_Cursor;
  int8_t m_Temp;
  uint16_t m_ScoreTemp;

  bool m_IsScore;
  bool m_IsCredit;
  bool m_IsReset;
  bool m_IsHardmode;
  bool m_IsHighSpeed;
  bool m_IsDrawed;

  void titleLoop(void);
  void startLoop(void);

public:
  Game() : Font() { m_IsHardmode = false; };
  ~Game(){};

  void init(void) { m_Cursor = 0; m_Temp = 0; m_ScoreTemp = 0; m_IsReset = false; m_IsHighSpeed = false; m_IsDrawed = false; Frame::scoreTime = 0; }
  void title(void);
  void start(void);
  void end(void);

};