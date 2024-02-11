/******************************************************************************
 *
 * Module: Configuration
 *
 * File Name: Cfg.c
 *
 * Description: Source file for the system configuration settings
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/
#include "Char_LcdCFg.h"
#include "Char_Lcd.h"

// Initialize an array to hold configurations for multiple LCDs
Lcd_Str8Bit_t Char_LcdArr[NUM_OF_LCD] = {
	[LCD_NUMBER1] = {
		    // Configuration for the first LCD
		   {PORT_enuPortA, PORT_enuPin0, PORT_enuOutput_Low},  //  RS pin configuration
		   {PORT_enuPortA, PORT_enuPin1, PORT_enuOutput_Low},  //  EN pin configuration
		   {
			// Configuration for 8 data pins 
			{PORT_enuPortA, PORT_enuPin2, PORT_enuOutput_Low},
			{PORT_enuPortA, PORT_enuPin3, PORT_enuOutput_Low},
			{PORT_enuPortA, PORT_enuPin4, PORT_enuOutput_Low},
			{PORT_enuPortA, PORT_enuPin5, PORT_enuOutput_Low},
			{PORT_enuPortA, PORT_enuPin6, PORT_enuOutput_Low},
			{PORT_enuPortA, PORT_enuPin7, PORT_enuOutput_Low},
			{PORT_enuPortB, PORT_enuPin0, PORT_enuOutput_Low},
			{PORT_enuPortB, PORT_enuPin1, PORT_enuOutput_Low},
		}
	}
	// Add configurations for other LCDs if needed
};