/*
 *    NOTE        - TFT.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "TFT.hpp"


/*----------------------------------------//
              Send Serial Bit
//----------------------------------------*/

void SPI::sendBit(uint8_t bitValue)
{
  SPDR = bitValue;
  while (!(SPSR & 0x80));
}

/*----------------------------------------//
              Export Command
//----------------------------------------*/

void SPI::exportCommand(uint8_t commandValue)
{
  RS_LOW;
  CS_LOW;

  sendBit(commandValue);

  CS_HIGH;
}

/*----------------------------------------//
              Export Data
//----------------------------------------*/

void SPI::exportData(uint8_t dataValue)
{
  RS_HIGH;
  CS_LOW;

  sendBit(dataValue);

  CS_HIGH;
}

/*----------------------------------------//
            Export Long Data
//----------------------------------------*/

void SPI::exportLongData(uint16_t longDataValue)
{
  RS_HIGH;
  CS_LOW;

  sendBit(longDataValue >> 8);
  sendBit(longDataValue & 0xFF);

  CS_HIGH;
}


/*----------------------------------------//
              Begin TFT LCD
//----------------------------------------*/

void TFT::begin(void)
{
  CS_HIGH;
  RST_LOW;
  _delay_ms(20);
  RST_HIGH;
  _delay_ms(500);

  exportCommand(0x01);  // Software Reset (01h)
  _delay_ms(20);

  exportCommand(0xC0);  // Power Control 1 (C0h)
  exportData(0x2B);     // VRH [5:0], GVDD 5.00V

  exportCommand(0x36);  // Memory Access Control (36h)
  exportData(0x48);     // Column Address Order, RGB-BGR Order

  exportCommand(0x3A);  // COLMOD: Pixel Format Set (3Ah)
  exportData(0x55);     // DBI [2:0], Format 16 bits / pixel

  exportCommand(0x20);  // Display Inversion OFF (20h)

  exportCommand(0x11);  // Sleep Out (11h)
  _delay_ms(60);

  exportCommand(0x29);  // Display ON (29h)
}

/*----------------------------------------//
              Set Rotation
//----------------------------------------*/

void TFT::setRotation(int8_t rotation)
{
  
  int16_t temp;

  exportCommand(0x36);  // Memory Access Control (36h)

  switch (rotation)
  {
  case 0:
    exportData(0x28);   // Row / Column Exchange, RGB-BGR Order
    temp = m_Width;
    m_Width = m_Height;
    m_Height = temp;
    break;

  case 1:
    exportData(0x48);   // Column Address Order, RGB-BGR Order
    break;

  case 2:
    exportData(0x88);   // Row Address Order, RGB-BGR Order
    break;

  default:
    break;
  }

}

/*----------------------------------------//
              Set Address
//----------------------------------------*/

void TFT::setAddress(int16_t xPos, int16_t yPos, int16_t width, int16_t height)
{
  exportCommand(0x2A);    // Column Address Set (2Ah)

  exportLongData(xPos);   // xPosition
  exportLongData(width);

  exportCommand(0x2B);    // Page Address Set (2Bh)

  exportLongData(yPos);   // yPosition
  exportLongData(height);

  exportCommand(0x2C);    // Memory Write (2Ch)
}

/*----------------------------------------//
                Fill Screen
//----------------------------------------*/

void TFT::fillScreen(uint16_t colorValue)
{

  setAddress(0, 0, (m_Width - 1), (m_Height - 1));

  for (int i=0; i<m_Height; i++)
  {
    for (int j=0; j<m_Width; j++)
    {
      exportLongData(colorValue);
    }
  }

}

/*----------------------------------------//
                Fill Rect
//----------------------------------------*/

void TFT::clear(int16_t xPos, int16_t yPos, int16_t width, int16_t height, uint16_t colorValue)
{

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int yPos=height; yPos>0; yPos--)
  {
    for (int xPos=width; xPos>0; xPos--)
    {
      exportLongData(colorValue);
    }
  }

}

/*----------------------------------------//
                Draw Bitmap
//----------------------------------------*/
/*
void TFT::drawBitmapOnce(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap,
  uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3)
{

  uint8_t data;
  uint8_t temp;

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int i=0; i<height; i++)
  {
    for (int j=0; j<(width / 4); j++)
    {

      data = pgm_read_byte(&bitmap[i * (width / 4) + j]);

      for (int k=0; k<4; k++)
      {
        temp = data >> 6;

        if (temp == 0x00)       //1Pixel = 00
        {
          exportLongData(color0);
        }

        else if (temp == 0x01)  //1Pixel = 01
        {
          exportLongData(color1);
        }

        else if (temp == 0x02)  //1Pixel = 10
        {
          exportLongData(color2);
        }

        else if (temp == 0x03)  //1Pixel = 11
        {
          exportLongData(color3);
        }

        data <<= 2;
      }

    }
  }

}
*/

/*----------------------------------------//
                Draw Bitmap
//----------------------------------------*/

void TFT::draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap,
  uint16_t color0, uint16_t color1)
{

  uint8_t data;
  uint8_t temp;

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int i=0; i<(height / 2); i++)
  {
    for (int j=0; j<2; j++)
    {
      for (int k=0; k<(width / 16); k++)
      {

        data = pgm_read_byte(&bitmap[i * (width / 16) + k]);

        for (int l=0; l<8; l++)
        {
          temp = data >> 7;

          for (int m=0; m<2; m++)
          {

            if (temp == 0x00)       //1Pixel = 0
            {
              exportLongData(color0);
            }

            else                    //1Pixel = 1
            {
              exportLongData(color1);
            }

          }

          data <<= 1;
        }

      }
    }
  }

}

/*----------------------------------------//
                Draw Bitmap
//----------------------------------------*/

void TFT::draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap,
  uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3)
{

  uint8_t data;
  uint8_t temp;

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int i=0; i<(height / 2); i++)
  {
    for (int j=0; j<2; j++)
    {
      for (int k=0; k<(width / 8); k++)
      {

        data = pgm_read_byte(&bitmap[i * (width / 8) + k]);

        for (int l=0; l<4; l++)
        {
          temp = data >> 6;

          for (int m=0; m<2; m++)
          {

            if (temp == 0x00)       //1Pixel = 00
            {
              exportLongData(color0);
            }

            else if (temp == 0x01)  //1Pixel = 01
            {
              exportLongData(color1);
            }

            else if (temp == 0x02)  //1Pixel = 10
            {
              exportLongData(color2);
            }

            else if (temp == 0x03)  //1Pixel = 11
            {
              exportLongData(color3);
            }

          }

          data <<= 2;
        }

      }
    }
  }

}

/*----------------------------------------//
            Draw 100bytes Bitmap
//----------------------------------------*/

void TFT::draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const unsigned char (*bitmap)[100], int8_t tileSelection,
  uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3)
{

  uint8_t data;
  uint8_t temp;

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int i=0; i<(height / 2); i++)
  {
    for (int j=0; j<2; j++)
    {
      for (int k=0; k<(width / 8); k++)
      {

        data = pgm_read_byte(&bitmap[tileSelection][i * (width / 8) + k]);

        for (int l=0; l<4; l++)
        {
          temp = data >> 6;

          for (int m=0; m<2; m++)
          {

            if (temp == 0x00)       //1Pixel = 00
            {
              exportLongData(color0);
            }

            else if (temp == 0x01)  //1Pixel = 01
            {
              exportLongData(color1);
            }

            else if (temp == 0x02)  //1Pixel = 10
            {
              exportLongData(color2);
            }

            else if (temp == 0x03)  //1Pixel = 11
            {
              exportLongData(color3);
            }

          }

          data <<= 2;
        }

      }
    }
  }

}


/*----------------------------------------//
            Draw 160bytes Bitmap
//----------------------------------------*/

void TFT::draw(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const unsigned char (*bitmap)[160], int8_t tileSelection,
  uint16_t color0, uint16_t color1, uint16_t color2, uint16_t color3)
{

  uint8_t data;
  uint8_t temp;

  setAddress(xPos, yPos, (xPos + width - 1), (yPos + height - 1));

  for (int i=0; i<(height / 2); i++)
  {
    for (int j=0; j<2; j++)
    {
      for (int k=0; k<(width / 8); k++)
      {

        data = pgm_read_byte(&bitmap[tileSelection][i * (width / 8) + k]);

        for (int l=0; l<4; l++)
        {
          temp = data >> 6;

          for (int m=0; m<2; m++)
          {

            if (temp == 0x00)       //1Pixel = 00
            {
              exportLongData(color0);
            }

            else if (temp == 0x01)  //1Pixel = 01
            {
              exportLongData(color1);
            }

            else if (temp == 0x02)  //1Pixel = 10
            {
              exportLongData(color2);
            }

            else if (temp == 0x03)  //1Pixel = 11
            {
              exportLongData(color3);
            }

          }

          data <<= 2;
        }

      }
    }
  }

}