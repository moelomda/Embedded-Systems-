/*
 * GPIO.c
 *
 *  Created on: ???/???/????
 *      Author: Mohamed Elomda
 */
#include "GPIO.h"
#define NUM_PORTS 6
#define	NULL	(void*)0
#define GPIOA				((volatile Gpio_strRegister* const) 0x40020000)
#define GPIOB				((volatile Gpio_strRegister* const) 0x40020400)
#define GPIOC				((volatile Gpio_strRegister* const) 0x40020800)
#define GPIOD				((volatile Gpio_strRegister* const) 0x40020C00)
#define GPIOE				((volatile Gpio_strRegister* const) 0x40021000)
#define GPIOH				((volatile Gpio_strRegister* const) 0x40021C00)


#define FOUR_BITS_CLEAR  1<<4
#define TWO_BITS_CLEAR   1<<2
#define ONE_BIT_CLEAR    1
#define TWO_BITS     2
#define FOUR_BITS    4
typedef struct
{
	volatile u32 Moder;
	volatile u32 Otyper;
	volatile u32 Ospeedr;
	volatile u32 Pupdr;
	volatile u32 Idr;
	volatile u32 Odr;
	volatile u32 Bsrr;
	volatile u32 Lckr;
	volatile u32 Afrl;

}Gpio_strRegister;



volatile Gpio_strRegister * const GPIO[NUM_PORTS] = {GPIOA ,GPIOB ,GPIOC ,GPIOD,GPIOE,GPIOH};


GPIO_ErrorStatus_t GPIO_Init(GpioPinCfg_t Copy_StrData)
{
    // Local variables initialization
    u8 Loc_ErrorStatus = GPIO_OK;
    u32 Loc_PinDirec = Copy_StrData.GPIO_Direction;
    u32 Loc_PinMode = Copy_StrData.GPIO_Mode;
    u32 Loc_PinSpeed = Copy_StrData.GPIO_Speed;
    u32 Loc_PinNum = Copy_StrData.GPIO_Pin;
    u32 Loc_Temp = GPIO[Copy_StrData.GPIO_Port]->Moder;

    // Check if the GPIO port number is valid
    if (Copy_StrData.GPIO_Port > NUM_PORTS - 1 )
    {
        Loc_ErrorStatus = GPIO_enuInvalidPortNum;
    }
    // Check if the GPIO pin number is valid
    else if (Copy_StrData.GPIO_Pin > GPIO_PIN_15 )
    {
        Loc_ErrorStatus = GPIO_enuInvalidPinNum;
    }
    // Check if the GPIO pin direction is valid
    else if (Copy_StrData.GPIO_Direction > GPIO_MODE_ANALOG )
    {
        Loc_ErrorStatus = GPIO_enuInvalidMode;
    }
    // Check if the GPIO pin speed is valid
    else if (Copy_StrData.GPIO_Speed > GPIO_SPEED_VERY_HIGH )
    {
        Loc_ErrorStatus = GPIO_enuInvalidSpeed;
    }
    else
    {
        // Clear and set the pin direction in Moder register
        Loc_Temp &= ~(TWO_BITS_CLEAR * Loc_PinNum);
        Loc_Temp |= Loc_PinDirec << Loc_PinNum * TWO_BITS;
        GPIO[Copy_StrData.GPIO_Port]->Moder = Loc_Temp;

        // Clear and set the pin mode in Otyper register
        Loc_Temp = GPIO[Copy_StrData.GPIO_Port]->Otyper;
        Loc_Temp &= ~(ONE_BIT_CLEAR * Loc_PinNum);
        Loc_Temp |= Loc_PinMode << Loc_PinNum;
        GPIO[Copy_StrData.GPIO_Port]->Otyper = Loc_Temp;

        // Clear and set the pin pull-up/pull-down in Pupdr register
        Loc_Temp = GPIO[Copy_StrData.GPIO_Port]->Pupdr;
        Loc_Temp &= ~(TWO_BITS_CLEAR * Loc_PinNum);
        Loc_Temp |= Loc_PinMode << Loc_PinNum * TWO_BITS;
        GPIO[Copy_StrData.GPIO_Port]->Pupdr = Loc_Temp;

        // Clear and set the pin output speed in Ospeedr register
        Loc_Temp = GPIO[Copy_StrData.GPIO_Port]->Ospeedr;
        Loc_Temp &= ~(TWO_BITS_CLEAR * Loc_PinNum);
        Loc_Temp |= Loc_PinSpeed << Loc_PinNum * TWO_BITS;
        GPIO[Copy_StrData.GPIO_Port]->Ospeedr = Loc_Temp;
    }

    // Return the error status
    return Loc_ErrorStatus;
}



