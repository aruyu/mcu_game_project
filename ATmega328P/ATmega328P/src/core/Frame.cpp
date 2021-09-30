/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

uint16_t Frame::secondTime;
uint32_t Frame::presentTime;
uint32_t Frame::pastTick;
uint32_t Frame::pastFrame;
uint32_t Frame::pastBeat;

int8_t Frame::oneTick;
int8_t Frame::fourFrames;
int8_t Frame::sixFrames;
int8_t Frame::sixteenBeats = 1;


/*----------------------------------------//
              Update Frame
//----------------------------------------*/

void Frame::update(void)
{

  if (presentTime >= pastTick + 10)
  {

    pastTick = presentTime;

    oneTick++;

    if (oneTick == 2)
    {
      oneTick = 0;
    }

  }

  if (presentTime >= pastFrame + 100)
  {

    pastFrame = presentTime;

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

  if (presentTime >= pastBeat + 125)
  {

    pastBeat = presentTime;

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
  pastTick = presentTime;
  pastFrame = presentTime;
  pastBeat = presentTime;
}