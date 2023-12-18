 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       7Segments.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :      
 * Target           :       Atmega32
 * Date             :       18/12/2023  
 * Last Update      :       18/12/2023                                                          */                                                                                  
                                                                           
 #ifndef S7even_H_
 #define S7even_H_
 #include "PORT.h"
 #include "DIO.h"
 #include "7SegmentsCfg.h"
 #include "PORT_Config.h"
 #include "lib/delay.h"
 
 /*--------------------------------------------------------*MACRO*-------------------------------------------------------------*/
 /* Active State */
 #define ACTIVE_LOW 0
 #define ACTIVE_HIGH 1
 /* LED State */
 #define  Se7enSegLed_OFF_STATE 0                  /* Choose this Macro if you want to make the  7Segments OFF */
 #define  Se7enSegLed_ON_STATE 1                   /* Choose this Macro if you want to make the  7Segments ON */
 /* Ports List */
 #define  Se7enSeg_PORTA 0                      /* 7Segments location in Port A */
 #define  Se7enSeg_PORTB 1                      /* 7Segments location in Port B */
 #define  Se7enSeg_PORTC 2                      /* 7Segments location in Port C */
 #define  Se7enSeg_PORTD 3                      /* 7Segments location in Port D */
 /* Pins List */
 #define  Se7enSeg_PIN0 0                       /* 7Segments LED connected to Pin0 */
 #define  Se7enSeg_PIN1 1                       /* 7Segments LED  connected to Pin1 */
 #define  Se7enSeg_PIN2 2                       /* 7Segments LED  connected to Pin2 */
 #define  Se7enSeg_PIN3 3                       /* 7Segments LED  connected to Pin3 */
 #define  Se7enSeg_PIN4 4                       /* 7Segments LED  connected to Pin4 */
 #define  Se7enSeg_PIN5 5                       /* 7Segments LED  connected to Pin5 */
 #define  Se7enSeg_PIN6 6                       /* 7Segments LED  connected to Pin6 */
 #define  Se7enSeg_PIN7 7                       /* 7Segments LED  connected to Pin7 */
 /* 7Segments LEDS List */  
 #define  Se7enSeg_LEDA 0                        /* 7Segments LED A */
 #define  Se7enSeg_LEDB 1                        /* 7Segments LED B */
 #define  Se7enSeg_LEDC 2						 /* 7Segments LED C */
 #define  Se7enSeg_LEDD 3						 /* 7Segments LED D */
 #define  Se7enSeg_LEDE 4						 /* 7Segments LED E */
 #define  Se7enSeg_LEDF 5						 /* 7Segments LED F */
 #define  Se7enSeg_LEDG 6						 /* 7Segments LED G */
 #define  Se7enSeg_LEDDP 7                       /* 7Segments LED DP*/
 
 /*--------------------------------------------------------*Enumerations*-------------------------------------------------------------*/
 typedef enum {
	 Se7enSeg_enuInvalidPort,                 /* Port Number Entered is Invalid */
	 Se7enSeg_enuInvalidPin,                  /* Pin Number Entered is Invalid */
	 Se7enSeg_enuInvalidActiveState,          /* Active State Entered is Invalid */
	 Se7enSeg_enuInvalidLogicState,          /* Logic State Entered is Invalid */
	 Se7enSeg_enusucceeded,                  /* Completed Successfully */
	 Se7enSeg_enuPortNOK,                    /* Port Function has an issue */
	 Se7enSeg_enuDioNOK,                     /* DIO Function has an issue */
	 Se7enSeg_enuInvalidName,                /* there is no 7Segments name like that */
	 Se7enSeg_enuInvalidValue,               /* value entered not valid*/
	   
	                            
 }Se7enSeg_enuErorState;
 
 /*-------------------------------------------------------*API'S*---------------------------------------------------------*/
  Se7enSeg_enuErorState Se7enSeg_Init(void);
  Se7enSeg_enuErorState Se7enSeg_SetValueSingle(u8 Copy_u8Se7enSegName , u8 Copy_u8Value);
   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 #endif