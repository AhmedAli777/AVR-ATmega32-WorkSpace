/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "MCAL/GI/GI_int.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/DIO/DIO_int.h"


int main()
{

	//interrupt pin input
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	//interrupt pin 1 "pullup"
	DIO_voidSetPinVal(DIO_PORTD, DIO_PIN2, DIO_HIGH);



	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN0, DIO_PIN_OUTPUT);

	GI_voidEnable();
	EXTI_voidEnable(EXTI_0);




	 while(1)
	 {




	 }

	return 0;
}


ISR(INT0_vect)
{
	DIO_voidTogPinVal(DIO_PORTD, DIO_PIN0);

}


