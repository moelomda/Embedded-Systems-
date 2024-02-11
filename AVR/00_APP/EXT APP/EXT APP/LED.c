 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       LED.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       LED
 * Target           :       Atmega32
 * Date             :       10/12/2023  
 * Last Update      :       11/12/2023                                                                                                    */
 #include "LED.h"

  extern LED_StrCfg_t LEDS_Arr[NUM_OF_LEDS];
  
 LED_enuErorState LED_Init(void){
	 
	 LED_enuErorState Loc_LEDErrorState = LED_enusucceeded ;
	 PORT_enuErrorStatus_t Loc_PORTErorState = PORT_enuSucceded ;
	 PORT_StrCFg_t Loc_Str_CurrLED_Arr[NUM_OF_LEDS];
	 u8 LocU8Counter;
	/*for(LocU8Counter = 0 ; LocU8Counter < NUM_OF_LEDS ; LocU8Counter ++){
	     
		   if (LEDS_Arr[LocU8Counter].LED_StrU8PortCfg > NUM_OF_PORTS || LEDS_Arr[LocU8Counter].LED_StrU8PortCfg < LED_PORTA )
		 {
			 
			 Loc_LEDErrorState = LED_enuInvalidPort ;
			 break; 
			 
		 }
		  else if (LEDS_Arr[LocU8Counter].LED_StrU8PinCFg > LED_PIN7 || LEDS_Arr[LocU8Counter].LED_StrU8PinCFg < LED_PIN0 )
		 {
			 
			 Loc_LEDErrorState = LED_enuInvalidPin ;
			 break;
			 
		 }
	     else if (LEDS_Arr[LocU8Counter].LED_StrU8ActiveState != ACTIVE_HIGH && LEDS_Arr[LocU8Counter].LED_StrU8ActiveState != ACTIVE_LOW) 
		 {
			 
			 Loc_LEDErrorState = LED_enuInvalidActiveState ;
			 break;
		 } 
		 else if(LEDS_Arr[LocU8Counter].LED_StrU8OnOffState != LED_ON_STATE && LEDS_Arr[LocU8Counter].LED_StrU8OnOffState != LED_OFF_STATE)
		 {
			 
			 Loc_LEDErrorState = LED_enuInvalidLogicState ;
			 break;
		 }
		 else  {
		 Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PortNum = LEDS_Arr[LocU8Counter].LED_StrU8PortCfg ;
		 Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinNum = LEDS_Arr[LocU8Counter].LED_StrU8PinCFg;
		 switch (LEDS_Arr[LocU8Counter].LED_StrU8ActiveState){
			 case (ACTIVE_HIGH) :
			    switch(LEDS_Arr[LocU8Counter].LED_StrU8OnOffState){
					case(LED_ON_STATE) :
					   Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_High ;
					     break ;
					case(LED_OFF_STATE) : 
					   Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_Low ;
					     break ;	
				}
		     break;
			  
			 case(ACTIVE_LOW) :
			   switch(LEDS_Arr[LocU8Counter].LED_StrU8OnOffState){
				   case(LED_ON_STATE) :
				   Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_Low ;
				   break ;
				   case(LED_OFF_STATE) :
				   Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_High ;
				   break ;
			   }
			  break; 
			        
		 
				 
	 }
		  Loc_PORTErorState = PORT_enuSetPinConfiguration(&Loc_Str_CurrLED_Arr[LocU8Counter]);

	 }
	     if (Loc_PORTErorState != PORT_enuSucceded){
			 
			 Loc_LEDErrorState = LED_enuPortNOK ; 
     }
	 
	 }
	 return Loc_LEDErrorState ;
	 
	 }   */
	
	
	  for(LocU8Counter = 0; LocU8Counter < NUM_OF_LEDS; LocU8Counter++) {
    if (LEDS_Arr[LocU8Counter].LED_StrU8PortCfg > NUM_OF_PORTS || LEDS_Arr[LocU8Counter].LED_StrU8PortCfg < LED_PORTA) {
        Loc_LEDErrorState = LED_enuInvalidPort;
        break;
    }
    else if (LEDS_Arr[LocU8Counter].LED_StrU8PinCFg > LED_PIN7 || LEDS_Arr[LocU8Counter].LED_StrU8PinCFg < LED_PIN0) {
        Loc_LEDErrorState = LED_enuInvalidPin;
        break;
    }
    else if (LEDS_Arr[LocU8Counter].LED_StrU8ActiveState != ACTIVE_HIGH && LEDS_Arr[LocU8Counter].LED_StrU8ActiveState != ACTIVE_LOW) {
        Loc_LEDErrorState = LED_enuInvalidActiveState;
        break;
    }
    else if (LEDS_Arr[LocU8Counter].LED_StrU8OnOffState != LED_ON_STATE && LEDS_Arr[LocU8Counter].LED_StrU8OnOffState != LED_OFF_STATE) {
        Loc_LEDErrorState = LED_enuInvalidLogicState;
        break;
    }
    else {
        Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PortNum = LEDS_Arr[LocU8Counter].LED_StrU8PortCfg;
        Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinNum = LEDS_Arr[LocU8Counter].LED_StrU8PinCFg;
      switch (LEDS_Arr[LocU8Counter].LED_StrU8ActiveState) {
    case ACTIVE_HIGH:
        switch (LEDS_Arr[LocU8Counter].LED_StrU8OnOffState) {
            case LED_ON_STATE:
                Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_High;
                break;
            case LED_OFF_STATE:
                Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_Low;
                break;
        }
        break;

    case ACTIVE_LOW:
        switch (LEDS_Arr[LocU8Counter].LED_StrU8OnOffState) {
            case LED_ON_STATE:
                Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_Low;
                break;
            case LED_OFF_STATE:
                Loc_Str_CurrLED_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuOutput_High;
                break;
        }
        break;
}


        Loc_PORTErorState = PORT_enuSetPinConfiguration(&Loc_Str_CurrLED_Arr[LocU8Counter]);
    }
}

if (Loc_PORTErorState != PORT_enuSucceded) {
    Loc_LEDErrorState = LED_enuPortNOK;
}

return Loc_LEDErrorState;

 }

LED_enuErorState LED_enuSetLedState (u8 Copy_u8LedName , u8 Copy_u8LedState)
{
	LED_enuErorState Loc_enuErorState = LED_enusucceeded ;
	DIO_enuErrorStatus_t Loc_enuDioEror = DIO_enuSucceded;
   if (Copy_u8LedName > NUM_OF_LEDS)
   {
	   
	Loc_enuErorState = LED_enuInvalidName ;
	
   }
   else if (Copy_u8LedState != LED_ON_STATE  && Copy_u8LedState != LED_OFF_STATE )
   {
	  
	  Loc_enuErorState = LED_enuInvalidLogicState ;
	   
   }
   else
    {
	   
    if (Copy_u8LedState == LED_ON_STATE)
	 {
		 switch (LEDS_Arr[Copy_u8LedName].LED_StrU8ActiveState)
		 {
			case (ACTIVE_HIGH):
		          Loc_enuDioEror=DIO_enuSetPinLogic(LEDS_Arr[Copy_u8LedName].LED_StrU8PortCfg ,LEDS_Arr[Copy_u8LedName].LED_StrU8PinCFg ,DIO_enuLogicHigh);
				   break ;
	        case(ACTIVE_LOW):
			      Loc_enuDioEror=DIO_enuSetPinLogic(LEDS_Arr[Copy_u8LedName].LED_StrU8PortCfg ,LEDS_Arr[Copy_u8LedName].LED_StrU8PinCFg ,DIO_enuLogicLow);
				   break ;
         }
     }
	else
	{
		switch (LEDS_Arr[Copy_u8LedName].LED_StrU8ActiveState)
		{
			case (ACTIVE_HIGH):
			Loc_enuDioEror=DIO_enuSetPinLogic(LEDS_Arr[Copy_u8LedName].LED_StrU8PortCfg ,LEDS_Arr[Copy_u8LedName].LED_StrU8PinCFg ,DIO_enuLogicLow);
			 break ;
			case(ACTIVE_LOW):
			Loc_enuDioEror=DIO_enuSetPinLogic(LEDS_Arr[Copy_u8LedName].LED_StrU8PortCfg ,LEDS_Arr[Copy_u8LedName].LED_StrU8PinCFg ,DIO_enuLogicHigh);
		     break ;
		} 
		       
		
		
	} 
	
   
   if (Loc_enuDioEror != DIO_enuSucceded)
   {
	   
	   Loc_enuErorState = LED_enuDioNOK ;
   }
   
	
 }
return Loc_enuErorState ;
}
