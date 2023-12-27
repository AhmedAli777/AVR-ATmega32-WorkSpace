/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_


#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "TWI_config.h"
#include "TWI_private.h"




void TWI_voidMasterInit();


void TWI_VoidSlaveInit(u8 u8SlaveAdress);


void TWI_voidMasterStart();
void TWI_voidMasterReStart();
void TWI_voidMasterStop();

void TWI_voidMasterWriteAddressW(u8 u8data);
void TWI_voidMasterWriteAddressR(u8 u8data);
void TWI_voidMasterWriteData(u8 u8data);

u8 TWI_u8MasterReadACK();
u8 TWI_u8MasterReadNACK();


void TWI_VoidSetErrorFunction(void (*Lpfunc)(u8) );

void TWI_u8ERROR(u8 u8error);

#endif /* MCAL_TWI_TWI_INT_H_ */
