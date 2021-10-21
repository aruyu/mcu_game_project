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
  int16_t m_Width;
  int16_t m_Height;
  int8_t m_Temp;
  int8_t m_rollTemp;
  int8_t m_clearTemp;

  int8_t m_MoveTemp;
  int8_t m_MoveSpeed;
  int16_t m_MoveDistance;
  uint8_t m_RandomNumber;
  
  bool m_IsBlock;
  bool m_IsReset;
  bool m_IsDrawed;
  bool m_IsClearDrawed;

  void ball(void);
  void bomb(void);
  void present(void);
  void rollBlock(void);
  void rollBackground(void);

public:
  Object() : TFT() { m_MoveSpeed = 3; m_IsBlock = true; m_IsReset = false; isRolling = false; isPresent = false; init(); }
  Object(int16_t width, int16_t height, const uint8_t *bitmap, int8_t speed) : TFT() { m_MoveSpeed = speed; m_IsBlock = false; m_IsReset = false; isRolling = false;
    m_Bitmap = bitmap; m_Width = width; m_Height = height; }

  ~Object(){};

  void init(void);
  void start(void);
  void setSpeed(int8_t speed) { m_MoveSpeed = speed; }
  void clearObject(void);

  int16_t xPosition;
  bool isRolling;
  bool isPresent;

};