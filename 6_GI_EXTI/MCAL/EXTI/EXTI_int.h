/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */
/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_


#include "../../LIB/TYPES.H"
#include "../../LIB/BIT_MATH.h"
#include "avr/interrupt.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


#define EXTI_0         0
#define EXTI_1         1
#define EXTI_2         2

#define EXTI_LOWLEVEL  0
#define EXTI_ONCHANGE  1
#define EXTI_FALLING   2
#define EXTI_RISING    3


void EXTI_voidEnable( u8 u8EXTI_Line);
void EXTI_voidDisable( u8 u8EXTI_Line);




#endif /* MCAL_EXTI_EXTI_INT_H_ */
