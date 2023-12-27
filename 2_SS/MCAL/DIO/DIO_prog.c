/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "DIO_int.h"



void DIO_voidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{

			if (u8PinDir == DIO_PIN_INPUT)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: CLR_BIT(DIO_DDRA_REG,u8PinId); break;
						case DIO_PORTB: CLR_BIT(DIO_DDRB_REG,u8PinId); break;
						case DIO_PORTC: CLR_BIT(DIO_DDRC_REG,u8PinId); break;
						case DIO_PORTD: CLR_BIT(DIO_DDRD_REG,u8PinId); break;
					}
				}
				else if (u8PinDir == DIO_PIN_OUTPUT)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: SET_BIT(DIO_DDRA_REG,u8PinId); break;
						case DIO_PORTB: SET_BIT(DIO_DDRB_REG,u8PinId); break;
						case DIO_PORTC: SET_BIT(DIO_DDRC_REG,u8PinId); break;
						case DIO_PORTD: SET_BIT(DIO_DDRD_REG,u8PinId); break;
					}
				}
		}
}



void DIO_voidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{

			if (u8PinVal == DIO_LOW)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: CLR_BIT(DIO_PORTA_REG,u8PinId); break;
						case DIO_PORTB: CLR_BIT(DIO_PORTB_REG,u8PinId); break;
						case DIO_PORTC: CLR_BIT(DIO_PORTC_REG,u8PinId); break;
						case DIO_PORTD: CLR_BIT(DIO_PORTD_REG,u8PinId); break;
					}
				}
				else if (u8PinVal == DIO_HIGH)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: SET_BIT(DIO_PORTA_REG,u8PinId); break;
						case DIO_PORTB: SET_BIT(DIO_PORTB_REG,u8PinId); break;
						case DIO_PORTC: SET_BIT(DIO_PORTC_REG,u8PinId); break;
						case DIO_PORTD: SET_BIT(DIO_PORTD_REG,u8PinId); break;
					}
				}
		}
}


void DIO_voidTogPinVal(u8 u8PortId, u8 u8PinId)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{
					switch(u8PortId)
					{
						case DIO_PORTA: TOG_BIT(DIO_PORTA_REG,u8PinId); break;
						case DIO_PORTB: TOG_BIT(DIO_PORTB_REG,u8PinId); break;
						case DIO_PORTC: TOG_BIT(DIO_PORTC_REG,u8PinId); break;
						case DIO_PORTD: TOG_BIT(DIO_PORTD_REG,u8PinId); break;
					}

		}
}
u8 DIO_u8GetPinVal(u8 u8PortId, u8 u8PinId)
{

	if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
	{
		u8 u8Result;

		switch(u8PortId)
		{
			case DIO_PORTA: u8Result= GET_BIT(DIO_PINA_REG,u8PinId); break;
			case DIO_PORTB: u8Result= GET_BIT(DIO_PINB_REG,u8PinId); break;
			case DIO_PORTC: u8Result= GET_BIT(DIO_PINC_REG,u8PinId); break;
			case DIO_PORTD: u8Result= GET_BIT(DIO_PIND_REG,u8PinId); break;
		}
		return u8Result;
	}
}






void DIO_voidSetPortDir(u8 u8PortId, u8 u8PortDir)
{
	if (u8PortId <=  DIO_PORTD)
	{
			switch(u8PortId)
			{
			case DIO_PORTA: DIO_DDRA_REG=  u8PortDir; break;
			case DIO_PORTB: DIO_DDRB_REG=  u8PortDir; break;
			case DIO_PORTC: DIO_DDRC_REG=  u8PortDir; break;
			case DIO_PORTD: DIO_DDRD_REG=  u8PortDir; break;
			}
	}

}


void DIO_voidSetPortVal(u8 u8PortId, u8 u8PortVal)
{
	if (u8PortId <=  DIO_PORTD)
	{
			switch(u8PortId)
			{
			case DIO_PORTA: DIO_PORTA_REG=  u8PortVal; break;
			case DIO_PORTB: DIO_PORTB_REG=  u8PortVal; break;
			case DIO_PORTC: DIO_PORTC_REG=  u8PortVal; break;
			case DIO_PORTD: DIO_PORTD_REG=  u8PortVal; break;
			}
	}
}
