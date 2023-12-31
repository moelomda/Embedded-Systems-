/*
 * EXT APP.c
 *
 * Created: 25/12/2023 06:23:34 م
 * Author : Tech Nation
 */ 

#include "LED.h"
#include "SWITCH.h"
#include "Interrupt.h"
// Function prototypes for ISR
void __vector_1(void) __attribute((signal)); // INT0
void __vector_2(void) __attribute((signal)); // INT1
void __vector_3(void) __attribute((signal)); // INT2



int main(void)
{
    LED_Init();
    SWITCH_Init();
    EXTI_Init();

    while (1) 
    {
		
    }
	return 0 ;
}
// ISR for INT0
void __vector_1(void)
{
	 LED_enuSetLedState(LED_NO_ZERO , LED_ON_STATE);
}

// ISR for INT1
void __vector_2(void)
{
	 LED_enuSetLedState(LED_NO_ONE , LED_ON_STATE);
}

// ISR for INT2
void __vector_3(void)
{
	 LED_enuSetLedState(LED_NO_TWO , LED_ON_STATE);
}
