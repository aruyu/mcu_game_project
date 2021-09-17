/*
 *    NOTE        - MCU.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.05.30
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "MCU.hpp"


/*----------------------------------------//
                Insert Bit
//----------------------------------------*/

uint8_t MCU::insertBit(uint8_t bitValue, bool isHigh)
{

  uint8_t highValue = 0x00;
  uint8_t lowValue = 0x00;

  if (isHigh == true)
  {
    return highValue |= (1 << bitValue);
  }

  else
  {
    return lowValue &= ~(1 << bitValue);
  }

}

/*----------------------------------------//
            Convert 10 to 16
//----------------------------------------*/

uint8_t MCU::Features::hex(uint8_t decimal)
{

  uint8_t hexadecimal = 0x00;

  if (decimal >= 0 && decimal <= 9)
  {
    return hexadecimal = decimal;
  }

  else if (decimal >= 10 && decimal <= 19)
  {
    return hexadecimal = decimal + 6;
  }

  else if (decimal >= 20 && decimal <= 29)
  {
    return hexadecimal = decimal + 12;
  }

  else if (decimal >= 30 && decimal <= 39)
  {
    return hexadecimal = decimal + 18;
  }

  else if (decimal >= 40 && decimal <= 49)
  {
    return hexadecimal = decimal + 24;
  }

  else if (decimal >= 50 && decimal <= 59)
  {
    return hexadecimal = decimal + 30;
  }

  else if (decimal >= 60 && decimal <= 69)
  {
    return hexadecimal = decimal + 36;
  }

  else if (decimal >= 70 && decimal <= 79)
  {
    return hexadecimal = decimal + 42;
  }

  else if (decimal >= 80 && decimal <= 89)
  {
    return hexadecimal = decimal + 48;
  }

  else if (decimal >= 90 && decimal <= 99)
  {
    return hexadecimal = decimal + 54;
  }

}

/*----------------------------------------//
            Convert 10 to ASKII
//----------------------------------------*/

uint8_t MCU::Features::ASKII(uint8_t decimal)
{

  int ASKIIValue = 0x00;

  if (decimal >= 0 && decimal <= 9)
  {
    return ASKIIValue = decimal + 0x30;
  }

}

/*----------------------------------------//
                Begin Port
//----------------------------------------*/

void MCU::Setting::beginPort(uint8_t port, bool isOutput)
{

  int ddrValue;
  int portValue;

    // INPUT or OUTPUT
  if (isOutput == true)
  {
    ddrValue = 0xFF;
    portValue = 0x00;
  }

  else
  {
    ddrValue = 0x00;
  }

  switch (port)
  {
    // PORTB
  case B:
    DDRB = ddrValue;
    PORTB = portValue;
    break;

    // PORTC
  case C:
    DDRC = ddrValue;
    PORTC = portValue;
    break;

    // PORTD
  case D:
    DDRD = ddrValue;
    PORTD = portValue;
    break;

  default:
    break;
  }

}

/*----------------------------------------//
        Begin Extended Interrupt
//----------------------------------------*/

void MCU::Setting::beginINT(uint8_t INTIndex, uint8_t INTMode)
{

  EIMSK += insertBit(INTIndex, HIGH);

  switch (INTMode)
  {
  case MAINTAIN:
    EICRA = 0x00;
    break;

  case DOWN:
    EICRA = 0x0A;
    break;

  case UP:
    EICRA = 0x0F;
    break;

  default:
    break;
  }

}

/*----------------------------------------//
        Begin Pin Change Interrupt
//----------------------------------------*/

void MCU::Setting::beginPCINT(uint8_t PCINTIndex)
{

  if (PCINTIndex <= 7)
  {
    PCMSK0 += insertBit(PCINTIndex, HIGH);
  }

  else if (PCINTIndex <= 14)
  {
    PCINTIndex -= 8;
    PCMSK1 += insertBit(PCINTIndex, HIGH);
  }

  else if (PCINTIndex <= 23)
  {
    PCINTIndex -= 16;
    PCMSK1 += insertBit(PCINTIndex, HIGH);
  }

}

/*----------------------------------------//
            Begin Timer Interrupt
//----------------------------------------*/

void MCU::Setting::beginTimer(uint8_t timerIndex, uint8_t timerMode)
{

  switch (timerIndex)
  {
    // TIMER INTERRUPT 0, 2 (8 BIT)
  case 0:
    if (timerMode == OVF)
    {
      TIMSK0 = 0x01;

      TCCR0A = 0x00;  // 1024, Normal Mode
      TCCR0B = 0x05;
      TCNT0 = 0x00;   // Start Counting 0x00
    }

    else if (timerMode == COMP)
    {
      TIMSK0 = 0x02;

      TCCR0A = 0x02;  // 1024, CTC Mode
      TCCR0B = 0x05;
      TCNT0 = 0x00;   // Start Counting 0x00

      OCR0A = _OCR0A;
    }

    break;

  case 2:
    if (timerMode == OVF)
    {
      TIMSK2 = 0x01;

      TCCR2A = 0x00;  // 1024, Normal Mode
      TCCR2B = 0x07;
      TCNT2 = 0x00;   // Start Counting 0x00
    }

    else if (timerMode == COMP)
    {
      TIMSK2 = 0x02;

      TCCR2A = 0x02;  // 1024, CTC Mode
      TCCR2B = 0x07;
      TCNT2 = 0x00;   // Start Counting 0x00

      OCR2A = _OCR2A;
    }

    break;

    // TIMER INTERRUPT 1 (16 BIT)
  case 1:
    if (timerMode == OVF)
    {
      TIMSK1 = 0x01;

      TCCR1A = 0x00;  // 1024, Normal Mode
      TCCR1B = 0x05;
      TCNT1H = 0x00;  // Start Counting 0x0000
      TCNT1L = 0x00;
    }

    else if (timerMode == COMP)
    {
      TIMSK1 = 0x02;

      TCCR1A = 0x00;  // 1024, CTC Mode
      TCCR1B = 0x0D;
      TCNT1H = 0x00;  // Start Counting 0x0000
      TCNT1L = 0x00;

      OCR1AH = _OCR1AH;
      OCR1AL = _OCR1AL;
    }

    break;

  default:
    break;
  }

}

/*----------------------------------------//
            Begin Timer PWM
//----------------------------------------*/

void MCU::Setting::beginPWM(uint8_t PWMIndex, uint8_t PWMMode)
{

  switch (PWMIndex)
  {
    // TIMER PWM 0, 2 (8 BIT)
  case OC0A:
    if (PWMMode == CORRECT)
    {
      TCCR0A |= 0x01 | (1 << COMA1);  // 256, Phase Correct PWM
      TCCR0B = 0x04;
      TCNT0 = 0x00;                   // Start Counting 0x00
    }

    else if (PWMMode == FAST)
    {
      TCCR0A |= 0x03 | (1 << COMA1);  // 256, Fast PWM Mode
      TCCR0B = 0x04;
      TCNT0 = 0x00;                   // Start Counting 0x00
    }

    break;

  case OC0B:
    if (PWMMode == CORRECT)
    {
      TCCR0A |= 0x01 | (1 << COMB1);  // 256, Phase Correct PWM
      TCCR0B = 0x04;
      TCNT0 = 0x00;                   // Start Counting 0x00
    }

    else if (PWMMode == FAST)
    {
      TCCR0A |= 0x03 | (1 << COMB1);  // 256, Fast PWM Mode
      TCCR0B = 0x04;
      TCNT0 = 0x00;                   // Start Counting 0x00
    }

    break;

  case OC2A:
    if (PWMMode == CORRECT)
    {
      TCCR2A |= 0x01 | (1 << COMA1);  // 256, Phase Correct PWM
      TCCR2B = 0x06;
      TCNT2 = 0x00;                   // Start Counting 0x00
    }

    else if (PWMMode == FAST)
    {
      TCCR2A |= 0x03 | (1 << COMA1);  // 256, Fast PWM Mode
      TCCR2B = 0x06;
      TCNT2 = 0x00;                   // Start Counting 0x00
    }

    break;

  case OC2B:
    if (PWMMode == CORRECT)
    {
      TCCR2A |= 0x01 | (1 << COMB1);  // 256, Phase Correct PWM
      TCCR2B = 0x06;
      TCNT2 = 0x00;                   // Start Counting 0x00
    }

    else if (PWMMode == FAST)
    {
      TCCR2A |= 0x03 | (1 << COMB1);  // 256, Fast PWM Mode
      TCCR2B = 0x06;
      TCNT2 = 0x00;                   // Start Counting 0x00
    }

    break;

    // TIMER PWM 1 (16 BIT)
  case OC1A:
    if (PWMMode == CORRECT)
    {
      TCCR1A |= 0x03 | (1 << COMA1);  // 256, Phase Correct PWM
      TCCR1B = 0x04;
      TCNT1H = 0x00;                  // Start Counting 0x0000
      TCNT1L = 0x00;
    }

    else if (PWMMode == FAST)
    {
      TCCR1A |= 0x03 | (1 << COMA1);  // 256, Fast PWM Mode
      TCCR1B = 0x0C;
      TCNT1H = 0x00;                  // Start Counting 0x0000
      TCNT1L = 0x00;
    }

    break;

  case OC1B:
    if (PWMMode == CORRECT)
    {
      TCCR1A |= 0x03 | (1 << COMB1);  // 256, Phase Correct PWM
      TCCR1B = 0x04;
      TCNT1H = 0x00;                  // Start Counting 0x0000
      TCNT1L = 0x00;
    }

    else if (PWMMode == FAST)
    {
      TCCR1A |= 0x03 | (1 << COMB1);  // 256, Fast PWM Mode
      TCCR1B = 0x0C;
      TCNT1H = 0x00;                  // Start Counting 0x0000
      TCNT1L = 0x00;
    }

    break;

  default:
    break;
  }

}

/*----------------------------------------//
                Begin SPI
//----------------------------------------*/

void MCU::Setting::beginSPI(void)
{
  SPCR = (1 << SPE) | (1 << MSTR);  //Enable SPI with 2000KHz in Master Mode
  SPSR = (1 << SPI2X);
}