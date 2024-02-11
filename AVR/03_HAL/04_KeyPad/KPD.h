/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                                       KPD.h                                                                                                 |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:                                                                                                                   |
 * |  This header file declares functions and constants for the Keypad Driver, allowing interfacing with a keypad on an                    |
 * |  ATmega32 microcontroller.                                 |
 * |                                                                                                                                       |
 * |  Author: Mohamed Ahmed Fouad Youssef                                                                                                  |
 * |  Created on: 07/01/2024, 08:30 PM                                                                                                     |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */

#include "DIO.h"
#include "PORT.h"
#include "std_types.h"
#include "Registers.h"
#include "KPDCfg.h"
#include "utildelay.h"
#include <stddef.h>


#ifndef KPD_H_
#define KPD_H_
/*------------------------------------------------------*Macros Section*-------------------------------------------------------------------------------*/
/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                             Keypad Matrix I/O Configuration                                                               |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  These macros define the Input/Output configurations for the Keypad Driver and should not be modified by the user.                        |
 * |                                                                                                                                           |
 * |  KPD_ROW_PIN_CFG: Specifies the configuration for the rows in the keypad matrix, set to PORT_enuInputInternalPullUP for internal pull-up. |
 * |                                                                                                                                           |
 * |  KPD_COL_PIN_CFG: Specifies the configuration for the columns in the keypad matrix, set to PORT_enuOutput_High for output with high logic.|
 * |                                                                                                                                           |
 * |  These settings are crucial for proper communication between the microcontroller and the keypad and should remain unchanged.              |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
#define KPD_ROW_PIN_CFG   PORT_enuInputInternalPullUP  // Configuration for the keypad matrix rows
#define KPD_COL_PIN_CFG   PORT_enuOutput_High          // Configuration for the keypad matrix columns
/*-----------------------------------------------------------*Enumerations*--------------------------------------------------------------------------------*/

/**
 * @brief Enumeration for Keypad Driver Error Status
 *
 * This enumeration defines various error statuses that the Keypad Driver
 * may encounter during its operation.
 */
typedef enum
{
	KPD_InvalidPortNum,      /**< Invalid port number */
	KPD_InvalidPinNum,       /**< Invalid pin number */
	KPD_InvalidPinCfg,       /**< Invalid pin configuration */
	KPD_PortNok,             /**< Port configuration error */
	KPD_DioNok,              /**< Digital I/O configuration error */
	KPD_enuSucceeded,        /**< Operation succeeded */
	KPD_enuInvalidPointer,   /**< Invalid pointer or null pointer error */
	KPD_enuInvalidKpdName,   /**< Invalid keypad number error */
} KPD_enuErrosStatus_t;

/*-----------------------------------------------------------*API'S*--------------------------------------------------------------------------------*/
/**
 * @brief Initialize Keypad Driver
 *
 * This function initializes the Keypad Driver, configuring the necessary
 * settings for optimal keypad functionality. It establishes a reliable
 * connection between the hardware and keypad matrix.
 *
 * @return KPD_enuErrosStatus_t:       
 */
KPD_enuErrosStatus_t KPD_Init();
/**
 * @brief Get the value of the currently pressed key on a specified keypad.
 *
 * This function searches through the specified keypad matrix to identify the
 * currently pressed key and returns its value. If no key is pressed, it sets
 * the output value to a default value and returns a status indicating that no
 * key is currently pressed.
 *
 * @param Copy_u8KpdName Keypad number to query.
 * @param Add_u8KpdValue Pointer to a variable to store the pressed key's value.
 *
 * @return KPD_enuErrosStatus_t Status indicating the result of the operation.       
 */
KPD_enuErrosStatus_t KPD_GetValue(u8 Copy_u8KpdName , u8 *Add_u8KpdValue);

#endif /* KPD_H_ */