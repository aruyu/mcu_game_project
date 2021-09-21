/*
 *    NOTE        - Font.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.21
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"
#include "../modules/TFT.hpp"
#include "../assets/Font.hpp"


/*
//==========================================
              CLASS - Player
==========================================//
*/

class Font : public TFT
{

private:
  const uint8_t *m_Bitmap;
  uint16_t m_Background;
  uint16_t m_Colored;

public:
  Font() : TFT(){};
  Font(const uint8_t *bitmap) : TFT() { &m_Bitmap = *bitmap; }
  ~Font(){};

  void setFont(const uint8_t *bitmap) { &m_Bitmap = *bitmap; }
  void printLetter(int16_t xPos, int16_t yPos, uint8_t ASCII);
  void print(const uint8_t *String);

};

