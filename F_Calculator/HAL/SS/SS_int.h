/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef HAL_SS_SS_INT_H_
#define HAL_SS_SS_INT_H_


#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"



#define cathode 1
#define anode   2



#define SS_TYPE cathode

#define delaytime 1000

// use DIO_PORTA , DIO_PORTB , DIO_PORTC, DIO_PORTD

#define SS_PORT  DIO_PORTA


#define zero  0
#define one   1
#define two   2
#define three 3
#define four  4
#define five  5
#define six   6
#define seven 7
#define eight 8
#define nine  9


void SS_voidInit(u8 u8SS_Port);
void SS_voidDisplayNumer(u8 u8ssPort, u8 u8Num);
void SS_voidDisp2digts(u8 u8ssPort1,u8 u8ssPort2, u8 u8Num);
void SS_voidTurnOff(u8 u8ssPort);
void SS_voidCountUp(u8 u8ssPort, u8 u8Num);
void SS_voidCountDown(u8 u8ssPort, u8 u8Num);






#endif /* HAL_SS_SS_INT_H_ */
