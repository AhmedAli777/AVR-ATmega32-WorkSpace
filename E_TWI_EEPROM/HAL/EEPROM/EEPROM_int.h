/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#include "../../MCAL/TWI/TWI_int.h"
#include "EEPROM_config.h"

void EEPROM_voidRead(u8 u8BlockNo,u8 Address,u8* ptr);
void EEPROM_voidWrite(u8 u8BlockNo,u8 Address,u8 u8data);

void EEPROM_voidReadString(u8 u8BlockNo,u8 Address,u8* ptr);
void EEPROM_voidWriteString(u8 u8BlockNo,u8 Address,u8 *ptr);

void EEPROM_voidERASEBLOCK(u8 U8BlockNo);
void EEPROM_voidERASEALLDATA(u8 u8Pass);


#endif /* HAL_EEPROM_EEPROM_INT_H_ */
