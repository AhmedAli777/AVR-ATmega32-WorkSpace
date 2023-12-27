/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef EXTI_INT_C_
#define EXTI_INT_C_


#define EXTI_GICR_REG    *((volatile u8*)0x5B)
#define EXTI_MCUCR_REG   *((volatile u8*)0x55)
#define EXTI_MCUCSR_REG  *((volatile u8*)0x54)
#define EXTI_GIFR_REG    *((volatile u8*)0x5A)



/******************GICR****************************/
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5


/******************MCUCR***************************/
#define MCUCR_ISC11		3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0


/******************MCUCSR**************************/
#define MCUCSR_INT2		6




#endif /* EXTI_INT_C_ */
