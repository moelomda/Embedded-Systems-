/******************************************************************************
 *
 * Module: Char_Lcd
 *
 * File Name: Char_Lcd.h
 *
 * Description: Header file for the Character LCD driver interface
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/

#ifndef CHAR_LCD_H_
#define CHAR_LCD_H_

#include "Char_LcdCFg.h"  
#include "DIO.h"
#include "PORT.h" 
#include <stddef.h>

/********************************************************************* Macro Definition **************************************************************/ 

// LCD Commands

#define LCD_CLEAR_DISPLAY           0x01  // Clear display
#define LCD_RETURN_HOME             0x02  // Return to home (1st line, 1st column)
#define LCD_ENTRY_MODE_SET          0x06  // Set entry mode: Increment cursor, no display shift
#define LCD_DISPLAY_ON_CURSOR_OFF   0x0C  // Display on, cursor off, blink off
#define LCD_DISPLAY_ON_CURSOR_ON    0x0E  // Display on, cursor on, blink off
#define LCD_FUNCTION_SET_2_LINES    0x38  // 8-bit data, 2 lines, 5x8 font
#define  LCD_CGRAM_START            0x40
#define  LCD_DDRAM_START            0x80

#define ROW1                          1
#define ROW2                          2

/********************************************************************* Structure Definition **************************************************************/
typedef struct 
{
    PORT_StrCFg_t Lcd_StrRsReg;
    PORT_StrCFg_t Lcd_StrEnReg;
    PORT_StrCFg_t Lcd_StrDataReg[8];
} Lcd_Str8Bit_t;


/********************************************************************* Enumeration Definition ************************************************************/
typedef enum
{
    Lcd_enuInvalidPortNum,
    Lcd_enuInvalidPinNum,
    Lcd_enuInvalidColNum,
    Lcd_enuInvalidRowNum,
    Lcd_enuDioNok,
	Lcd_enuNullPtr,
	Lcd_enuOk,
	Lcd_enuPortNok,
	Lcd_enuInvalidLcdName,
} Lcd_enuErrorState;

/********************************************************************* Function Prototypes **************************************************************/
/**
 * @brief Initializes the 8-bit Character LCD.
 * 
 * 
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitInit();

/**
 * @brief Writes a command to the 8-bit Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD you want to send command to .
 * @param Copy_u8Command The command to be written.
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteCommand(u8 Copy_u8LcdName, u8 Copy_u8Command);

/**
 * @brief Writes character data to the 8-bit Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD 
 * @param Copy_u8Data The character data to be written.
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteCharData(u8 Copy_u8LcdName, u8 Copy_u8Data);

/**
 * @brief Writes character data to a specified position on the 8-bit Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD 
 * @param Copy_u8Row The row number (1 to 2).
 * @param Copy_u8Col The column number (1 to 16).
 * @param Copy_u8Data The character data to be written.
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteCharDataPos(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8Data);

/**
 * @brief Writes a string to the 8-bit Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD 
 * @param Copy_AddStr Pointer to the string to be written.
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteString(u8 Copy_u8LcdName, u8 *Copy_AddStr);

/**
 * @brief Writes a string to a specified position on the 8-bit Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD 
 * @param Copy_u8Row The row number (1 to 2).
 * @param Copy_u8Col The column number (1 to 16).
 * @param Copy_AddStr Pointer to the string to be written.
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteStringPos(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 *Copy_AddStr);

/**
 * @brief Writes a custom character to a specified position on the 8-bit 2x16 Character LCD.
 * 
 * @param Copy_u8LcdName the name of a LCD .
 * @param Copy_u8Row The row number (1 or 2).
 * @param Copy_u8Col The column number (1 to 16).
 * @param Copy_u8charArr Array containing the custom character pattern (8 bytes).
 * @param Copy_u8MemPos Memory position where the custom character will be stored (0 to 7).
 * @return Lcd_enuErrorState Status of the function.
 *         - Lcd_enuDioNok: The function has an issue performing action related to Dio.
 *         - Others: Specific error codes indicating the issue.
 */
Lcd_enuErrorState Lcd_8bitWriteCustomChar(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8charArr[], u8 Copy_u8MemPos);

#endif /* CHAR_LCD_H_ */ 
