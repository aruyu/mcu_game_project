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
                Set Sound
//----------------------------------------*/

void Audio::setSound(bool isON)
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
              Set TonicSolFa
//----------------------------------------*/

void Audio::setTonicSolFa(int8_t tonicSolFa)
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
                Title BGM
//----------------------------------------*/

void Music::titleMusic(void)
{

  switch (m_SixteenBeat)
  {
  case 0:
    setTonicSolFa(MI);
    setSound(ON);
    break;
  
  case 1:
    setSound(OFF);
    break;
  
  case 2:
    setTonicSolFa(MI);
    setSound(ON);
    break;
  
  case 3:
    setSound(OFF);
    break;
  
  case 4:
    setTonicSolFa(SI);
    setSound(ON);
    break;
  
  case 5:
    setSound(OFF);
    break;
  
  case 6:
    setSound(OFF);
    break;
  
  case 7:
    setSound(OFF);
    break;
  
  case 8:
    setTonicSolFa(MI);
    setSound(ON);
    break;
  
  case 9:
    setSound(OFF);
    break;
  
  case 10:
    setTonicSolFa(MI);
    setSound(ON);
    break;
  
  case 11:
    setSound(OFF);
    break;
  
  case 12:
    setTonicSolFa(DO);
    setSound(ON);
    break;
  
  case 13:
    setSound(OFF);
    break;
  
  case 14:
    setSound(OFF);
    break;
  
  case 15:
    setSound(OFF);
    break;
  
  case 16:
    m_SixteenBeat = 0;
    break;

  default:
    break;
  }

}

/*----------------------------------------//
                Start Effect
//----------------------------------------*/

void Music::startingMusic(void)
{

  switch (m_SixteenBeat)
  {
  case 0:
    break;
  
  case 1:
    break;
    
  case 2:
    setTonicSolFa(MI);
    setSound(ON);
    break;
    
  case 3:
    setSound(OFF);
    break;

  case 4:
    setTonicSolFa(MI);
    setSound(ON);
    break;
    
  case 5:
    setTonicSolFa(RE);
    setSound(ON);
    break;
  
  case 6:
    setSound(OFF);
    break;
  
  case 7:
    setTonicSolFa(FA);
    setSound(ON);
    break;
  
  case 8:
    setSound(OFF);
    break;
    
  case 9:
    setTonicSolFa(FA);
    setSound(ON);
    break;
    
  case 10:
    setTonicSolFa(MI);
    setSound(ON);
    break;

  case 11:
    setSound(OFF);
    break;
    
  case 12:
    setTonicSolFa(SO);
    setSound(ON);
    break;
  
  case 13:
    break;
  
  case 14:
    break;
  
  case 15:
    break;
  
  case 16:
    setSound(OFF);
    break;
  
  case 17:
    isPlay = false;
    break;
    
  default:
    break;
  }

}

/*----------------------------------------//
                Jump Effect
//----------------------------------------*/

void Music::jumpingMusic(void)
{

  switch (m_SixteenBeat)
  {
  case 0:
    break;
    
  case 1:
    setTonicSolFa(MI);
    setSound(ON);
    break;
    
  case 2:
    setTonicSolFa(FA);
    break;

  case 3:
    setTonicSolFa(SO);
    break;
    
  case 4:
    setSound(OFF);
    break;
    
  default:
    break;
  }

}

/*----------------------------------------//
                Start Music
//----------------------------------------*/

void Music::start(void)
{

  if (isPlay == true)
  {
    if (Frame::presentTime >= Frame::pastBeat + 125)
    {
      Frame::pastBeat = Frame::presentTime;
      m_SixteenBeat++;
    }

    switch (m_MusicMode)
    {
    case TITLE:
      titleMusic();
      break;
      
    case START:
      startingMusic();
      break;

    case JUMP:
      jumpingMusic();
      break;
      
    default:
      break;
    }
    
  }

  else
  {
    m_SixteenBeat = 0;
  }

}