/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "KPD_int.h"

u8 col, row,KPD_u8PressedKey;


u8 KPD_GRID[4][4]={
		{7  ,8 , 9 ,'/'}, //ROWS
		{4  ,5 , 6 ,'*'},
		{1  ,2 , 3 ,'-'},
		{'C',0 ,'=','+'}
		//COL
};


void KPD_voidInit(){
	DIO_voidSetPortDir(KPD_PORT, 0b00001111);
	DIO_voidSetPortVal(KPD_PORT, 0b11111111);
}

u8 KPD_u8GetPressedKey()
{
	KPD_u8PressedKey=255;
	for( col=0; col <ColsNo ; col++)
	{
		DIO_voidSetPinVal(KPD_PORT, col, DIO_LOW);
		for(row=4; row<RowsNo+ColsNo; row++) //4,5,6,7
		{
			if(DIO_u8GetPinVal(KPD_PORT, row)==DIO_LOW)
			{
				KPD_u8PressedKey= KPD_GRID[row-RowsNo][col];
			}
			while(DIO_u8GetPinVal(KPD_PORT, row)==DIO_LOW);
			_delay_ms(10);
		}
		DIO_voidSetPinVal(KPD_PORT, col, DIO_HIGH);
	}


	return KPD_u8PressedKey;
}
