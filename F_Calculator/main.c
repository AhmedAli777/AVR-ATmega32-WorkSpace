/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */



#include "HAL/LCD/LCD_int.h"
#include "HAL/KPD/KPD_int.h"

u8 NumOrOp (u8 num);

void showResult( );

void CalInit();

u8 button,op;
s32 num1,num2;
u8 fnum1=1,fnum2=0,fop=0,fresult=0, SYNError=0;



int main()
{

	LCD_voidInit();
	KPD_voidInit();


	//loop
	while(1)
	{



		button= KPD_u8GetPressedKey();
		if(button!=255)
		{

			if(fresult==1)
			{
				CalInit();
				fresult=0;
			}


			LCD_voidWriteChar(button);

			if(NumOrOp (button))
				{
					if(fnum1)
						{
						num1=num1*10+ (button -48);
						fop=1;
						}
					else if (fnum2)
					{
						num2=num2*10+ (button -48);
						fop=0;
					}
				}
			else if(~NumOrOp(button))
			{
				if (button=='C')
				{
					 LCD_ClrLCD();
					 CalInit();

				}
				else if(fop && button != '=')
				{
					op = button;
					fop=0;
					fnum1=0;
					fnum2=1;

				}

				else if (button =='=')
				{
					showResult();
					fresult=1;
				}
			}

		}
	}
	return 0;
}

void CalInit()
{

	 LCD_ClrLCD();

	 fnum1=1;
	 fnum2=0;
	 fop=0;
	 SYNError=0;
	 num1=0;
	 num2=0;
	 LCD_voidGoTo(1,1);
}
u8 NumOrOp (u8 num)
 {
	 u8 localresult;
	 if ( num == '+' ||  num == '-' || num == 'X' || num == '/' || num == '=' || num == 'C'  )
		 localresult= 0;
	 else
		 localresult= 1;

	return localresult;
 }





void showResult()
{
	LCD_voidGoTo(1,2);
	LCD_voidWriteString("                ");
	LCD_voidGoTo(1,2);
	if( fnum1==1 && fop==1 && fnum2 ==0) // for 1 =
		LCD_voidWriteNum(num1);

	else if (op == '+')
 		LCD_voidWriteNum(num1+num2);
 	 else if (op == '-')
 		LCD_voidWriteNum(num1-num2);
 	 else if (op=='X')
 		LCD_voidWriteNum(num1*num2);
 	 else if (op=='/')
 	 {
 		 if(num2==0)
 			 LCD_voidWriteString("ERROR / ZERO");
 		 else
 			 LCD_voidWriteNum(num1/num2);
 	 }
 	 else
 		LCD_voidWriteString("ERROR");

}
