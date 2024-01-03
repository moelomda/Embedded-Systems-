 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       PORT.h
 * AUTHOR           :      Mohamed Ahmed Fouad Youssef
 * SWC              :       PORT
 * Target           :       Atmega32
 * Date             :       02/12/2023 10:19:55 am
 * Last Update      :       10/12/2023                                                                                                    */
#ifndef PORT_H_
#define PORT_H_
/*-----------------------------------------Inclusion section------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "../../../03_Lib/BIT_MATH.h"
#include "../../../03_Lib/std_types.h"
#include "PORT_Config.h"
#include "../../../03_Lib/Registers.h"

/*-----------------------------------------Inclusion section End------------------------------------*/
/*----------------------------------------------Macro Section---------------------------------------*/
#define INPUT_PU 0
#define INPUT_HI 1
#define OUTPUT_HIGH 2
#define OUTPUT_LOW 3
#define PORT_LOW 0
#define PORT_HIGH 1

/*---------------------------------------------Macro Section End--------------------------------------*/
/*---------------------------------------------Enumeration Section--------------------------------------*/
typedef enum
{
	PORT_enuPortA,        /*Port A*/
	PORT_enuPortB,          /*Port B*/
	PORT_enuPortC,          /*Port C*/
	PORT_enuPortD,	      /*Port D*/
}PORT_enuPortNumber_t;

typedef enum{
	 	                  
	PORT_enuInputInternalPullUP,	     
	PORT_enuInputExternalPullDown,  
	PORT_enuOutput_Low,
	PORT_enuOutput_High,
	                            
}PORT_enuPinConfiguration_t;


typedef enum {
	
	PORT_enuInvalidPortNumber,
	PORT_enuInvalidPinNumber,
	PORT_enuInvalidPinLogic,
	PORT_enuIvalidpinConfiguration,
	PORT_enuSucceded,
	PORT_enuNullPtr,
} PORT_enuErrorStatus_t;

typedef enum {
	
	
	PORT_enuPin0,       /*pin 0*/
	PORT_enuPin1,      /*Pin 1*/
	PORT_enuPin2,      /*Pin 2*/
	PORT_enuPin3,	 /*Pin 3*/
	PORT_enuPin4,     /*Pin 4*/
	PORT_enuPin5,      /*Pin 5*/
	PORT_enuPin6,       /*Pin 6*/
	PORT_enuPin7,        /*Pin 7*/
	
	
}PORT_enuPinNumber_t;

typedef enum {
	PORT_enuLogicLow,                     /*Input Low*/
	PORT_enuLogicHigh,                   /*Input High*/
}PORT_enuSetPinLogic_t;

typedef struct {
u8 PORT_StrU8PortNum;
u8 PORT_StrU8PinNum;
u8 PORT_StrU8PinCfg;
	}PORT_StrCFg_t;


/*--------------------------------------------------------*API'S*----------------------------------------------------------------------------------*/
/* 
 *@brief  : Function to Set the Configuration of a Specific Pin.
 *@param  : A pointer to array of Type Struct
 *@return : Error State
 Note that each port contains 8 Pins (from Pin0 to Pin7 )
*/ 
 PORT_enuErrorStatus_t PORT_enuSetPinConfiguration(PORT_StrCFg_t *Add_StrPortCfg); 
  /* This function is called when user choose pre-compile */
  void PORT_PreInit();            
   /* This function is called when user choose post-compile */
  //void PORT_PostInit();        
  //DIO_enuErrorStatus_t DIO_enuSetPinConfiguration( DIO_enuPortNumber_t Copy_PortNum , DIO_enuPinNumber_t Copy_PinNum , DIO_enuPinConfiguration_t Copy_PinConfiguration );

#endif