/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "HAL/SS/SS_int.h"
#include "HAL/KPD/KPD_int.h"

int main()
{
	//init.
	SS_voidInit(DIO_PORTD);
	KPD_voidInit();
	u8 button;
	//loop
	while(1)
	{
		button= KPD_u8GetPressedKey();
		if (button!=255)
			SS_voidDisplayNumer(DIO_PORTD, button);
	}
	return 0;
}
