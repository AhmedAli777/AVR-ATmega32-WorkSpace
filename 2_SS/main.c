/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "HAL/SS/SS_int.h"
#include <util/delay.h>


int main()
{
	//init
	SS_voidInit(DIO_PORTD);
	SS_voidInit(DIO_PORTB);

	//loop
	while(1)
	{
		for (u8 i=99; i>1;i--)
		{
			SS_voidDisp2digts(DIO_PORTD,DIO_PORTB,i);
			_delay_ms(500);
		}
	}
	return 0;
}
