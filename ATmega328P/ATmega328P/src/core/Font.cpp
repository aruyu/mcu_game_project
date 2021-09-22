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
  int16_t ASCIIValue = ASCII - 32;
  ASCIIValue = (ASCIIValue / 16) * 128 + (ASCIIValue % 16);

  setAddress(xPos, yPos, (xPos + 15), (yPos + 15));

  for (int i=0; i<(16 / 2); i++)
  {
    for (int j=0; j<2; j++)
    {

      data = pgm_read_byte(&m_Bitmap[(i * 16) + ASCIIValue]);

      for (int k=0; k<8; k++)
      {
        temp = data >> 7;

        for (int l=0; l<2; l++)
        {

          if (temp == 0x00)       //1Pixel = 0
          {
            exportLongData(m_Background);
          }

          else                    //1Pixel = 1
          {
            exportLongData(m_Colored);
          }

        }

        data <<= 1;
      }

    }
  }

}

/*----------------------------------------//
              Print String
//----------------------------------------*/

void Font::print(int16_t xPos, int16_t yPos, const char *stringValue)
{

  while (*stringValue != '\0')
  {
    printLetter(xPos, yPos, *stringValue);
    stringValue++;
    xPos += 16;
  }

}