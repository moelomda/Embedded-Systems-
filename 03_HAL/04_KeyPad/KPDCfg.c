/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                                        KPDCfg.c                                                                                              |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:                                                                                                                   |
 * |  This source file defines the configuration settings for the Keypad Driver.                                                           |
 * |  Modify the settings to match your hardware connections and requirements.                                                             |
 * |                                                                                                                                       |
 * |  Author: Mohamed Ahmed Fouad Youssef                                                                                                  |
 * |  Created on: 07/01/2024, 08:25 PM                                                                                                     |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
#include "KPDCfg.h"
#include "KPD.h"

/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                              Configure Keypad Switch Values                                                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Customize the KPD_Arru8SwitchVal array to map keypad buttons to their respective values.                                           |
 * |  Adjust the array elements based on the labels and values associated with each button on your keypad.                               |
 * |                                                                                                                                     |
 * |  Use characters for alphanumeric keys and numerical values for numeric keys. For special keys, use their respective ASCII values.   |
 * |  The array is organized by keypad index, rows, and columns. Update the values as per your keypad layout.                            |
 * |                                                                                                                                     |
 * |  Example:                                                                                                                           |
 * |  - 'C' represents the Clear button.                                                                                                 |
 * |  - '=' represents the Equals button.                                                                                                |
 * |  - Numeric keys are represented by their corresponding digits.                                                                      |
 * |  - Special keys like '/', '*', '-', and '+' are represented by their respective ASCII values.                                       |
 * |                                                                                                                                     |
 * |  Ensure that the array dimensions (KPD_NUMBER, KPD_ROWNUMBER, KPD_COLNUMBER) match your keypad configuration.                       |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */

const u8 KPD_Arru8SwitchVal[KPD_NUMBER][KPD_COLNUMBER][KPD_ROWNUMBER] = {
	[KPD_NUM1] =
	 {
		{ 7 ,   4 ,  1 , 'C'},
		{ 8 ,   5 ,  2 ,  0 },
		{ 9 ,   6 ,  3 , '='},
		{'/',  '*', '-', '+'}
	 }
	// Add more arrays if needed for additional keypads
};

/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                               Configure Keypad Column Pins Settings                                                                       |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Customize the KPD_PinsColCfg array to define the configuration for each column pin of your keypad.                                |
 * |  Adjust the elements based on the keypad index, column number, and the specific configuration settings for each column pin.        |
 * |                                                                                                                                    |
 * |  Example:                                                                                                                          |
 * |  - For KPD_NUM1, Column 0: Configure the pin settings for PORTA, Pin 0 using KPD_COL_PIN_CFG settings.                             |
 * |  - Repeat this pattern for each column in the array.                                                                               |
 * |                                                                                                                                    |
 * |  Ensure that the array dimensions (KPD_NUMBER, KPD_COLNUMBER) match your keypad and column pin configuration.                      |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
PORT_StrCFg_t KPD_PinsColCfg[KPD_NUMBER][KPD_COLNUMBER] = {
    [KPD_NUM1] = {
        {PORT_enuPortA, PORT_enuPin0, KPD_COL_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin1, KPD_COL_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin2, KPD_COL_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin3, KPD_COL_PIN_CFG}
    }
    // Repeat this pattern for additional keypads and columns
};
/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                            Configure Keypad Row Pins Settings                                                                          |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Customize the KPD_PinsRowCfg array to define the configuration for each row pin of your keypad.                                   |
 * |  Adjust the elements based on the keypad index, row number, and the specific configuration settings for each row pin.              |
 * |                                                                                                                                    |
 * |  Example:                                                                                                                          |
 * |  - For KPD_NUM1, Row 0: Configure the pin settings for PORTA, Pin 4 using KPD_ROW_PIN_CFG settings.                                |
 * |  - Repeat this pattern for each row in the array.                                                                                  |
 * |                                                                                                                                    |
 * |  Ensure that the array dimensions (KPD_NUMBER, KPD_ROWNUMBER) match your keypad and row pin configuration.                         |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
PORT_StrCFg_t KPD_PinsRowCfg[KPD_NUMBER][KPD_ROWNUMBER] = {
    [KPD_NUM1] = {
        {PORT_enuPortA, PORT_enuPin4, KPD_ROW_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin5, KPD_ROW_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin6, KPD_ROW_PIN_CFG},
        {PORT_enuPortA, PORT_enuPin7, KPD_ROW_PIN_CFG}
    }
    // Repeat this pattern for additional keypads and rows
};




