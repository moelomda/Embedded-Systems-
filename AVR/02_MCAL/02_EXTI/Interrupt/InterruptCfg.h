/******************************************************************************
 *
 * Module: Interrupt_Driver_Cfg
 *
 * File Name: Interrupt_Driver_Cfg.h
 *
 * Description: Header file for the Interrupt driver Configurations
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/ 
#ifndef INTERRUPTCFG_H_
#define INTERRUPTCFG_H_

/* Macros for INT0 */
#define INT0_MODE            EXTI_ENABLE          /* Options: EXTI_ENABLE, EXTI_DISABLE */
#define INT0_SENSE_CTRL      INT0_RISING_EDGE     /* Options: INT0_LOW_LEV, INT0_ANY_EDGE, INT0_FALLING_EDGE, INT0_RISING_EDGE */

/* Macros for INT1 */
#define INT1_MODE            EXTI_ENABLE          /* Options: EXTI_ENABLE, EXTI_DISABLE */
#define INT1_SENSE_CTRL      INT1_FALLING_EDGE     /* Options: INT1_LOW_LEV, INT1_ANY_EDGE, INT1_FALLING_EDGE, INT1_RISING_EDGE */

/* Macros for INT2 */
#define INT2_MODE            EXTI_ENABLE          /* Options: EXTI_ENABLE, EXTI_DISABLE */
#define INT2_SENSE_CTRL      INT2_RISING_EDGE     /* Options: INT2_FALLING_EDGE, INT2_RISING_EDGE */

/* 
   Configuration Options:
   
   INT0_MODE:
   - EXTI_ENABLE: Enable INT0
   - EXTI_DISABLE: Disable INT0

   INT0_SENSE_CTRL:
   - INT0_LOW_LEV: Low Level Trigger
   - INT0_ANY_EDGE: Any Logical Change Trigger
   - INT0_FALLING_EDGE: Falling Edge Trigger
   - INT0_RISING_EDGE: Rising Edge Trigger

   INT1_MODE:
   - EXTI_ENABLE: Enable INT1
   - EXTI_DISABLE: Disable INT1

   INT1_SENSE_CTRL:
   - INT1_LOW_LEV: Low Level Trigger
   - INT1_ANY_EDGE: Any Logical Change Trigger
   - INT1_FALLING_EDGE: Falling Edge Trigger
   - INT1_RISING_EDGE: Rising Edge Trigger

   INT2_MODE:
   - EXTI_ENABLE: Enable INT2
   - EXTI_DISABLE: Disable INT2

   INT2_SENSE_CTRL:
   - INT2_FALLING_EDGE: Falling Edge Trigger
   - INT2_RISING_EDGE: Rising Edge Trigger
*/
#endif /* INTERRUPTCFG_H_ */
