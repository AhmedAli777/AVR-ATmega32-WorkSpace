/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "SS_int.h"



u8 SS_grid[10]={
		0b00111111,  //0
		0b00000110,  //1
		0b01011011,  //2
		0b01001111,  //3
		0b01100110,  //4
		0b01101101,  //5
		0b01111101,  //6
		0b00000111,  //7
		0b01111111,  //8
		0b01101111   //9

};

void SS_voidInit(u8 u8SS_Port)
	{
	DIO_voidSetPortDir(u8SS_Port, DIO_PORT_OUTPUT);
	}


void SS_voidDisplayNumer(u8 u8ssPort, u8 u8Num)
{
	if(u8Num<10)
	{
#if SS_TYPE == cathode
		DIO_voidSetPortVal (u8ssPort,SS_grid[u8Num]);
#elif SS_TYPE == anode
		DIO_voidSetPortVal (u8ssPort,~SS_grid[u8Num]);
#endif
	}
}



void SS_voidDisp2digts(u8 u8ssPort1,u8 u8ssPort2, u8 u8Num)
{
	if (u8Num <100)
	{
		u8 dig1 = u8Num % 10;
		u8 dig2 = u8Num / 10;

		SS_voidDisplayNumer(u8ssPort1, dig1);
		SS_voidDisplayNumer(u8ssPort2, dig2);
	}


}


void SS_voidTurnOff(u8 u8ssPort){
#if SS_TYPE == cathode
		DIO_voidSetPortVal (u8ssPort,0x00);
#elif SS_TYPE == anode
		DIO_voidSetPortVal (u8ssPort,0xff);
#endif
}


void SS_voidCountUp(u8 u8ssPort, u8 u8Num)
{
	for ( u8 counter=u8Num ; counter <= nine ; counter++ )
	{
		SS_voidDisplayNumer(u8ssPort, counter);
		_delay_ms(delaytime);
	}

}


void SS_voidCountDown(u8 u8ssPort, u8 u8Num)
{
	for (s8 counter=u8Num ; counter >= zero ; counter-- )
	{
		SS_voidDisplayNumer(u8ssPort, counter);
		_delay_ms(delaytime);
	}
}
