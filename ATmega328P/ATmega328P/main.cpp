/*
 *    NOTE        - main.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "src/modules/MCU.hpp"
#include "src/core/Game.hpp"

using namespace MCU::Setting;

Game game;


/*========================================//
--------------  MAIN START  --------------
//========================================*/

int main(void)
{
  beginPort(B, OUT);
  beginSPI();

  game.title();

  while (1)
  {
    game.start();
  }

  return 0;
}

/*========================================//
---------------  MAIN END  ---------------
//========================================*/