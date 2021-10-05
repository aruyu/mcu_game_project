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
  drawBitmap(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(3000);

  fillScreen(BLACK);
  drawBitmap(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
  _delay_ms(500);

  setFont(fontASCII);
  setColor(BLACK, WHITE);
}

/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Game::start(void)
{
  
  _delay_ms(100);

  Frame frame;
  frame.init();

  while (1)
  {
    frame.update();

    if (SW::up == ON)
    {
      m_Cursor -= 1;

      if (m_Cursor < 0)
      {
        m_Cursor = 0;
      }

      SW::up = OFF;
    }

    else if (SW::down == ON)
    {
      m_Cursor += 1;

      if (m_Cursor > 2)
      {
        m_Cursor = 2;
      }

      SW::down = OFF;
    }

    if (Frame::sixFrames == 0)
    {
      switch (m_Cursor)
      {
      case 0:
        fillRect(2, 160, 6, 14, BLACK);
        break;

      case 1:
        fillRect(2, 184, 6, 14, BLACK);
        break;

      case 2:
        fillRect(2, 208, 6, 14, BLACK);
        break;
      
      default:
        break;
      }
    }

    else if (Frame::sixFrames == 4)
    {
      fillRect(2, 160, 6, 14, WHITE);
      fillRect(2, 184, 6, 14, WHITE);
      fillRect(2, 208, 6, 14, WHITE);
    }
  }


  Player user;
  //Frame::secondTime = 0;
  //print(16, 16, "Time:");

  for (int i=0; i<5; i++)
  {
    drawBitmap(64 * i, 180, 64, 60, groundTile, BLACK, MAROON, RED, WHITE);
  }

  while (1)
  {
    frame.update();
    user.startPlayer();
    //print(100, 16, Frame::secondTime);
  }

}