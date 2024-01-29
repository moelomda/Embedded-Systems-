/*
 * -------------------------------------------------------------------------------------------------------------------------------------
 * |                                    Timer.h                                                                                        |
 * -------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:																											   |
 * |  This header file declares the interface for the Timer Driver for ATmega32.													   |
 * |  It provides function prototypes and any necessary macro definitions for the Timer Driver.									       |
 * |  Users should include this file in their main program to interact with the Timer functionality.								   |
 * |																																   |
 * |  Author: Mohamed Ahmed Fouad Youssef																							   |
 * |  Created on: 2024-01-17																										   |
 * -------------------------------------------------------------------------------------------------------------------------------------
 */

#include "Registers.h"
#include "std_types.h"
#include "BIT_MATH.h"
#include <math.h>
#include <stddef.h>

#ifndef TIMER_H_
#define TIMER_H_

/*
 * ┌─────────────── Timer Names Definitions ───────────────┐
 * │ TIMER0: Identifier for Timer/Counter0                 │
 * │   - Represents Timer/Counter0 in the configuration.   │
 * │ TIMER1: Identifier for Timer/Counter1                 │
 * │   - Represents Timer/Counter1 in the configuration.   │
 * │ TIMER2: Identifier for Timer/Counter2                 │
 * │   - Represents Timer/Counter2 in the configuration.   │
 * └──────────────────────────────────────────────────────┘
 */


		#define TIMER0 0  
		#define TIMER1 1  
		#define TIMER2 2 
/*
 * ┌──────────────────── Time Durations Definitions ─────────────────────┐
 * │ TIME_25_MICRO:   0 - 25 microseconds                                │
 * │   - Represents a time interval of 25 microseconds.                  │
 * │                                                                     │
 * │ TIME_100_MICRO:  1 - 100 microseconds                               │
 * │   - Represents a time interval of 100 microseconds.                 │
 * │                                                                     │
 * │ TIME_250_MILLI:  2 - 250 milliseconds                               │
 * │   - Represents a time interval of 250 milliseconds.                 │
 * │                                                                     │
 * │ TIME_500_MILLI:  3 - 500 milliseconds                               │
 * │   - Represents a time interval of 500 milliseconds.                 │
 * │                                                                     │
 * │ TIME_1_SECONED:  4 - 1 second                                       │
 * │   - Represents a time interval of 1 second.                         │
 * │                                                                     │
 * │ TIME_2_SECONED:  5 - 2 seconds                                      │
 * │   - Represents a time interval of 2 seconds.                        │
 * │                                                                     │
 * │ TIME_5_SECONED:  6 - 5 seconds                                      │
 * │   - Represents a time interval of 5 seconds.                        │
 * │                                                                     │
 * │ TIME_10_SECONED: 7 - 10 seconds                                     │
 * │   - Represents a time interval of 10 seconds.                       │
 * └──────────────────────────────────────────────────────────────────────┘
 */
		
		
  
  #define  NO_PRESCALER     1
  #define  PRESCALER_8      8
  #define  PRESCALER_64     64
  #define  PRESCALER_256    256
  #define  PRESCALER_1024   1024
  
  #define  TIMEROF_INTERRUPT_COUNT 4 
  #define  TIMERCM_INTERRUPT_COUNT 4
  
  #define  TIMER0_OF_INTERRUPT     0
  #define  TIMER1_OF_INTERRUPT     1
  #define  TIMER2_OF_INTERRUPT     2
  #define  TIMER0_CM_INTERRUPT     5
  #define  TIMER1_CM_INTERRUPT     6
  #define  TIMER2_CM_INTERRUPT     7

/*
 * ========================================
 * |      TIMER DRIVER ERROR STATUSES       |
 * ========================================
 * | Timer_InvalidTimerName: Invalid timer  |
 * | Timer_InvalidTimerMode: Invalid mode   |
 * ========================================
 */
typedef enum
{
    Timer_enuInvalidTimerName,
    Timer_enuInvalidTimerMode,
	Timer_enuInvalidTimerPreScaler,
	Timer_enuSucceeded,
} Timer_enuErrorStatus_t;
/*
 * ==========================================
 * |         TIMER MODE DEFINITIONS          |
 * ==========================================
 * | NORMAL_MODE: Timer operates in Normal   |
 * |              Mode, counting without     |
 * |              any special functionality. |
 * | CTC_MODE:    Timer operates in Clear    |
 * |              Timer on Compare Match     |
 * |              (CTC) Mode, counting up to |
 * |              a specified value, then    |
 * |              resets.                    |
 * | CTC_OCR_MODE: Timer operates in Clear   |
 * |              Timer on Compare Match     |
 * |              (CTC) Mode using OCRx as   |
 * |              the top value. (for 16-bit |
 * |              timers)                    |
 * | CTC_ICR_MODE: Timer operates in Clear   |
 * |              Timer on Compare Match     |
 * |              (CTC) Mode using ICRx as   |
 * |              the top value. (for 16-bit |
 * |              timers)                    |
 * ==========================================
 */

#define NORMAL_MODE  0 
#define CTC_MODE     1
#define CTC_OCR_MODE 2   // for 16-bit timer
#define CTC_ICR_MODE 3   // for 16-bit timer

/*
 * ┌─────────────── Timer/Counter0 Bit Definitions ───────────────┐
 * │ TOV0: Timer/Counter0 Overflow Flag                           │
 * │   - Indicates an overflow in Timer/Counter0.                 │
 * │ IBIT_SREG: Global Interrupt Enable (I-bit) in SREG           │
 * │   - Controls the global interrupt enable/disable state.      │
 * │ TOIE0: Timer/Counter0 Overflow Interrupt Enable              │
 * │   - Enables the Timer/Counter0 Overflow interrupt.           │
 * │ OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable  │
 * │   - Enables the Timer/Counter0 Output Compare Match interrupt│
 * │ OCF0: Timer/Counter0 Output Compare Flag                     │
 * │   - Indicates a match between the counter and the OCR0 value.│
 * └──────────────────────────────────────────────────────────────┘
 * ┌─────────────── Timer/Counter1 Bit Definitions ───────────────┐
 * │ TOV1: Timer/Counter1 Overflow Flag                           │
 * │   - Indicates an overflow in Timer/Counter1.                 │
 * │ TOIE1: Timer/Counter1 Overflow Interrupt Enable              │
 * │   - Enables the Timer/Counter1 Overflow interrupt.           │
 * │ OCF1A: Timer/Counter1 Output Compare A Flag                  │
 * │   - Indicates a match between the counter and the OCR1A value│
 * │ OCF1B: Timer/Counter1 Output Compare B Flag                  │
 * │   - Indicates a match between the counter and the OCR1B value│
 * │ OCIE1A:Timer/Counter1 Output Compare Match A InterruptEnable │
 * │   Enables the Timer/Counter1 Output Compare Match A interrupt│
 * │ OCIE1B: Timer/Counter1 Output Compare Match B InterruptEnable│
 * │   Enables the Timer/Counter1 Output Compare Match B interrupt│
 * │ TICIE1: Timer/Counter1 Input Capture Interrupt Enable        │
 * │   - Enables the Timer/Counter1 Input Capture interrupt.      │
 * │ ICF1: Timer/Counter1 Input Capture Flag                      │
 * │   - Indicates an Input Capture event on Timer/Counter1.      │
 * └──────────────────────────────────────────────────────────────┘
 * ┌─────────────── Timer/Counter2 Bit Definitions ───────────────┐
 * │ TOV2: Timer/Counter2 Overflow Flag                           │
 * │   - Indicates an overflow in Timer/Counter2.                 │
 * │ TOIE2: Timer/Counter2 Overflow Interrupt Enable              │
 * │   - Enables the Timer/Counter2 Overflow interrupt.           │
 * │ OCF2: Timer/Counter2 Output Compare Flag                     │
 * │   - Indicates a match between the counter and the OCR2 value.│
 * │ OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable  │
 * │   - Enables the Timer/Counter2 Output Compare Match interrupt│
 * └──────────────────────────────────────────────────────────────┘
 */

#define TOV0      0    // Timer/Counter0 Overflow Flag (Bit 0)
#define TOV2      6    // Timer/Counter2 Overflow Flag (Bit 6)
#define IBIT_SREG 7    // Global Interrupt Enable (I-bit) in SREG (Bit 7)
#define TOIE0     0    // Timer/Counter0 Overflow Interrupt Enable (Bit 0)
#define OCIE0     1    // Timer/Counter0 Output Compare Match Interrupt Enable (Bit 1)
#define OCF0      1    // Timer/Counter0 Output Compare Flag (Bit 1)
#define TOIE2     6    // Timer/Counter2 Overflow Interrupt Enable (Bit 6)
#define OCF2      7    // Timer/Counter2 Output Compare Flag (Bit 7)
#define OCIE2     7    // Timer/Counter2 Output Compare Match Interrupt Enable (Bit 7)
#define TOV1      2    // Timer/Counter1 Overflow Flag (Bit 2)
#define TOIE1     2    // Timer/Counter1 Overflow Interrupt Enable (Bit 2)
#define OCF1A     4    // Timer/Counter1 Output Compare A Flag (Bit 4)
#define OCF1B     5    // Timer/Counter1 Output Compare B Flag (Bit 5)
#define OCIE1A    4    // Timer/Counter1 Output Compare Match A Interrupt Enable (Bit 4)
#define OCIE1B    3    // Timer/Counter1 Output Compare Match B Interrupt Enable (Bit 3)
#define TICIE1    5    // Timer/Counter1 Input Capture Interrupt Enable (Bit 5)
#define ICF1      5    // Timer/Counter1 Input Capture Flag (Bit 5)
/*-------------------------------------------------------*MASKS*--------------------------------------------------------------*/
/* Mask for Timer/Counter0 Overflow Flag */
#define TOV0_MASK           0xFE

/* Mask for the I-bit in the Status Register */
#define IBIT_SREG_MASK      0x7F

/* Mask for Timer/Counter0 Overflow Interrupt Enable */
#define TOIE0_MASK          0xFE

/* Mask for Timer/Counter0 Output Compare Flag */
#define OCF0_MASK           0xFD

/* Mask for Timer/Counter0 Output Compare Interrupt Enable */
#define OCIE0_MASK          0xFD

/* Mask for Timer/Counter2 Overflow Flag */
#define TOV2_MASK           0xBF

/* Mask for Timer/Counter2 Overflow Interrupt Enable */
#define TOIE2_MASK          0xBF

/* Mask for Timer/Counter2 Output Compare Flag */
#define OCF2_MASK           0x7F

/* Mask for Timer/Counter2 Output Compare Interrupt Enable */
#define OCIE2_MASK          0x7F

/* Mask for Timer/Counter1 Overflow Flag */
#define TOV1_MASK           0xFB

/* Mask for Timer/Counter1 Overflow Interrupt Enable */
#define TOIE1_MASK          0xFB

/* Mask for Timer/Counter1 Output Compare A Flag */
#define OCF1A_MASK          0xEF

/* Mask for Timer/Counter1 Output Compare B Flag */
#define OCF1B_MASK          0xF7

/* Mask for Timer/Counter1 Input Capture Flag */
#define ICF1_MASK           0xDF

/* Mask for Timer/Counter1 Input Capture Interrupt Enable */
#define TICIE1_MASK         0xDF

/* Mask for Timer/Counter1 Output Compare A Interrupt Enable */
#define OCIE1A_MASK         0xEF

/* Mask for Timer/Counter1 Output Compare B Interrupt Enable */
#define OCIE1B_MASK         0xF7

#define PRESCALER_MASK    0xF8


/*
 * ╔═══════════════ Timer_Init ════════════════╗
 * ║ Initializes the specified timer with the  ║
 * ║ given mode.                               ║
 * ║                                           ║
 * ║ Parameters:                               ║
 * ║   - Copy_u8TimerName: Identifier for the  ║
 * ║     timer (TIMER0, TIMER1, TIMER2).       ║
 * ║   - Copy_u8TimerMode: Operating mode of   ║
 * ║     the timer.                            ║
 * ║                                           ║
 * ║ Returns:                                  ║
 * ║   - Timer_enuErrorStatus_t: Error status  ║
 * ║     indicating success or failure.        ║
 * ║                                           ║
 * ║ Details:                                  ║
 * ║   This API initializes the timer specified║
 * ║   by Copy_u8TimerName with the provided   ║
 * ║   mode. It returns an error status to     ║
 * ║   indicate if the initialization was      ║
 * ║   successful. Use this function to        ║
 * ║   configure timers for various timing     ║
 * ║   operations.                             ║
 * ╚═══════════════════════════════════════════╝
 */
Timer_enuErrorStatus_t Timer_Init(u8 Copy_u8TimerName, u8 Copy_u8TimerMode);
/*
 * ╔═════════════ Timer_SetValue ══════════════╗
 * ║ Sets  value for the specified             ║
 * ║ timer in the given mode.                  ║
 * ║                                           ║
 * ║ Parameters:                               ║
 * ║   - Copy_u8TimerName: Identifier for the  ║
 * ║     timer (TIMER0, TIMER1, TIMER2).       ║
 * ║   - Copy_u8Value:  value to set.          ║
 * ║   - Copy_u8TimerMode: Operating mode of   ║
 * ║     the timer.                            ║
 * ║                                           ║
 * ║ Returns:                                  ║
 * ║   - Timer_enuErrorStatus_t: Error status  ║
 * ║     indicating success or failure.        ║
 * ║                                           ║
 * ║ Details:                                  ║
 * ║   This API sets the a value for the       ║
 * ║   timer specified by Copy_u8TimerName in  ║
 * ║   the provided mode. It returns an error  ║
 * ║   status to indicate if the operation was ║
 * ║   successful.                             ║
 * ╚═══════════════════════════════════════════╝
 */
Timer_enuErrorStatus_t Timer_SetValueMicro(u8 Copy_u8TimerName, f32 Copy_u8Value,u16 Copy_u8PreScaler, u8 Copy_u8TimerMode);
/*
 * ╔═══════════════════ TIMER_SetCallBack ════════════════════╗
 * ║ Sets a callback function to be executed when a timer     ║
 * ║ interrupt occurs on the specified timer.                 ║
 * ║                                                          ║
 * ║ Parameters:                                              ║
 * ║   - Copy_u8TimerName: Identifier for the timer (TIMER0,  ║
 * ║     TIMER1, TIMER2).                                     ║
 * ║- Add_CaLLBackFun: Pointer to the callback function to be ║
 * ║     executed.                                            ║
 * ║                                                          ║
 * ║ Details:                                                 ║
 * ║This function sets a callback function that will be       ║
 * ║called when a timer interrupt event occurs on the         ║
 * ║specified timer. The callback function is provided by the ║
 * ║user and should be of type void (*Add_CaLLBackFun)(void). ║
 * ║                                                          ║
 * ║ Note:                                                    ║
 * ║   The user should ensure that the specified timer is     ║
 * ║   configured correctly and enabled to trigger interrupts.║
 * ╚══════════════════════════════════════════════════════════╝
 */
void TIMER_SetCallBack(u8 Copy_u8InterruptName, void (*Add_CaLLBackFun) (void) );

#endif /* TIMER_H_ */