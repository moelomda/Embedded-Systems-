#include <util/delay.h>
#include "LED.h"
#include "7Segments.h"
#include "SWITCH.h"


int main(void)
{
	LED_Init();
	SWITCH_Init();
	Se7enSeg_Init();

	u8 Loc_u8Switch0State = 0;
	u8 Loc_u8Switch1State = 0;
	u8 Loc_u8Switch2State = 0;

	u8 Loc_u8Counter = 0;
	while (1)
	{
		SWITCH_enuGetSwitchState(SWITCH_NO_ZERO , &Loc_u8Switch0State);
		SWITCH_enuGetSwitchState(SWITCH_NO_ONE , &Loc_u8Switch1State);
		SWITCH_enuGetSwitchState(SWITCH_NO_TWO , &Loc_u8Switch2State);

		if (Loc_u8Switch0State == SWITCH_PRESSED)
		{
			LED_enuSetLedState(LED_NO_ZERO, LED_OFF_STATE);
			if (Loc_u8Counter < 99)
			{
				Loc_u8Counter++;
			}
			Se7enSeg_SetValueALL(Loc_u8Counter);
			_delay_ms(500);  // Delay for 500 milliseconds
		}

		if (Loc_u8Switch1State == SWITCH_PRESSED)
		{
			if (Loc_u8Counter > 0)
			{
				Loc_u8Counter--;
			}
			
			Se7enSeg_SetValueALL(Loc_u8Counter);
			_delay_ms(500);  // Delay for 500 milliseconds
		}

		if (Loc_u8Switch2State == SWITCH_PRESSED)
		{
			for(u8 i = Loc_u8Counter; i != 0; i--)
			{
				if (Loc_u8Counter > 0)
				{
					--Loc_u8Counter;
				}
				Se7enSeg_SetValueALL(Loc_u8Counter);
				_delay_ms(500);  // Delay for 500 milliseconds
			}
			// Turn on the LED after the countdown ends
			LED_enuSetLedState(LED_NO_ZERO, LED_ON_STATE);
		}
	}
}