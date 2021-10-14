/*
 *    NOTE        - Object.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Object.hpp"


/*----------------------------------------//
                Object Ball
//----------------------------------------*/

void Object::ball(void)
{

  if (m_MoveDistance < 304)
  {
    xPosition = 304 - m_MoveDistance;
    draw(304 - m_MoveDistance, 164, 16, 16, ballTile, BLACK, DARKGRAY, GRAY, WHITE);
    clear(320 - m_MoveDistance, 164, m_MoveSpeed + 2, 16, BLACK);
  }

  else
  {
    clear(0, 164, 24, 16, BLACK);
    isRolling = false;
  }

}

/*----------------------------------------//
                Object Bomb
//----------------------------------------*/

void Object::bomb(void)
{

  if (m_MoveDistance < 304)
  {
    xPosition = 304 - m_MoveDistance;
    draw(304 - m_MoveDistance, 164, 16, 16, bombTile, BLACK, DARKGRAY, GRAY, WHITE);
    clear(320 - m_MoveDistance, 164, m_MoveSpeed + 2, 16, BLACK);
  }

  else
  {
    draw(0, 164, 16, 16, fireTile, BLACK, RED, YELLOW, WHITE);
    clear(16, 164, 4, 16, BLACK);
    m_MoveDistance = 304;
    m_MoveTemp += 1;

    if (m_MoveTemp > 25)
    {
      clear(0, 164, 24, 16, BLACK);
      isRolling = false;
    }
  }

}

/*----------------------------------------//
              Object Present
//----------------------------------------*/

void Object::present(void)
{

  if (m_MoveDistance < 304)
  {
    xPosition = 304 - m_MoveDistance;
    draw(304 - m_MoveDistance, 164, 16, 16, presentTile, BLACK, MAROON, RED, WHITE);
    clear(320 - m_MoveDistance, 164, m_MoveSpeed + 2, 16, BLACK);
    isPresent = true;
  }

  else
  {
    clear(0, 164, 24, 16, BLACK);
    isRolling = false;
    isPresent = false;
  }

}

/*----------------------------------------//
                Roll Object
//----------------------------------------*/

void Object::rollBlock(void)
{

  if (m_Temp != Frame::twoTick)
  {
    m_Temp = Frame::twoTick;

    if (Frame::twoTick == 1)
    {
      m_MoveDistance += m_MoveSpeed;
      m_IsDrawed = false;
    }
  }

  if (isRolling == true && m_IsDrawed == false)
  {
    if (m_RandomNumber < 4)
    {
      ball();
    }

    else if (m_RandomNumber >= 4 && m_RandomNumber < 6)
    {
      present();
    }

    else if (m_RandomNumber >= 6)
    {
      bomb();
    }

    m_IsDrawed = true;
  }

  else if (isRolling == false)
  {
    if (m_RandomNumber == Frame::secondFrame)
    {
      m_IsReset = false;
    }
  }

}

/*----------------------------------------//
                Roll Object
//----------------------------------------*/

void Object::rollBackground(void)
{

  if (m_Temp != Frame::twoTick)
  {
    m_Temp = Frame::twoTick;
    m_rollTemp++;

    if (Frame::twoTick == 1 && m_rollTemp > m_MoveSpeed)
    {
      m_rollTemp = 0;
      m_MoveDistance += 1;
      m_IsDrawed = false;
    }
  }
  
  if (isRolling == true && m_IsDrawed == false)
  {
    if ((m_Width - m_MoveDistance) > 0)
    {
      draw(m_Width - m_MoveDistance, m_Height, 16, 10, m_Bitmap, BLACK, WHITE);
    }

    else
    {
      clear(0, m_Height, 20, 10, BLACK);
      isRolling = false;
    }
  
    m_IsDrawed = true;
  }

  else if (isRolling == false)
  {
    m_Width = 304;
    m_IsReset = false;
  }

}

/*----------------------------------------//
              Start Object
//----------------------------------------*/

void Object::start(void)
{

  if (m_IsReset == false)
  {
    init();
    m_IsReset = true;
    isRolling = true;
  }
  
  if (m_IsBlock == true)
  {
    rollBlock();
  }

  else
  {
    rollBackground();
  }
  
}

/*----------------------------------------//
            Initialize Object
//----------------------------------------*/

void Object::init(void)
{
  xPosition = 0;
  m_MoveTemp = 0;
  m_MoveDistance = 0;
  m_RandomNumber = (Frame::presentTime * 3) % 10;
  m_RandomNumber = (Frame::presentTime * m_RandomNumber) % 10;
}