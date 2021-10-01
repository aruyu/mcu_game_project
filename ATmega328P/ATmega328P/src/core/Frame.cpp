/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

uint16_t Frame::secondTime = 0;
uint32_t Frame::presentTime = 0;

int8_t Frame::oneTick = 0;
int8_t Frame::fourFrames = 0;
int8_t Frame::sixFrames = 0;
int8_t Frame::sixteenBeats = 1;


/*----------------------------------------//
              Update Frame
//----------------------------------------*/

void Frame::update(void)
{

  if (presentTime >= m_PastTick + 5)
  {

    m_PastTick = presentTime;

    oneTick++;

    if (oneTick == 2)
    {
      oneTick = 0;
    }

  }

  if (presentTime >= m_PastFrame + 100)
  {

    m_PastFrame = presentTime;

    fourFrames++;
    sixFrames++;

    if (fourFrames == 4)
    {
      fourFrames = 0;
    }

    if (sixFrames == 6)
    {
      sixFrames = 0;
    }

  }

  if (presentTime >= m_PastBeat + 125)
  {

    m_PastBeat = presentTime;

    sixteenBeats++;

    if (sixteenBeats == 2)
    {
      sixteenBeats = 0;
    }

  }

}

/*----------------------------------------//
                Reset Frame
//----------------------------------------*/

void Frame::init(void)
{
  m_PastTick = presentTime;
  m_PastFrame = presentTime;
  m_PastBeat = presentTime;
}