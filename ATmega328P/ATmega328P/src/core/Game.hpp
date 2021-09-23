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
#include "../modules/TFT.hpp"
#include "../assets/LogoAtmel.hpp"
#include "../assets/FontASCII.hpp"

#include "Font.hpp"
#include "Frame.hpp"
#include "Object.hpp"
#include "Player.hpp"


/*
//==========================================
                CLASS - Game
==========================================//
*/

class Game : public Font
{

private:
  

public:
  Game() : Font(){};
  ~Game(){};

  void title(void);
  void start(void);
  void end(void);

};