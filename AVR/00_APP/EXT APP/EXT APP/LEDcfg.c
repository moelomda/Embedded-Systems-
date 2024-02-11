 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       LEDcfg.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       LED
 * Target           :       Atmega32
 * Date             :       10/12/2023  
 * Last Update      :       10/12/2023 
                                                                                                                               */
 #include "LEDcfg.h"
 #include "LED.h"
 /* 
 use this array for each LED configuration 
 @ the first location is for Port
 @ the second location is for Pin 
 @ the third location is for active state 
 @ the fourth location is for LED state 
 */                                                                                                  
LED_StrCfg_t LEDS_Arr[NUM_OF_LEDS]= {
	[LED_NO_ZERO] = {LED_PORTA, LED_PIN1 ,ACTIVE_HIGH ,LED_OFF_STATE},
	[LED_NO_ONE]  = {LED_PORTA, LED_PIN2 ,ACTIVE_HIGH ,LED_OFF_STATE},  
	[LED_NO_TWO]  = {LED_PORTA, LED_PIN3 ,ACTIVE_HIGH ,LED_OFF_STATE},     
	};
