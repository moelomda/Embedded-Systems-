 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       SWITCH.h
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       SWITCH
 * Target           :       Atmega32
 * Date             :       11/12/2023  
 * Last Update      :       11/12/2023                                              */
 #ifndef SWITCH_H_
 #define SWITCH_H_
 #include "PORT.h"
 #include "SWITCH_Cfg.h"
 #include "DIO.h"
 /*--------------------------------------------------------*MACRO*-------------------------------------------------------------*/
 #define SWITCH_NPRESSED 0
 #define SWITCH_PRESSED 1
 /*----------------------*/
 #define PORTR_LOW 0
 #define PORTR_HIGH 1
 /* SWITCH State */
 #define SWITCH_PULLUP 0                  
 #define SWITCH_PULLDOWN 1                   
 /* Ports List */
 #define SWITCH_PORTA 0                      /* SWITCH location in Port A */
 #define SWITCH_PORTB 1                      /* SWITCH location in Port B */
 #define SWITCH_PORTC 2                      /* SWITCH location in Port C */
 #define SWITCH_PORTD 3                      /* SWITCH location in Port D */
 /* Pins List */
 #define SWITCH_PIN0 0                       /* SWITCH connected to Pin0 */
 #define SWITCH_PIN1 1                       /* SWITCH connected to Pin1 */
 #define SWITCH_PIN2 2                       /* SWITCH connected to Pin2 */
 #define SWITCH_PIN3 3                       /* SWITCH connected to Pin3 */
 #define SWITCH_PIN4 4                       /* SWITCH connected to Pin4 */
 #define SWITCH_PIN5 5                       /* SWITCH connected to Pin5 */
 #define SWITCH_PIN6 6                       /* SWITCH connected to Pin6 */
 #define SWITCH_PIN7 7                       /* SWITCH connected to Pin7 */
 /*--------------------------------------------------------*Enumerations*-------------------------------------------------------------*/
 typedef enum {
	 SWITCH_enuInvalidPort,                 /* Port Number Entered is Invalid */
	 SWITCH_enuInvalidPin,                  /* Pin Number Entered is Invalid */
     SWITCH_enuInvalidSWITCHState,          /* Logic State Entered is Invalid */
	 SWITCH_enusucceeded,                  /* Completed Successfully */
	 SWITCH_enuPortNOK,                     /* Port Function has an issue */ 
	 SWITCH_enuInvalidSwitchname, 
	 SWITCH_enuDioNOK,
	 SWITCH_enuNullPtr,               
 }SWITCH_enuErorState;
 /*--------------------------------------------------------*API'S*-------------------------------------------------------------*/
 SWITCH_enuErorState SWITCH_Init(void);   /* This Function is used to initialize SWITCH Pins Values */
 SWITCH_enuErorState SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName , u8 *Add_u8State);
 #endif