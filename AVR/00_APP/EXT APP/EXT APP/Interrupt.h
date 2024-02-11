/******************************************************************************
 *
 * Module: Interrupt_Driver
 *
 * File Name: Interrupt.h
 *
 * Description: Header file for the Interrupt driver implementation
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "InterruptCfg.h"
#include "std_types.h"
#include "BIT_MATH.h"
#include "Registers.h"

/* Macros to enable or disable interrupt pins */
#define EXTI_DISABLE 0  // Disable interrupt pin
#define EXTI_ENABLE  1  // Enable interrupt pin

/* INT0 Configuration Masks */
#define MCUCR_INT0_MASK 0xFC  // Mask to configure INT0 in MCUCR register

/* INT1 Configuration Masks */
#define MCUCR_INT1_MASK 0xF3  // Mask to configure INT1 in MCUCR register

/* INT2 Configuration Masks */
#define MCUCSR_INT2_MASK 0xBF  // Mask to configure INT2 in MCUCSR register

/* INT0 Trigger Level Definitions */
#define INT0_LOW_LEV 0x00       // Low Level Trigger
#define INT0_ANY_EDGE 0x01      // Any Logical Change Trigger
#define INT0_FALLING_EDGE 0x02  // Falling Edge Trigger
#define INT0_RISING_EDGE 0x03   // Rising Edge Trigger

/* INT1 Trigger Level Definitions */
#define INT1_LOW_LEV 0x00       // Low Level Trigger
#define INT1_ANY_EDGE 0x04      // Any Logical Change Trigger
#define INT1_FALLING_EDGE 0x08  // Falling Edge Trigger
#define INT1_RISING_EDGE 0x0C   // Rising Edge Trigger

/* INT2 Trigger Level Definitions */
#define INT2_FALLING_EDGE 0x00  // Falling Edge Trigger
#define INT2_RISING_EDGE 0x40   // Rising Edge Trigger

/* Function to initialize the interrupt */
void EXTI_Init(void);

#endif /* INTERRUPT_H_ */
