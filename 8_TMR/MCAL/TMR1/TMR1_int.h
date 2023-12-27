/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR1_TMR1_INT_H_
#define MCAL_TMR1_TMR1_INT_H_
#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TMR1_private.h"
#include "TMR1_config.h"


void TMR1_voidSetOVFCallBack(void(*LocPFunc)(void));
void TMR1_voidSetOCACallBack(void(*LocPFunc)(void));


void TMR1_voidInit(void);

void TMR1_voidEnableOVFInterrupt(void);
void TMR1_voidEnableOCAMInterrupt(void);
void TMR1_voidEnableOCBMInterrupt(void);

void TMR1_voidSetTimerCounter(u16 Value_of_TCNT1);
void TMR1_voidSetOCR1A(u16 Value_of_OCR1A);
void TMR1_voidSetOCR1B(u16 Value_of_OCR1B);




#endif /* MCAL_TMR1_TMR1_INT_H_ */
