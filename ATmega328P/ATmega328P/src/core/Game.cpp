/*
 *    NOTE        - Game.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Game.hpp"


/*----------------------------------------//
                Game Title
//----------------------------------------*/

void Game::title(void)
{
  begin();
  setRotation(0);

  fillScreen(WHITE);
  drawBitmap(8, 70, 152, 48, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(500);

  drawBitmapTwice(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
  _delay_ms(3000);

  fillScreen(BLACK);
  setFont(fontASCII);
  setColor(BLACK, WHITE);
  print(30, 70, "Hello, World!");
  _delay_ms(1000);

  setColor(BLACK, CYAN);
  print(30, 120, "And Welcome to");
  setColor(BLACK, RED);
  print(30, 136, "Atmega Game (^0^)");
  _delay_ms(5000);
}

/*----------------------------------------//
                Start Game
//----------------------------------------*/

void Game::start(void)
{

  fillScreen(BLACK);
  _delay_ms(100);

  //Player user;

  while (1)
  {
    //Frame::updateFrame();
    //user.startPlayer();
	
	TCCR0B = 0x0D;
	
	for (int i=0; i<51; i++)
	{
		OCR0A = i;
		_delay_ms(1000);
	}

    
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
*/