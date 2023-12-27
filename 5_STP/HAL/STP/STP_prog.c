/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "STP_int.h"

u8 FullStepCCW[4]= {0x03,0x06,0x0c,0x09};
u8 HalfStepCCW[8]= {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};

u8 HalfStepCW[8]=  {0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
u8 FullStepCW[4]=  {0x0c,0x06,0x03,0x09};

void STP_voidInit(){

	//DIO_voidSetPortDir(STP_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDir(STP_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(STP_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(STP_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(STP_PIN4, DIO_PIN_OUTPUT);
}


void STP_voidGoToAngle(u8 u8Direction, u8 u8Step, u16 u8Angle)
{

	if (u8Step == FSTEP)
	{
		switch(u8Direction){

		case CW:

			for(u8 i= 0; i < ITRATOR(u8Angle)  ; i++)
			{

				for (u8 j=0 ;j<4;j++)
				{
					//DIO_voidSetPortVal(STP_PORT,  FullStepCW[j]);
					DIO_voidSetPinVal(STP_PIN1, GET_BIT(FullStepCW[j],0));
					DIO_voidSetPinVal(STP_PIN2, GET_BIT(FullStepCW[j],1));
					DIO_voidSetPinVal(STP_PIN3, GET_BIT(FullStepCW[j],2));
					DIO_voidSetPinVal(STP_PIN4, GET_BIT(FullStepCW[j],3));
					_delay_ms(DelayTime);
				}
			}; break;
		case CCW:
			for(u8 i= 0; i < ITRATOR(u8Angle)  ; i++)
			{

				for (u8 j=0 ;j<4;j++)
				{
					//DIO_voidSetPortVal(STP_PORT,  FullStepCCW[j]);
					DIO_voidSetPinVal(STP_PIN1, GET_BIT(FullStepCCW[j],0));
					DIO_voidSetPinVal(STP_PIN2, GET_BIT(FullStepCCW[j],1));
					DIO_voidSetPinVal(STP_PIN3, GET_BIT(FullStepCCW[j],2));
					DIO_voidSetPinVal(STP_PIN4, GET_BIT(FullStepCCW[j],3));
					_delay_ms(DelayTime);
				}
			}; break;

		}
	}
	else if (u8Step == HSTEP)
	{
		switch(u8Direction){

		case CW:
			for(u8 i= 0; i < ITRATOR(u8Angle)  ; i++)
			{

				for (u8 j=0 ;j<8;j++)
				{
					//DIO_voidSetPortVal(STP_PORT,  HalfStepCW[j]);
					DIO_voidSetPinVal(STP_PIN1, GET_BIT(HalfStepCW[j],0));
					DIO_voidSetPinVal(STP_PIN2, GET_BIT(HalfStepCW[j],1));
					DIO_voidSetPinVal(STP_PIN3, GET_BIT(HalfStepCW[j],2));
					DIO_voidSetPinVal(STP_PIN4, GET_BIT(HalfStepCW[j],3));
					_delay_ms(DelayTime);
				}
			}; break;
		case CCW:
			for(u8 i= 0; i < ITRATOR(u8Angle)  ; i++)
			{

				for (u8 j=0 ;j<8;j++)
				{
					//DIO_voidSetPortVal(STP_PORT,   HalfStepCCW[j]);
					DIO_voidSetPinVal(STP_PIN1, GET_BIT(HalfStepCCW[j],0));
					DIO_voidSetPinVal(STP_PIN2, GET_BIT(HalfStepCCW[j],1));
					DIO_voidSetPinVal(STP_PIN3, GET_BIT(HalfStepCCW[j],2));
					DIO_voidSetPinVal(STP_PIN4, GET_BIT(HalfStepCCW[j],3));
					_delay_ms(DelayTime);
				}
			}; break;

		}
	}




}

