/*
 * -------------------------------------------------------------------------------------------------------------------------------------
 * |                                    Timer.c                                                                                        |
 * -------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:                                                                                                               |
 * |  This source file contains the implementation of the Timer Driver for ATmega32.                                                   |
 * |  It initializes Timer/Counter  to operate in either CTC (Clear Timer on Compare Match) or Normal mode.                            |
 * |  The driver provides an overflow interrupt service routine for user-defined actions.                                              |
 * |																																   |
 * |                                                                                                                                   |
 * |  Author: Mohamed Ahmed Fouad Youssef                                                                                              |
 * |  Created on: 2024-01-17                                                                                                           |
 * |                                                                                                                                   |
 * |  Operation Modes:                                                                                                                 |
 * |   - CTC (Clear Timer on Compare Match) mode                                                                                       |
 * |   - Normal mode                                                                                                                   |
 * -------------------------------------------------------------------------------------------------------------------------------------
 */

#include "Timer.h"
void (*TIMER_FuncArr[TIMEROF_INTERRUPT_COUNT])(void) = {NULL, NULL, NULL , NULL };
void (*TIMER_FuncArr1[TIMERCM_INTERRUPT_COUNT])(void) = {NULL, NULL, NULL , NULL };
/*
 * Global variable: Timer0_u16OverFlowTime
 * Description: Represents the duration (time) of one Timer0 overflow in microseconds.
 *              This value is used to calculate the number of overflows needed to reach a specific time value.
 */
f32 Timer0_f32OverFlowTime = 0;

u8 Timer0_u8Tcnt0Temp = 0 ;
/*
 * Global variable: Timer0_f32Cov
 * Description: Represents the fractional part of the number of overflows needed to reach a specific time value for Timer0.
 *              This variable is used to handle cases where the time value is not an exact multiple of the overflow time.
 */
f32 Timer0_f32Cov = 0.00;


/*
 * Global variable: Timer0_u16PreLoadValue
 * Description: Represents the value to be loaded into the Timer0 counter register (TCNT0).
 *              This value is calculated based on Timer0_u16OverFlowTime, Timer0_f32Cov, and the desired time value.
 */
f32 Timer0_f32PreLoadValue = 0;

/*
 * Global variable: Timer2_u16OverFlowTime
 * Description: Represents the duration (time) of one Timer2 overflow in microseconds.
 *              This value is used to calculate the number of overflows needed to reach a specific time value.
 */
u16 Timer2_u16OverFlowTime = 0;

/*
 * Global variable: Timer2_f32Cov
 * Description: Represents the fractional part of the number of overflows needed to reach a specific time value for Timer2.
 *              This variable is used to handle cases where the time value is not an exact multiple of the overflow time.
 */
f32 Timer2_f32Cov = 0.00;

u8 test = 0;

/*
 * Global variable: Timer2_u16PreLoadValue
 * Description: Represents the value to be loaded into the Timer2 counter register (TCNT2).
 *              This value is calculated based on Timer2_u16OverFlowTime, Timer2_f32Cov, and the desired time value.
 */
u16 Timer2_u16PreLoadValue = 0;
/*--------------------------------------------------------------------------------------*/
u32 Timer1_u32OverFlowTime = 0;


f32 Timer1_f32Cov = 0.00;



u16 Timer1_u16PreLoadValue = 0;

/*
 * =============================================================================
 * |                             TIMER INITIALIZATION FUNCTION                   |
 * =============================================================================
 * | Timer_Init: Initializes a timer with the specified name and mode.           |
 * | Returns an error status from Timer_enuErrorStatus_t.                        |
 * =============================================================================
 */
Timer_enuErrorStatus_t Timer_Init(u8 Copy_u8TimerName, u8 Copy_u8TimerMode)
{
	u8 Loc_u8MaskVar = 0 ;

	/* Default to success status */
	Timer_enuErrorStatus_t Loc_enuTimerErrorStatus = Timer_enuSucceeded;

	/* Validate the timer mode */
	if (Copy_u8TimerMode < NORMAL_MODE  && Copy_u8TimerMode > CTC_ICR_MODE )
	{
		Loc_enuTimerErrorStatus = Timer_enuInvalidTimerMode;
	}
	else if (Copy_u8TimerName < TIMER0 || Copy_u8TimerName > TIMER2)
	{
		/* Validate the timer name */
		Loc_enuTimerErrorStatus = Timer_enuInvalidTimerName;
	}
	else
	{
		/* Configure the timer based on the specified name and mode */
		if (Copy_u8TimerName == TIMER0)
		{
			switch (Copy_u8TimerMode)
			{
				case NORMAL_MODE:
				/* Configure Timer0 in Normal Mode with No Clock */
				TCCR0 = 0x00;
				TCNT0 = 0x00;    /* Initialize Timer0 counter value to 0x00 */
				
				/* Clear Timer0 Overflow Flag in TIFR */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= TOV0_MASK;
				TIFR = Loc_u8MaskVar;
				
				/* Set the I-bit in the Status Register to enable global interrupts */
				/*Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;*/
				SET_BIT(SREG , 7);
				
				/* Enable Timer0 Overflow interrupt by setting TOIE0 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= TOIE0_MASK;
				Loc_u8MaskVar |= 0x01;
				TIMSK = Loc_u8MaskVar;
				
				break;
				
				case CTC_MODE:
				/* Configure Timer0 in CTC Mode with no clock and COM pins are Disconnected */
				TCCR0 = 0x08;
				TCNT0 = 0x00;    /* Initialize Timer0 counter value to 0x00 */
				
				/* Clear Timer0 Output Compare Flag in TIFR to ensure no pending interrupt */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= OCF0_MASK;
				TIFR = Loc_u8MaskVar;
				
				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;
				
				/* Enable Timer0 Output Compare Match Interrupt by setting OCIE0 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= OCIE0_MASK;
				Loc_u8MaskVar |= 0x02;
				TIMSK = Loc_u8MaskVar;
				
				break;
			}
		}
		else if (Copy_u8TimerName == TIMER2)
		{
			switch(Copy_u8TimerMode)
			{
				case NORMAL_MODE:
				/* Configure Timer2 in Normal Mode with No Clock */
				TCCR2 = 0x00;
				TCNT2 = 0x00;    /* Initialize Timer2 counter value to 0x00 */
				
				/* Clear Timer2 Overflow Flag in TIFR to ensure no pending interrupt */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= TOV2_MASK;
				TIFR = Loc_u8MaskVar;
				
				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;
				
				/* Enable Timer2 Overflow interrupt by setting TOIE2 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= TOIE2_MASK;
				Loc_u8MaskVar |= 0x40;
				TIMSK = Loc_u8MaskVar;
				
				break;
				
				case CTC_MODE:
				/* Configure Timer2 in CTC Mode with No Clock and COM pins are Disconnected */
				TCCR2 = 0x08;
				TCNT2 = 0x00;    /* Initialize Timer2 counter value to 0x00 */
				
				/* Clear Timer0 Output Compare Flag in TIFR to ensure no pending interrupt */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= OCF2_MASK;
				TIFR = Loc_u8MaskVar;
				
				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;
				
				/* Enable Timer2 Output Compare Match Interrupt by setting OCIE0 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= OCIE2_MASK;
				Loc_u8MaskVar |= 0x80;
				TIMSK = Loc_u8MaskVar;
				
				break;
			}
		}
		else
		{
			switch(Copy_u8TimerMode)
			{
				case NORMAL_MODE:
				/* Configure Timer1 in Normal Mode */
				// Configure Timer/Counter Control Register A (TCCR1A)
				TCCR1A = 0x00;   // Configure Normal Mode and Disable Compare Output (COM) Pins

				// Configure Timer/Counter Control Register B (TCCR1B)
				TCCR1B = 0x00;   // Configure Normal Mode, No Clock, and Disable Input Capture Noise Canceler

				// Initialize Timer/Counter Register (TCNT1) to 0
				TCNT1 = 0x0000;  // Set the initial count value of Timer/Counter 1 to zero

				/* Clear Timer1 Overflow Flag in TIFR */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= TOV1_MASK;
				TIFR = Loc_u8MaskVar;

				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;

				/* Enable Timer1 Overflow interrupt by setting TOIE1 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= TOIE1_MASK;
				Loc_u8MaskVar |= 0x04;
				TIMSK = Loc_u8MaskVar;

				break;

				case CTC_OCR_MODE:
				// Configure Timer1 in CTC OCR Mode
				// Configure Timer/Counter Control Register A (TCCR1A)
				TCCR1A = 0x00;

				// Configure Timer/Counter Control Register B (TCCR1B)
				TCCR1B = 0x09;  // CTC OCR Mode, No Prescaling (CS12 = 0, CS11 = 0, CS10 = 1)

				// Initialize Timer/Counter Register (TCNT1) to 0
				TCNT1 = 0x00;

				/* Clear Timer1 Output Compare Flags in TIFR to ensure no pending interrupts */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= OCF1A_MASK;
				TIFR = Loc_u8MaskVar;
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= OCF1B_MASK;
				TIFR = Loc_u8MaskVar;

				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;

				/* Enable Timer1 Output Compare Match A and B interrupts by setting OCIE1A and OCIE1B in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= OCIE1A_MASK;
				Loc_u8MaskVar |= 0x10;
				TIMSK = Loc_u8MaskVar;
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= OCIE1B_MASK;
				Loc_u8MaskVar |= 0x08;
				TIMSK = Loc_u8MaskVar;

				break;

				case CTC_ICR_MODE:
				// Configure Timer1 in CTC ICR Mode
				// Configure Timer/Counter Control Register A (TCCR1A)
				TCCR1A = 0x00;   // Disable Compare Output (COM) Pins

				// Configure Timer/Counter Control Register B (TCCR1B)
				TCCR1B = 0x19;  // CTC Mode, NO Prescaler (CS12 = 0, CS11 = 0, CS10 = 1)

				// Initialize Timer/Counter Register (TCNT1) to 0
				TCNT1 = 0x00;

				/* Clear Timer1 Input Capture Flag in TIFR to ensure no pending interrupt */
				Loc_u8MaskVar = TIFR;
				Loc_u8MaskVar &= ICF1_MASK;
				TIFR = Loc_u8MaskVar;

				/* Set the I-bit in the Status Register to enable global interrupts */
				Loc_u8MaskVar = SREG;
				Loc_u8MaskVar &= IBIT_SREG_MASK;
				Loc_u8MaskVar |= 0x80;
				SREG = Loc_u8MaskVar;

				/* Enable Timer1 Input Capture interrupt by setting TICIE1 in TIMSK */
				Loc_u8MaskVar = TIMSK;
				Loc_u8MaskVar &= TICIE1_MASK;
				Loc_u8MaskVar |= 0x20;
				TIMSK = Loc_u8MaskVar;


			break;

            }			 
		 }
       }

    return Loc_enuTimerErrorStatus;
}
/*
 * =============================================================================
 * |                          TIMER SET VALUE MICROSECONDS                      |
 * =============================================================================
 * | Timer_SetValueMicro: Sets the timer value in microseconds for the specified|
 * | timer and mode. Initializes timer settings based on the provided parameters|
 * | Returns an error status from Timer_enuErrorStatus_t.                       |
 * |                                                                            |
 * | Parameters:                                                                |
 * |   - Copy_u8TimerName: The timer to configure (TIMER0, TIMER2).             |
 * |   - Copy_u8Value: The desired timer value in microseconds.                 |
 * |   - Copy_u8PreScaler: The pre-scaler value for the timer.                  |
 * |   - Copy_u8TimerMode: The mode of operation for the timer (NORMAL_MODE).   |
 * |                                                                            |
 * | Notes:                                                                     |
 * |   - This function configures the timer's pre-scaler, overflow time, and    |
 * |     sets up appropriate interrupt vectors for the specified mode.          |
 * |   - The actual action to be performed during timer overflow is left as a   |
 * |     placeholder. Adjust the __vector_11 and __vector_7 functions as needed.|
 * |   - Ensure proper definition of macros (TIMER0, TIMER2, NO_PRESCALER, etc.)|
 * |     and configure interrupt vectors accordingly.                           |
 * |                                                                            |
 * | Example usage:                                                             |
 * |   Timer_SetValueMicro(TIMER0, 1000, PRESCALER_64, NORMAL_MODE);            |
 * =============================================================================
 */
Timer_enuErrorStatus_t Timer_SetValueMicro(u8 Copy_u8TimerName, f32 Copy_f32Value, u16 Copy_u8PreScaler, u8 Copy_u8TimerMode)
{  
	 Timer_enuErrorStatus_t Loc_ErrorStatus_t = Timer_enuSucceeded ;
	f32 Loc_f32FracPart = 0;
	u8 Loc_u8MaskVar = 0;
	u8 Loc_u8Resolution = 255;
	
	//u16 Loc_u16Resolution = 65535;
	
	Timer_Init(Copy_u8TimerName, Copy_u8TimerMode);
	

	/* Check if the timer is TIMER0 */
	if (Copy_u8TimerName == TIMER0)
	{
		/* Configure the timer based on the specified mode */
		switch (Copy_u8TimerMode)
		{
			case NORMAL_MODE:
			/* Calculate overflow time and fractional part for Normal Mode */
			Timer0_f32OverFlowTime = ((Copy_u8PreScaler) / 8) * 256;
			Timer0_f32Cov = ((f32)(Copy_f32Value) / (f32)(Timer0_f32OverFlowTime));
			Loc_f32FracPart = (f32)Timer0_f32Cov - (u16)Timer0_f32Cov;

			/* Check if the calculated count of overflow is greater than or equal to 1 */
			if (Timer0_f32Cov >= 1)
			{
				Timer0_f32PreLoadValue = 256 * (1 - Loc_f32FracPart);

				/* Check if the pre-load value is 256 and adjust accordingly */
				if (Timer0_f32PreLoadValue == 256)
				{
					Timer0_f32PreLoadValue = 0;
				}
				else
				{
					Timer0_f32Cov = Timer0_f32Cov + 1;
				}
			}
			else
			{
				Timer0_f32PreLoadValue = 256 * (1 - Timer0_f32Cov);
				Timer0_f32Cov = 1;
				
			}
			Timer0_u8Tcnt0Temp = (u8)Timer0_f32PreLoadValue ;
			TCNT0 = (u8)Timer0_u8Tcnt0Temp ;
			
			break;

			case CTC_MODE:
			/* Find the highest possible resolution for CTC Mode */
			while (((u16)Copy_f32Value) % Loc_u8Resolution != 0)
			{
				Loc_u8Resolution--;
			}

			/* Set the OCR0 register with the calculated resolution */
			OCR0 = Loc_u8Resolution;

			/* Calculate the overflow time for CTC Mode */
			Timer0_f32Cov = (Copy_f32Value) / (Loc_u8Resolution);
               
			break;
			
			default:
			Loc_ErrorStatus_t = Timer_enuInvalidTimerMode ; 
			break;
		}

		/* Configure the prescaler based on the specified value */
		switch (Copy_u8PreScaler)
		{
			case NO_PRESCALER:
			Loc_u8MaskVar = TCCR0;
			Loc_u8MaskVar &= PRESCALER_MASK;
			Loc_u8MaskVar |= 0x01;
			TCCR0 = Loc_u8MaskVar;
			break;

			case PRESCALER_8:
			Loc_u8MaskVar = TCCR0;
			Loc_u8MaskVar &= PRESCALER_MASK;
			Loc_u8MaskVar |= 0x02;
			TCCR0 = Loc_u8MaskVar;
			break;

			case PRESCALER_64:
			Loc_u8MaskVar = TCCR0;
			Loc_u8MaskVar &= PRESCALER_MASK;
			Loc_u8MaskVar |= 0x03;
			TCCR0 = Loc_u8MaskVar;
			break;

			case PRESCALER_256:
			Loc_u8MaskVar = TCCR0;
			Loc_u8MaskVar &= PRESCALER_MASK;
			Loc_u8MaskVar |= 0x04;
			TCCR0 = Loc_u8MaskVar;
			break;

			case PRESCALER_1024:
			Loc_u8MaskVar = TCCR0;
			Loc_u8MaskVar &= PRESCALER_MASK;
			Loc_u8MaskVar |= 0x05;
			TCCR0 = Loc_u8MaskVar;
			break;
			default:
			Loc_ErrorStatus_t = Timer_enuInvalidTimerPreScaler;
			break;
		}
	}
         else if (Copy_u8TimerName == TIMER2)
          {
	   		
	   		 switch(Copy_u8TimerMode)
	   		 {
		   		 case NORMAL_MODE :
		   		 Timer2_u16OverFlowTime = ((Copy_u8PreScaler)/8)*256 ;
		   		 Timer2_f32Cov = ((f32)Copy_f32Value)/((f32)Timer2_u16OverFlowTime);
		   		 Loc_f32FracPart = (f32)Timer2_f32Cov - (f32)(u16)Timer2_f32Cov ;
		   		 if (Timer2_f32Cov >= 1 )
		   		 {
			   		 Timer2_u16PreLoadValue = 256 * (1-Loc_f32FracPart);
			   		 if(Timer2_u16PreLoadValue == 256)
			   		 {
				   		 Timer2_u16PreLoadValue = 0;
			   		 }
			   		 else
			   		 {
				   		 Timer2_f32Cov = (u16)Timer2_f32Cov + 1 ;
			   		 }
			   		 TCNT2 = Timer2_u16PreLoadValue ;
		   		 }
		   		 else
		   		 {
			   		 Timer2_u16PreLoadValue = 256 * (1-Timer2_f32Cov);
			   		 Timer2_f32Cov = 1 ;
			   		 TCNT2 =  Timer2_u16PreLoadValue ;
		   		 }
					break; 
					  case CTC_MODE  :
					  while (((u16)Copy_f32Value) % Loc_u8Resolution != 0)
					  {
						  Loc_u8Resolution -- ;
					  }
					  OCR2 = Loc_u8Resolution ;
					  
					  Timer2_f32Cov = (Copy_f32Value)/(Loc_u8Resolution);
		   		 
		   		         break;
							 
				 default:
					Loc_ErrorStatus_t = Timer_enuInvalidTimerMode ;
				  break;
					 
	   		 }
	   		 
	   		 switch(Copy_u8PreScaler)
	   		 {
		   		 Loc_u8MaskVar = TCCR2 ;
		   		 Loc_u8MaskVar &= PRESCALER_MASK ;
		   		 
		   		 case NO_PRESCALER :
		   		 Loc_u8MaskVar |= 0x01 ;
		   		 TCCR2 = Loc_u8MaskVar ;
		   		 break;
		   		 case PRESCALER_8  :
		   		 Loc_u8MaskVar |= 0x02 ;
		   		 TCCR2 = Loc_u8MaskVar ;
		   		 break;
		   		 case PRESCALER_64 :
		   		 Loc_u8MaskVar |= 0x03 ;
		   		 TCCR2 = Loc_u8MaskVar ;
		   		 break;
		   		 case PRESCALER_256:
		   		 Loc_u8MaskVar |= 0x04 ;
		   		 TCCR2 = Loc_u8MaskVar ;
		   		 break;
		   		 case PRESCALER_1024:
		   		 Loc_u8MaskVar |= 0x05 ;
		   		 TCCR2 = Loc_u8MaskVar ;
		   		 break;
				 default:	
				 Loc_ErrorStatus_t = Timer_enuInvalidTimerPreScaler;
				 break;
	   		 }
	   		 
   		 }    
			
				
/*	else if (Copy_u8TimerName == TIMER1 )
		{
			
			switch (Copy_u8TimerMode)
			{
				case NORMAL_MODE:
	
				Timer1_u32OverFlowTime = ((Copy_u8PreScaler) / 8) * 65535;
				Timer1_f32Cov = ((f32)(Copy_u32Value) / (f32)(Timer1_u32OverFlowTime));
				Loc_f32FracPart = (f32)Timer1_f32Cov - (f32)(u16)Timer1_f32Cov;

				if (Timer1_f32Cov >= 1)
				{
					Timer1_u16PreLoadValue = 65535 * (1 - Loc_f32FracPart);

		
						Timer1_f32Cov = (u16)Timer1_f32Cov + 1;
				
				}
				else
				{
					Timer1_u16PreLoadValue = 65535 * (1 - Timer1_f32Cov);
					Timer1_f32Cov = 1;
					
				}
				TCNT1 = Timer1_u16PreLoadValue;
				break;

			   case CTC_MODE  :
			   while (Copy_u32Value % Loc_u16Resolution != 0)
			   {
				   Loc_u8Resolution -- ;
			   }
			   OCR1A = Loc_u8Resolution ;
			   
			   Timer1_f32Cov = (Copy_u32Value)/(Loc_u16Resolution);
			   
			   break;
			
			}
			switch (Copy_u8PreScaler)
			{
				case NO_PRESCALER:
				Loc_u8MaskVar = TCCR0;
				Loc_u8MaskVar &= PRESCALER_MASK;
				Loc_u8MaskVar |= 0x01;
				TCCR0 = Loc_u8MaskVar;
				break;

				case PRESCALER_8:
				Loc_u8MaskVar = TCCR0;
				Loc_u8MaskVar &= PRESCALER_MASK;
				Loc_u8MaskVar |= 0x02;
				TCCR0 = Loc_u8MaskVar;
				break;

				case PRESCALER_64:
				Loc_u8MaskVar = TCCR0;
				Loc_u8MaskVar &= PRESCALER_MASK;
				Loc_u8MaskVar |= 0x03;
				TCCR0 = Loc_u8MaskVar;
				break;

				case PRESCALER_256:
				Loc_u8MaskVar = TCCR0;
				Loc_u8MaskVar &= PRESCALER_MASK;
				Loc_u8MaskVar |= 0x04;
				TCCR0 = Loc_u8MaskVar;
				break;

				case PRESCALER_1024:
				Loc_u8MaskVar = TCCR0;
				Loc_u8MaskVar &= PRESCALER_MASK;
				Loc_u8MaskVar |= 0x05;
				TCCR0 = Loc_u8MaskVar;
				break;
				default:
				Loc_ErrorStatus_t = Timer_enuInvalidTimerPreScaler;
				break;
			}
			}
			*/
			else
			{
				Loc_ErrorStatus_t = Timer_enuInvalidTimerName ;
			}
			
			return Loc_ErrorStatus_t ;
				
}

/*
 * ----------------------------------------------------------------------------
 * Function: TIMER_SetCallBackOF
 * ----------------------------------------------------------------------------
 * Description:
 * Sets the callback function for the specified timer overflow interrupt.
 * 
 * Parameters:
 * - Copy_u8TimerName: Identifier for the timer overflow interrupt
 *   (TIMER0_OF_INTERRUPT, TIMER1_OF_INTERRUPT, TIMER2_OF_INTERRUPT).
 * - Add_CaLLBackFun: Pointer to the function that will be called when the
 *   specified timer's overflow interrupt occurs.
 * ----------------------------------------------------------------------------
 */
void TIMER_SetCallBack(u8 Copy_u8InterruptName, void (*Add_CaLLBackFun)(void))
{
    switch (Copy_u8InterruptName)
    {
        case TIMER0_OF_INTERRUPT:
            TIMER_FuncArr[TIMER0_OF_INTERRUPT] = Add_CaLLBackFun;
            break;

        case TIMER1_OF_INTERRUPT:
            TIMER_FuncArr[TIMER1_OF_INTERRUPT] = Add_CaLLBackFun;
                break;
        case TIMER2_OF_INTERRUPT:
            TIMER_FuncArr[TIMER2_OF_INTERRUPT] = Add_CaLLBackFun;
                break;
		case TIMER0_CM_INTERRUPT:
		    TIMER_FuncArr1[TIMER0_CM_INTERRUPT] = Add_CaLLBackFun;
			     break;
		case TIMER1_CM_INTERRUPT:
		TIMER_FuncArr1[TIMER1_CM_INTERRUPT] = Add_CaLLBackFun;	
		       break;
		case TIMER2_CM_INTERRUPT:
		TIMER_FuncArr1[TIMER2_CM_INTERRUPT] = Add_CaLLBackFun;
		       break;
    }
}

/* 
 * Interrupt Service Routine for Timer/Counter0 Overflow
 * This function is invoked when Timer/Counter0 overflows.
 */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{ 
	static u32 Timer_u32Counter = 0 ;
	Timer_u32Counter++;  /* Increment the overflow counter */
	test = 10 ;
	test ++ ;
	/* Check if the counter has reached the specified overflow value */
	if (Timer_u32Counter == Timer0_f32Cov)
	{
		Timer_u32Counter = 0;           /* Reset the counter */
		TCNT0 = Timer0_u8Tcnt0Temp;  /* Reload the timer with the preloaded value */
		TIMER_FuncArr[TIMER0_OF_INTERRUPT]();  /* Call the registered callback function for Timer/Counter0 overflow */
		
	}
}

/* 
 * Interrupt Service Routine for Timer/Counter2 Overflow
 * This function is invoked when Timer/Counter2 overflows.
 */
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u16 Timer_u16Counter = 0 ;
	Timer_u16Counter++;  /* Increment the overflow counter */
	
	/* Check if the counter has reached the specified overflow value */
	if (Timer_u16Counter == (u16)Timer2_f32Cov)
	{
		Timer_u16Counter = 0;           /* Reset the counter */
		TCNT2 = Timer2_u16PreLoadValue;  /* Reload the timer with the preloaded value */
		TIMER_FuncArr[TIMER2_OF_INTERRUPT]();  /* Call the registered callback function for Timer/Counter2 overflow */
	}
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	static u16 Timer_u16Counter = 0 ;
	
	if (Timer_u16Counter == (u16)(Timer0_f32Cov))
	{
		TIMER_FuncArr1[TIMER0_CM_INTERRUPT]();
	}
	
	
	
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	
	static u16 Timer_u16Counter = 0 ;
	
	if (Timer_u16Counter == (u16)(Timer2_f32Cov))
	{
		TIMER_FuncArr1[TIMER2_CM_INTERRUPT]();
	}
	
}


