/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_ICU_ICU_INT_H_
#define MCAL_ICU_ICU_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "../TMR1/TMR1_int.h"
#include "ICU_config.h"



void ICU_voidSeICtCallBack(void(*LocPFunc)(void));
void ICU_voidInit();


void ICU_voidSetICFalling();
void ICU_voidSetICRising();
u16  ICU_u16GetICUFreq();
u16  ICU_u16GetICUDuty();


void ICU_voidEnableICInterrupt();
void ICU_voidDisableICInterrupt();

#endif /* MCAL_ICU_ICU_INT_H_ */
