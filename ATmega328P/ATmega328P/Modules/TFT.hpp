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

#define _CS 0
#define _RST 1
#define _RS 2
#define _MOSI 3
#define _SCK 5

#define CS_HIGH (PORTB |= (1 << _CS))
#define CS_LOW (PORTB &= ~(1 << _CS))
#define RST_HIGH (PORTB |= (1 << _RST))
#define RST_LOW (PORTB &= ~(1 << _RST))
#define RS_HIGH (PORTB |= (1 << _RS))
#define RS_LOW (PORTB &= ~(1 << _RS))

#define BLACK 0x0000       /*   0,   0,   0 */
#define NAVY 0x000F        /*   0,   0,  15 */
#define DARKGREEN 0x03E0   /*   0,  31,   0 */
#define DARKCYAN 0x03EF    /*   0,  31,  15 */
#define MAROON 0x7800      /*  15,   0,   0 */
#define PURPLE 0x780F      /*  15,   0,  15 */
#define OLIVE 0x7BE0       /*  15,  31,   0 */
#define LIGHTGREY 0xC618   /*  24,  48,  24 */
#define DARKGREY 0x7BEF    /*  15,  31,  15 */
#define BLUE 0x001F        /*   0,   0,  31 */
#define GREEN 0x07E0       /*   0,  63,   0 */
#define CYAN 0x07FF        /*   0,  63,  31 */
#define RED 0xF800         /*  31,   0,   0 */
#define MAGENTA 0xF81F     /*  31,   0,  31 */
#define YELLOW 0xFFE0      /*  31,  63,   0 */
#define WHITE 0xFFFF       /*  31,  63,  31 */
#define ORANGE 0xFD20      /*  31,  41,   0 */
#define GREENYELLOW 0xAFE5 /*  21,  63,   5 */
#define PINK 0xF81F        /*  31,   0,  31 */


/*
//==========================================
                CLASS - SPI
==========================================//
*/

class SPI
{

public:
  SPI() { SPCR = (1 << SPE) | (1 << MSTR); SPSR = (1 << SPI2X); };
  ~SPI(){};

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
  //uint16_t m_Cache[15][20];

public:
  TFT(int16_t TFTWidth, int16_t TFTHeight) : SPI() { m_Width = TFTWidth; m_Height = TFTHeight; };
  ~TFT(){};

  void begin(void);
  void setRotation(int8_t rotation);
  void setAddress(int16_t xPos, int16_t yPos, int16_t width, int16_t height);
  void fillScreen(uint16_t colorValue);
  void drawPixel(int16_t xPos, int16_t yPos, uint16_t colorValue);
  void drawRect(int16_t xPos, int16_t yPos, int16_t width, int16_t height, uint16_t colorValue);
  void draw1Bitmap(int16_t xPos, int16_t yPos, int16_t width, int16_t height, const uint8_t *bitmap, uint16_t color0Bit, uint16_t color1Bit);
  //void draw4Bitmap();
  //void setDraw(const uint8_t *cacheMap);
  //void startDraw(void);
  //void drawImageRotate();

};


// Only for scalability, Slow speed. //
/*
class SPI
{

private:
  int8_t m_CS;
  int8_t m_RST;
  int8_t m_RS;
  int8_t m_MOSI;
  int8_t m_SCK;

public:
  SPI(int8_t _CS, int8_t _RST, int8_t _RS, int8_t _MOSI, int8_t _SCK)
  {
    m_CS = _CS;
    m_RST = _RST;
    m_RS = _RS;
    m_MOSI = _MOSI;
    m_SCK = _SCK;
  }
  ~SPI(){};

  inline void CS_HIGH(void) { PORTB |= (1 << m_CS); }
  inline void CS_LOW(void) { PORTB &= ~(1 << m_CS); }
  inline void RST_HIGH(void) { PORTB |= (1 << m_RST); }
  inline void RST_LOW(void) { PORTB &= ~(1 << m_RST); }
  inline void RS_HIGH(void) { PORTB |= (1 << m_RS); }
  inline void RS_LOW(void) { PORTB &= ~(1 << m_RS); }

  void sendBit(uint8_t bitValue);
  void exportCommand(uint8_t commandValue);
  void exportData(uint8_t dataValue);
  void exportLongData(uint16_t longDataValue);

};

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
*/