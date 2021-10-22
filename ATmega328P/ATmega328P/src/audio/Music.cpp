/*
 *    NOTE        - Music.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.10.14
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Music.hpp"


/*----------------------------------------//
                Export OCR
//----------------------------------------*/

void Audio::exportOCR(uint16_t OCRValue)
{
  OCR0A = OCRValue;
}

/*----------------------------------------//
                  Set OCR
//----------------------------------------*/

void Audio::setOCR(bool isON)
{
  if (isON == true)
  {
    TCCR0B = 0x0C;
  }
  
  else
  {
    TCCR0B = 0x00;
  }
}

/*----------------------------------------//
                Set Sound
//----------------------------------------*/

void Audio::setSound(int8_t tonicSolFa)
{

  switch (tonicSolFa)
  {
  case DO:
    exportOCR(60);
    break;

  case RE:
    exportOCR(53);
    break;

  case MI:
    exportOCR(47);
    break;

  case FA:
    exportOCR(45);
    break;

  case SO:
    exportOCR(40);
    break;

  case RA:
    exportOCR(36);
    break;

  case SI:
    exportOCR(31);
    break;
      
  default:
    break;
  }

}

/*----------------------------------------//
                Start title
//----------------------------------------*/

void Music::title(void)
{

  if (Frame::presentTime >= Frame::pastBeat + 125)
  {
    Frame::pastBeat = Frame::presentTime;
    m_SixteenBeat++;

    if (m_SixteenBeat == 16)
    {
      m_SixteenBeat = 0;
    }
  }

  switch (m_SixteenBeat)
  {
  case 0:
    setSound(MI);
    setOCR(ON);
    break;
  
  case 1:
    setOCR(OFF);
    break;
  
  case 2:
    setSound(MI);
    setOCR(ON);
    break;
  
  case 3:
    setOCR(OFF);
    break;
  
  case 4:
    setSound(SI);
    setOCR(ON);
    break;
  
  case 5:
    setOCR(OFF);
    break;
  
  case 6:
    setOCR(OFF);
    break;
  
  case 7:
    setOCR(OFF);
    break;
  
  case 8:
    setSound(MI);
    setOCR(ON);
    break;
  
  case 9:
    setOCR(OFF);
    break;
  
  case 10:
    setSound(MI);
    setOCR(ON);
    break;
  
  case 11:
    setOCR(OFF);
    break;
  
  case 12:
    setSound(DO);
    setOCR(ON);
    break;
  
  case 13:
    setOCR(OFF);
    break;
  
  case 14:
    setOCR(OFF);
    break;
  
  case 15:
    setOCR(OFF);
    break;
  
  default:
    break;
  }

}

/*----------------------------------------//
                Jump BGM
//----------------------------------------*/

void Music::jump(void)
{

  if (Frame::presentTime >= Frame::pastBeat + 125)
  {
    Frame::pastBeat = Frame::presentTime;
    m_SixteenBeat++;
  }

  switch (m_SixteenBeat)
  {
  case 0:
    setSound(FA);
    setOCR(ON);
    break;
  
  case 1:
    setSound(SO);
    break;
  
  case 2:
    setSound(SI);
    break;
  
  default:
    break;
  }

}