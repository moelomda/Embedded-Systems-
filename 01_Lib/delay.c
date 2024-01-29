/*
 * delay.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Mohamed Ahmed Fouad Youssef
 */

#include "std_types.h"
#include "delay.h"

void DIO_enuCustomDelay(u32 Copy_u32DelayValue)
{
	volatile u32 Loc_iu32Counter;
	volatile u32 Loc_ju32Counter;
	
	for (Loc_iu32Counter=0 ; Loc_iu32Counter < Copy_u32DelayValue ; Loc_iu32Counter++)
	{
		for(Loc_ju32Counter=0 ; Loc_ju32Counter<1000 ; Loc_ju32Counter++)
		{
			
			
		}
	}
}