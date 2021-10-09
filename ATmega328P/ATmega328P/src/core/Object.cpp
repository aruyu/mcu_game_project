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
              Object Rolling
//----------------------------------------*/

void Object::rolling(void)
{

  if (Frame::oneTick == 1)
  {
    m_MoveDistance += 4;

    if (m_MoveDistance > 304)
    {
      draw(0, 164, 16, 16, fire, BLACK, RED, YELLOW, WHITE);
      clear(16, 164, 4, 16, BLACK);
      m_MoveDistance = 304;
      m_MoveTemp += 1;

      if (m_MoveTemp > 20)
      {
        clear(0, 164, 24, 16, BLACK);
        m_MoveDistance = 0;
        m_MoveTemp = 0;
        return;
      }
    }

    else
    {
      setPosition(304 - m_MoveDistance, 164);
      draw(304 - m_MoveDistance, 164, 16, 16, bomb, BLACK, DARKGRAY, GRAY, WHITE);
      clear(320 - m_MoveDistance, 164, 6, 16, BLACK);
    }
  }

}

/*----------------------------------------//
              Object Disappear
//----------------------------------------*/

void Object::disappear(void)
{

  //m_RandomNumber = srand(Frame::presentTime) % 10;

}

/*----------------------------------------//
              Start Object
//----------------------------------------*/

void Object::start(void)
{

  if (m_IsNomal == false)
  {
    rolling();
  }

  else
  {
    draw(40, 164, 40, 40, m_Bitmap, BLACK, MAROON, RED, WHITE);
    clear(0, 164, 40, 40, BLACK);
  }

}