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
#include "../assets/TitleScreen.hpp"
#include "../audio/Music.hpp"

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
  int8_t m_Cache;
  int8_t m_Temp;
  uint16_t m_ScoreTemp;

  bool m_IsScore;
  bool m_IsCredit;
  bool m_IsHardmode;
  bool m_IsReset;
  bool m_IsHighSpeed;
  bool m_IsDrawed;
  bool m_IsDrawedScore;

  void scoreTitle(void);
  void creditTitle(void);
  void nomalTitle(void);
  void titleLoop(void);
  void startLoop(void);
  void endLoop(void);

  void init(void) { m_Cursor = 0; m_Cache = 0; m_Temp = 0; m_ScoreTemp = 0; Frame::scoreTime = 0;
    m_IsReset = false; m_IsHighSpeed = false; m_IsDrawed = false; m_IsDrawedScore = false;  }

protected:
  uint8_t firstName1st;
  uint8_t firstName2nd;
  uint8_t firstName3rd;
  uint8_t firstMode;
  uint16_t firstScore;

  uint8_t secondName1st;
  uint8_t secondName2nd;
  uint8_t secondName3rd;
  uint8_t secondMode;
  uint16_t secondScore;

  uint8_t thirdName1st;
  uint8_t thirdName2nd;
  uint8_t thirdName3rd;
  uint8_t thirdMode;
  uint16_t thirdScore;

  uint8_t fourthName1st;
  uint8_t fourthName2nd;
  uint8_t fourthName3rd;
  uint8_t fourthMode;
  uint16_t fourthScore;

  uint8_t fifthName1st;
  uint8_t fifthName2nd;
  uint8_t fifthName3rd;
  uint8_t fifthMode;
  uint16_t fifthScore;

  uint8_t tempName1st;
  uint8_t tempName2nd;
  uint8_t tempName3rd;
  uint8_t tempMode;

  uint8_t checkReset;

  void resetScore(void);
  void readScore(void);

public:
  Game() : Font() { m_IsHardmode = false; }
  ~Game(){};

  void title(void);
  void start(void);
  void end(void);

};