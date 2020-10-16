**OLED Driver**

Device: UTRONICS OLED Module 128 x 64. 
Model: SSD1306
Communication Protocol: I2C
MCU Compatibility: STM32F407 Discovery

This is a driver for an OLED device called UCTRONICS OLED Module. I picked it up on [Amazon](https://www.amazon.com/dp/B072Q2X2LL/) without realizing if it has a driver for my MCU. It turns out, it doesn't. I googled and found out a few drivers created for STM32F1, but nothing for my STM32F4. To make things even more challenging, the drivers I found doesn't use the new HAL provided by STM. So I basically ported the STM32F1 code to my STM32F407 Discovery MCU using the new and updated HAL. This MCU uses PB6 and PB9 for SCL and SDA respectively. 

*Note: This code uses Tilen Majerle's code, that was ported by [Alexander Lutsai for STM32F1](https://github.com/SL-RU/stm32libs/tree/master/stm32f10x/ssd1306) and then further ported by me for STM32F407.*