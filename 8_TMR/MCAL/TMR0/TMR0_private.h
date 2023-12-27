/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR0_TMR0_PRIVATE_H_
#define MCAL_TMR0_TMR0_PRIVATE_H_

#define OCR0   	*((volatile u8*)0x5C)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)
#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)



#define NULL 		( (void*) 0 )

#endif /* MCAL_TMR0_TMR0_PRIVATE_H_ */
