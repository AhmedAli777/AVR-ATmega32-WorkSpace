/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "EEPROM_int.h"
#include <string.h>


void EEPROM_voidRead(u8 u8BlockNo,u8 Address,u8* ptr)
{
	if (u8BlockNo < MaxBlockNo && Address <MaxWordAddress)
	{
		TWI_voidMasterStart();

		TWI_voidMasterWriteAddressW(EEPROM_Adress|u8BlockNo);

		TWI_voidMasterWriteData(Address);

		TWI_voidMasterReStart();

		TWI_voidMasterWriteAddressR(EEPROM_Adress|u8BlockNo);

			*(ptr)=(TWI_u8MasterReadACK());


		TWI_voidMasterStop();
	}
}

void EEPROM_voidWrite(u8 u8BlockNo,u8 Address,u8 u8data)
{
	if (u8BlockNo < MaxBlockNo && Address <MaxWordAddress)
	{
		TWI_voidMasterStart();
		TWI_voidMasterWriteAddressW(EEPROM_Adress|u8BlockNo);
		TWI_voidMasterWriteData(Address);

		TWI_voidMasterWriteData(u8data);

		TWI_voidMasterStop();
		_delay_ms(10);

	}
}


void EEPROM_voidReadString(u8 u8BlockNo,u8 Address,u8* ptr)
{
	if (u8BlockNo < MaxBlockNo && Address <MaxWordAddress)
	{
		TWI_voidMasterStart();

		TWI_voidMasterWriteAddressW(EEPROM_Adress|u8BlockNo);

		TWI_voidMasterWriteData(Address);

		TWI_voidMasterReStart();

		TWI_voidMasterWriteAddressR(EEPROM_Adress|u8BlockNo);

		for (u8 i = 0; i<strlen(ptr); i++)
		{
			*(ptr+i)=(TWI_u8MasterReadACK());
		}

		TWI_voidMasterStop();
	}
}

void EEPROM_voidWriteString(u8 u8BlockNo,u8 Address,u8 *ptr)
{
	if (u8BlockNo < MaxBlockNo && Address <MaxWordAddress)
	{
		TWI_voidMasterStart();
		TWI_voidMasterWriteAddressW(EEPROM_Adress|u8BlockNo);
		TWI_voidMasterWriteData(Address);
		for (u8 i = 0; i<strlen(ptr); i++)
		{
			TWI_voidMasterWriteData(ptr[i]);
		}
		TWI_voidMasterStop();
		_delay_ms(10);
	}
}


