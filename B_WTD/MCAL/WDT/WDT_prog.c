/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "WDT_int.h"


void WDT_voidEnable(void)
{
	SET_BIT(WDTCR, WDTCR_WDE);
}



void WDT_voidDisable(void)
{

	WDTCR = 0b00011000;
	WDTCR = 0;
}


void WDT_voidSleep(u8 u8SleepTime)
{
	if(u8SleepTime < 8)
	{
		WDTCR &= 0b01111000;
		WDTCR |= u8SleepTime;
	}
}
