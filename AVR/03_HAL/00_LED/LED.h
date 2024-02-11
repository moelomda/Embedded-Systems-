 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       LED.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       LED
 * Target           :       Atmega32
 * Date             :       10/12/2023  
 * Last Update      :       10/12/2023                                                                                                    */
                                                                         
 #ifndef LED_H_
 #define LED_H_
 #include "PORT.h"
 #include "DIO.h"
 #include "LEDcfg.h"
 #include "PORT_Config.h"
 #include "lib/delay.h"
 
/*--------------------------------------------------------*MACRO*-------------------------------------------------------------*/
/* Active State */
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1
/* LED State */
#define LED_OFF_STATE 0                  /* Choose this Macro if you want to make the LED OFF */
#define LED_ON_STATE 1                   /* Choose this Macro if you want to make the LED ON */
/* Ports List */
#define LED_PORTA 0                      /* LED location in Port A */
#define LED_PORTB 1                      /* LED location in Port B */
#define LED_PORTC 2                      /* LED location in Port C */
#define LED_PORTD 3                      /* LED location in Port D */
/* Pins List */
#define LED_PIN0 0                       /* LED connected to Pin0 */
#define LED_PIN1 1                       /* LED connected to Pin1 */
#define LED_PIN2 2                       /* LED connected to Pin2 */
#define LED_PIN3 3                       /* LED connected to Pin3 */
#define LED_PIN4 4                       /* LED connected to Pin4 */
#define LED_PIN5 5                       /* LED connected to Pin5 */
#define LED_PIN6 6                       /* LED connected to Pin6 */
#define LED_PIN7 7                       /* LED connected to Pin7 */
 /*--------------------------------------------------------*Enumerations*-------------------------------------------------------------*/
 typedef enum {
	 LED_enuInvalidPort,                 /* Port Number Entered is Invalid */
	 LED_enuInvalidPin,                  /* Pin Number Entered is Invalid */
	 LED_enuInvalidActiveState,          /* Active State Entered is Invalid */
	 LED_enuInvalidLogicState,          /* Logic State Entered is Invalid */
	 LED_enusucceeded,                  /* Completed Successfully */
	 LED_enuPortNOK,                    /* Port Function has an issue */
	 LED_enuDioNOK,                     /* DIO Function has an issue */ 
	 LED_enuInvalidName,                /* there is no led name like that */    
	 }LED_enuErorState;
/*--------------------------------------------------------*API'S*-------------------------------------------------------------*/	 
	 LED_enuErorState LED_Init(void);   /* This Function is used to initialize LED Pins Values */
	 LED_enuErorState LED_enuSetLedState(u8 Copy_u8LedName , u8 Copy_u8LedState);
	 
 #endif