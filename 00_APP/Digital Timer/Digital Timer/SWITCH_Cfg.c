 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       SWITCHCfg.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       SWITCH
 * Target           :       Atmega32
 * Date             :       11/12/2023  
 * Last Update      :       11/12/2023 
                                                                                                                               */
 #include "SWITCH_Cfg.h"
 #include "SWITCH.h"
 /* 
 use this array for each SWITCH configuration 
 @ the first location is for Port
 @ the second location is for Pin 
 @ the third location is for SWITCH state 
 
 */                                                                                                  
SWITCH_StrCfg_t SWITCHS_Arr[NUM_OF_SWITCHS] = {
	[SWITCH_NO_ZERO] = {SWITCH_PORTC, SWITCH_PIN0, SWITCH_PULLUP},
	[SWITCH_NO_ONE]  = {SWITCH_PORTC, SWITCH_PIN1, SWITCH_PULLUP},
	[SWITCH_NO_TWO]= {SWITCH_PORTC, SWITCH_PIN2, SWITCH_PULLUP},	
};
