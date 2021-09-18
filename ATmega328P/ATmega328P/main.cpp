/*
 *    NOTE        - main.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Modules/MCU.hpp"
#include "Modules/TFT.hpp"

using namespace MCU::Setting;

TFT tft(240, 320);


/*========================================//
--------------  MAIN START  --------------
//========================================*/

int main(void)
{
  beginPort(B, OUT);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  tft.drawRect(70, 0, 88, 31, RED);
  tft.drawRect(70, 70, 45, 31, GREEN);
  tft.drawRect(70, 140, 71, 31, BLUE);
  _delay_ms(5000);

  while (1)
  {
    tft.fillScreen(RED);
    _delay_ms(500);

    tft.fillScreen(ORANGE);
    _delay_ms(500);

    tft.fillScreen(YELLOW);
    _delay_ms(500);

    tft.fillScreen(GREEN);
    _delay_ms(500);

    tft.fillScreen(BLUE);
    _delay_ms(500);
  }

  return 0;
}

/*========================================//
---------------  MAIN END  ---------------
//========================================*/