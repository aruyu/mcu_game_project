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
              Game Title Loop
//----------------------------------------*/

void Game::titleLoop(void)
{

  while (1)
  {
    Frame::update();

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

    switch (m_Cursor)
    {
    case 0:
      if (Frame::sixFrames == 0)
      {
        fillRect(2, 160, 6, 14, BLACK);
      }

      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
        return;
      }
      
      break;

    case 1:
      if (Frame::sixFrames == 0)
      {
        fillRect(2, 184, 6, 14, BLACK);
      }

      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
      }
      
      break;

    case 2:
      if (Frame::sixFrames == 0)
      {
        fillRect(2, 208, 6, 14, BLACK);
      }

      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
      }
      
      break;

    default:
      break;
    }

    if (Frame::sixFrames == 4)
    {
      fillRect(2, 160, 6, 14, WHITE);
      fillRect(2, 184, 6, 14, WHITE);
      fillRect(2, 208, 6, 14, WHITE);
    }
  }

}

/*----------------------------------------//
              Game Start Loop
//----------------------------------------*/

void Game::startLoop(void)
{

  Player user;
  
  while (1)
  {
    Frame::update();
    user.startPlayer();
    //print(100, 16, Frame::secondTime);
  }

}

/*----------------------------------------//
                Game Logo
//----------------------------------------*/

void Game::title(void)
{

  if (mIs_Reset == false)
  {
    begin();
    setRotation(0);

    fillScreen(WHITE);
    drawBitmap(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
    _delay_ms(3000);

    setFont(fontASCII);
    setColor(BLACK, WHITE);

    mIs_Reset = true;
  }
  
  fillScreen(BLACK);
  drawBitmap(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
  _delay_ms(100);

  SW::init();
  Frame::init();
  titleLoop();

}

/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Game::start(void)
{

  fillScreen(BLACK);
  print(80, 100, "Game Start");
  _delay_ms(2500);
  fillRect(80, 100, 160, 16, BLACK);

  for (int i=0; i<5; i++)
  {
    drawBitmap(64 * i, 180, 64, 60, groundTile, BLACK, MAROON, RED, WHITE);
  }

  SW::init();
  Frame::init();
  startLoop();

}