#include "stm32f4xx.h"
#include "adc_config.h"

uint16_t adc_val;
float voltage;
float temp;

int main(void){

	// Initialises PA4 as ADC
	adc_PA_init(4);

	// Sets PA5 as output (clock already enable in adc_PA_init)
	GPIOA->MODER &= ~GPIO_MODER_MODER5_Msk;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;

	while(1){
		adc_val = adc_PA_read();
		voltage = 3.3 * adc_val/4095;
		temp = (voltage-0.5)*100.0;

		if (adc_val < 2048){
			GPIOA->BSRR |= GPIO_BSRR_BR5;
		} else{
			GPIOA->BSRR |= GPIO_BSRR_BS5;
		}

		for(int i = 0; i < 400000; i++);
	}
}
