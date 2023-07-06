/*
* File: LCD.h
* Author: Truong Huynh Quang Thong
* Date: 02/01/2003
* Description: Defining pins and functions
*/

#ifndef _LCD_H
#define _LCD_H

#include "stm32f10x.h"

/* Define pins connected to LCD */
#define LCD_RS_PIN      GPIO_Pin_0
#define LCD_RW_PIN      GPIO_Pin_1
#define LCD_E_PIN       GPIO_Pin_10
#define LCD_D4_PIN      GPIO_Pin_11
#define LCD_D5_PIN      GPIO_Pin_12
#define LCD_D6_PIN      GPIO_Pin_13
#define LCD_D7_PIN      GPIO_Pin_14

/* Define port and delay value in microseconds */
#define LCD_GPIO_PORT   GPIOB
#define LCD_CMD_DELAY   2000
#define LCD_DATA_DELAY  50

/* Initialize the LCD and register the corresponding pins */
void LCD_Init(void);

/* Setting modes or profiles for LCD */
void LCD_SendCmd(uint8_t cmd);

/* Transmit data to LCD */
void LCD_SendData(uint8_t data);

/* Pass data to function LCD_SendData on condition with space */
void LCD_SendString(char* str);

/* Convert numbers to letters and pass data to function LCD_SendData */
void LCD_PrintNumber(uint8_t number);

#endif

