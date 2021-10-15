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
ISR(INT1_vect);
ISR(TIMER0_OVF_vect);
//ISR(TIMER1_COMPA_vect);
ISR(TIMER2_COMPA_vect);

Game game;


/*========================================//
--------------  MAIN START  --------------
//========================================*/

int main(void)
{
  beginPort(B, OUT);
  beginPort(C, IN);
  beginPin(D, 6);

  beginINT(0, DOWN);
  beginINT(1, DOWN);
  beginTimer(0, OVF);
  //beginTimer(1, COMP);
  beginTimer(2, COMP);

  beginSPI();
  sei();

  while (1)
  {
    game.title();
    game.start();
  }

  return 0;
}

/*========================================//
---------------  MAIN END  ---------------
//========================================*/


ISR(TIMER0_OVF_vect)
{
  SW::update();

  if (SW::result != SW_OFF)
  {
    switch (SW::result)
    {
    case SW_UP:
      SW::up = ON;
      break;
    
    case SW_DOWN:
      SW::down = ON;
      break;
    
    case SW_LEFT:
      SW::left = ON;
      break;
    
    case SW_RIGHT:
      SW::right = ON;
      break;
    
    case SW_START:
      SW::start = ON;
      break;
    
    case SW_SELECT:
      SW::select = ON;
      break;

    default:
      break;
    }
  }
}
/*
ISR(TIMER1_COMPA_vect)
{
  switch (PWM)
  {
  case ON:
    PWM = OFF;
    break;
  
  case OFF:
    PWM = ON;
    break;
  
  default:
    break;
  }
}
*/
ISR(TIMER2_COMPA_vect)
{
  Frame::presentTime++;
}

ISR(INT0_vect)
{
  SW::interrupt0 = ON;
}

ISR(INT1_vect)
{
  SW::interrupt1 = ON;
}