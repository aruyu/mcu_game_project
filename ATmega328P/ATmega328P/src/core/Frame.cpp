/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

uint16_t Frame::scoreTime = 0;
uint32_t Frame::presentTime = 0;
uint32_t Frame::pastTick = 0;
uint32_t Frame::pastFrame = 0;
uint32_t Frame::pastScore = 0;
uint32_t Frame::pastBeat = 0;

uint8_t Frame::oneTick = 0;
uint8_t Frame::secondFrame = 0;
uint8_t Frame::fourFrames = 0;
uint8_t Frame::sixFrames = 0;


/*----------------------------------------//
              Update Frame
//----------------------------------------*/

void Frame::update(void)
{

  if (presentTime >= pastTick + 5)
  {

    pastTick = presentTime;
    oneTick++;

    if (oneTick == 3)
    {
      oneTick = 0;
    }

  }

  if (presentTime >= pastFrame + 100)
  {

    pastFrame = presentTime;

    secondFrame++;
    fourFrames++;
    sixFrames++;

    if (secondFrame == 10)
    {
      secondFrame = 0;
    }

    if (fourFrames == 4)
    {
      fourFrames = 0;
    }

    if (sixFrames == 6)
    {
      sixFrames = 0;
    }

  }

  if (presentTime >= pastScore + 125)
  {
    pastScore = presentTime;
    scoreTime++;
  }

}

/*----------------------------------------//
              Initialize Frame
//----------------------------------------*/

void Frame::init(void)
{
  pastTick = presentTime;
  pastFrame = presentTime;
  pastScore = presentTime;
  pastBeat = presentTime;
}