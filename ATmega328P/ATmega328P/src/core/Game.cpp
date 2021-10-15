/*
 *    NOTE        - Game.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.09.20
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "Game.hpp"


/*----------------------------------------//
              Game Title Loop
//----------------------------------------*/

void Game::titleLoop(void)
{

  while (1)
  {

    Frame::update();
    
    if (m_IsScore == true && m_IsCredit == false)
    {
      print(120, 30, "Score");

      print(70, 65, "1");
      printLetter(102, 65, firstName1st);
      printLetter(118, 65, firstName2nd);
      printLetter(134, 65, firstName3rd);
      print(166, 65, firstScore);

      print(70, 95, "2");
      printLetter(102, 95, secondName1st);
      printLetter(118, 95, secondName2nd);
      printLetter(134, 95, secondName3rd);
      print(166, 95, secondScore);

      print(70, 125, "3");
      printLetter(102, 125, thirdName1st);
      printLetter(118, 125, thirdName2nd);
      printLetter(134, 125, thirdName3rd);
      print(166, 125, thirdScore);

      print(70, 155, "4");
      printLetter(102, 155, fourthName1st);
      printLetter(118, 155, fourthName2nd);
      printLetter(134, 155, fourthName3rd);
      print(166, 155, fourthScore);

      print(70, 185, "5");
      printLetter(102, 185, fifthName1st);
      printLetter(118, 185, fifthName2nd);
      printLetter(134, 185, fifthName3rd);
      print(166, 185, fifthScore);

      _delay_ms(100);

      if (SW::interrupt0 == ON)
      {
        draw(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
        SW::interrupt0 = OFF;
        m_IsScore = false;
      }
    }

    else if (m_IsScore == false && m_IsCredit == true)
    {
      _delay_ms(100);

      if (SW::interrupt0 == ON)
      {
        draw(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
        SW::interrupt0 = OFF;
        m_IsCredit = false;
      }
    }

    else if (m_IsScore == false && m_IsCredit == false)
    {
      if (SW::up == ON)
      {
        m_Cursor -= 1;

        if (m_Cursor < 0)
        {
          m_Cursor = 0;
        }

        switch (m_Cursor)
        {
        case 0:
          clear(2, 160, 6, 14, BLACK);
          clear(2, 184, 6, 14, WHITE);

          break;

        case 1:
          clear(2, 160, 6, 14, WHITE);
          clear(2, 184, 6, 14, BLACK);
          clear(2, 208, 6, 14, WHITE);

          break;

        case 2:
          clear(2, 184, 6, 14, WHITE);
          clear(2, 208, 6, 14, BLACK);
          
          break;

        default:
          break;
        }

        _delay_ms(100);
        SW::up = OFF;
      }

      else if (SW::down == ON)
      {
        m_Cursor += 1;

        if (m_Cursor > 2)
        {
          m_Cursor = 2;
        }

        switch (m_Cursor)
        {
        case 0:
          clear(2, 160, 6, 14, BLACK);
          clear(2, 184, 6, 14, WHITE);

          break;

        case 1:
          clear(2, 160, 6, 14, WHITE);
          clear(2, 184, 6, 14, BLACK);
          clear(2, 208, 6, 14, WHITE);

          break;

        case 2:
          clear(2, 184, 6, 14, WHITE);
          clear(2, 208, 6, 14, BLACK);
          
          break;

        default:
          break;
        }

        _delay_ms(100);
        SW::down = OFF;
      }

      switch (m_Cursor)
      {
      case 0:
        if (SW::interrupt0 == ON)
        {
          SW::interrupt0 = OFF;
          return;
        }

        if (Frame::sixFrames == 0)
        {
          clear(2, 160, 6, 14, BLACK);
        }

        else if (Frame::sixFrames == 4)
        {
          clear(2, 160, 6, 14, WHITE);
        }

        break;

      case 1:
        if (SW::interrupt0 == ON)
        {
          clear(55, 20, 210, 200, BLACK);
          SW::interrupt0 = OFF;
          m_IsScore = true;
        }

        if (Frame::sixFrames == 0)
        {
          clear(2, 184, 6, 14, BLACK);
        }

        else if (Frame::sixFrames == 4)
        {
          clear(2, 184, 6, 14, WHITE);
        }

        break;

      case 2:
        if (SW::interrupt0 == ON)
        {
          clear(55, 20, 210, 200, BLACK);
          SW::interrupt0 = OFF;
          m_IsCredit = true;
        }

        if (Frame::sixFrames == 0)
        {
          clear(2, 208, 6, 14, BLACK);
        }

        else if (Frame::sixFrames == 4)
        {
          clear(2, 208, 6, 14, WHITE);
        }
        
        break;

      default:
        break;
      }
    }

  }

}

/*----------------------------------------//
              Game Start Loop
//----------------------------------------*/

void Game::startLoop(void)
{

  Player user;
  Object block1, block2, block3;
  Object star1(50, 70, bigStar, 30);
  Object star2(250, 80, smallStar1, 10);
  Object star3(150, 110, smallStar0, 3);

  print(16, 16, "Score:");
  draw(256, 32, 32, 32, moonTile, BLACK, WHITE);

  while (1)
  {

    star1.start();
    star2.start();
    star3.start();

    if (m_IsHighSpeed == false && Frame::scoreTime < 5)
    {
      block1.start();
    }

    else if (m_IsHighSpeed == false)
    {
      block1.start();
      block2.start();
    }

    else
    {
      block1.start();
      block2.start();
      block3.start();
    }

    if (m_IsReset == false)
    {
      if (m_ScoreTemp >= 200 && m_ScoreTemp < 211)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(4);
        block2.setSpeed(4);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 400 && m_ScoreTemp < 411)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(5);
        block2.setSpeed(5);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 600 && m_ScoreTemp < 611)
      {
        print(120, 40, "Speed+");
        block1.setSpeed(6);
        block2.setSpeed(6);

        m_IsReset = true;
        m_IsDrawed = true;
      }

      else if (m_ScoreTemp >= 1000 && m_ScoreTemp < 1011)
      {
        print(120, 40, "Block+");
        block1.setSpeed(7);
        block2.setSpeed(7);
        block3.setSpeed(7);
        user.setSpeed(8);

        m_IsReset = true;
        m_IsHighSpeed = true;
        m_IsDrawed = true;
      }
    }

    /*
    if (block1.isRolling == false || block2.isRolling == false)
    {
      block1.setSpeed(4);
      block2.setSpeed(4);
    }

    else
    {
      block1.setSpeed(6);
      block2.setSpeed(6);
    }
    */

    if (m_ScoreTemp != Frame::scoreTime)
    {
      m_ScoreTemp = Frame::scoreTime;
      print(120, 16, Frame::scoreTime);
      SW::start = OFF;

      if (m_IsDrawed == true)
      {
        m_Temp ++;

        if (m_IsReset == false && m_Temp > 5)
        {
          m_Temp = 0;
          clear(120, 40, 96, 16, BLACK);
          m_IsDrawed = false;
        }

        else if (m_IsReset == true && m_Temp > 10)
        {
          m_Temp = 0;
          clear(120, 40, 96, 16, BLACK);
          m_IsReset = false;
          m_IsDrawed = false;
        }
      }
    }

    if (user.isJump == false)
    {
      if (block1.xPosition < 75 && block1.xPosition > 40)
      {
        if (block1.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block1.isRolling = false;
          block1.isPresent = false;
          block1.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }

      if (block2.xPosition < 75 && block2.xPosition > 40)
      {
        if (block2.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block2.isRolling = false;
          block2.isPresent = false;
          block2.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }

      if (block3.xPosition < 75 && block3.xPosition > 40)
      {
        if (block3.isPresent == true)
        {
          clear(80, 160, 20, 20, BLACK);
          clear(120, 40, 96, 16, BLACK);
          print(120, 40, "+10");
          Frame::scoreTime += 10;
          m_IsDrawed = true;

          block3.isRolling = false;
          block3.isPresent = false;
          block3.init();
        }

        else
        {
          print(90, 100, "GAME OVER");
          _delay_ms(2000);
          m_IsReset = true;
          return;
        }
      }
    }

    if (SW::select == OFF)
    {
      Frame::update();
      user.start();
    }

    else
    {
      print(120, 100, "Pause");

      if (SW::start == ON)
      {
        print(120, 100, "Ready");
        _delay_ms(1500);

        for (int i=0; i<5; i++)
        {
          print(120, 100, "Start");
          _delay_ms(100);
          clear(120, 100, 80, 16, BLACK);
          _delay_ms(100);
        }

        SW::init();
      }
    }

  }

}

/*----------------------------------------//
              Game End Loop
//----------------------------------------*/

void Game::endLoop(void)
{

  clear(55, 20, 210, 200, BLACK);
  print(80, 50, "Name Score");
  print(166, 100, m_ScoreTemp);
  tempName1st = 0x41;
  tempName2nd = 0x41;
  tempName3rd = 0x41;
  m_Temp = 0x41;

  while (1)
  {

    Frame::update();

    printLetter(102, 100, tempName1st);
    printLetter(118, 100, tempName2nd);
    printLetter(134, 100, tempName3rd);

    if (SW::left == ON)
    {
      m_Temp -= 1;

      if (m_Temp < 0x41)
      {
        m_Temp = 0x5A;
      }

      _delay_ms(100);
      SW::left = OFF;
    }

    else if (SW::right == ON)
    {
      m_Temp += 1;

      if (m_Temp > 0x5A)
      {
        m_Temp = 0x41;
      }

      _delay_ms(100);
      SW::right = OFF;
    }

    else if (SW::select == ON)
    {
      m_Temp = 0x41;
      m_Cursor += 1;

      if (m_Cursor > 3)
      {
        m_Cursor = 3;
      }

      switch (m_Cursor)
      {
      case 0:
        clear(102, 120, 16, 8, WHITE);
        clear(118, 120, 16, 8, BLACK);

        break;

      case 1:
        clear(102, 120, 16, 8, BLACK);
        clear(118, 120, 16, 8, WHITE);
        clear(134, 120, 16, 8, BLACK);

        break;

      case 2:
        clear(118, 120, 16, 8, BLACK);
        clear(134, 120, 16, 8, WHITE);

        break;

      case 3:
        clear(134, 120, 16, 8, BLACK);

      default:
        break;
      }

      _delay_ms(100);
      SW::start = OFF;
      SW::select = OFF;
    }

    switch (m_Cursor)
    {
    case 0:
      tempName1st = m_Temp;

      if (Frame::sixFrames == 0)
      {
        clear(102, 120, 16, 8, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(102, 120, 16, 8, WHITE);
      }

      break;

    case 1:
      tempName2nd = m_Temp;

      if (Frame::sixFrames == 0)
      {
        clear(118, 120, 16, 8, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(118, 120, 16, 8, WHITE);
      }

      break;

    case 2:
      tempName3rd = m_Temp;

      if (Frame::sixFrames == 0)
      {
        clear(134, 120, 16, 8, BLACK);
      }

      else if (Frame::sixFrames == 4)
      {
        clear(134, 120, 16, 8, WHITE);
      }

      break;

    case 3:
      if (SW::start == ON)
      {
        return;
      }

    default:
      break;
    }

  }

}

/*----------------------------------------//
                Game title
//----------------------------------------*/

void Game::title(void)
{

  if (m_IsReset == false)
  {
    begin();
    setRotation(0);

    fillScreen(WHITE);
    draw(8, 70, 304, 96, logoAtmel, BLACK, RED, BLUE, WHITE);
    _delay_ms(3000);

    setFont(fontASCII);
    setColor(BLACK, WHITE);

    m_IsReset = true;
  }

  readScore();

  if (checkReset != 0x01)
  {
    resetScore();
    readScore();
  }

  fillScreen(BLACK);
  draw(0, 16, 320, 224, titleMenu, BLACK, MAROON, RED, WHITE);
  _delay_ms(100);

  SW::init();
  Frame::init();
  Game::init();
  titleLoop();

}

/*----------------------------------------//
                Game Start
//----------------------------------------*/

void Game::start(void)
{

  fillScreen(BLACK);
  draw(40, 140, 40, 40, charStand, BLACK, MAROON, RED, WHITE);

  print(120, 100, "Ready");
  _delay_ms(1500);

  for (int i=0; i<5; i++)
  {
    print(120, 100, "Start");
    _delay_ms(100);
    clear(120, 100, 80, 16, BLACK);
    _delay_ms(100);
  }
  
  for (int j=0; j<5; j++)
  {
    draw(64 * j, 180, 64, 48, groundTile, BLACK, BROWN, MAROON, WHITE);
  }

  SW::init();
  Frame::init();
  Game::init();
  startLoop();

}

/*----------------------------------------//
                  Game End
//----------------------------------------*/

void Game::end(void)
{

  if (m_ScoreTemp > fifthScore)
  {
    for (int i=0; i<4; i++)
    {
      print(90, 100, "NEW SCORE");
      _delay_ms(250);
      clear(90, 100, 144, 16, BLACK);
      _delay_ms(250);
    }

    SW::init();
    Frame::init();
    endLoop();

    if (m_ScoreTemp > firstScore)
    {
      eeprom_update_word((uint16_t*)10, m_ScoreTemp);
      eeprom_update_byte((uint8_t*)110, tempName1st);
      eeprom_update_byte((uint8_t*)111, tempName2nd);
      eeprom_update_byte((uint8_t*)112, tempName3rd);
      eeprom_update_byte((uint8_t*)113, 0x00);
    }

    else if (m_ScoreTemp > secondScore)
    {
      eeprom_update_word((uint16_t*)20, m_ScoreTemp);
      eeprom_update_byte((uint8_t*)120, tempName1st);
      eeprom_update_byte((uint8_t*)121, tempName2nd);
      eeprom_update_byte((uint8_t*)122, tempName3rd);
      eeprom_update_byte((uint8_t*)123, 0x00);
    }

    else if (m_ScoreTemp > thirdScore)
    {
      eeprom_update_word((uint16_t*)30, m_ScoreTemp);
      eeprom_update_byte((uint8_t*)130, tempName1st);
      eeprom_update_byte((uint8_t*)131, tempName2nd);
      eeprom_update_byte((uint8_t*)132, tempName3rd);
      eeprom_update_byte((uint8_t*)133, 0x00);
    }

    else if (m_ScoreTemp > fourthScore)
    {
      eeprom_update_word((uint16_t*)40, m_ScoreTemp);
      eeprom_update_byte((uint8_t*)140, tempName1st);
      eeprom_update_byte((uint8_t*)141, tempName2nd);
      eeprom_update_byte((uint8_t*)142, tempName3rd);
      eeprom_update_byte((uint8_t*)143, 0x00);
    }

    else if (m_ScoreTemp > fifthScore)
    {
      eeprom_update_word((uint16_t*)50, m_ScoreTemp);
      eeprom_update_byte((uint8_t*)150, tempName1st);
      eeprom_update_byte((uint8_t*)151, tempName2nd);
      eeprom_update_byte((uint8_t*)152, tempName3rd);
      eeprom_update_byte((uint8_t*)153, 0x00);
    }
  }

}

/*----------------------------------------//
                Reset Score
//----------------------------------------*/

void Game::resetScore(void)
{

  eeprom_update_word((uint16_t*)10, 2000);
  eeprom_update_word((uint16_t*)20, 1000);
  eeprom_update_word((uint16_t*)30, 800);
  eeprom_update_word((uint16_t*)40, 600);
  eeprom_update_word((uint16_t*)50, 400);

  eeprom_update_byte((uint8_t*)110, 0x4B);
  eeprom_update_byte((uint8_t*)111, 0x50);
  eeprom_update_byte((uint8_t*)112, 0x4F);
  eeprom_update_byte((uint8_t*)113, 0x00);
    
  eeprom_update_byte((uint8_t*)120, 0x41);
  eeprom_update_byte((uint8_t*)121, 0x42);
  eeprom_update_byte((uint8_t*)122, 0x43);
  eeprom_update_byte((uint8_t*)123, 0x00);
    
  eeprom_update_byte((uint8_t*)130, 0x44);
  eeprom_update_byte((uint8_t*)131, 0x45);
  eeprom_update_byte((uint8_t*)132, 0x46);
  eeprom_update_byte((uint8_t*)133, 0x00);
    
  eeprom_update_byte((uint8_t*)140, 0x47);
  eeprom_update_byte((uint8_t*)141, 0x48);
  eeprom_update_byte((uint8_t*)142, 0x49);
  eeprom_update_byte((uint8_t*)143, 0x00);
    
  eeprom_update_byte((uint8_t*)150, 0x4A);
  eeprom_update_byte((uint8_t*)151, 0x4B);
  eeprom_update_byte((uint8_t*)152, 0x4C);
  eeprom_update_byte((uint8_t*)153, 0x00);

  eeprom_update_byte((uint8_t*)200, 0x01);

}

/*----------------------------------------//
                Read Score
//----------------------------------------*/

void Game::readScore(void)
{

  firstScore = eeprom_read_word((uint16_t*)10);
  secondScore = eeprom_read_word((uint16_t*)20);
  thirdScore = eeprom_read_word((uint16_t*)30);
  fourthScore = eeprom_read_word((uint16_t*)40);
  fifthScore = eeprom_read_word((uint16_t*)50);

  firstName1st = eeprom_read_byte((uint8_t*)110);
  firstName2nd = eeprom_read_byte((uint8_t*)111);
  firstName3rd = eeprom_read_byte((uint8_t*)112);
  firstMode = eeprom_read_byte((uint8_t*)113);

  secondName1st = eeprom_read_byte((uint8_t*)120);
  secondName2nd = eeprom_read_byte((uint8_t*)121);
  secondName3rd = eeprom_read_byte((uint8_t*)122);
  secondMode = eeprom_read_byte((uint8_t*)123);

  thirdName1st = eeprom_read_byte((uint8_t*)130);
  thirdName2nd = eeprom_read_byte((uint8_t*)131);
  thirdName3rd = eeprom_read_byte((uint8_t*)132);
  thirdMode = eeprom_read_byte((uint8_t*)133);

  fourthName1st = eeprom_read_byte((uint8_t*)140);
  fourthName2nd = eeprom_read_byte((uint8_t*)141);
  fourthName3rd = eeprom_read_byte((uint8_t*)142);
  fourthMode = eeprom_read_byte((uint8_t*)143);

  fifthName1st = eeprom_read_byte((uint8_t*)150);
  fifthName2nd = eeprom_read_byte((uint8_t*)151);
  fifthName3rd = eeprom_read_byte((uint8_t*)152);
  fifthMode = eeprom_read_byte((uint8_t*)153);

  checkReset = eeprom_read_byte((uint8_t*)200);

}