/*
 *    NOTE        - Frame.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.23
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Frame.hpp"

uint8_t Frame::frameRate;
uint8_t Frame::fourFrames;
uint8_t Frame::sixFrames;
uint16_t Frame::tickFrame;
uint16_t Frame::secondFrame;


/*----------------------------------------//
                Update Frame
//----------------------------------------*/

void Frame::updateFrame(void)
{

  if (frameRate == 100)
  {

    secondFrame++;

    if (secondFrame == 1000)
    {
      secondFrame = 0;
    }

  }

  if (frameRate % 10 == 0)
  {

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

  if (frameRate % 2 == 0)
  {

    tickFrame++;

    if (tickFrame == 1000)
    {
      tickFrame = 0;
    }

  }

}