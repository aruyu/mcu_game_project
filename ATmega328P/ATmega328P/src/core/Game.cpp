/*
 *    NOTE        - Game.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Game.hpp"


/*----------------------------------------//
                Game Title
//----------------------------------------*/

void Game::title(void)
{
  begin();
  setRotation(0);
  fillScreen(BLACK);

  drawRect(70, 0, 88, 31, RED);
  drawRect(70, 70, 45, 31, GREEN);
  drawRect(70, 140, 71, 31, BLUE);
  _delay_ms(500);

  fillScreen(RED);
  _delay_ms(500);

  fillScreen(GREEN);
  _delay_ms(500);

  fillScreen(BLUE);
  _delay_ms(500);

  //fillScreen(BLACK);
  //drawBitmap(0, 0, 48, 128, font, BLACK, WHITE);

  fillScreen(WHITE);
  drawBitmap(0, 30, 160, 80, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(500);

  drawBitmapTwice(0, 30, 320, 160, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(3000);
}


/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Game::start(void)
{
  fillScreen(BLACK);
  _delay_ms(10);
  
  Player user;

  while (1)
  {
    user.startPlayer();
  }

}