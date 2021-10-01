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

  for (int i=0; i<6; i++)
  {
    if (Frame::sixFrames == i)
    {
      drawBitmap(60, 140, 40, 40, charRun, i, BLACK, MAROON, RED, WHITE);
    }
  }

}


/*----------------------------------------//
              Jumping Player
//----------------------------------------*/

void Player::jumping(void)
{

  if (Frame::oneTick == 1)
  {

    if (m_JumpHeight >= 50)
    {
      m_JumpTemp ++;
      m_JumpHeight -= 6;

      if (m_JumpTemp == 3)
      {
        m_JumpHeight += 6;
        mIs_Up = false;
      }
    }

    if (mIs_Up == true)
    {
      m_JumpHeight += 6;
    }

    else
    {
      m_JumpHeight -= 6;

      if (m_JumpHeight <= 0)
      {
        fillRect(60, 140 - 40, 40, 40, BLACK);
        fillRect(60, 140 + 40, 40, 40, BLACK);
        fillRect(60, 180, 40, 40, WHITE);
        SW::interrupt0 = OFF;
        mIs_Jump = false;
        mIs_Reset = false;
        return;
      }
    }

  }

  if (mIs_Up == true)
  {
    for (int i=0; i<4; i++)
    {
      if (Frame::fourFrames == i)
      {
        drawBitmap(60, 130 - m_JumpHeight, 32, 50, charUp, i, BLACK, MAROON, RED, WHITE);

        //fillRect(60, (130 - m_JumpHeight) - 8, 32, 8, BLACK);
        fillRect(60, (130 - m_JumpHeight) + 50, 32, 8, BLACK);
        fillRect(60, 180, 40, 15, WHITE);
      }
    }
  }

  else
  {
    for (int i=0; i<4; i++)
    {
      if (Frame::fourFrames == i)
      {
        drawBitmap160(60, 125 - m_JumpHeight, 40, 64, charDown, i, BLACK, MAROON, RED, WHITE);

        fillRect(60, (125 - m_JumpHeight) - 8, 40, 8, BLACK);
        //fillRect(60, (125 - m_JumpHeight) + 64, 40, 12, BLACK);
      }
    }
  }

}


/*----------------------------------------//
                Player Dead
//----------------------------------------*/

void Player::dead(void)
{

}


/*----------------------------------------//
                Start Player
//----------------------------------------*/

void Player::startPlayer(void)
{

  if (SW::interrupt0 == ON)
  {
    if (mIs_Reset == false)
    {
      fillRect(92, 130, 8, 50, BLACK);
      m_JumpTemp = 0;
      m_JumpHeight = 0;
      mIs_Up = true;
      mIs_Jump = true;
      mIs_Reset = true;
    }
  }
  

  if (mIs_Jump == false)
  {
    running();
  }
  
  else
  {
    jumping();
  }

}