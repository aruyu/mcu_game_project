# AVR Game Project

> A Game project powered by ATmega328P MCU...

This project is making a *'dino game like'* game with ILI9341 TFT LCD & driver.

Also, used PNP buzzer which has controlled by **Fast PWM (Timer Interrupt 0)** for sound.

1. *'A', 'B' buttons* are modified by **External Interrupt**.

2. *Other buttons* are modified by **Compare A (Timer Interrupt 1)**.

3. *System & Graphic frame timer* is modified by **Compare A (Timer Interrupt 2)**.

4. *ILI9341 driver* has controlled by **SPI (16MHz / 2 = 8MHz)**.

* * *

## Playing preview

https://user-images.githubusercontent.com/75081360/205556472-7ff9449e-21d0-4962-baee-ec20d2e9f18d.mov

## PCB

![ezgif com-gif-maker](https://user-images.githubusercontent.com/75081360/205558036-a9276dd3-40ba-414b-83e9-c5321475656f.png)
