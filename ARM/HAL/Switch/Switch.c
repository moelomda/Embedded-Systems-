/**
  ******************************************************************************
  * @file    SWITCH.c
  * @brief   Source file for SWITCH module.
  ******************************************************************************
  * @attention
  *
  * This file implements the functions declared in SWITCH.h. It provides the
  * functionality for initializing switches and reading their states.
  *
  * @note
  *   - Make sure to include "SWITCH.h" and "GPIO.h" in your project to use these functions.
  ******************************************************************************
  */
#include "Switch.h"
#include "GPIO.h"
extern const Switchcfg_t Switches[_Switch_num];

void Switch_Init(void)
{
    GpioPinCfg_t Switch_Cfg;
    u8 Loc_Iterator;

    Switch_Cfg.GPIO_Direction = GPIO_INPUT;
    Switch_Cfg.GPIO_Speed = GPIO_SPEED_LOW;

    for (Loc_Iterator = 0; Loc_Iterator < _Switch_num; Loc_Iterator++)
    {
        Switch_Cfg.GPIO_Port = Switches[Loc_Iterator].Port;
        Switch_Cfg.GPIO_Pin = Switches[Loc_Iterator].Pin;
        Switch_Cfg.GPIO_Mode = Switches[Loc_Iterator].PhysicalState;
        GPIO_Init(&Switch_Cfg);
    }
}

void Switch_GetSwitchState(u32 SwitchName, u32 *Add_SwitchState)
{
    u32 Loc_State;
    GPIO_GetPinValue(Switches[SwitchName].Port, Switches[SwitchName].Pin, &Loc_State);
    *Add_SwitchState = Loc_State ^ Switches[SwitchName].PhysicalState;
}
