/*
 *    NOTE        - TFT.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.17
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "MCU.hpp"

#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0,  15 */
#define DARKGREEN   0x03E0      /*   0,  31,   0 */
#define DARKCYAN    0x03EF      /*   0,  31,  15 */
#define MAROON      0x7800      /*  15,   0,   0 */
#define PURPLE      0x780F      /*  15,   0,  15 */
#define OLIVE       0x7BE0      /*  15,  31,   0 */
#define LIGHTGREY   0xC618      /*  24,  48,  24 */
#define DARKGREY    0x7BEF      /*  15,  31,  15 */
#define BLUE        0x001F      /*   0,   0,  31 */
#define GREEN       0x07E0      /*   0,  63,   0 */
#define CYAN        0x07FF      /*   0,  63,  31 */
#define RED         0xF800      /*  31,   0,   0 */
#define MAGENTA     0xF81F      /*  31,   0,  31 */
#define YELLOW      0xFFE0      /*  31,  63,   0 */
#define WHITE       0xFFFF      /*  31,  63,  31 */
#define ORANGE      0xFD20      /*  31,  41,   0 */
#define GREENYELLOW 0xAFE5      /*  21,  63,   5 */
#define PINK        0xF81F      /*  31,   0,  31 */


/*
//==========================================
                CLASS - SPI
==========================================//
*/

class SPI
{

private:
  int8_t m_CS;
  int8_t m_RST;
  int8_t m_RS;
  int8_t m_MOSI;
  int8_t m_SCK;

public:
  SPI(int8_t _CS, int8_t _RST, int8_t _RS, int8_t _MOSI, int8_t _SCK);
  ~SPI(){};

  void CS_HIGH(void) { PORTB |= (1 << m_CS); }
  void CS_LOW(void) { PORTB &= ~(1 << m_CS); }
  void RST_HIGH(void) { PORTB |= (1 << m_RST); }
  void RST_LOW(void) { PORTB &= ~(1 << m_RST); }
  void RS_HIGH(void) { PORTB |= (1 << m_RS); }
  void RS_LOW(void) { PORTB &= ~(1 << m_RS); }

  void sendBit(uint8_t bitValue);
  void exportCommand(uint8_t commandValue);
  void exportData(uint8_t dataValue);
  void exportLongData(uint16_t longDataValue);

};


/*
//==========================================
            CLASS - TFT LCD
==========================================//
*/

class TFT : public SPI
{

private:
  int16_t m_Width;
  int16_t m_Height;
  int16_t m_Temp;

public:
  TFT(int8_t _CS, int8_t _RST, int8_t _RS, int8_t _MOSI, int8_t _SCK)
    : SPI(_CS, _RST, _RS, _MOSI, _SCK){};
  ~TFT(){};

  void begin(int16_t TFTWidth, int16_t TFTHeight);
  void setRotation(uint8_t rotation);
  void setAddress(int16_t xPos, int16_t yPos, int16_t width, int16_t height);
  void fillScreen(uint16_t colorValue);
  void drawPixel(int16_t xPos, int16_t yPos, uint16_t colorValue);
  void drawRect(int16_t xPos, int16_t yPos, int16_t width, int16_t height, uint16_t colorValue);
  //void drawImage();
  //void drawImageRotate();

};