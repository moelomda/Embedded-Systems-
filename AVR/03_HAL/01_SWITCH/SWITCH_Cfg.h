 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       SWITCH_Cfg.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       SWITCH
 * Target           :       Atmega32
 * Date             :       11/12/2023  
 * Last Update      :       11/12/2023                                                                                                    */
#ifndef _SWITCH_CFG_H_
#define _SWITCH_CFG_H_

#include "./lib/std_types.h" 

/*--------------------------------------------------------*SWITCH List*-------------------------------------------------------------*/
/*
use this macro to add the number of SWITCH'S you want
*/
#define NUM_OF_SWITCHS 2
/* SWITCH List */

#define SWITCH_NO_ZERO  0
#define SWITCH_NO_ONE  1


/* SWITCH List End  */
typedef struct {
	
	u8 SWITCH_StrU8PortCfg ;	            /* To Choose SWITCH Port */
	u8 SWITCH_StrU8PinCFg;                 /* To Choose SWITCH Pin */
	u8 SWITCH_StrU8SWITCHState;            /* To Choose SWITCH State */
	
}SWITCH_StrCfg_t;

#endif








