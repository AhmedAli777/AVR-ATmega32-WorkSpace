/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef HAL_STP_STP_INT_H_
#define HAL_STP_STP_INT_H_


#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "STP_config.h"


#define DEG2FULLSTEP(DEG)    (DEG/ STP_ANG)
#define ITRATOR(DEG)         (DEG / STP_ANG) / 4
#define CW                    1
#define CCW                   2
#define HSTEP                 1
#define FSTEP                 2



void STP_voidInit();
void STP_voidGoToAngle(u8 u8Direction, u8 u8Step, u16 u8Angle);
// possible degrees are the degrees makes the "ITRATOR(DEG)" function returns an integer number.
// angle is relative to stepper current angle, i.e: 90 degree means go 90 degrees from current degree

#endif /* HAL_STP_STP_INT_H_ */
