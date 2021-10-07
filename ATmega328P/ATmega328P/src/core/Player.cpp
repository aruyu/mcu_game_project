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

  if (Frame::oneTick == 1)
  {
    mIs_Drawed = false;
  }

  if (mIs_Drawed == false)
  {
    for (int i=0; i<6; i++)
    {

      if (Frame::sixFrames == i)
      {
        draw(40, 140, 40, 40, charRun, i, BLACK, MAROON, RED, WHITE);
        mIs_Drawed = true;
      }

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

    if (mIs_Up == true)
    {
      m_JumpHeight += 6;

      if (m_JumpHeight >= 50)
      {
        m_JumpTemp ++;
        m_JumpHeight -= 6;

        if (m_JumpTemp == 4)
        {
          m_JumpHeight += 6;
          mIs_Up = false;
        }
      }
    }

    else
    {
      m_JumpHeight -= 6;

      if (m_JumpHeight <= 0)
      {
        clear(40, 140 - 25, 40, 25, BLACK);
        SW::interrupt0 = OFF;
        mIs_Jump = false;
        mIs_Reset = false;
        return;
      }
    }

    mIs_Drawed = false;

  }

  if (mIs_Drawed == false)
  {
    if (mIs_Up == true)
    {
      for (int i=0; i<4; i++)
      {
        if (Frame::fourFrames == i)
        {
          draw(40, 122 - m_JumpHeight, 32, 50, charUp, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) + 50, 32, 8, BLACK);
          mIs_Drawed = true;
        }
      }
    }

    else
    {
      for (int i=0; i<4; i++)
      {
        if (Frame::fourFrames == i)
        {
          draw(40, 122 - m_JumpHeight, 40, 64, charDown, i, BLACK, MAROON, RED, WHITE);
          clear(40, (122 - m_JumpHeight) - 8, 40, 8, BLACK);
          mIs_Drawed = true;
        }
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

void Player::start(void)
{

  if (SW::interrupt0 == ON)
  {
    if (mIs_Reset == false)
    {
      clear(40, 140, 40, 40, BLACK);
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