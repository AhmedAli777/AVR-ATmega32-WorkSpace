/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "LIB/BIT_MATH.h"
#include "LIB/TYPES.h"
#include "MCAL/DIO/DIO_int.h"

#include "HAL/SERVO/SERVO_int.h"
#include "HAL/LCD/LCD_int.h"

int main()
{

	SERVO_voidInit(SERVO1);
	SERVO_voidInit(SERVO2);

while(1)
	{
	SERVO_voidGoToDeg(SERVO1, 30);
	SERVO_voidGoToDeg(SERVO2, 55);

	}

	return 0;
}
