#include "main.h"
#include "stm32f407xx.h"
#include "stm32f4xx_hal_i2c.h"
#include "ssd1306.h"
#include <stdio.h>

#define GPIO_AF4_I2C1          ((uint8_t)0x04)

static void I2C1_Init(void);
static void GPIO_Init(void);

int main(void)
{
	HAL_Init();
	GPIO_Init();
	I2C1_Init();

    // Test if display works
	uint8_t res = SSD1306_Init();
	printf("OLED init: %d\n", res);
	SSD1306_GotoXY(10,27);
	SSD1306_Puts("OLED inited", &Font_7x10, 1);
	SSD1306_GotoXY(10,52);
	SSD1306_Puts("Imtiaz Ahmed", &Font_7x10, 1);
	SSD1306_UpdateScreen();
	HAL_Delay(1000);

    // Clear screena and write something new
	SSD1306_Fill(0);
	SSD1306_GotoXY(10, 0);
	SSD1306_Puts("Time: 2:20pm", &Font_7x10, 1);
	SSD1306_GotoXY(10, 20);
	SSD1306_Puts("Temp: 59F", &Font_7x10, 1);
	SSD1306_GotoXY(12, 40);
	SSD1306_Puts("Humidity: 25%", &Font_7x10, 1);
	SSD1306_UpdateScreen(); //display
	HAL_Delay(1000);

	while(1) {
		//
	}
}

static void I2C1_Init(void)
{
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_HandleTypeDef hi2c1;

	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 400000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_16_9;
	hi2c1.Init.OwnAddress1 = 0x15;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;

	HAL_I2C_Init(&hi2c1);
}

static void GPIO_Init(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_B;

	GPIO_B.Pin = GPIO_PIN_6 | GPIO_PIN_9;
	GPIO_B.Mode = GPIO_MODE_AF_OD;
	GPIO_B.Pull = GPIO_PULLUP;
	GPIO_B.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_B.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &GPIO_B);
}