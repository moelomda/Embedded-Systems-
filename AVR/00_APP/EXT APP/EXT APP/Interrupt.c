/******************************************************************************
 *
 * Module: Interrupt_Driver
 *
 * File Name: Interrupt.c
 *
 * Description: Source file for the Interrupt driver implementation
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/ 

#include "Interrupt.h"
void EXTI_Init(void)
{
	/* Read the current value of MCUCR register for INT0 */
	u8 Loc_u8RegVal_INT0 = MCUCR;

	/* Clear the bits related to INT0 in MCUCR using the defined mask */
	Loc_u8RegVal_INT0 &= MCUCR_INT0_MASK;

	/* Set the desired sense control for INT0 */
	Loc_u8RegVal_INT0 |= INT0_SENSE_CTRL;

	/* Update MCUCR register with the modified value for INT0 */
	MCUCR = Loc_u8RegVal_INT0;

	/* Read the current value of MCUCR register for INT1 */
	u8 Loc_u8RegVal_INT1 = MCUCR;

	/* Clear the bits related to INT1 in MCUCR using the defined mask */
	Loc_u8RegVal_INT1 &= MCUCR_INT1_MASK;

	/* Set the desired sense control for INT1 */
	Loc_u8RegVal_INT1 |= INT1_SENSE_CTRL;

	/* Update MCUCR register with the modified value for INT1 */
	MCUCR = Loc_u8RegVal_INT1;

	/* Read the current value of MCUCSR register for INT2 */
	u8 Loc_u8RegVal_INT2 = MCUCSR;

	/* Clear the bits related to INT2 in MCUCSR using the defined mask */
	Loc_u8RegVal_INT2 &= MCUCSR_INT2_MASK;

	/* Set the desired sense control for INT2 */
	Loc_u8RegVal_INT2 |= INT2_SENSE_CTRL;

	/* Update MCUCSR register with the modified value for INT2 */
	MCUCSR = Loc_u8RegVal_INT2;

	/* Enable or Disable INT0 based on user configuration */
	#if INT0_MODE == EXTI_ENABLE
	SET_BIT(GICR, 6);
	#elif INT0_MODE == EXTI_DISABLE
	CLR_BIT(GICR, 6);
	#endif

	/* Enable or Disable INT1 based on user configuration */
	#if INT1_MODE == EXTI_ENABLE
	SET_BIT(GICR, 7);
	#elif INT1_MODE == EXTI_DISABLE
	CLR_BIT(GICR, 7);
	#endif

	/* Enable or Disable INT2 based on user configuration */
	#if INT2_MODE == EXTI_ENABLE
	SET_BIT(GICR, 5);
	#elif INT2_MODE == EXTI_DISABLE
	CLR_BIT(GICR, 5);
	#endif

	/* Enable Global Interrupt if not already enabled */
	if (!(SREG & (1 << 7))) {
		SET_BIT(SREG, 7);
	}
	
}

