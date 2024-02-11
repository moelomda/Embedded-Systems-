/*-----------------------------------------------------------------------------------------------------------------------------------------
* File             :       Task2.c                                                                                                              
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


/*----------------------------------------------------Main Program Section---------------------------------------------------*/
int main(void)

{
	
   
   u8 Loc_u8Counter=0;
   
   DIO_enu_Port_int();
   
   while(1)
   {
	   
	   
	   while(Loc_u8Counter<16)
	   {
		   
		   if(!GET_BIT(PINA , 4  ))
		   {
			   
			   Loc_u8Counter++;
			   DIO_enuCustomDelay(100);
			   
			   PORTA = Loc_u8Counter;
			   DIO_enuCustomDelay(100);
		   }
		   
	   }
	   Loc_u8Counter=0;
   }

}
/*----------------------------------------------------Main Program Section End---------------------------------------------------*/

	