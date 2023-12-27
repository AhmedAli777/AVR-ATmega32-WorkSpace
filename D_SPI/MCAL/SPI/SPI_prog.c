/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */



#include "SPI_int.h"

#include <avr/interrupt.h>

/**GLOBAL POINTER TO FUNCTION**/
void (*Gpfunc1)(void)= NULL;


/********CALL BACK FUNCTION*****/
void SPI_voidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
/*************ISR FOR SPI**********/
ISR(SPI_STC_vect)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}


void SPI_voidMasterInit(void)
{


	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN5,DIO_PIN_OUTPUT); //MOSI
	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN7,DIO_PIN_OUTPUT); //SCK

    DIO_voidSetPinDir(SS1,DIO_PIN_OUTPUT);//SS1 OUTPUT
    DIO_voidSetPinDir(SS2,DIO_PIN_OUTPUT);//SS2 OUTPUT
    SPCR |= (1<<MSTR);
	SPCR |= (1<<SPE) |(LSB_FIRST<<DORD) |(PHASE<<CPHA)| (POLARITY<<CPHA);

	SPCR |=(GET_BIT(FREQ,0) << SPR0 );
	SPCR |=(GET_BIT(FREQ,1) << SPR1 );
	SPSR |=(GET_BIT(FREQ,2) << SPI2X);



    DIO_voidSetPinVal(SS1,DIO_HIGH);//SS HIGH
    DIO_voidSetPinVal(SS2,DIO_HIGH);//SS HIGH
}

void SPI_voiddSlaveInit(void)
{

	DIO_voidSetPinDir(DIO_PORTB, DIO_PIN6,DIO_PIN_OUTPUT);//MISO


	SPCR |= (1<<SPE) |(LSB_FIRST<<DORD) |(PHASE<<CPHA)|(POLARITY<<CPHA);

	SPCR |=(GET_BIT(FREQ,0) << SPR0 );
	SPCR |=(GET_BIT(FREQ,1) << SPR1 );
	SPSR |=(GET_BIT(FREQ,2) << SPI2X);

}

u8 SPI_u8Transfer(u8 u8Data)
{
	SPDR= u8Data;
	while((GET_BIT(SPSR,SPIF))==0);
	return SPDR;
}

void SPI_voidInterruptEnable(void)
{
	SET_BIT(SPCR,SPIE);
}
