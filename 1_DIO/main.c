/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */



#include "DIO_int.h"


int main()
{


	//init
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	//loop
	while(1)
	{

		DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1, DIO_LOW);
		_delay_ms(1000);

		DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		_delay_ms(1000);

	}


	return 0;
}
