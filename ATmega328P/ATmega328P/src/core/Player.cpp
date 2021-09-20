/*
 *    NOTE        - Player.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Player.hpp"


/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Player::startPlayer(void)
{
  for (int i=0; i<6; i++)
  {
    drawTile(60, 120, charRun, i, BLACK, MAROON, RED, WHITE);
    _delay_ms(100);
  }
}