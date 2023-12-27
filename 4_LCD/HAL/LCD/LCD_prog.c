/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */
#include "LCD_int.h"


void LCD_voidSendCMD(u8 u8CMD)
{
	//SET RS TO LOW
	DIO_voidSetPinVal(LCD_RS, DIO_LOW);

	//SET RW TO LOW
	DIO_voidSetPinVal(LCD_RW , DIO_LOW);

	//SEND CMD ON DATA BUS
	DIO_voidSetPortVal(LCD_PORT, u8CMD);

	//SET E TO HIGH
	DIO_voidSetPinVal(LCD_E, DIO_HIGH);
	//SET E TO LOW
	DIO_voidSetPinVal(LCD_E, DIO_LOW);
	_delay_ms(5);

}

void LCD_voidWriteChar(u8 u8CHAR)
{
	//SET RS TO HIGH
	DIO_voidSetPinVal(LCD_RS, DIO_HIGH);

	//SET RW TO LOW
	DIO_voidSetPinVal(LCD_RW, DIO_LOW);
	//SEND CHAR ON DATA BUS
	DIO_voidSetPortVal(LCD_PORT, u8CHAR);
	//SET E TO HIGH
	DIO_voidSetPinVal(LCD_E, DIO_HIGH);
	//SET E TO LOW
	DIO_voidSetPinVal(LCD_E, DIO_LOW);
	_delay_ms(5);
}

void LCD_voidInit()
{
	DIO_voidSetPortDir(LCD_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDir(LCD_RW   , DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(LCD_RS   , DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(LCD_E    , DIO_PIN_OUTPUT);


	_delay_ms(30);
	LCD_voidSendCMD(LCD_FUNCSET_8BIT);
	_delay_us(40);
	LCD_voidSendCMD(LCD_DISPON_CURSON);
	_delay_us(40);
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(2);
	LCD_voidSendCMD(LCD_ENTRY_MODE);
	_delay_ms(2);


}

void LCD_ClrLCD()
{
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(2);

}

void LCD_voidGoTo(u8 X, u8 Y)
{
	if( X>0 && X<=16)
	{
		switch(Y)
		{
		case 1:  LCD_voidSendCMD(X +127); break; //1: 0x80 => Dec 128
		case 2:  LCD_voidSendCMD(X +191); break; //1: 0xC0 => DEC 192
		default: break;
		}
	}


}

void LCD_voidWriteString(u8 *u8ptrString)
{
	u8 u8counter=0;

	while(u8ptrString[u8counter]!='\0')
	{
		LCD_voidWriteChar(u8ptrString[u8counter++]);
	}

}

void LCD_voidWriteNum(s32 s32NUM)
{
	u32 temp= 1;
	if(s32NUM==0){
		LCD_voidWriteChar('0');
	}

	if(s32NUM<0){
		LCD_voidWriteChar('-');
		s32NUM*=-1;
	}
	while(s32NUM!=0)
	{
		temp= (temp*10)+s32NUM%10;
		s32NUM/=10;
	}
	while(temp !=1)
	{
		LCD_voidWriteChar((temp%10)+48);
		temp/=10;
	}
}



void LCD_VoidSaveCustomChar(u8 u8CGRAMIndex, u8 u8CustomArr[])
{
	LCD_voidSendCMD(LCD_CGRAM_ADDRESS+(u8CGRAMIndex*8)); //set cgram address 0-7, 64 dec of 0b01000000

	for(u8 index=0 ; index<8 ; index++)
	{
		LCD_voidWriteChar(u8CustomArr[index]);
	}

	LCD_voidSendCMD(LCD_SETCURS_DDRAM);
}

void LCD_VoidWriteCustomChar(u8 u8CGRAMIndex){
	if (u8CGRAMIndex<8)
		LCD_voidWriteChar(u8CGRAMIndex);

}
