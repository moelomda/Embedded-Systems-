/*
 * main.c
 *
 * Created: 24/12/2023 04:50:15 م
 *  Author: Tech Nation
 */ ٍٍ
#include "LED.h"
#include "SWITCH.h"

// Function prototypes for ISR
void __vector_1(void) __attribute((signal)); // INT0
void __vector_2(void) __attribute((signal)); // INT1
void __vector_3(void) __attribute((signal)); // INT2



int main(void)
{
	
	while(1)
	{
		
		
		
		
		
	}
	
	
	
	return 0 ;
}
// ISR for INT0
void __vector_1(void)
{
	
    /*action*/
}

// ISR for INT1
void __vector_2(void)
{
	/*action*/
}

// ISR for INT2
void __vector_3(void)
{
	/*action*/
}