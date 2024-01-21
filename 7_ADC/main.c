/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "MCAL/ADC/ADC_int.h"
#include "MCAL/DIO/DIO_int.h"
#include "HAL/LCD/LCD_int.h"
int main()
{
	//initializations

	DIO_voidSetPortVal(DIO_PORTD, DIO_PORT_INPUT);


	LCD_voidInit();
	ADC_voidADCInit();
	s32  millivolt1,millivolt2,degree;

	//loop
	while(1)
	{


		millivolt1=ADC_u16ReadChannel(CH_0)*4.88;
		millivolt2=ADC_u16ReadChannel(CH_1)*4.88;


		//x1=((u16)(ADC_u16ReadChannel(CH_0) *(u32) 5000))/(s32)(1024);
		degree = (millivolt1-millivolt2)/10;

		LCD_voidGoTo(1,1);
		LCD_voidWriteString("Temp:");
		LCD_voidGoTo(1,2);

		LCD_voidWriteNum(degree);
		LCD_voidWriteString("          "); //for clearing extra numbers when counting down

	}
	return 0;
}



