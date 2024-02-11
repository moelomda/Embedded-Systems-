 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       LEDcfg.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       LED
 * Target           :       Atmega32
 * Date             :       10/12/2023  
 * Last Update      :       10/12/2023                                                                                                    */
  #ifndef LED_CFG_H_
  #define LED_CFG_H_
  
  
 
#include "../../../03_Lib/std_types.h"
#define NUM_OF_LEDS  1  
/*
use this macro to add the number of LED'S you want 
*/
 
/*--------------------------------------------------------*LED List*-------------------------------------------------------------*/
/* LED List */

#define LED_NO_ZERO  0
#define LED_NO_ONE  1
#define LED_NO_TWO  2
#define LED_NO_THREE  3

/* LED List End  */
typedef struct {
	
	u8 LED_StrU8PortCfg ;	            /* To Choose LED Port */
	u8 LED_StrU8PinCFg;                 /* To Choose LED Pin */
	
	u8 LED_StrU8ActiveState;            /* To Choose LED Active State */
	u8 LED_StrU8OnOffState;		        /* To Choose LED ON/Off State  */
}LED_StrCfg_t;

	
  #endif