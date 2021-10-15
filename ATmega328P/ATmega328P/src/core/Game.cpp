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
  Object block1, block2, block3;
  Object star1(50, 70, bigStar, 30);
  Object star2(250, 80, smallStar1, 10);
  Object star3(150, 110, smallStar0, 3);

  print(16, 16, "Score:");
  draw(256, 32, 32, 32, moonTile, BLACK, WHITE);

  while (1)
  {

    star1.start();
    star2.start();
    star3.start();

    if (m_IsHighSpeed == false && Frame::scoreTime < 5)
    {
      block1.start();
    }

    else if (m_IsHighSpeed == false)
    {
      block1.start();
      block2.start();
    }

    else
    {
      block1.start();
      block2.start();
      block3.start();
    }

    if (m_IsReset == false)
    {
      if (m_ScoreTemp >= 200 && m_ScoreTemp < 211)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(4);
        block2.setSpeed(4);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 400 && m_ScoreTemp < 411)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(5);
        block2.setSpeed(5);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 600 && m_ScoreTemp < 611)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(6);
        block2.setSpeed(6);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 1000 && m_ScoreTemp < 1011)
      {
        print(120, 40, "Block+");
        block1.setSpeed(7);
        block2.setSpeed(7);
        block3.setSpeed(7);
        user.setSpeed(8);

        m_IsReset = true;
        m_IsHighSpeed = true;
        m_IsDrawed = true;
      }
    }

    /*
    if (block1.isRolling == false || block2.isRolling == false)
    {
      block1.setSpeed(4);
      block2.setSpeed(4);
    }

    else
    {
      block1.setSpeed(6);
      block2.setSpeed(6);
    }
    */

    if (m_ScoreTemp != Frame::scoreTime)
    {
      m_ScoreTemp = Frame::scoreTime;
      print(120, 16, Frame::scoreTime);
      SW::start = OFF;

      if (m_IsDrawed == true)
      {
        m_Temp ++;

        if (m_IsReset == false && m_Temp > 5)
        {
          m_Temp = 0;
          clear(120, 40, 96, 16, BLACK);
          m_IsDrawed = false;
        }

        else if (m_IsReset == true && m_Temp > 10)
        {
          m_Temp = 0;
          clear(120, 40, 96, 16, BLACK);
          m_IsReset = false;
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
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block1.isRolling = false;
          block1.isPresent = false;
          block1.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }

      if (block2.xPosition < 75 && block2.xPosition > 40)
      {
        if (block2.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block2.isRolling = false;
          block2.isPresent = false;
          block2.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }

      if (block3.xPosition < 75 && block3.xPosition > 40)
      {
        if (block3.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block3.isRolling = false;
          block3.isPresent = false;
          block3.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }
    }

    if (SW::select == OFF)
    {
      Frame::update();
      user.start();
    }

    else
    {
      print(120, 100, "Pause");

      if (SW::start == ON)
      {
        print(120, 100, "Ready");
        _delay_ms(1500);

        for (int i=0; i<5; i++)
        {
          print(120, 100, "Start");
          _delay_ms(100);
          clear(120, 100, 80, 16, BLACK);
          _delay_ms(100);
        }

        SW::init();
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
  Game::init();
  startLoop();

}