/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "HAL/LCD/LCD_int.h"


int main()

{
	LCD_voidInit();
	u8 ARR[8]= { 0x1f, 0x01,0x1f,0x10,0x10,0x10,0x1f,0x00};

	LCD_VoidSaveCustomChar(1,ARR);
	while(1)
	{
		LCD_voidGoTo(7,2);
		LCD_VoidWriteCustomChar(1);
	}

	return 0;
}

/* 1234 => TEMP = 4321
 * temp =0
 * temp = temp*10 + 1234%10 = > 4
 * 1234/10 => 123
 *
 * temp = temp*10 + 123%10 = 43
 * 123/10 =>12
 *
 * temp=temp*10 +12%10 = 432
 *
 * temp =4321
 *
 */


/*
*/






