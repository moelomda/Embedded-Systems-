/*-----------------------------------------------------------------------------------------------------------------------------------------
* File             :       Task1.c                                                                                                              
* AUTHOR           :      Mohamed Ahmed Fouad Youssef                                                                                                                                                                                                            
* SWC              :       DIO                                                                                                                 
* Target           :       Atmega32   
* Date             :       26/11/2023                                                                                                                                                                                                       
* Last Update      :       2/12/2023                                                                                                    */
/*------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------Inclusion Section-----------------------------------------*/
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/std_types.h"
#include "../../Lib/delay.h"
#include "../../MCAL/00_DIO/DIO.h"
#include "../../MCAL/01_PORT/PORT.h"
#include "../../MCAL/01_PORT/PORT_Config.h"

/*---------------------------------------------------Inclusion Section End-----------------------------------------*/
/*-----------------------------------------------Register Configuration Section------------------------------------*/
#define DDRA  *((volatile u8*)(0x3A))
#define DDRB  *((volatile u8*)(0x37))
#define DDRC  *((volatile u8*)(0x34))
#define DDRD  *((volatile u8*)(0x31))

#define PORTA *((volatile u8*)(0x3B))
#define PORTB *((volatile u8*)(0x38))
#define PORTC *((volatile u8*)(0x35))
#define PORTD *((volatile u8*)(0x32))

#define PINA  *((volatile u8*)(0x39))
#define PINB  *((volatile u8*)(0x36))
#define PINC  *((volatile u8*)(0x33))
#define PIND  *((volatile u8*)(0x30))
/*---------------------------------------------------- Register Configuration Section End------------------------------------*/

/*----------------------------------------------------Main Program Section---------------------------------------------------*/
int main(void)

{
	
     DIO_enu_Port_int();
    while (1){

	    DIO_enuSetPin(DIO_enuPortA , DIO_enuPin1 , DIO_enuLogicHigh);
	    DIO_enuSetPin(DIO_enuPortA , DIO_enuPin2 , DIO_enuLogicLow);
	    DIO_enuCustomDelay(100);
	/*    _delay_ms(1000);*/
	    DIO_enuSetPin(DIO_enuPortA , DIO_enuPin1 , DIO_enuLogicLow);
	    DIO_enuSetPin(DIO_enuPortA , DIO_enuPin2 , DIO_enuLogicHigh);
	   DIO_enuCustomDelay(100);
	 /*  _delay_ms(1000); */

    }

    /*
	  SET_BIT(DDRA,1);
	  SET_BIT(DDRA,2);
	  
	  while(1){
		  SET_BIT(PORTA,1);
		  CLR_BIT(PORTA,2);
		  _delay_ms(1000);
		  CLR_BIT(PORTA,1);
		  SET_BIT(PORTA,2);
		  _delay_ms(1000);
	  }
	  
	  */
	  
	  
	  
	  
	  

}
/*----------------------------------------------------Main Program Section End---------------------------------------------------*/
