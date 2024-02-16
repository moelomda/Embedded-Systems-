/**
  ******************************************************************************
  * @file    SWITCH.h
  * @brief   Header file for SWITCH module.
  ******************************************************************************
  * @attention
  *
  * This file contains the definitions and prototypes related to the SWITCH module.
  * It provides functions for initializing and reading the state of switches connected
  * to the microcontroller.
  *
  * @note
  *   - Refer to the specific switch hardware documentation for connection details.
  ******************************************************************************
  */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "std_types.h"
#include "GPIO.h"
#include "SwitchCfg.h"

/**
 * @brief   Defines the state when the switch is not pressed.
 */
#define SWITCH_NOT_PRESSED    0

/**
 * @brief   Defines the state when the switch is pressed.
 */
#define SWITCH_PRESSED        1



/**
 * @brief   Structure for switch configuration.
 * @details This structure defines the configuration parameters for a switch.
 *           - Port: The GPIO port to which the switch is connected.
 *           - Pin: The pin number on the GPIO port to which the switch is connected.
 *           - PhysicalState: The physical state of the switch.
 */
typedef struct {
    u32 Port;                   /**< GPIO port to which the switch is connected */
    u32 Pin;                    /**< Pin number on the GPIO port */
    u8 PhysicalState;           /**< Physical state of the switch */
} Switchcfg_t;

/**
 * @brief   Initializes the SWITCH module.
 */
void Switch_Init(void);

/**
 * @brief   Gets the state of a switch.
 * @param   SwitchName: The index of the switch in the configuration table.
 * @param   Add_SwitchState: Pointer to a variable to store the switch state.
 */
void Switch_GetSwitchState(u32 SwitchName, u32 *Add_SwitchState);

#endif /* SWITCH_H_ */
