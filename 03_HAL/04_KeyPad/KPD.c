/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           KPD.c                                                                                                 |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:                                                                                                                   |
 * |  This source file implements the Keypad Driver functions for interfacing with a 4x4 matrix keypad on an ATmega32 microcontroller.     |
 * |                                                             |
 * |                                                                                                                                       |
 * |  Author: Mohamed Ahmed Fouad Youssef                                                                                                  |
 * |  Created on: 07/01/2024, 08:30 PM                                                                                                     |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
#include "KPD.h"
extern const u8 KPD_Arru8SwitchVal[KPD_NUMBER][KPD_ROWNUMBER][KPD_COLNUMBER];
extern PORT_StrCFg_t KPD_PinsColCfg[KPD_NUMBER][KPD_COLNUMBER];
extern PORT_StrCFg_t KPD_PinsRowCfg[KPD_NUMBER][KPD_ROWNUMBER];

KPD_enuErrosStatus_t KPD_Init()
{
    u8 Loc_u8kpdNum;
    u8 Loc_u8ColNum;
    u8 Loc_u8RowNum;
    KPD_enuErrosStatus_t Loc_enuKpdErrorStatus = KPD_enuSucceeded;
    PORT_enuErrorStatus_t Loc_enuPortErrorStatus = PORT_enuSucceded;

    // Loop through each keypad
    for (Loc_u8kpdNum = 0; Loc_u8kpdNum < KPD_NUMBER; Loc_u8kpdNum++)
    {
        // Loop through columns
        for (Loc_u8ColNum = 0; Loc_u8ColNum < KPD_COLNUMBER; Loc_u8ColNum++)
        {
            // Check if the column port is within valid range
            if (KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PortNum > PORT_enuPortD || KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PortNum < PORT_enuPortA)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPortNum;
            }
            // Check if the column pin is within valid range
            else if (KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PinNum > PORT_enuPin7 || KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PinNum < PORT_enuPin0)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPinNum;
            }
            // Check if the column pin configuration is valid
            else if (KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PinCfg != KPD_COL_PIN_CFG)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPinCfg;
            }
            else
            {
                // Set pin configuration for the column
                Loc_enuPortErrorStatus = PORT_enuSetPinConfiguration(&KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum]);
            }
        }

        // Loop through rows
        for (Loc_u8RowNum = 0; Loc_u8RowNum < KPD_ROWNUMBER; Loc_u8RowNum++)
        {
            // Check if the row port is within valid range
            if (KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PortNum > PORT_enuPortD || KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PortNum < PORT_enuPortA)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPortNum;
            }
            // Check if the row pin is within valid range
            else if (KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PinNum > PORT_enuPin7 || KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PinNum < PORT_enuPin0)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPinNum;
            }
            // Check if the row pin configuration is valid
            else if (KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PinCfg != KPD_ROW_PIN_CFG)
            {
                Loc_enuKpdErrorStatus = KPD_InvalidPinCfg;
            }
            else
            {
                // Set pin configuration for the row
                Loc_enuPortErrorStatus = PORT_enuSetPinConfiguration(&KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum]);
            }
        }
    }

    // Check if any port configuration failed
    if (Loc_enuPortErrorStatus != PORT_enuSucceded)
    {
        Loc_enuKpdErrorStatus = KPD_PortNok;
    }

    return Loc_enuKpdErrorStatus;
}

/**
 * @brief Steps to detect which key in the keypad is pressed:
 * 
 * 1. Set the keypad column pins to OUTPUT-HIGH.
 * 2. Make only one column OUTPUT-LOW at a time while keeping the rest as OUTPUT-HIGH.
 * 3. Set the keypad row pins to INPUT-PULLUP, where pins are normally LOGIC-HIGH and become LOGIC-LOW when pressed.
 * 4. Check if any row pins have become LOGIC-LOW, indicating a pressed key.
 * 5. If any row becomes LOGIC-LOW, it indicates the key press event.
 * 6. Repeat the above steps to continuously monitor key presses.
 * 
 * This sequence employs a grid-based scanning technique, resembling a vigilant sentry scanning rows and columns
 * to identify the pressed key in a matrix keypad. The use of OUTPUT-HIGH, OUTPUT-LOW, and INPUT-PULLUP settings
 * ensures a controlled and reliable detection mechanism for key presses.
 */

KPD_enuErrosStatus_t KPD_GetValue(u8 Copy_u8KpdName, u8 *Add_u8KpdValue)
{
    u8 Loc_u8kpdNum;
    u8 Loc_u8ColNum;
    u8 Loc_u8RowNum;
    u8 Loc_u8Rowstatus;
    KPD_enuErrosStatus_t Loc_enuKpdErrorStatus = KPD_enuSucceeded;
    DIO_enuErrorStatus_t Loc_enuDioErrorStatus = DIO_enuSucceded;

    // Check if the keypad index is valid
    if (Copy_u8KpdName < KPD_NUM1 || Copy_u8KpdName > KPD_NUMBER)
    {
        Loc_enuKpdErrorStatus = KPD_enuInvalidKpdName;
    }
    // Check if the pointer is valid
    else if (Add_u8KpdValue == NULL)
    {
        Loc_enuKpdErrorStatus = KPD_enuInvalidPointer;
    }
    else
    {
        // Iterate through columns and rows to read the keypad
        for (Loc_u8kpdNum = 0; Loc_u8kpdNum < KPD_NUMBER; Loc_u8kpdNum++)
        {
            for (Loc_u8ColNum = 0; Loc_u8ColNum < KPD_COLNUMBER; Loc_u8ColNum++)
            {
                // Activate the current column
                Loc_enuDioErrorStatus = DIO_enuSetPinLogic(KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PortNum, KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PinNum, DIO_enuLogicLow);

                // Read the status of each row
                for (Loc_u8RowNum = 0; Loc_u8RowNum < KPD_ROWNUMBER; Loc_u8RowNum++)
                {
                    Loc_enuDioErrorStatus = DIO_enuGetPinLogic(KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PortNum, KPD_PinsRowCfg[Loc_u8kpdNum][Loc_u8RowNum].PORT_StrU8PinNum, &Loc_u8Rowstatus);

                    // If a key is pressed, store its value
                    if (Loc_u8Rowstatus == DIO_enuLogicLow)
                    {
                        *Add_u8KpdValue = KPD_Arru8SwitchVal[Loc_u8kpdNum][Loc_u8RowNum][Loc_u8ColNum];
                    }
                }

                // Deactivate the current column
                Loc_enuDioErrorStatus = DIO_enuSetPinLogic(KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PortNum, KPD_PinsColCfg[Loc_u8kpdNum][Loc_u8ColNum].PORT_StrU8PinNum, DIO_enuLogicHigh);
                _delay_ms(10);
            }
        }
    }

    // Check if there was an error with DIO operations
    if (Loc_enuDioErrorStatus != DIO_enuSucceded)
    {
        Loc_enuKpdErrorStatus = KPD_DioNok;
    }

    return Loc_enuKpdErrorStatus;
}
