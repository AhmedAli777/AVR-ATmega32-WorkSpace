/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "EEPROM_int.h"
#include <string.h>


void EEPROM_voidRead(u8 Address,u8* ptr)
{
	TWI_voidMasterStart();

	TWI_voidMasterWriteAddressW(EEPROM_Addess);

	TWI_voidMasterWriteData(Address);

	TWI_voidMasterReStart();

	TWI_voidMasterWriteAddressR(EEPROM_Addess);

		*(ptr)=(TWI_u8MasterReadACK());


	TWI_voidMasterStop();
}

void EEPROM_voidWrite(u8 Address,u8 u8data)
{
	TWI_voidMasterStart();
	TWI_voidMasterWriteAddressW(EEPROM_Addess);
	TWI_voidMasterWriteData(Address);

	TWI_voidMasterWriteData(u8data);

	TWI_voidMasterStop();
	_delay_ms(10);
}




void EEPROM_voidReadString(u8 Address,u8* ptr)
{
	TWI_voidMasterStart();

	TWI_voidMasterWriteAddressW(EEPROM_Addess);

	TWI_voidMasterWriteData(Address);

	TWI_voidMasterReStart();

	TWI_voidMasterWriteAddressR(EEPROM_Addess);

	for (int i = 0; i<strlen(ptr); i++)
	{
		*(ptr+i)=(TWI_u8MasterReadACK());
	}

	TWI_voidMasterStop();
}

void EEPROM_voidWriteString(u8 Address,u8 *ptr)
{
	TWI_voidMasterStart();
	TWI_voidMasterWriteAddressW(EEPROM_Addess);
	TWI_voidMasterWriteData(Address);
	for (int i = 0; i<strlen(ptr); i++)
	{
		TWI_voidMasterWriteData(ptr[i]);
	}
	TWI_voidMasterStop();
	_delay_ms(10);
}

