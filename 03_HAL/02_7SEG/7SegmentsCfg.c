 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       7SegmentsCfg.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       7Segments
 * Target           :       Atmega32
 * Date             :       18/12/2023  
 * Last Update      :       18/12/2023         
                                        */
 #include "7SegmentsCfg.h"
 #include "7Segments.h"
 
 Se7enSegLED_StrCfg_t Se7venSegmentsArr[NUM_OF_Se7enSeg][7]=
 {
	
	[Se7enSeg_NO_ZERO]=
	{
		[Se7enSeg_LEDA] = {Se7enSeg_PORTA, Se7enSeg_PIN0 ,ACTIVE_LOW ,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDB] = {Se7enSeg_PORTA , Se7enSeg_PIN1 ,ACTIVE_LOW ,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDC] = {Se7enSeg_PORTA , Se7enSeg_PIN2 ,ACTIVE_LOW ,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDD] = {Se7enSeg_PORTA , Se7enSeg_PIN3,ACTIVE_LOW,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDE] = {Se7enSeg_PORTA , Se7enSeg_PIN4,ACTIVE_LOW ,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDF] = {Se7enSeg_PORTA , Se7enSeg_PIN5,ACTIVE_LOW,Se7enSegLed_ON_STATE},
		[Se7enSeg_LEDG] = {Se7enSeg_PORTA , Se7enSeg_PIN6,ACTIVE_LOW ,Se7enSegLed_ON_STATE},
			
	},
	
   [Se7enSeg_NO_ONE]=
   {
	   	[Se7enSeg_LEDA] = {Se7enSeg_PORTB, Se7enSeg_PIN0 ,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDB] = {Se7enSeg_PORTB , Se7enSeg_PIN1 ,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDC] = {Se7enSeg_PORTB , Se7enSeg_PIN2 ,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDD] = {Se7enSeg_PORTB , Se7enSeg_PIN3,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDE] = {Se7enSeg_PORTB , Se7enSeg_PIN4,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDF] = {Se7enSeg_PORTB , Se7enSeg_PIN5,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	   	[Se7enSeg_LEDG] = {Se7enSeg_PORTB , Se7enSeg_PIN6,ACTIVE_HIGH ,Se7enSegLed_OFF_STATE},
	      
   },
    
  
 };
 u8 Se7enSeg_u8ValuesArr[10][7]=
 {

	 [0] = {1,1,1,1,1,1,0},
	 [1] = {0,1,1,0,0,0,0},
	 [2] = {1,1,0,1,1,0,1},
	 [3] = {1,1,1,1,0,0,1},
	 [4] = {0,1,1,0,0,1,1},
	 [5] = {1,0,1,1,0,1,1},
	 [6] = {1,0,1,1,1,1,1},
	 [7] = {1,1,1,0,0,0,0},
	 [8] = {1,1,1,1,1,1,1},
	 [9] = {1,1,1,1,0,1,1},
	 
 } ;
 