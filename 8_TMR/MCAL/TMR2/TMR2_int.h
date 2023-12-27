/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR2_TMR2_INT_H_
#define MCAL_TMR2_TMR2_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TMR2_config.h"
#include "TMR2_private.h"

void TMR2_voidSetOVFCallBack(void(*LocPFunc)(void));

void TMR2_voidSetOCMCallBack(void(*LocPFunc)(void));

void TMR2_voidInit(void);

void TMR2_voidEnableOVFInterrupt(void);

void TMR2_voidEnableOCMInterrupt(void);

void TMR2_voidSetCounter(u8 Value_of_TCNT2);

void TMR2_voidSetCM(u8 Value_of_OCR2);

void TMR2_voidSetDutyCycle(u8 DutyCycle );





#endif /* MCAL_TMR2_TMR2_INT_H_ */
