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
              Running Player
//----------------------------------------*/

void Player::running(void)
{

  if (m_Temp != Frame::oneTick)
  {
    m_Temp = Frame::oneTick;

    if (Frame::oneTick == 0)
    {
      m_IsDrawed = false;
    }

    else
    {
      return;
    }
  }

  if (m_IsDrawed == false)
  {
    for (int i=0; i<6; i++)
    {
      if (Frame::sixFrames == i)
      {
        draw(40, 140, 40, 40, charRun, i, BLACK, MAROON, RED, WHITE);
        m_IsDrawed = true;
      }
    }
  }

}

/*----------------------------------------//
              Jumping Player
//----------------------------------------*/

void Player::jumping(void)
{

  if (m_Temp != Frame::oneTick)
  {
    m_Temp = Frame::oneTick;

    if (Frame::oneTick == 0)
    {
      if (m_IsUp == true)
      {
        m_JumpHeight += m_JumpSpeed;

        if (m_JumpHeight >= 50)
        {
          m_JumpHeight -= m_JumpSpeed;
          m_JumpTemp ++;

          if (m_JumpTemp == 8)
          {
            m_IsUp = false;
          }
        }
      }

      else
      {
        m_JumpHeight -= m_JumpSpeed;

        if (m_JumpHeight <= 0)
        {
          clear(40, 140 - 25, 40, 25, BLACK);
          SW::interrupt0 = OFF;
          m_IsReset = false;
          isJump = false;
          return;
        }
      }

      m_IsDrawed = false;
    }

    else
    {
      return;
    }
  }

  if (m_IsDrawed == false)
  {
    for (int i=0; i<4; i++)
    {
      if (Frame::fourFrames == i)
      {

        if (m_IsUp == true)
        {
          draw(40, 122 - m_JumpHeight, 32, 50, charUp, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) + 50, 32, 8, BLACK);
        }

        else
        {
          draw(40, 122 - m_JumpHeight, 32, 60, charDown, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) - 8, 32, 8, BLACK);
        }

        m_IsDrawed = true;

      }
    }
  }
  
}

/*----------------------------------------//
                Start Player
//----------------------------------------*/

void Player::start(void)
{

  if (SW::interrupt0 == ON && m_IsReset == false)
  {
    init();
    m_IsReset = true;
    m_IsUp = true;
    isJump = true;
  }

  if (isJump == false)
  {
    running();
  }
  
  else
  {
    jumping();
  }

}

/*----------------------------------------//
            Initialize Player
//----------------------------------------*/

void Player::init(void)
{
  clear(40, 140, 40, 40, BLACK);
  m_Temp = 0;
  m_JumpTemp = 0;
  m_JumpHeight = 0;
}