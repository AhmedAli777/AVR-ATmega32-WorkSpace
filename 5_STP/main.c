/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "HAL/STP/STP_int.h"


int main (){

	void STP_voidInit();

	while(1)
	{
		STP_voidGoToAngle(CW, FSTEP , 30);
		_delay_ms(1000);
		STP_voidGoToAngle(CCW, FSTEP , 30);
		_delay_ms(1000);
		STP_voidGoToAngle(CW, HSTEP ,120);
		_delay_ms(1000);
		STP_voidGoToAngle(CCW, HSTEP , 120);
		_delay_ms(1000);

	}
	return 0;
}
