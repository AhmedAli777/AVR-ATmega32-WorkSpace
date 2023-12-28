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

void EEPROM_voidERASEBLOCK(u8 u8BlockNo)
{
	if (u8BlockNo < MaxBlockNo )
	{
		TWI_voidMasterStart();
		TWI_voidMasterWriteAddressW(EEPROM_Adress|u8BlockNo);
		TWI_voidMasterWriteData(0X00);
		for (u8 i = 0; i<MaxWordAddress; i++)
		{
			TWI_voidMasterWriteData(0XFF);
		}
		TWI_voidMasterStop();
		_delay_ms(10);
	}
}

void EEPROM_voidERASEALLDATA(u8 u8Pass)
{

	if (u8Pass == ERASEPASS)
	{
		u8 erase_i =0;
		for (erase_i=0 ;erase_i<=MaxBlockNo;erase_i++)
		{
			EEPROM_voidERASEBLOCK(erase_i);

		}

	}


}
