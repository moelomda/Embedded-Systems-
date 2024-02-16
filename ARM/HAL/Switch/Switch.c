#include "Switch.h"

extern const Switchcfg_t Switches[_Switch_num];

void Switch_Init(void)
{
    GpioPinCfg_t Switch;
    u8 Loc_Iterator;

    Switch.GPIO_Direction = GPIO_INPUT;
    Switch.GPIO_Speed = GPIO_SPEED_LOW;

    for (Loc_Iterator = 0; Loc_Iterator < _Switch_num; Loc_Iterator++)
    {
        Switch.GPIO_Port = Switches[Loc_Iterator].Port;
        Switch.GPIO_Pin = Switches[Loc_Iterator].Pin;
        Switch.GPIO_Mode = Switches[Loc_Iterator].PhysicalState;
        GPIO_Init(&Switch);
    }
}

void Switch_GetSwitchState(u32 SwitchName, u32 *Add_SwitchState)
{
    u32 Loc_State;
    GPIO_GetPinValue(Switches[SwitchName].Port, Switches[SwitchName].Pin, &Loc_State);
    *Add_SwitchState = Loc_State ^ Switches[SwitchName].PhysicalState;
}
