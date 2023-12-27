/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */



#include "TWI_int.h"

#include "../../HAL/LCD/LCD_int.h"
#include <string.h>
#include "math.h"






#define TWBR_VAL	((F_CPU/FREQ)-16)/(2*pow(4,PRESCALE))



void TWI_voidMasterInit()
{
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_INPUT);

	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN0,DIO_HIGH);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN1,DIO_HIGH);


	TWSR |= PRESCALE;
	TWBR = TWBR_VAL;

	TWCR = (1<<TWEN);
}



void TWI_VoidSlaveInit(u8 u8SlaveAdress)
{
	//TWAR-SLAVE ADRESS
	TWAR=(u8SlaveAdress << 1)| TWAR;
	//ENABLE ACK
	SET_BIT(TWCR,TWEA);
	//ENABLE TWI
	SET_BIT(TWCR,TWEN);
}


void TWI_voidMasterStart()
{

	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != STARTCONDITION )
	{
		TWI_u8ERROR(1);
	}

}

void TWI_voidMasterReStart(void)
{
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != RESTART )
	{
		TWI_u8ERROR(2);
	}


}

void TWI_voidMasterStop()
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
	while(TWCR & (1<<TWSTO));
}


void TWI_voidMasterWriteAddressW(u8 u8data)
{
	TWDR = (u8data<<1) & 0XFE;	// R/W BIT =0
	CLR_BIT(TWCR,TWSTA); //CLEAR START BIT
	TWCR = (1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != SendSlaveAdressWithWrite )
	{
		TWI_u8ERROR(3);
	}
}

void TWI_voidMasterWriteAddressR(u8 u8data)
{
	TWDR = (u8data<<1) |1;	// R/W BIT =1
	CLR_BIT(TWCR,TWSTA); //CLEAR START BIT
	TWCR = (1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != SendSlaveAdressWithRead )
	{
		TWI_u8ERROR(4);
	}
}

void TWI_voidMasterWriteData(u8 u8data)
{
	TWDR = u8data;
	TWCR = (1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != MasterSendData )
	{
		TWI_u8ERROR(5);
	}
}

u8 TWI_u8MasterReadACK()
{

	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	if((TWSR&0xf8) != MasterReceieveDataACK  )
	{
		TWI_u8ERROR(6);
	}
	return TWDR;
}

u8 TWI_u8MasterReadNACK()
{
	TWCR=(1<<TWEN)|(1<<TWINT);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
	if((TWSR&0xf8) != MasterReceieveDataNACK  )
	{
		TWI_u8ERROR(7);
	}
}


//ERROR HANDLING///

void (*Gpfunc1)(u8)= NULL;


void TWI_VoidSetErrorFunction(void (*Lpfunc)(u8) )
{
	Gpfunc1=Lpfunc;
}

void TWI_u8ERROR(u8 u8error)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1(u8error);
	}
}
