/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "TMR0_int.h"
#include <avr/interrupt.h>

/****** Global Pointer To Function *********/
void (*TMR0_PFunc_OVF)(void)=NULL;
void (*TMR0_PFunc_OCM)(void)=NULL;

void TMR0_voidSetOVFCallBack(void(*LocPFunc)(void))
	{
	TMR0_PFunc_OVF=LocPFunc;
	}


void TMR0_voidSetOCMCallBack(void(*LocPFunc)(void))
	{
	TMR0_PFunc_OCM=LocPFunc;
	}

ISR(TIMER0_OVF_vect)
{
	if(TMR0_PFunc_OVF!=NULL)
	{
		TMR0_PFunc_OVF();
	}

}
ISR(TIMER0_COMP_vect)
{

	if(TMR0_PFunc_OCM!=NULL)
	{
		TMR0_PFunc_OCM();
	}
}
void TMR0_voidInit(void)
{
/*********************TIMER0 MODE*************************/
	#if	TIMER0_MODE==Normal
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif	TIMER0_MODE==PWM_Phase_Correct
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif     TIMER0_MODE==CTC
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#elif     TIMER0_MODE==Fast_PWM
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#endif

	/*********************TIMER0 PRESCALER*************************/

	TCCR0 &= 0XF8;
	TCCR0 |=TMR0_Prescaler ;


	/*********************TIMER0 OC0 MODE*************************/
	#if	TIMER0_OC0_MODE==OC0_disconnected
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Toggle_OC0
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==RESERVED
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Clear_OC0
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif 	TIMER0_OC0_MODE==Set_OC0
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#endif
}
void TMR0_voidEnableOVFInterrupt(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TMR0_voidEnableOCMInterrupt(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void TMR0_voidSetCounter(u8 Value_of_TCNT0)
{
	TCNT0=Value_of_TCNT0;
}
void TMR0_voidSetCM(u8 Value_of_OCR0)
{
	OCR0=Value_of_OCR0;
}
void TMR0_voidSetDutyCycle(u8 DutyCycle ) //NON INVERTED FAST PWM
{
	OCR0=(DutyCycle*255)/100;
}
