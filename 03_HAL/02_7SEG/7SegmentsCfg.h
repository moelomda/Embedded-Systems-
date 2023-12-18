 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       7SegmentsCfg.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       7Segments
 * Target           :       Atmega32
 * Date             :       18/12/2023  
 * Last Update      :       18/12/2023                                                                                                    */
                                                                         
 #ifndef S7evenCfg_H_
 #define S7evenCfg_H_
 #include "./lib/std_types.h"

#define NUM_OF_Se7enSeg  4
/*
use this macro to add the number of Se7enSeg you want 
note that the maximum number is 4 
*/
 
/*--------------------------------------------------------*Se7enSeg List*-------------------------------------------------------------*/
/* Se7enSeg List */

#define Se7enSeg_NO_ZERO  0
#define Se7enSeg_NO_ONE  1
#define Se7enSeg_NO_TWO 2
#define Se7enSeg_NO_THREE 3

/* Se7enSeg List End  */
typedef struct {
	
	u8 Se7enSegLED_StrU8PortCfg ;	            /* To Choose Se7enSeg_LED Port */
	u8 Se7enSegLED_StrU8PinCfg;                 /* To Choose Se7enSeg_LED Pin */
	u8 Se7enSegLED_StrU8ActiveState;            /* To Choose Se7enSeg_LED Active State */
	u8 Se7enSegLED_StrU8OnOffState;		        /* To Choose Se7enSeg_LED ON/Off State  */
}Se7enSegLED_StrCfg_t;


 #endif