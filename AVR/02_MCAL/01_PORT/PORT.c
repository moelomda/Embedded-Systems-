 /*-----------------------------------------------------------------------------------------------------------------------------------------
 * File             :       PORT.c
 * AUTHOR           :      Mohamed Ahmed Fouad Youssef
 * SWC              :       PORT
 * Target           :       Atmega32
 * Date             :       02/12/2023 10:19:55 am
 * Last Update      :       10/12/2023                                                                                                    */
 

/*---------------------------------------------------**Include Section**--------------------------------------------*/

#include "PORT.h"

// extern DIO_enuPinConfiguration_t DIO_ArrPingCf[8 * NUM_OF_PORTS];

/*---------------------------------------------------**Macro definition**--------------------------------------------*/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)		CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0
#define NUN_OF_PINS 32 

/*-------------------------------------------*PreCompile*-----------------------------------------*/
#if Compile_Way == PRE_COMPILE

void PORT_PreInit()

{
 /* by default every Mcu has at least two ports */
/*--------------------------------------*PIN0*------------------------------------------------*/
     #if DIO_PIN0 == INPUT_PU
	   #define PIN0_DIR  PORT_LOW
	   #define PIN0_PORT PORT_HIGH                                              
	#elif DIO_PIN0 == INPUT_HI
	  #define  PIN0_DIR PORT_LOW
	  #define  PIN0_PORT PORT_LOW
    #elif DIO_PIN0 == OUTPUT_HIGH
	  #define  PIN0_DIR PORT_HIGH
	  #define  PIN0_PORT PORT_HIGH
	#elif DIO_PIN0 == OUTPUT_LOW
	  #define  PIN0_DIR PORT_HIGH
	  #define  PIN0_PORT PORT_LOW
	#else
	    #error "Invalid Configuration "
		#endif 
/*--------------------------------------*PIN1*------------------------------------------------*/
				
		 #if DIO_PIN1 == INPUT_PU
		 #define PIN1_DIR  PORT_LOW
		 #define PIN1_PORT PORT_HIGH
		 #elif DIO_PIN1 == INPUT_HI
		 #define  PIN1_DIR PORT_LOW
		 #define  PIN1_PORT PORT_LOW
		 #elif DIO_PIN1 == OUTPUT_HIGH
		 #define  PIN1_DIR PORT_HIGH
		 #define  PIN1_PORT PORT_HIGH
		 #elif DIO_PIN1 == OUTPUT_LOW
		 #define  PIN1_DIR PORT_HIGH
		 #define  PIN1_PORT PORT_LOW
		 #else
		 #error "Invalid Configuration "
		 #endif 	
/*--------------------------------------*PIN2*------------------------------------------------*/
		 #if DIO_PIN2 == INPUT_PU
		 #define PIN2_DIR  PORT_LOW
		 #define PIN2_PORT PORT_HIGH
		 #elif DIO_PIN2 == INPUT_HI
		 #define  PIN2_DIR PORT_LOW
		 #define  PIN2_PORT PORT_LOW
		 #elif DIO_PIN2 == OUTPUT_HIGH
		 #define  PIN2_DIR PORT_HIGH
		 #define  PIN2_PORT PORT_HIGH
		 #elif DIO_PIN2 == OUTPUT_LOW
		 #define  PIN2_DIR PORT_HIGH
		 #define  PIN2_PORT PORT_LOW
		 #else
		 #error "Invalid Configuration "	
		 #endif 
/*--------------------------------------*PIN3*------------------------------------------------*/
#if DIO_PIN3 == INPUT_PU
#define PIN3_DIR  PORT_LOW
#define PIN3_PORT PORT_HIGH
#elif DIO_PIN3 == INPUT_HI
#define PIN3_DIR PORT_LOW
#define PIN3_PORT PORT_LOW
#elif DIO_PIN3 == OUTPUT_HIGH
#define PIN3_DIR PORT_HIGH
#define PIN3_PORT PORT_HIGH
#elif DIO_PIN3 == OUTPUT_LOW
#define PIN3_DIR PORT_HIGH
#define PIN3_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif 
/*--------------------------------------*PIN4*------------------------------------------------*/
#if DIO_PIN4 == INPUT_PU
#define PIN4_DIR  PORT_LOW
#define PIN4_PORT PORT_HIGH
#elif DIO_PIN4 == INPUT_HI
#define PIN4_DIR PORT_LOW
#define PIN4_PORT PORT_LOW
#elif DIO_PIN4 == OUTPUT_HIGH
#define PIN4_DIR PORT_HIGH
#define PIN4_PORT PORT_HIGH
#elif DIO_PIN4 == OUTPUT_LOW
#define PIN4_DIR PORT_HIGH
#define PIN4_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN5*------------------------------------------------*/
#if DIO_PIN5 == INPUT_PU
#define PIN5_DIR  PORT_LOW
#define PIN5_PORT PORT_HIGH
#elif DIO_PIN5 == INPUT_HI
#define PIN5_DIR PORT_LOW
#define PIN5_PORT PORT_LOW
#elif DIO_PIN5 == OUTPUT_HIGH
#define PIN5_DIR PORT_HIGH
#define PIN5_PORT PORT_HIGH
#elif DIO_PIN5 == OUTPUT_LOW
#define PIN5_DIR PORT_HIGH
#define PIN5_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN6*------------------------------------------------*/
#if DIO_PIN6 == INPUT_PU
#define PIN6_DIR  PORT_LOW
#define PIN6_PORT PORT_HIGH
#elif DIO_PIN6 == INPUT_HI
#define PIN6_DIR PORT_LOW
#define PIN6_PORT PORT_LOW
#elif DIO_PIN6 == OUTPUT_HIGH
#define PIN6_DIR PORT_HIGH
#define PIN6_PORT PORT_HIGH
#elif DIO_PIN6 == OUTPUT_LOW
#define PIN6_DIR PORT_HIGH
#define PIN6_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN7*------------------------------------------------*/
#if DIO_PIN7 == INPUT_PU
#define PIN7_DIR  PORT_LOW
#define PIN7_PORT PORT_HIGH
#elif DIO_PIN7 == INPUT_HI
#define PIN7_DIR PORT_LOW
#define PIN7_PORT PORT_LOW
#elif DIO_PIN7 == OUTPUT_HIGH
#define PIN7_DIR PORT_HIGH
#define PIN7_PORT PORT_HIGH
#elif DIO_PIN7 == OUTPUT_LOW
#define PIN7_DIR PORT_HIGH
#define PIN7_PORT PORT_LOW
#else
 #error "Invalid Configuration "
#endif
/*--------------------------------------*PIN8*------------------------------------------------*/
#if DIO_PIN8 == INPUT_PU
#define PIN8_DIR  PORT_LOW
#define PIN8_PORT PORT_HIGH
#elif DIO_PIN8 == INPUT_HI
#define PIN8_DIR PORT_LOW
#define PIN8_PORT PORT_LOW
#elif DIO_PIN8 == OUTPUT_HIGH
#define PIN8_DIR PORT_HIGH
#define PIN8_PORT PORT_HIGH
#elif DIO_PIN8 == OUTPUT_LOW
#define PIN8_DIR PORT_HIGH
#define PIN8_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN9*------------------------------------------------*/
#if DIO_PIN9 == INPUT_PU
#define PIN9_DIR  PORT_LOW
#define PIN9_PORT PORT_HIGH
#elif DIO_PIN9 == INPUT_HI
#define PIN9_DIR PORT_LOW
#define PIN9_PORT PORT_LOW
#elif DIO_PIN9 == OUTPUT_HIGH
#define PIN9_DIR PORT_HIGH
#define PIN9_PORT PORT_HIGH
#elif DIO_PIN9 == OUTPUT_LOW
#define PIN9_DIR PORT_HIGH
#define PIN9_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN10*------------------------------------------------*/
        #if DIO_PIN10 == INPUT_PU
        #define PIN10_DIR  PORT_LOW
        #define PIN10_PORT PORT_HIGH
	   #elif DIO_PIN10 == INPUT_HI
	   #define  PIN10_DIR PORT_LOW
	   #define  PIN10_PORT PORT_LOW
	   #elif DIO_PIN10 == OUTPUT_HIGH
	   #define  PIN10_DIR PORT_HIGH
	   #define  PIN10_PORT PORT_HIGH
	   #elif DIO_PIN10 == OUTPUT_LOW
	   #define  PIN10_DIR PORT_HIGH
	   #define  PIN10_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
/*---------------------------------------------------*PIN11*------------------------------------------------------*/
	   #if DIO_PIN11 == INPUT_PU
	   #define PIN11_DIR  PORT_LOW
	   #define PIN11_PORT PORT_HIGH
	   #elif DIO_PIN11 == INPUT_HI
	   #define  PIN11_DIR PORT_LOW
	   #define  PIN11_PORT PORT_LOW
	   #elif DIO_PIN11 == OUTPUT_HIGH
	   #define  PIN11_DIR PORT_HIGH
	   #define  PIN11_PORT PORT_HIGH
	   #elif DIO_PIN11 == OUTPUT_LOW
	   #define  PIN11_DIR PORT_HIGH
	   #define  PIN11_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
 /*---------------------------------------------------*PIN12*------------------------------------------------------*/
	   #if DIO_PIN12 == INPUT_PU
	   #define PIN12_DIR  PORT_LOW
	   #define PIN12_PORT PORT_HIGH
	   #elif DIO_PIN12 == INPUT_HI
	   #define  PIN12_DIR PORT_LOW
	   #define  PIN12_PORT PORT_LOW
	   #elif DIO_PIN12 == OUTPUT_HIGH
	   #define  PIN12_DIR PORT_HIGH
	   #define  PIN12_PORT PORT_HIGH
	   #elif DIO_PIN12 == OUTPUT_LOW
	   #define  PIN12_DIR PORT_HIGH
	   #define  PIN12_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
	   
/*---------------------------------------------------*PIN13*------------------------------------------------------*/
	   #if DIO_PIN13 == INPUT_PU
	   #define PIN13_DIR  PORT_LOW
	   #define PIN13_PORT PORT_HIGH
	   #elif DIO_PIN13 == INPUT_HI
	   #define  PIN13_DIR PORT_LOW
	   #define  PIN13_PORT PORT_LOW
	   #elif DIO_PIN13 == OUTPUT_HIGH
	   #define  PIN13_DIR PORT_HIGH
	   #define  PIN13_PORT PORT_HIGH
	   #elif DIO_PIN13 == OUTPUT_LOW
	   #define  PIN13_DIR PORT_HIGH
	   #define  PIN13_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
/*---------------------------------------------------*PIN14*------------------------------------------------------*/
	   #if DIO_PIN14 == INPUT_PU
	   #define PIN14_DIR  PORT_LOW
	   #define PIN14_PORT PORT_HIGH
	   #elif DIO_PIN14 == INPUT_HI
	   #define  PIN14_DIR PORT_LOW
	   #define  PIN14_PORT PORT_LOW
	   #elif DIO_PIN14 == OUTPUT_HIGH
	   #define  PIN14_DIR PORT_HIGH
	   #define  PIN14_PORT PORT_HIGH
	   #elif DIO_PIN14 == OUTPUT_LOW
	   #define  PIN14_DIR PORT_HIGH
	   #define  PIN14_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
/*---------------------------------------------------*PIN15*------------------------------------------------------*/
	   #if DIO_PIN15 == INPUT_PU
	   #define PIN15_DIR  PORT_LOW
	   #define PIN15_PORT PORT_HIGH
	   #elif DIO_PIN15 == INPUT_HI
	   #define  PIN15_DIR PORT_LOW
	   #define  PIN15_PORT PORT_LOW
	   #elif DIO_PIN15 == OUTPUT_HIGH
	   #define  PIN15_DIR PORT_HIGH
	   #define  PIN15_PORT PORT_HIGH
	   #elif DIO_PIN15 == OUTPUT_LOW
	   #define  PIN15_DIR PORT_HIGH
	   #define  PIN15_PORT PORT_LOW
	   #else
	   #error "Invalid Configuration "
	   #endif 
/*--------------------------------------------Assign PORT A & B-----------------------------------------*/
DDRA= CONC(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR);
PORTA= CONC(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);
DDRB= CONC(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR);
PORTB= CONC(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT);   
/*-----------------------------------------*Three Ports*-----------------------------------------------*/ 
 #if (NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS)
 /*--------------------------------------*PIN16*------------------------------------------------*/
#if DIO_PIN16 == INPUT_PU
#define PIN16_DIR  PORT_LOW
#define PIN16_PORT PORT_HIGH
#elif DIO_PIN16 == INPUT_HI
#define PIN16_DIR PORT_LOW
#define PIN16_PORT PORT_LOW
#elif DIO_PIN16 == OUTPUT_HIGH
#define PIN16_DIR PORT_HIGH
#define PIN16_PORT PORT_HIGH
#elif DIO_PIN16 == OUTPUT_LOW
#define PIN16_DIR PORT_HIGH
#define PIN16_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN17*------------------------------------------------*/
#if DIO_PIN17 == INPUT_PU
#define PIN17_DIR  PORT_LOW
#define PIN17_PORT PORT_HIGH
#elif DIO_PIN17 == INPUT_HI
#define PIN17_DIR PORT_LOW
#define PIN17_PORT PORT_LOW
#elif DIO_PIN17 == OUTPUT_HIGH
#define PIN17_DIR PORT_HIGH
#define PIN17_PORT PORT_HIGH
#elif DIO_PIN17 == OUTPUT_LOW
#define PIN17_DIR PORT_HIGH
#define PIN17_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN18*------------------------------------------------*/
#if DIO_PIN18 == INPUT_PU
#define PIN18_DIR  PORT_LOW
#define PIN18_PORT PORT_HIGH
#elif DIO_PIN18== INPUT_HI
#define PIN18_DIR PORT_LOW
#define PIN18_PORT PORT_LOW
#elif DIO_PIN18== OUTPUT_HIGH
#define PIN18_DIR PORT_HIGH
#define PIN18_PORT PORT_HIGH
#elif DIO_PIN18 == OUTPUT_LOW
#define PIN18_DIR PORT_HIGH
#define PIN18_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN19*------------------------------------------------*/
#if DIO_PIN19 == INPUT_PU
#define PIN19_DIR  PORT_LOW
#define PIN19_PORT PORT_HIGH
#elif DIO_PIN19== INPUT_HI
#define PIN19_DIR PORT_LOW
#define PIN19_PORT PORT_LOW
#elif DIO_PIN19== OUTPUT_HIGH
#define PIN19_DIR PORT_HIGH
#define PIN19_PORT PORT_HIGH
#elif DIO_PIN19 == OUTPUT_LOW
#define PIN19_DIR PORT_HIGH
#define PIN19_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN20*------------------------------------------------*/
#if DIO_PIN20== INPUT_PU
#define PIN20_DIR  PORT_LOW
#define PIN20_PORT PORT_HIGH
#elif DIO_PIN20== INPUT_HI
#define PIN20_DIR PORT_LOW
#define PIN20_PORT PORT_LOW
#elif DIO_PIN20== OUTPUT_HIGH
#define PIN20_DIR PORT_HIGH
#define PIN20_PORT PORT_HIGH
#elif DIO_PIN20 == OUTPUT_LOW
#define PIN20_DIR PORT_HIGH
#define PIN20_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN21*------------------------------------------------*/
#if DIO_PIN21== INPUT_PU
#define PIN21_DIR  PORT_LOW
#define PIN21_PORT PORT_HIGH
#elif DIO_PIN21== INPUT_HI
#define PIN21_DIR PORT_LOW
#define PIN21_PORT PORT_LOW
#elif DIO_PIN21== OUTPUT_HIGH
#define PIN21_DIR PORT_HIGH
#define PIN21_PORT PORT_HIGH
#elif DIO_PIN21 == OUTPUT_LOW
#define PIN21_DIR PORT_HIGH
#define PIN21_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN22*------------------------------------------------*/
#if DIO_PIN22== INPUT_PU
#define PIN22_DIR  PORT_LOW
#define PIN22_PORT PORT_HIGH
#elif DIO_PIN22== INPUT_HI
#define PIN22_DIR PORT_LOW
#define PIN22_PORT PORT_LOW
#elif DIO_PIN22== OUTPUT_HIGH
#define PIN22_DIR PORT_HIGH
#define PIN22_PORT PORT_HIGH
#elif DIO_PIN22 == OUTPUT_LOW
#define PIN22_DIR PORT_HIGH
#define PIN22_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN23*------------------------------------------------*/
#if DIO_PIN23== INPUT_PU
#define PIN23_DIR  PORT_LOW
#define PIN23_PORT PORT_HIGH
#elif DIO_PIN23== INPUT_HI
#define PIN23_DIR PORT_LOW
#define PIN23_PORT PORT_LOW
#elif DIO_PIN23== OUTPUT_HIGH
#define PIN23_DIR PORT_HIGH
#define PIN23_PORT PORT_HIGH
#elif DIO_PIN23 == OUTPUT_LOW
#define PIN23_DIR PORT_HIGH
#define PIN23_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif 
/*-----------------------------------------Assign Port C ----------------------------------------*/
DDRC=CONC(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR);
PORTC=CONC(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT);
#endif
/*-----------------------------------------------Four Ports--------------------------------------------*/
#if NUM_OF_PORTS == FOUR_PORTS

/*--------------------------------------*PIN24*------------------------------------------------*/
#if DIO_PIN24== INPUT_PU
#define PIN24_DIR  PORT_LOW
#define PIN24_PORT PORT_HIGH
#elif DIO_PIN24== INPUT_HI
#define PIN24_DIR PORT_LOW
#define PIN24_PORT PORT_LOW
#elif DIO_PIN24== OUTPUT_HIGH
#define PIN24_DIR PORT_HIGH
#define PIN24_PORT PORT_HIGH
#elif DIO_PIN24 == OUTPUT_LOW
#define PIN24_DIR PORT_HIGH
#define PIN24_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN25*------------------------------------------------*/
#if DIO_PIN25== INPUT_PU
#define PIN25_DIR  PORT_LOW
#define PIN25_PORT PORT_HIGH
#elif DIO_PIN25== INPUT_HI
#define PIN25_DIR PORT_LOW
#define PIN25_PORT PORT_LOW
#elif DIO_PIN25== OUTPUT_HIGH
#define PIN25_DIR PORT_HIGH
#define PIN25_PORT PORT_HIGH
#elif DIO_PIN25 == OUTPUT_LOW
#define PIN25_DIR PORT_HIGH
#define PIN25_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN26*------------------------------------------------*/
#if DIO_PIN26== INPUT_PU
#define PIN26_DIR  PORT_LOW
#define PIN26_PORT PORT_HIGH
#elif DIO_PIN26== INPUT_HI
#define PIN26_DIR PORT_LOW
#define PIN26_PORT PORT_LOW
#elif DIO_PIN26== OUTPUT_HIGH
#define PIN26_DIR PORT_HIGH
#define PIN26_PORT PORT_HIGH
#elif DIO_PIN26 == OUTPUT_LOW
#define PIN26_DIR PORT_HIGH
#define PIN26_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN27*------------------------------------------------*/
#if DIO_PIN27== INPUT_PU
#define PIN27_DIR  PORT_LOW
#define PIN27_PORT PORT_HIGH
#elif DIO_PIN27== INPUT_HI
#define PIN27_DIR PORT_LOW
#define PIN27_PORT PORT_LOW
#elif DIO_PIN27== OUTPUT_HIGH
#define PIN27_DIR PORT_HIGH
#define PIN27_PORT PORT_HIGH
#elif DIO_PIN27 == OUTPUT_LOW
#define PIN27_DIR PORT_HIGH
#define PIN27_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN28*------------------------------------------------*/
#if DIO_PIN28== INPUT_PU
#define PIN28_DIR  PORT_LOW
#define PIN28_PORT PORT_HIGH
#elif DIO_PIN28== INPUT_HI
#define PIN28_DIR PORT_LOW
#define PIN28_PORT PORT_LOW
#elif DIO_PIN28== OUTPUT_HIGH
#define PIN28_DIR PORT_HIGH
#define PIN28_PORT PORT_HIGH
#elif DIO_PIN28 == OUTPUT_LOW
#define PIN28_DIR PORT_HIGH
#define PIN28_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN29*------------------------------------------------*/
#if DIO_PIN29== INPUT_PU
#define PIN29_DIR  PORT_LOW
#define PIN29_PORT PORT_HIGH
#elif DIO_PIN29== INPUT_HI
#define PIN29_DIR PORT_LOW
#define PIN29_PORT PORT_LOW
#elif DIO_PIN29== OUTPUT_HIGH
#define PIN29_DIR PORT_HIGH
#define PIN29_PORT PORT_HIGH
#elif DIO_PIN29 == OUTPUT_LOW
#define PIN29_DIR PORT_HIGH
#define PIN29_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN30*------------------------------------------------*/
#if DIO_PIN30== INPUT_PU
#define PIN30_DIR  PORT_LOW
#define PIN30_PORT PORT_HIGH
#elif DIO_PIN30== INPUT_HI
#define PIN30_DIR PORT_LOW
#define PIN30_PORT PORT_LOW
#elif DIO_PIN30== OUTPUT_HIGH
#define PIN30_DIR PORT_HIGH
#define PIN30_PORT PORT_HIGH
#elif DIO_PIN30 == OUTPUT_LOW
#define PIN30_DIR PORT_HIGH
#define PIN30_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*--------------------------------------*PIN31*------------------------------------------------*/
#if DIO_PIN31== INPUT_PU
#define PIN31_DIR  PORT_LOW
#define PIN31_PORT PORT_HIGH
#elif DIO_PIN31== INPUT_HI
#define PIN31_DIR PORT_LOW
#define PIN31_PORT PORT_LOW
#elif DIO_PIN31== OUTPUT_HIGH
#define PIN31_DIR PORT_HIGH
#define PIN31_PORT PORT_HIGH
#elif DIO_PIN31 == OUTPUT_LOW
#define PIN31_DIR PORT_HIGH
#define PIN31_PORT PORT_LOW
#else
#error "Invalid Configuration "
#endif
/*------------------------------------Assign Port D-----------------------------------------------*/	
	
DDRD=CONC(PIN31_DIR,PIN30_DIR,PIN29_DIR,PIN28_DIR,PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_PORT);
PORTD=CONC(PIN31_PORT,PIN30_PORT,PIN29_PORT,PIN28_PORT,PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT);

#endif 	
}

#endif

#if Compile_Way == POST_COMPILE
/*------------------------------------*PostCompile*-------------------------------------------------------*/

 /* void PORT_PostInit(){
	 u8 Loc_u8Counter;
	 DIO_enuPortNumber_t Loc_enuPortNum;
	 DIO_enuPinNumber_t Loc_enuPinNum;
	 for(Loc_u8Counter=0 ; Loc_u8Counter <NUM_OF_PORTS*8; Loc_u8Counter++){
		 
		    
				Loc_enuPortNum = Loc_u8Counter / 8 ;
				Loc_enuPinNum  = Loc_u8Counter % 8 ;
				
				DIO_enuSetPinConfiguration(Loc_enuPortNum , Loc_enuPinNum ,DIO_ArrPingCf[Loc_u8Counter] );
					   
				
			}
	 
 }
 */
 PORT_enuErrorStatus_t PORT_enuSetPinConfiguration(PORT_StrCFg_t *Add_StrPortCfg){
	 
	 PORT_enuErrorStatus_t Loc_enuErorState=  PORT_enuSucceded;
	 
	 if (Add_StrPortCfg->PORT_StrU8PortNum > NUM_OF_PORTS || Add_StrPortCfg->PORT_StrU8PortNum < PORT_enuPortA  )
	 {
		 Loc_enuErorState= PORT_enuInvalidPortNumber;
	 }
	 else if (Add_StrPortCfg->PORT_StrU8PinNum > PORT_enuPin7 || Add_StrPortCfg->PORT_StrU8PinNum < PORT_enuPin0)
	 {
		 Loc_enuErorState=  PORT_enuInvalidPinNumber;
	 }
	 else if  (Add_StrPortCfg->PORT_StrU8PinCfg > PORT_enuOutput_High || Add_StrPortCfg->PORT_StrU8PinCfg < PORT_enuInputInternalPullUP)
	 {
		 
		 Loc_enuErorState = PORT_enuIvalidpinConfiguration;
	 }
	 
	 else
	 {
		 
		 switch(Add_StrPortCfg->PORT_StrU8PortNum)
		 {
			 case PORT_enuPortA :
			 
			 switch(Add_StrPortCfg->PORT_StrU8PinCfg)
			 {
				 
				 case PORT_enuOutput_Low:
				 SET_BIT(DDRA,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTA,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuOutput_High:
				 SET_BIT(DDRA,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTA,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuInputInternalPullUP:
				 CLR_BIT(DDRA,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTA,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 case PORT_enuInputExternalPullDown:
				 CLR_BIT(DDRA,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTA,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 
				 
				 
			 }
			 break;
			 
			 case PORT_enuPortB :
			 
			 switch(Add_StrPortCfg->PORT_StrU8PinCfg)
			 {
				 
				 case PORT_enuOutput_Low:
				 SET_BIT(DDRB,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTB,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuOutput_High:
				 SET_BIT(DDRB,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTB,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuInputInternalPullUP:
				 CLR_BIT(DDRB,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTB,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 case PORT_enuInputExternalPullDown:
				 CLR_BIT(DDRB,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTB,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 
				 
			 }
			 break;
			 
			 case PORT_enuPortC :
			 switch(Add_StrPortCfg->PORT_StrU8PinCfg)
			 {
				 
				 case PORT_enuOutput_Low:
				 SET_BIT(DDRC,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTC,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuOutput_High:
				 SET_BIT(DDRC,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTC,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuInputInternalPullUP:
				 CLR_BIT(DDRC,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTC,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 case PORT_enuInputExternalPullDown:
				 CLR_BIT(DDRC,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTC,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 
				 
			 }
			 break;
			 
			 case PORT_enuPortD :
			 switch(Add_StrPortCfg->PORT_StrU8PinCfg)
			 {
				 case PORT_enuOutput_Low:
				 SET_BIT(DDRD,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTD,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuOutput_High:
				 SET_BIT(DDRD,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTD,Add_StrPortCfg->PORT_StrU8PinNum);
				 
				 break;
				 case PORT_enuInputInternalPullUP:
				 CLR_BIT(DDRD,Add_StrPortCfg->PORT_StrU8PinNum);
				 SET_BIT(PORTD,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 case PORT_enuInputExternalPullDown:
				 CLR_BIT(DDRD,Add_StrPortCfg->PORT_StrU8PinNum);
				 CLR_BIT(PORTD,Add_StrPortCfg->PORT_StrU8PinNum);
				 break;
				 
				 
				 
			 }
			 break;
			 
			 
		 }
		 
	 }
	 
	 return Loc_enuErorState;
 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 }
 
 
 
 
 
 
 
 
 
 #endif
