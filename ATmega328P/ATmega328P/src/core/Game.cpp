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

      switch (m_Cursor)
      {
      case 0:
        clear(2, 160, 6, 14, BLACK);
        clear(2, 184, 6, 14, WHITE);

        break;

      case 1:
        clear(2, 160, 6, 14, WHITE);
        clear(2, 184, 6, 14, BLACK);
        clear(2, 208, 6, 14, WHITE);

        break;

      case 2:
        clear(2, 184, 6, 14, WHITE);
        clear(2, 208, 6, 14, BLACK);
        
        break;

      default:
        break;
      }

      _delay_ms(100);
      SW::up = OFF;
    }

    else if (SW::down == ON)
    {
      m_Cursor += 1;

      if (m_Cursor > 2)
      {
        m_Cursor = 2;
      }

      switch (m_Cursor)
      {
      case 0:
        clear(2, 160, 6, 14, BLACK);
        clear(2, 184, 6, 14, WHITE);

        break;

      case 1:
        clear(2, 160, 6, 14, WHITE);
        clear(2, 184, 6, 14, BLACK);
        clear(2, 208, 6, 14, WHITE);

        break;

      case 2:
        clear(2, 184, 6, 14, WHITE);
        clear(2, 208, 6, 14, BLACK);
        
        break;

      default:
        break;
      }

      _delay_ms(100);
      SW::down = OFF;
    }

    switch (m_Cursor)
    {
    case 0:
      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
        return;
      }

      else if (Frame::sixFrames == 0)
      {
        clear(2, 160, 6, 14, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(2, 160, 6, 14, WHITE);
      }

      break;

    case 1:
      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
      }

      else if (Frame::sixFrames == 0)
      {
        clear(2, 184, 6, 14, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(2, 184, 6, 14, WHITE);
      }

      break;

    case 2:
      if (SW::interrupt0 == ON)
      {
        SW::interrupt0 = OFF;
      }

      else if (Frame::sixFrames == 0)
      {
        clear(2, 208, 6, 14, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(2, 208, 6, 14, WHITE);
      }
      
      break;

    default:
      break;
    }

  }

}

/*----------------------------------------//
              Game Start Loop
//----------------------------------------*/

void Game::startLoop(void)
{

  Player user;
  Object block1;
  Object block2;

  Frame::scoreTime = 0;
  print(16, 16, "Score:");
  draw(256, 32, 32, 32, moonTile, BLACK, WHITE);
  
  while (1)
  {

    Frame::update();
    user.start();
    block1.start();
    block2.start();

    if (block1.isRolling == false || block2.isRolling == false)
    {
      block1.setSpeed(2);
      block2.setSpeed(2);
    }

    else
    {
      block1.setSpeed(4);
      block2.setSpeed(4);
    }

    if (m_ScoreTemp != Frame::scoreTime)
    {

      print(120, 16, Frame::scoreTime);
      m_ScoreTemp = Frame::scoreTime;

      if (m_IsDrawed == true)
      {
        m_Temp ++;

        if (m_Temp > 5)
        {
          m_Temp = 0;
          clear(120, 40, 48, 16, BLACK);
          m_IsDrawed = false;
        }
      }
      
    }

    if (user.isJump == false)
    {
      if (block1.xPosition < 75 && block1.xPosition > 40)
      {
        if (block1.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          Frame::scoreTime += 10;
          print(120, 40, "+10");
          m_IsDrawed = true;

          block1.isRolling = false;
          block1.isPresent = false;
          block1.init();
        }

        else
        {
          print(96, 100, "GAME OVER");
          _delay_ms(2500);
          return;
        }
      }

      if (block2.xPosition < 75 && block2.xPosition > 40)
      {
        if (block2.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          Frame::scoreTime += 10;
          print(120, 40, "+10");
          m_IsDrawed = true;

          block2.isRolling = false;
          block2.isPresent = false;
          block2.init();
        }

        else
        {
          print(96, 100, "GAME OVER");
          _delay_ms(2500);
          return;
        }
      }
    }

  }

}

/*----------------------------------------//
                Game Logo
//----------------------------------------*/

void Game::title(void)
{

  if (m_IsReset == false)
  {
    begin();
    setRotation(0);

    fillScreen(WHITE);
    draw(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
    _delay_ms(3000);

    setFont(fontASCII);
    setColor(BLACK, WHITE);

    m_IsReset = true;
  }
  
  fillScreen(BLACK);
  draw(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
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
  draw(40, 140, 40, 40, charStand, BLACK, MAROON, RED, WHITE);

  print(120, 100, "Ready");
  _delay_ms(1500);

  for (int i=0; i<5; i++)
  {
    print(120, 100, "Start");
    _delay_ms(100);
    clear(120, 100, 80, 16, BLACK);
    _delay_ms(100);
  }
  
  for (int j=0; j<5; j++)
  {
    draw(64 * j, 180, 64, 48, groundTile, BLACK, BROWN, MAROON, WHITE);
  }

  SW::init();
  Frame::init();
  startLoop();

}