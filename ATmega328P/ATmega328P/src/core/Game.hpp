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
#include "../assets/LogoAtmel.hpp"
#include "../assets/FontASCII.hpp"
#include "../assets/TitleMenu.hpp"
#include "../assets/groundTile.hpp"

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
  bool mIs_Start;
  bool mIs_Score;
  bool mIs_Credit;
  bool mIs_Reset;

  void titleLoop(void);
  void startLoop(void);

public:
  Game() : Font(){ m_Cursor = 0; mIs_Start = false; mIs_Score = false; mIs_Credit = false; mIs_Reset = false; }
  ~Game(){};

  void title(void);
  void start(void);
  void end(void);

};