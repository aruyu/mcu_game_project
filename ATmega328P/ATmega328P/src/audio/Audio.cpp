/*
 *    NOTE        - Audio.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.28
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Audio.hpp"


/*----------------------------------------//
                Start Sound
//----------------------------------------*/

void Audio::sound(int8_t tonicSolFa, int8_t octaves, int8_t beatValue)
{

  int8_t temp;

  if (mIs_Play == OFF)
  {
    switch (octaves)
    {
    case 9:
      switch (tonicSolFa)
      {
      case DO:
        OCR0A = 60;
        break;

      case RE:
        OCR0A = 53;
        break;

      case MI:
        OCR0A = 47;
        break;

      case FA:
        OCR0A = 45;
        break;

      case SO:
        OCR0A = 40;
        break;

      case RA:
        OCR0A = 36;
        break;

      case SI:
        OCR0A = 31;
        break;
      
      default:
        break;
      }
      
      break;
    
    default:
      break;
    }

    mIs_Play == ON;
    TCCR0B = 0x0B;
  }

  temp += Frame::beatFrame;

  if (temp == beatValue)
  {
    mIs_Play == OFF;
    TCCR0B = 0x00;
  }

}

/*----------------------------------------//
                Start Sound
//----------------------------------------*/

void Audio::stopSound(int8_t beatValue)
{

  mIs_Play == ON;

  int8_t temp;

  temp += Frame::beatFrame;

  if (temp == beatValue)
  {
    mIs_Play == OFF;
    TCCR0B = 0x00;
  }

}


/*
31 = 8B
34 = 8A#
36 = 8A
38 = 8G#
40 = 8G
42 = 8F#
45 = 8F
47 = 8E
50 = 8D#
53 = 8D
56 = 8C#
60 = 8C

    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 36;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 47;
    TCCR0B = 0x0B;
    _delay_ms(500);
    TCCR0B = 0x00;
    _delay_ms(500);
	
	/////

    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 47;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 53;
    TCCR0B = 0x0B;
    _delay_ms(750);
    TCCR0B = 0x00;
    _delay_ms(1250);
	
    ////
    
    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 36;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 47;
    TCCR0B = 0x0B;
    _delay_ms(500);
    TCCR0B = 0x00;
    _delay_ms(500);
    
    /////

    OCR0A = 40;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    
    OCR0A = 47;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 53;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
    
    OCR0A = 47;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);

    OCR0A = 60;
    TCCR0B = 0x0B;
    _delay_ms(250);
    TCCR0B = 0x00;
    _delay_ms(250);
	
    OCR0A = 80;
    TCCR0B = 0x0B;
    _delay_ms(750);
    TCCR0B = 0x00;
    _delay_ms(1250);
*/