#include "stm32f10x.h"

void config(){

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);

}

void delay(){
	uint32_t i;
	for(i = 0; i < 1000000; i++);
}

int main(void){

	config();
	
	while(1){
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay();
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay();
	
	}
}