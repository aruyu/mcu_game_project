/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

uint32_t Frame::presentTime;
uint32_t Frame::pastTick;
uint32_t Frame::pastBeat;

int8_t Frame::fourFrames;
int8_t Frame::sixFrames;

int8_t Frame::beatFrame;
int8_t Frame::secondFrame;
int16_t Frame::secondTime;


/*----------------------------------------//
              Update Timer
//----------------------------------------*/

void Frame::update(void)
{

  if (presentTime > pastTick + 20)
  {

    pastTick = presentTime;

    fourFrames++;
    sixFrames++;

    if (fourFrames == 5)
    {
      fourFrames = 0;
    }

    if (sixFrames == 7)
    {
      sixFrames = 0;
    }

  }

  if (presentTime > pastBeat + 50)
  {

    pastTick = presentTime;

    beatFrame++;
    secondFrame++;

    if (beatFrame == 2)
    {
      beatFrame = 0;
    }

    if (beatFrame == 20)
    {
      secondFrame = 0;
      secondTime++;
    }

  }

}