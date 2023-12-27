/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "MCAL/DIO/DIO_int.h"
#include "MCAL/WDT/WDT_int.h"
#include <util/delay.h>

int main()
{

	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);

	DIO_voidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	_delay_ms(1000);

	DIO_voidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);


	WDT_voidEnable();


	while(1){
		WDT_voidSleep(6);


	}

	return 0;
}
