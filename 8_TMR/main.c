/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "LIB/BIT_MATH.h"
#include "LIB/TYPES.h"
#include "MCAL/DIO/DIO_int.h"

#include "MCAL/GI/GI_int.h"
#include "MCAL/TMR1/TMR1_Int.h"

void timer0_func(void);
u16 counter=0;
int main(void)
{
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);

	TMR1_voidSetOCACallBack(timer0_func);

	TMR1_voidInit();
	TMR1_voidEnableOCAMInterrupt();
	TMR1_voidSetOCR1A(100);
	GI_voidEnable();

	while(1)
	{

	}
	return 0;
}

void timer0_func(void)
{

	counter++;
	if(counter==10)
	{
		DIO_voidTogPinVal(DIO_PORTA, DIO_PIN0);
		counter=0;
	}
}
