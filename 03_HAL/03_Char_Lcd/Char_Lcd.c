/******************************************************************************
 *
 * Module: Char_Lcd
 *
 * File Name: Char_Lcd.c
 *
 * Description: Source file for the Character LCD driver implementation
 *
 * Author: Mohamed Ahmed Fouad
 *
 *****************************************************************************/
#include "Char_Lcd.h"
#include "utildelay.h"
extern Lcd_Str8Bit_t Char_LcdArr[NUM_OF_LCD];
static Lcd_enuErrorState Lcd_8bitSetCursor(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col);
static Lcd_enuErrorState Lcd_8bitSendEnableSignal(u8 Copy_u8LcdName);
/**************************************************API'S********************************************************************************/
Lcd_enuErrorState Lcd_8bitInit()
{
	Lcd_enuErrorState Loc_LcdenuErrorState = Lcd_enuOk;
	PORT_enuErrorStatus_t Loc_PortenuErrorState = PORT_enuSucceded;
	
		// Loop through the LCD array to initialize each LCD
		for (u8 i = 0; i < NUM_OF_LCD; i++)
		{
			// Set pin configuration for RS pin
			Loc_PortenuErrorState = PORT_enuSetPinConfiguration(&Char_LcdArr[i].Lcd_StrRsReg);

			// Check if the pin configuration was successful
			if (Loc_PortenuErrorState != PORT_enuSucceded)
			{
				// Update the LCD error state with the PORT error state
				Loc_LcdenuErrorState = Lcd_enuPortNok;
				break;
			}
                // Set pin configuration for EN pin   
			Loc_PortenuErrorState = PORT_enuSetPinConfiguration(&Char_LcdArr[i].Lcd_StrEnReg);

			// Check if the pin configuration was successful
			if (Loc_PortenuErrorState != PORT_enuSucceded)
			{
				// Update the LCD error state with the PORT error state
				Loc_LcdenuErrorState = Lcd_enuPortNok;
				break;
			}

			// Loop through the data pins, copy their configurations, and set pin configurations
			for (int j = 0; j < 8; j++)
			{
				Loc_PortenuErrorState = PORT_enuSetPinConfiguration(&Char_LcdArr[i].Lcd_StrDataReg[j]);

				// Check if the pin configuration was successful
				if (Loc_PortenuErrorState != PORT_enuSucceded)
				{
					// Update the LCD error state with the PORT error state
					Loc_LcdenuErrorState = Lcd_enuPortNok;
					break;
				}
			
		   }
		        _delay_ms(35);
				Loc_LcdenuErrorState = Lcd_8bitWriteCommand(i , LCD_FUNCTION_SET_2_LINES);
		        _delay_us(45);
				Loc_LcdenuErrorState = Lcd_8bitWriteCommand(i , LCD_DISPLAY_ON_CURSOR_OFF);
		        _delay_us(45);
				Loc_LcdenuErrorState = Lcd_8bitWriteCommand(i , LCD_CLEAR_DISPLAY);
				_delay_ms(10);
				Loc_LcdenuErrorState = Lcd_8bitWriteCommand(i , LCD_ENTRY_MODE_SET);
				
				Loc_LcdenuErrorState = Lcd_8bitWriteCommand(i , 0x80);
				
			}

	return Loc_LcdenuErrorState;
}
Lcd_enuErrorState Lcd_8bitWriteCommand(u8 Copy_u8LcdName, u8 Copy_u8Command)
{
	
	u8 Loc_u8LcdErrorstate = Lcd_enuOk ;
	u8 Loc_u8DioErrorstate = DIO_enuSucceded;
	if(Copy_u8LcdName < LCD_NUMBER1 || Copy_u8LcdName > NUM_OF_LCD)
	{
		Loc_u8LcdErrorstate = Lcd_enuInvalidLcdName ;
	}
	else 
	{
		Loc_u8DioErrorstate = DIO_enuSetPinLogic((Char_LcdArr[Copy_u8LcdName].Lcd_StrRsReg.PORT_StrU8PortNum), (Char_LcdArr[Copy_u8LcdName].Lcd_StrRsReg.PORT_StrU8PinNum) , DIO_enuLogicLow ) ;
		   for (u8 i = 0 ; i < 8 ; i++)
		   {
			   Loc_u8DioErrorstate=DIO_enuSetPinLogic((Char_LcdArr[Copy_u8LcdName].Lcd_StrDataReg[i].PORT_StrU8PortNum) , (Char_LcdArr[Copy_u8LcdName].Lcd_StrDataReg[i].PORT_StrU8PinNum) , (Copy_u8Command >> i) & (u8) 0x01 );
		   }
		Loc_u8LcdErrorstate = Lcd_8bitSendEnableSignal(Copy_u8LcdName); 
	}
	
	
	  if (Loc_u8DioErrorstate != DIO_enuSucceded )
	  {
		  Loc_u8DioErrorstate = Lcd_enuDioNok ;
	  }
	return Loc_u8LcdErrorstate ;
	
}
Lcd_enuErrorState Lcd_8bitWriteCharData(u8 Copy_u8LcdName, u8 Copy_u8Data)
{
		u8 Loc_u8LcdErrorstate = Lcd_enuOk ;
		u8 Loc_u8DioErrorstate = DIO_enuSucceded;
		if(Copy_u8LcdName < LCD_NUMBER1 || Copy_u8LcdName > NUM_OF_LCD)
		{
			Loc_u8LcdErrorstate = Lcd_enuInvalidLcdName ;
		}
		else
		{
			Loc_u8DioErrorstate = DIO_enuSetPinLogic(Char_LcdArr[Copy_u8LcdName].Lcd_StrRsReg.PORT_StrU8PortNum ,Char_LcdArr[Copy_u8LcdName].Lcd_StrRsReg.PORT_StrU8PinNum , DIO_enuLogicHigh ) ;
		    for (u8 i = 0 ; i < 8 ; i++)
		    {
				Loc_u8DioErrorstate = DIO_enuSetPinLogic(Char_LcdArr[Copy_u8LcdName].Lcd_StrDataReg[i].PORT_StrU8PortNum , Char_LcdArr[Copy_u8LcdName].Lcd_StrDataReg[i].PORT_StrU8PinNum , (Copy_u8Data >> i) & (u8) 0x01);
		    }
			Loc_u8LcdErrorstate = Lcd_8bitSendEnableSignal(Copy_u8LcdName); 
		}
		
			  if (Loc_u8DioErrorstate != DIO_enuSucceded )
			  {
				  Loc_u8DioErrorstate = Lcd_enuDioNok ;
			  }
			  return Loc_u8LcdErrorstate ;
		
		return Loc_u8LcdErrorstate ;
		
}		
Lcd_enuErrorState Lcd_8bitWriteCharDataPos(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8Data)
{
		Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;
		
		// Check if the LCD name is within valid range
		if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
		{
			Loc_LcdErrorState = Lcd_enuInvalidLcdName;
		}
		else
		{
			Loc_LcdErrorState = Lcd_8bitSetCursor(Copy_u8LcdName , Copy_u8Row ,  Copy_u8Col );
		    Loc_LcdErrorState = Lcd_8bitWriteCharData(Copy_u8LcdName , Copy_u8Data);
			
		}
		
		
		
		
		return Loc_LcdErrorState;
}
Lcd_enuErrorState Lcd_8bitWriteString(u8 Copy_u8LcdName, u8 *Copy_AddStr)
{
	Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;
	
	// Check if the LCD name is within valid range
	if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
	{
		Loc_LcdErrorState = Lcd_enuInvalidLcdName;
	}
	else if (Copy_AddStr == NULL )
	{
		Loc_LcdErrorState = Lcd_enuNullPtr;
	}
	else
	{
		while(*Copy_AddStr)
		{
			Loc_LcdErrorState = Lcd_8bitWriteCharData(Copy_u8LcdName ,*Copy_AddStr);
			Copy_AddStr++ ;
		}
			
	}
	
	return Loc_LcdErrorState ;
}
Lcd_enuErrorState Lcd_8bitWriteStringPos(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 *Copy_AddStr)
{
		Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;
		
		// Check if the LCD name is within valid range
		if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
		{
			Loc_LcdErrorState = Lcd_enuInvalidLcdName;
		}
		else if (Copy_AddStr == NULL )
		{
			Loc_LcdErrorState = Lcd_enuNullPtr;
		}
		else
		{
			 Loc_LcdErrorState =Lcd_8bitSetCursor( Copy_u8LcdName, Copy_u8Row, Copy_u8Col);
			while(*Copy_AddStr)
			{         
				Loc_LcdErrorState = Lcd_8bitWriteCharData(Copy_u8LcdName ,*Copy_AddStr);
				Copy_AddStr++ ;
			}
			
		}
		
		return Loc_LcdErrorState ;
	}
Lcd_enuErrorState Lcd_8bitWriteCustomChar(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8charArr[], u8 Copy_u8MemPos)
{
	Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;
	
	// Check if the LCD name is within valid range
	if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
	{
		Loc_LcdErrorState = Lcd_enuInvalidLcdName;
	}
	else
	{
		Loc_LcdErrorState = Lcd_8bitWriteCommand(Copy_u8LcdName ,LCD_CGRAM_START+((Copy_u8MemPos*8)));
		for(u8 i = 0 ; i < 8 ; i++)
		{
			Loc_LcdErrorState = Lcd_8bitWriteCharData (Copy_u8LcdName , Copy_u8charArr[i] );
		}
		Loc_LcdErrorState = Lcd_8bitWriteCharDataPos(Copy_u8LcdName , Copy_u8Row , Copy_u8Col , Copy_u8MemPos);
	}
	
	return Loc_LcdErrorState ;
}
static Lcd_enuErrorState Lcd_8bitSendEnableSignal(u8 Copy_u8LcdName)
{
	Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;
	DIO_enuErrorStatus_t Loc_DioErrorState = DIO_enuSucceded;

	// Check if the LCD name is within valid range
	if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
	{
		Loc_LcdErrorState = Lcd_enuInvalidLcdName;
	}
	else
	{
		// Set the EN pin to logic high
		Loc_DioErrorState = DIO_enuSetPinLogic(
		Char_LcdArr[Copy_u8LcdName].Lcd_StrEnReg.PORT_StrU8PortNum,
		Char_LcdArr[Copy_u8LcdName].Lcd_StrEnReg.PORT_StrU8PinCfg,
		DIO_enuLogicHigh);
		
		// Delay for a short period
		_delay_us(5);

		// Set the EN pin to logic low
		Loc_DioErrorState = DIO_enuSetPinLogic(
		Char_LcdArr[Copy_u8LcdName].Lcd_StrEnReg.PORT_StrU8PortNum,
		Char_LcdArr[Copy_u8LcdName].Lcd_StrEnReg.PORT_StrU8PinCfg,
		DIO_enuLogicLow);

		// Delay for a short period
		_delay_us(5);
	}

	// Check if any DIO operation failed
	if (Loc_DioErrorState != DIO_enuSucceded)
	{
		Loc_LcdErrorState = Lcd_enuDioNok;
	}

	return Loc_LcdErrorState;
}
static Lcd_enuErrorState Lcd_8bitSetCursor(u8 Copy_u8LcdName, u8 Copy_u8Row, u8 Copy_u8Col)
{
	Lcd_enuErrorState Loc_LcdErrorState = Lcd_enuOk;

	// Check if the LCD name is within valid range
	if (Copy_u8LcdName > NUM_OF_LCD || Copy_u8LcdName < LCD_NUMBER1)
	{
		Loc_LcdErrorState = Lcd_enuInvalidLcdName;
	}
	else
	{
		Copy_u8Col--;
		switch (Copy_u8Row)
		{
			case ROW1:
			// Set cursor position in the first row
			Loc_LcdErrorState = Lcd_8bitWriteCommand(Copy_u8LcdName, 0x80 + Copy_u8Col);
			break;

			case ROW2:
			// Set cursor position in the second row
			Loc_LcdErrorState = Lcd_8bitWriteCommand(Copy_u8LcdName, 0xC0 + Copy_u8Col);
			break;
		}
	}

	return Loc_LcdErrorState;
}
