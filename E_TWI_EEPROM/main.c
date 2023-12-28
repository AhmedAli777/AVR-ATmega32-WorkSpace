/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "MCAL/TWI/TWI_int.h"
#include "HAL/LCD/LCD_int.h"
#include "HAL/EEPROM/EEPROM_int.h"


void Errorfun(u8 u8error){

	LCD_voidGoTo(1,2);
	LCD_voidWriteString("ERROR NO:");
	LCD_voidWriteNum(u8error);
}


int main(void)
{
	TWI_VoidSetErrorFunction(Errorfun);

	u8 x;
	u8*ptrx = &x;

	u8 array[] = "Ahmed";
	u8 arrayR[]= "     ";


	LCD_voidInit();
	TWI_voidMasterInit();

	EEPROM_voidWriteString(1,0x00,array);
	EEPROM_voidWrite(3,0x10,0x5);



	EEPROM_voidReadString(1,0x00,arrayR);
	EEPROM_voidRead(3,0x10,ptrx);

	LCD_voidGoTo(1,1);
	LCD_voidWriteString("EEPROM Read:");
	LCD_voidGoTo(1,2);

	LCD_voidWriteString(arrayR);
	LCD_voidGoTo(8,2);
	LCD_voidWriteNum(x);

	EEPROM_voidERASEALLDATA(0X22);


	while(1)
	{
	}

}


