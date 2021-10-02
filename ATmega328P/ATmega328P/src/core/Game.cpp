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
  drawBitmap(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(3000);

  fillScreen(BLACK);
  setFont(fontASCII);
  setColor(BLACK, WHITE);
  print(30, 70, "Hello, World!");
  _delay_ms(1000);

  setColor(BLACK, CYAN);
  print(30, 120, "And Welcome to");
  setColor(BLACK, RED);
  print(30, 136, "Atmega Game (^O^)");
  _delay_ms(5000);

  fillScreen(BLACK);
  setColor(BLACK, WHITE);
  print(16, 16, "Time:");
  fillRect(0, 180, 320, 60, WHITE);
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