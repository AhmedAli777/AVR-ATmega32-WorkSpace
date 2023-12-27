/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#include "../../MCAL/TWI/TWI_int.h"
#include "EEPROM_config.h"

void EEPROM_voidRead(u8 Address,u8* ptr);
void EEPROM_voidWrite(u8 Address,u8 u8data);

void EEPROM_voidReadString(u8 Address,u8* ptr);
void EEPROM_voidWriteString(u8 Address,u8 *ptr);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */
