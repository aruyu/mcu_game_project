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

enum MusicMode
{
  TITLE, START, JUMP
};


/*
//==========================================
              CLASS - Audio
==========================================//
*/

class Audio
{

private:
  void exportOCR(uint16_t OCRValue);

public:
  Audio(){};
  ~Audio(){};

  void setSound(bool isON);
  void setTonicSolFa(int8_t tonicSolFa);

};

/*
//==========================================
              CLASS - Music
==========================================//
*/

class Music : private Audio
{

private:
  int8_t m_MusicMode;
  uint8_t m_SixteenBeat;

  void titleMusic(void);
  void startingMusic(void);
  void jumpingMusic(void);

public:
  Music(int8_t mode) { m_MusicMode = mode; m_SixteenBeat = 0; isPlay = false; }
  Music(int8_t mode, bool start) { m_MusicMode = mode; m_SixteenBeat = 0; isPlay = true; }
  ~Music() { setSound(OFF); }

  void start(void);
  void pause(void) { setSound(OFF); }

  bool isPlay;

};