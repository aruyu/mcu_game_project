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
#include "../assets/Logo.hpp"

#include "Player.hpp"
#include "Object.hpp"


/*
//==========================================
              CLASS - Game
==========================================//
*/

class Game : public TFT
{

private:
  

public:
  Game() : TFT(){};
  ~Game(){};

  void title(void);
  void start(void);
  void end(void);

};