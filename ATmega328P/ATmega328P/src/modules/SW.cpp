/*
 *    NOTE        - SW.cpp
 *    Copyright   - NULL
 *
 *    Created     - 2021.05.30
 *    Author      - 2033112012 CLJ
 *    Contact     - vine9151@gmail.com
 */

#include "SW.hpp"

volatile uint8_t SW::result;
volatile uint8_t SW::newData;
volatile uint8_t SW::oldData;

bool SW::interrupt0 = OFF;
bool SW::interrupt1 = OFF;
bool SW::up = OFF;
bool SW::down = OFF;
bool SW::left = OFF;
bool SW::right = OFF;
bool SW::start = OFF;
bool SW::select = OFF;


/*----------------------------------------//
              update Switch
//----------------------------------------*/

void SW::update(void)
{
  newData = PINC | 0xC0;
  result = oldData & ~newData;
  oldData = newData;
}

/*----------------------------------------//
            Initialize Switch
//----------------------------------------*/

void SW::init(void)
{
  interrupt0 = OFF;
  interrupt1 = OFF;
  up = OFF;
  down = OFF;
  left = OFF;
  right = OFF;
  start = OFF;
  select = OFF;
}