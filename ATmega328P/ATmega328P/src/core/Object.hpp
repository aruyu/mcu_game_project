/*
 *    NOTE        - Object.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"
#include "../modules/TFT.hpp"
#include "../assets/ObjectTiles.hpp"

#include "Frame.hpp"


/*
//==========================================
              CLASS - Object
==========================================//
*/

class Object : private TFT
{

private:
  const uint8_t *m_Bitmap;
  int16_t m_ObjectWidth;
  int16_t m_ObjectHeight;

  int8_t m_MoveSpeed;
  int8_t m_MoveTemp;
  int16_t m_MoveDistance;
  int8_t m_RandomNumber;

  bool m_IsReset;
  bool m_IsNomal;
  bool m_IsRolling;
  bool m_IsDrawed;

  void ball(void);
  void bomb(void);
  void present(void);
  
  void rolling(void);
  void disappear(void);
  void setPosition(int16_t xPos, int16_t yPos) { xPosition = xPos; yPosition = yPos; }

public:
  Object() : TFT() { m_MoveSpeed = 4; m_IsNomal = false; m_IsRolling = false; }
  Object(const uint8_t *bitmap, int8_t speed) : TFT() { m_Bitmap = bitmap; m_MoveSpeed = speed; m_IsNomal = true; }
  ~Object(){};

  void start(void);
  void init(void);

  int16_t xPosition;
  int16_t yPosition;

};