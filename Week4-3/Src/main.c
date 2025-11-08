#include "stm32f4xx.h"      // Include STM32F4 device header file
#include "adc_config.h"     // Include ADC configuration functions

// Global variables to store ADC value, voltage, and temperature
uint16_t adc_val;
float voltage;
float temp;

int main(void){
    // Initialize pin PA4 as an analog input for ADC
    adc_PA_init(4);
    // Configure PA5 as an output pin
    GPIOA->MODER &= ~GPIO_MODER_MODER5_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER5_0;     

    while(1){
        // Read analog value from PA4 (ADC channel)
        adc_val = adc_PA_read();
        // Convert raw ADC value to corresponding voltage
        voltage = 3.3 * adc_val / 4095.0;
        // Convert voltage from TMP36 sensor to temperature in °C
        temp = (voltage - 0.5) * 100.0;
        // Turn off LED (PA5 low) if ADC value < 2048
        if (adc_val < 2048) {
            GPIOA->BSRR |= GPIO_BSRR_BR5;    // Reset PA5 (turn LED OFF)
        } 
        // Turn on LED (PA5 high) if ADC value >= 2048
        else {
            GPIOA->BSRR |= GPIO_BSRR_BS5;    // Set PA5 (turn LED ON)
        }
        // delay loop for visible LED blinking or sampling interval
        for (int i = 0; i < 400000; i++);
    }
}
