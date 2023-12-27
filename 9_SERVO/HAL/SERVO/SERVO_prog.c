/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "SERVO_int.h"


void SERVO_voidInit(u8 u8ServoNum)
{
	if (u8ServoNum==1)
		DIO_voidSetPinDir(SERVO1_PIN, DIO_PIN_OUTPUT);
	else if (u8ServoNum==2)
		DIO_voidSetPinDir(SERVO2_PIN, DIO_PIN_OUTPUT);

	TMR1_voidInit();
	ICR1= TOP;
}


void SERVO_voidGoToDeg(u8 u8ServoNum, u16 u8Degree)
{
	if (u8ServoNum==1)
	{
		OCR1A= Ticks0Degree + (u8Degree *TicksForDegree );

	}
	else if (u8ServoNum==2)
	{
		OCR1B= Ticks0Degree + (u8Degree *TicksForDegree );
	}


}
