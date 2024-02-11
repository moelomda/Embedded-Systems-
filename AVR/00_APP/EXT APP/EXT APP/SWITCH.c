 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       SWITCH.c
 * AUTHOR           :       Mohamed Ahmed Fouad Youssef
 * SWC              :       SWITCH
 * Target           :       Atmega32
 * Date             :       11/12/2023  
 * Last Update      :       17/12/2023                                                                             */
 #include "SWITCH.h" 
 
 extern SWITCH_StrCfg_t SWITCHS_Arr[NUM_OF_SWITCHS];
 
 SWITCH_enuErorState SWITCH_Init(void)
 {
      SWITCH_enuErorState Loc_SWITCHErrorState = SWITCH_enusucceeded ;
	  PORT_enuErrorStatus_t Loc_PORTErorState = PORT_enuSucceded ;
	  PORT_StrCFg_t Loc_Str_CurrSWITCH_Arr[NUM_OF_SWITCHS];
	  u8 LocU8Counter;
	  for(LocU8Counter = 0 ; LocU8Counter < NUM_OF_SWITCHS ; LocU8Counter ++)
	  {
		  
		  if (SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PortCfg > NUM_OF_PORTS || SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PortCfg < SWITCH_PORTA )
		  {
			  
			  Loc_SWITCHErrorState = SWITCH_enuInvalidPort ;
			  break;
			  
		  }
		  else if (SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PinCFg > SWITCH_PIN7 || SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PinCFg < SWITCH_PIN0 )
		  {
			  
			  Loc_SWITCHErrorState = SWITCH_enuInvalidPin ;
			  break;
			  
		  }
		  else if (SWITCHS_Arr[LocU8Counter].SWITCH_StrU8SWITCHState != SWITCH_PULLUP && SWITCHS_Arr[LocU8Counter].SWITCH_StrU8SWITCHState != SWITCH_PULLDOWN)
		  {
			  
			  Loc_SWITCHErrorState = SWITCH_enuInvalidSWITCHState ;
			  break;
			  
		  }
		  else
		  {
			    
				 Loc_Str_CurrSWITCH_Arr[LocU8Counter].PORT_StrU8PortNum = SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PortCfg ;
				 Loc_Str_CurrSWITCH_Arr[LocU8Counter].PORT_StrU8PinNum = SWITCHS_Arr[LocU8Counter].SWITCH_StrU8PinCFg;
	            
				  switch(SWITCHS_Arr[LocU8Counter].SWITCH_StrU8SWITCHState)	
				  {
					  
					  case (SWITCH_PULLUP) :
					     Loc_Str_CurrSWITCH_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuInputInternalPullUP ;
					       break;
					  case (SWITCH_PULLDOWN):
					      Loc_Str_CurrSWITCH_Arr[LocU8Counter].PORT_StrU8PinCfg = PORT_enuInputExternalPullDown ;
					       break;
				  }					  
					  
				  
				  Loc_PORTErorState = PORT_enuSetPinConfiguration(&Loc_Str_CurrSWITCH_Arr[LocU8Counter]);
		 }	  
	 }
	 
	 
	 
	     if (Loc_PORTErorState != PORT_enuSucceded)
		  { 
		 
		      Loc_SWITCHErrorState = SWITCH_enuPortNOK ;
	      }
	           return Loc_SWITCHErrorState;
 }
 SWITCH_enuErorState SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName , u8 *Add_u8State)
	{
		 SWITCH_enuErorState Loc_SwitchErorState = SWITCH_enusucceeded ;
		 DIO_enuErrorStatus_t Loc_DioErorsState = DIO_enuSucceded;
		 u8  Loc_u8State ;
		if (Copy_u8SwitchName > NUM_OF_SWITCHS )
		{
			Loc_SwitchErorState = SWITCH_enuInvalidSwitchname; 
		}
		else if (Add_u8State == 0 )
		{
			Loc_SwitchErorState = SWITCH_enuNullPtr;
		}
		else
		{
			 Loc_DioErorsState = DIO_enuGetPinLogic(SWITCHS_Arr[Copy_u8SwitchName].SWITCH_StrU8PortCfg , SWITCHS_Arr[Copy_u8SwitchName].SWITCH_StrU8PinCFg ,&Loc_u8State);
		     switch(SWITCHS_Arr[Copy_u8SwitchName].SWITCH_StrU8SWITCHState)
		       {
			        case (SWITCH_PULLUP):
			   
			       if(Loc_u8State == PORTR_HIGH)
			       {
                      *Add_u8State = SWITCH_NPRESSED ;		   
			       }
			      else
			       {
				     *Add_u8State = SWITCH_PRESSED ;	
				   
			       }
			         break;
			       case (SWITCH_PULLDOWN):  
			 
			        if(Loc_u8State == PORTR_HIGH)
			       {
				      *Add_u8State = SWITCH_PRESSED ;
			       }
			       else
			       {
				     *Add_u8State = SWITCH_NPRESSED ;
				   
			       }
			        break;	
			   }
		}
		if(Loc_DioErorsState != DIO_enuSucceded)
		{
		    Loc_SwitchErorState = SWITCH_enuDioNOK ;	   
			   
		}
		  return Loc_SwitchErorState;
	}