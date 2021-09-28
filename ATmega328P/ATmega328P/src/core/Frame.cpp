/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

int8_t Frame::frameRate;
int8_t Frame::tickFrame;
int8_t Frame::fourFrames;
int8_t Frame::sixFrames;

int8_t Frame::beatFrame;
int8_t Frame::secondFrame;
int16_t Frame::secondTime;


/*----------------------------------------//
                Update Frame
//----------------------------------------*/

void Frame::updateFrame(void)
{

  if (frameRate == 7)
  {
    frameRate = 0;
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

  if (tickFrame == 2)
  {
    tickFrame = 0;
  }

  if (beatFrame == 2)
  {
    beatFrame = 0;
  }

  if (secondFrame == 4)
  {
    secondFrame = 0;
    secondTime++;
  }

}