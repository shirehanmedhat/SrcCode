/******************************************************************
					Author  : Shirehan Medhat Abdeldsalam Ali
					Date    : 26-1-2023
					Driver  : DIO
					File    : DIO.c
					Version : (1)
*****************************************************************/

#include "DIO.h"

DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t DIO_ErrorState = NOK;
	/*Error Check for Pin , Port and Configuration*/
	if (  ( ( (Copy_enumPortNum >= PORTA_Choice ) && (Copy_enumPortNum <= PORTD_Choice) )  && ( ( Copy_enumPinNum >= PIN0 )  && (Copy_enumPinNum <= PIN7 ) ) &&   ( (Copy_enumConfig >= OUTPUT) && (Copy_enumConfig <= INPUT_PULLDOWN )  )    ))
	{
		DIO_ErrorState = OK;
		switch (Copy_enumPortNum)
		{
			case PORTA_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				Set_Bit (DDRA , Copy_enumPinNum);
				break;
				case INPUT_PULLUP:
				Clr_Bit (DDRA , Copy_enumPinNum);
				Set_Bit (PORTA , Copy_enumPinNum);
				break;
				case INPUT_PULLDOWN:
				Clr_Bit (DDRA , Copy_enumPinNum);
				Clr_Bit (PORTA , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			
			case PORTB_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				Set_Bit (DDRB , Copy_enumPinNum);
				break;
				case INPUT_PULLUP:
				Clr_Bit (DDRB , Copy_enumPinNum);
				Set_Bit (PORTB , Copy_enumPinNum);
				break;
				case INPUT_PULLDOWN:
				Clr_Bit (DDRB , Copy_enumPinNum);
				Clr_Bit (PORTB , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case PORTC_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				Set_Bit (DDRC , Copy_enumPinNum);
				break;
				case INPUT_PULLUP:
				Clr_Bit (DDRC , Copy_enumPinNum);
				Set_Bit (PORTC , Copy_enumPinNum);
				break;
				case INPUT_PULLDOWN:
				Clr_Bit (DDRC , Copy_enumPinNum);
				Clr_Bit (PORTC , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case PORTD_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				Set_Bit (DDRD , Copy_enumPinNum);
				break;
				case INPUT_PULLUP:
				Clr_Bit (DDRD , Copy_enumPinNum);
				Set_Bit (PORTD , Copy_enumPinNum);
				break;
				case INPUT_PULLDOWN:
				Clr_Bit (DDRD , Copy_enumPinNum);
				Clr_Bit (PORTD , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			default:
			break;
			
		}
		
	}
	
	else
	{
		/*Do Nothing*/
	}
	
	return DIO_ErrorState;
}




DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t DIO_ErrorState = NOK;
	
	if ( ( (Copy_enumPortNum >= PORTA_Choice ) && (Copy_enumPortNum <= PORTD_Choice) &&   ( (Copy_enumConfig >= OUTPUT) && (Copy_enumConfig <= INPUT_PULLDOWN )  )  ) )
	{
		DIO_ErrorState = OK;
		switch (Copy_enumPortNum)
		{
			case PORTA_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				DDRA = 0xff;
				break;
				case INPUT_PULLUP:
				DDRA =0x00;
				PORTA =0xff;
				break;
				case INPUT_PULLDOWN:
				DDRA = 0x00;
				PORTA = 0x00;
				break;
				default:
				break;
			}
			break;
			case PORTB_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				DDRB = 0xff;
				break;
				case INPUT_PULLUP:
				DDRB =0x00;
				PORTB =0xff;
				break;
				case INPUT_PULLDOWN:
				DDRB = 0x00;
				PORTB = 0x00;
				break;
				default:
				break;
			}
			break;
			case PORTC_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				DDRC = 0xff;
				break;
				case INPUT_PULLUP:
				DDRC =0x00;
				PORTC =0xff;
				break;
				case INPUT_PULLDOWN:
				DDRC = 0x00;
				PORTC = 0x00;
				break;
				default:
				break;
			}
			break;
			case PORTD_Choice:
			switch (Copy_enumConfig)
			{
				case OUTPUT:
				DDRD = 0xff;
				break;
				case INPUT_PULLUP:
				DDRD =0x00;
				PORTD =0xff;
				break;
				case INPUT_PULLDOWN:
				DDRD = 0x00;
				PORTD = 0x00;
				break;
				default:
				break;
			}
			break;
			default:
			break;
			
			
		}
		
	}
	else
	{
		/*Do Nothing*/
	}
	
	return DIO_ErrorState;
	
}

DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t DIO_ErrorState = NOK;
	/*Error Check For Port , Pin and Logic State*/
	if ( ( (Copy_enumPortNum >= PORTA_Choice ) && (Copy_enumPortNum <= PORTD_Choice) ) && ( ( Copy_enumPinNum >= PIN0 )  && (Copy_enumPinNum <= PIN7 ) ) &&( (Copy_enumLogicState >= LOW) && ( Copy_enumLogicState <= HIGH )))
	{
		DIO_ErrorState = OK;
		switch (Copy_enumPortNum)
		{
			case PORTA_Choice:
			switch (Copy_enumLogicState)
			{
				case LOW:
				Clr_Bit(PORTA , Copy_enumPinNum);
				break;
				case HIGH:
				Set_Bit (PORTA , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case PORTB_Choice:
			switch (Copy_enumLogicState)
			{
				case LOW:
				Clr_Bit(PORTB, Copy_enumPinNum);
				break;
				case HIGH:
				Set_Bit (PORTB , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case PORTC_Choice:
			switch (Copy_enumLogicState)
			{
				case LOW:
				Clr_Bit(PORTC, Copy_enumPinNum);
				break;
				case HIGH:
				Set_Bit (PORTC , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			case PORTD_Choice:
			switch (Copy_enumLogicState)
			{
				case LOW:
				Clr_Bit(PORTD, Copy_enumPinNum);
				break;
				case HIGH:
				Set_Bit (PORTD , Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;
			default:
			break;
			
		}
	}
	else
	{
		/*Do Nothing*/
	}
	
	return DIO_ErrorState;
}

DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t DIO_ErrorState = NOK;
	/*Error Check For the Port ONLY*/
	if ( ( (Copy_enumPortNum >= PORTA_Choice ) && (Copy_enumPortNum <= PORTD_Choice)  ) )
	{
		DIO_ErrorState = OK;
		
		switch (Copy_enumPortNum)
		{
			case PORTA_Choice:
			PORTA = Copy_enumLogicState;
			break;
			
			case PORTB_Choice:
			PORTB = Copy_enumLogicState;
			break;
			
			case PORTC_Choice:
			PORTC = Copy_enumLogicState;
			break;
			
			case PORTD_Choice:
			PORTD = Copy_enumLogicState;
			break;
			
			default:
			break;
		}
		
	}
	
	return DIO_ErrorState;
}


DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t DIO_ErrorState = NOK;
	
	if (  ( (Add_Pu8PinValue != NULL) && ( (Copy_enumPortNum >= PORTA_Choice ) && (Copy_enumPortNum <= PORTD_Choice) )  && ( ( Copy_enumPinNum >= PIN0 )  && (Copy_enumPinNum <= PIN7 ) ) ))
	{
		DIO_ErrorState = OK;
		switch (Copy_enumPortNum)
		{
			case PORTA_Choice:
			*Add_Pu8PinValue = Get_Bit (PINA , Copy_enumPinNum);
			break;
			case PORTB_Choice:
			*Add_Pu8PinValue = Get_Bit (PINB , Copy_enumPinNum);
			break;
			case PORTC_Choice:
			*Add_Pu8PinValue = Get_Bit (PINC , Copy_enumPinNum);
			break;
			case PORTD_Choice:
			*Add_Pu8PinValue = Get_Bit (PIND , Copy_enumPinNum);
			break;
			default:
			break;
			
		}
		
		
	}
	return DIO_ErrorState;
}

