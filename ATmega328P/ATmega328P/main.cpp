/*
 *    NOTE        - main.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "src/modules/MCU.hpp"
#include "src/core/Game.hpp"

using namespace MCU::Setting;

ISR(TIMER1_COMPA_vect);
ISR(TIMER2_COMPA_vect);

Game game;


/*========================================//
--------------  MAIN START  --------------
//========================================*/

int main(void)
{
  beginPort(B, OUT);
  beginPort(D, OUT);
  beginTimer(1, COMP);
  beginTimer(2, COMP);
  beginPWM(OC0A, FAST);
  beginSPI();
  sei();

  TCCR0B = 0x00;

  game.title();

  while (1)
  {
    game.start();
  }

  return 0;
}

/*========================================//
---------------  MAIN END  ---------------
//========================================*/


ISR(TIMER1_COMPA_vect)
{
  Frame::secondTime++;
}

ISR(TIMER2_COMPA_vect)
{
  Frame::presentTime++;
}

  /*
  ISR(PCINT0_vect)
  {
    if (SW_ == 0)
    {
      SW_ = 1;
    }
    
    else
    {
      SW_ = 0;
    }
  }*/