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
  fillScreen(WHITE);

  _delay_ms(500);
  drawBitmap(8, 70, 304, 96, logoAtmel, 2, BLACK, RED, BLUE, WHITE);
  _delay_ms(3000);

  fillScreen(BLACK);
  drawBitmap(8, 16, 304, 224, titleMenu, 2, BLACK, MAROON, RED, WHITE);
  _delay_ms(7500);

  fillScreen(BLACK);
  setFont(fontASCII);
  setColor(BLACK, WHITE);
  print(16, 16, "Time:");

  for (int i=0; i<5; i++)
  {
    drawBitmap(64 * i, 180, 64, 60, groundTile, 2, BLACK, MAROON, RED, WHITE);
  }
}

/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Game::start(void)
{
  
  _delay_ms(100);

  Frame frame;
  Player user;

  Frame::secondTime = 0;
  frame.init();

  while (1)
  {
    frame.update();
    user.startPlayer();
    print(100, 16, Frame::secondTime);
  }

}