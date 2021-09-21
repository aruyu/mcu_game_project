/*
 *    NOTE        - Font.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.21
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Font.hpp"


/*----------------------------------------//
              Print 8x8 Letter
//----------------------------------------*/

void Font::printLetter(int16_t xPos, int16_t yPos, uint8_t ASCII)
{

  uint8_t data;
  uint8_t temp;

  
  setAddress(xPos, yPos, (xPos + 7), (yPos + 7));

  for (int i = 0; i < 8; i++)
  {

    data = pgm_read_byte( &m_Bitmap[i + ( (ASCII/16) * 8 ) + ( (ASCII%16) * 8 ) ]);

    for (int j = 0; j < 8; j++)
    {
      temp = data >> 7;

      if (temp == 0x00)
      {
        exportLongData(m_Background); //1Pixel = 0
      }

      else
      {
        exportLongData(m_Colored); //1Pixel = 1
      }

      data <<= 1;
    }

  }

}