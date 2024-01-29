 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :      PORT_Config.h
 * AUTHOR           :      Mohamed Ahmed Fouad Youssef
 * SWC              :       PORT
 * Target           :       Atmega32
 * Date             :       02/12/2023 10:19:55 am
 * Last Update      :       10/12/2023                                                                                                    */
#ifndef PORT_Config_H_
#define PORT_Config_H_
/*-----------------------------------------Inclusion section------------------------------------*/
#include "PORT.h"
/*-----------------------------------------Inclusion section End------------------------------------*/
/*--------------------------------------------**Choose Compile Way**----------------------------------------*/

 #define Compile_Way POST_COMPILE
 /*
 Your Options :
 @ PRE_COMPILE
 @ POST_COMPILE 
*/
 #define  PRE_COMPILE 0
 #define  POST_COMPILE 1 
/*-------------------------------------------**Pre_Compile**---------------------------------------------------*/
/*-------------------------------------------*PORT CONFG*-----------------------------------------------------------*/
#define NUM_OF_PORTS  THREE_PORTS                          
/*  
 Your Options :
    @ Two_Ports
	@ Three_Ports 
	@ Four_Ports	
*/  
#define TWO_PORTS 2
#define THREE_PORTS 3
#define FOUR_PORTS  4
/*-------------------------------------------*PIN CONFG*-----------------------------------------------------------------*/
/*-----PORTA----*/
#define DIO_PIN0   OUTPUT_HIGH 
#define DIO_PIN1   OUTPUT_HIGH
#define DIO_PIN2   OUTPUT_HIGH
#define DIO_PIN3   OUTPUT_HIGH
#define DIO_PIN4   OUTPUT_HIGH
#define DIO_PIN5   OUTPUT_HIGH
#define DIO_PIN6   OUTPUT_HIGH
#define DIO_PIN7   OUTPUT_HIGH
/*-----PORTB----*/
#define DIO_PIN8  OUTPUT_HIGH 
#define DIO_PIN9  OUTPUT_HIGH
#define DIO_PIN10 OUTPUT_HIGH 
#define DIO_PIN11 OUTPUT_HIGH
#define DIO_PIN12 OUTPUT_HIGH
#define DIO_PIN13 OUTPUT_HIGH
#define DIO_PIN14 OUTPUT_HIGH
#define DIO_PIN15 OUTPUT_HIGH
/*-----PORTC----*/
#if (NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS)
#define DIO_PIN16 OUTPUT_HIGH
#define DIO_PIN17 OUTPUT_HIGH
#define DIO_PIN18 OUTPUT_HIGH
#define DIO_PIN19 OUTPUT_HIGH
#define DIO_PIN20 OUTPUT_HIGH
#define DIO_PIN21 OUTPUT_HIGH
#define DIO_PIN22 OUTPUT_HIGH
#define DIO_PIN23 OUTPUT_HIGH
/*-----PORTD----*/
#endif
#if (NUM_OF_PORTS == FOUR_PORTS)
#define DIO_PIN24 OUTPUT_HIGH
#define DIO_PIN25 OUTPUT_HIGH
#define DIO_PIN26 OUTPUT_HIGH
#define DIO_PIN27 OUTPUT_HIGH
#define DIO_PIN28 OUTPUT_HIGH
#define DIO_PIN29 OUTPUT_HIGH
#define DIO_PIN30 OUTPUT_HIGH
#define DIO_PIN31 OUTPUT_HIGH
#endif

/*  
 Your Options :
    @INPUT_PU
	@INPUT_HI
	@OUTPUT_HIGH
	@OUTPUT_LOW	
*/

/*----------------------------------------*Array for Post Compile*--------------------------------------------*/


#endif 