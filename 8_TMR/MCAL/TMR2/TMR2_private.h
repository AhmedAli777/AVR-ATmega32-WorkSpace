/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR0_TMR0_PRIVATE_H_
#define MCAL_TMR0_TMR0_PRIVATE_H_

#define OCR2   	*((volatile u8*)0x43)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)
#define TCCR2	*((volatile u8*)0x45)
#define TCNT2	*((volatile u8*)0x44)



#define NULL 		( (void*) 0 )

#endif /* MCAL_TMR0_TMR0_PRIVATE_H_ */
