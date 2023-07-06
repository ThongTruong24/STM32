/*
* File: delay.h 
* Author: Truong Huynh Quang Thong
* Date: 02/01/2003
* Description: This is the file used to delay the time in millis and micros
*/

#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"

/* Delay us */
void delayUs(uint32_t us);

/* Delay ms */
void delayMs(uint32_t ms);

#endif