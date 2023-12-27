/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef HAL_SERVO_SERVO_INT_H_
#define HAL_SERVO_SERVO_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/TMR1/TMR1_Int.h"
#include "SERVO_config.h"


#define Ticks0Degree         TIME_0DEG    * F_CPU /TIMER_PRESCALLER
#define Ticks180Degree       TIME_180DEG  * F_CPU /TIMER_PRESCALLER
#define TicksForDegree       (Ticks180Degree -Ticks0Degree ) /MAXANGLE
#define SERVO1               1
#define SERVO2               2



void SERVO_voidInit(u8 u8ServoNum);
void SERVO_voidGoToDeg(u8 u8ServoNum, u16 u8Degree);


#endif /* HAL_SERVO_SERVO_INT_H_ */
