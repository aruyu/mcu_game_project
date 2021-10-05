/*
 *    NOTE        - main.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "src/core/Game.hpp"
using namespace MCU::Setting;

ISR(INT0_vect);
//ISR(INT1_vect);
ISR(TIMER1_COMPA_vect);
ISR(TIMER2_COMPA_vect);

Game game;
SW sw;


/*========================================//
--------------  MAIN START  --------------
//========================================*/

int main(void)
{
  beginPort(B, OUT);
  beginPort(C, IN);
  beginPin(D, 6);

  beginINT(0, DOWN);
  //beginINT(1, DOWN);
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
  sw.update();

  switch (sw.result)
  {
  case SW_UP:
    sw.up = ON;
    break;
  
  case SW_DOWN:
    sw.down = ON;
    break;

   default:
    break;
  }
}

ISR(TIMER2_COMPA_vect)
{
  Frame::presentTime++;
}


ISR(INT0_vect)
{
  SW::interrupt0 = ON;
}