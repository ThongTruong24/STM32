/*
* File: delay.c 
* Author: Truong Huynh Quang Thong
* Date: 02/01/2003
* Description: Write functions of delay in millis and micros
*/

#include "stm32f10x.h"
#include "delay.h"

/*
* Function: delayUs
* Description: Delay in micros
* Input:
*   us: Number of ms needed to delay
* Output:
*   None
*/
void delayUs(uint32_t us)
{
    /* Enable active mode for DWT cycle counter on Cortex-M microcontroller */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	
	  /* Set CYCCNT cycle counter value in DWT to 0 */
    DWT->CYCCNT = 0;
	
	  /* Enable CYCCNT cycle counter in DWT */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    
	  /* Store the number of cycles (cycles) that need to be delayed in microseconds */ 
    uint32_t cycles = us * (SystemCoreClock / 1000000);
	
	  /* Waiting loop */
    uint32_t start = DWT->CYCCNT;
    while ((DWT->CYCCNT - start) < cycles);
    
    /* Disable DWT cycle counter */
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
}

/*
* Function: delayMs
* Description: Delay in millis
* Input:
*   ms: Number of ms needed to delay
* Output:
*   None
*/
void delayMs (uint32_t ms) {
	
	delayUs(ms * 1000);
	
}