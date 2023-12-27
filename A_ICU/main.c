/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "LIB/BIT_MATH.h"
#include "LIB/TYPES.h"
#include "MCAL/DIO/DIO_int.h"

#include "MCAL/GI/GI_int.h"
#include "MCAL/TMR1/TMR1_Int.h"
#include "MCAL/ICU/ICU_int.h"
#include "HAL/LCD/LCD_int.h"


int main(void)
{

	LCD_voidInit();
	ICU_voidInit();

	TMR1_voidInit();


u16 freq, duty;

	while(1)
	{
		freq= ICU_u16GetICUFreq();
		duty =ICU_u16GetICUDuty();
			LCD_voidGoTo(1, 1);
			LCD_voidWriteString("D: ");
			LCD_voidWriteNum(duty);
			LCD_voidWriteString(" %");
			LCD_voidGoTo(1, 2);
			LCD_voidWriteString("f:");
			LCD_voidWriteNum(freq);
			LCD_voidWriteString(" Hz");


		_delay_ms(1000);
	}
	return 0;
}

