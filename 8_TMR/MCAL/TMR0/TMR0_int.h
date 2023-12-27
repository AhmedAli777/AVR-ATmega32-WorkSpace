/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR0_TMR0_INT_H_
#define MCAL_TMR0_TMR0_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TMR0_config.h"
#include "TMR0_private.h"

void TMR0_voidSetOVFCallBack(void(*LocPFunc)(void));

void TMR0_voidSetOCMCallBack(void(*LocPFunc)(void));

void TMR0_voidInit(void);

void TMR0_voidEnableOVFInterrupt(void);

void TMR0_voidEnableOCMInterrupt(void);

void TMR0_voidSetCounter(u8 Value_of_TCNT0);

void TMR0_voidSetCM(u8 Value_of_OCR0);

void TMR0_voidSetDutyCycle(u8 DutyCycle );





#endif /* MCAL_TMR0_TMR0_INT_H_ */
