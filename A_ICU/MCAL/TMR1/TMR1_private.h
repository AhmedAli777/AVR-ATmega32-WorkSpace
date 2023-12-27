/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR1_TMR1_PRIVATE_H_
#define MCAL_TMR1_TMR1_PRIVATE_H_


#define TCNT1   *((volatile u16*)0x4C)

#define OCR1A   *((volatile u16*)0x4A)

#define OCR1B   *((volatile u16*)0x48)

#define ICR1   *((volatile u16*)0x46)

#define TCCR1A   *((volatile u8*)0x4F)

#define TCCR1B   *((volatile u8*)0x4E)

#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)


#define NULL 		( (void*) 0 )
#endif /* MCAL_TMR1_TMR1_PRIVATE_H_ */
