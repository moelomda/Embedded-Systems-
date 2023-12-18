 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       7Segments.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       7Segments
 * Target           :       Atmega32
 * Date             :       18/12/2023  
 * Last Update      :       18/12/2023                                            */
 #include "7Segments.h"
#include "7Segments.h"

extern Se7enSegLED_StrCfg_t Se7venSegmentsArr[NUM_OF_Se7enSeg][7];
extern u8 Se7enSeg_u8ValuesArr[10][7];

Se7enSeg_enuErorState Se7enSeg_Init(void) {
 Se7enSeg_enuErorState Loc_Se7enSegErrorState = Se7enSeg_enusucceeded;
 PORT_enuErrorStatus_t Loc_PORTErorState = PORT_enuSucceded;
 PORT_StrCFg_t Loc_StrCurrSe7enSegArr[NUM_OF_Se7enSeg][7];
  u8 LocU8Counter;
  u8 LocU8Counter1;

	for (LocU8Counter = 0; LocU8Counter < NUM_OF_Se7enSeg; LocU8Counter++) 
	{
		for (LocU8Counter1 = 0; LocU8Counter1 < 7; LocU8Counter1++)
		 { 

			if (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PortCfg > NUM_OF_PORTS || Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PortCfg < Se7enSeg_PORTA) 
			{
				Loc_Se7enSegErrorState = Se7enSeg_enuInvalidPort;
				break;
			} 
			else if (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PinCfg > Se7enSeg_PIN7 ||Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PinCfg <Se7enSeg_PIN0) 
			{
				Loc_Se7enSegErrorState = Se7enSeg_enuInvalidPin;
				break;
			}
			 else if (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8ActiveState != ACTIVE_HIGH && Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8ActiveState!= ACTIVE_LOW) 
			 {
				Loc_Se7enSegErrorState = Se7enSeg_enuInvalidActiveState;
				break;
			 } 
				else
				 {
				Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PortNum = Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PortCfg;
				Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PinNum = Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8PinCfg;

				switch (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8ActiveState) 
				  {
					case ACTIVE_HIGH:
					switch (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8OnOffState)
					 {
						case Se7enSegLed_ON_STATE :
						Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PinCfg = PORT_enuOutput_High;
						break;
						case Se7enSegLed_OFF_STATE :
						Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PinCfg = PORT_enuOutput_Low;
						break;
					}
					break;

					case ACTIVE_LOW:
					switch (Se7venSegmentsArr[LocU8Counter][LocU8Counter1].Se7enSegLED_StrU8OnOffState)
					{
						case Se7enSegLed_ON_STATE :
						Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PinCfg = PORT_enuOutput_Low;
						   break;
						case Se7enSegLed_OFF_STATE :
						Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1].PORT_StrU8PinCfg = PORT_enuOutput_High;
						   break;
					}
					break;
				}


				Loc_PORTErorState = PORT_enuSetPinConfiguration(&Loc_StrCurrSe7enSegArr[LocU8Counter][LocU8Counter1]);
			}
		}
	}

	if (Loc_PORTErorState != PORT_enuSucceded) {
		Loc_Se7enSegErrorState = Se7enSeg_enuPortNOK;
	}

	return Loc_Se7enSegErrorState;
}
Se7enSeg_enuErorState Se7enSeg_SetValueSingle(u8 Copy_u8Se7enSegName , u8 Copy_u8Value)
{
	Se7enSeg_enuErorState Loc_enuErorState = Se7enSeg_enusucceeded ;
	DIO_enuErrorStatus_t Loc_enuDioEror = DIO_enuSucceded;
	u8 Loc_u8Counter ;
	if (Copy_u8Se7enSegName > NUM_OF_Se7enSeg)
	{
		
		Loc_enuErorState =  Se7enSeg_enuInvalidName ;
		
	}
	else if (Copy_u8Value > 9 || Copy_u8Value < 0)
	{
		
		Loc_enuErorState = Se7enSeg_enuInvalidValue ;
		
	}
	else
	{
		
		for (Loc_u8Counter = 0 ; Loc_u8Counter < 7 ; Loc_u8Counter ++ )
		{
			switch(Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8ActiveState)
			{
				case  ACTIVE_HIGH :
				Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8OnOffState =Se7enSeg_u8ValuesArr[Copy_u8Value][Loc_u8Counter];
				Loc_enuDioEror =DIO_enuSetPinLogic(Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8PortCfg ,Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8PinCfg ,Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8OnOffState );
				      break;
				case  ACTIVE_LOW :	
				Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8OnOffState =Se7enSeg_u8ValuesArr[Copy_u8Value][Loc_u8Counter];
				Loc_enuDioEror =DIO_enuSetPinLogic(Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8PortCfg ,Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8PinCfg ,!(Se7venSegmentsArr[Copy_u8Se7enSegName][Loc_u8Counter].Se7enSegLED_StrU8OnOffState) );
				break;  
				
			}
		
			
				
			
		}	
		
    }
	if (Loc_enuDioEror != DIO_enuSucceded)
	{
		
		Loc_enuErorState = Se7enSeg_enuDioNOK ;
	}
	return Loc_enuErorState;
}
