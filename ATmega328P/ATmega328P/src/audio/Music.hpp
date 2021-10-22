/*
 *    NOTE        - Music.hpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.10.14
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#pragma once
#include "../modules/MCU.hpp"
#include "../core/Frame.hpp"

enum TonicSolFa
{
  DO, RE, MI, FA, SO, RA, SI
};


/*
//==========================================
              CLASS - Audio
==========================================//
*/

class Audio
{

public:
  Audio(){};
  ~Audio(){};

  void exportOCR(uint16_t OCRValue);
  void setOCR(bool isON);
  void setSound(int8_t tonicSolFa);

};

/*
//==========================================
              CLASS - Music
==========================================//
*/

class Music : private Audio
{

private:
  uint8_t m_SixteenBeat;
  bool m_IsFirst;
  bool m_IsSecond;

public:
  Music() { init(); }
  ~Music() { setOCR(OFF); }

  void title(void);
  void jump(void);
  void dead(void);
  void end(void) { setOCR(OFF); }
  void init(void) { m_SixteenBeat = 0; }

};