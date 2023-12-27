/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "TMR2_int.h"
#include <avr/interrupt.h>

/****** Global Pointer To Function *********/
void (*TMR2_PFunc_OVF)(void)=NULL;
void (*TMR2_PFunc_OCM)(void)=NULL;

void TMR2_voidSetOVFCallBack(void(*LocPFunc)(void))
	{
	TMR2_PFunc_OVF=LocPFunc;
	}
void TMR2_voidSetOCMCallBack(void(*LocPFunc)(void))
	{
	TMR2_PFunc_OCM=LocPFunc;
	}

ISR(TIMER2_OVF_vect)
{
	if(TMR2_PFunc_OVF!=NULL)
	{
		TMR2_PFunc_OVF();
	}

}
ISR(TIMER2_COMP_vect)
{

	if(TMR2_PFunc_OCM!=NULL)
	{
		TMR2_PFunc_OCM();
	}
}
void TMR2_voidInit(void)
{
/*********************TIMER0 MODE*************************/
	#if	TMR2_MODE==Normal
		CLR_BIT(TCCR2,WGM00);
		CLR_BIT(TCCR2,WGM01);
	#elif	TIMER0_MODE==PWM_Phase_Correct
		SET_BIT(TCCR2,WGM00);
		CLR_BIT(TCCR2,WGM01);
	#elif     TIMER0_MODE==CTC
		CLR_BIT(TCCR2,WGM00);
		SET_BIT(TCCR2,WGM01);
	#elif     TIMER0_MODE==Fast_PWM
		SET_BIT(TCCR2,WGM00);
		SET_BIT(TCCR2,WGM01);
	#endif

	/*********************TIMER0 PRESCALER*************************/

	TCCR2 &= 0XF8;
	TCCR2 |=TMR2_Prescaler ;


	/*********************TIMER0 OC0 MODE*************************/
	#if	TIMER0_OC0_MODE==OC0_disconnected
		CLR_BIT(TCCR2,COM00);
		CLR_BIT(TCCR2,COM01);
	#elif 	TIMER0_OC0_MODE==Toggle_OC0
		SET_BIT(TCCR2,COM00);
		CLR_BIT(TCCR2,COM01);
	#elif 	TIMER0_OC0_MODE==RESERVED
		SET_BIT(TCCR2,COM00);
		CLR_BIT(TCCR2,COM01);
	#elif 	TIMER0_OC0_MODE==Clear_OC0
		CLR_BIT(TCCR2,COM00);
		SET_BIT(TCCR2,COM01);
	#elif 	TIMER0_OC0_MODE==Set_OC0
		SET_BIT(TCCR2,COM00);
		SET_BIT(TCCR2,COM01);
	#endif
}
void TMR2_voidEnableOVFInterrupt(void)
{
	SET_BIT(TIMSK,TOIE2);
}
void TMR2_voidEnableOCMInterrupt(void)
{
	SET_BIT(TIMSK,OCIE2);
}

void TMR2_voidSetCounter(u8 Value_of_TCNT2)
{
	TCNT2=Value_of_TCNT2;
}
void TMR2_voidSetCM(u8 Value_of_OCR2)
{
	OCR2=Value_of_OCR2;
}
void TMR2_voidSetDutyCycle(u8 DutyCycle )
{
	OCR2=(DutyCycle*255)/100;
}
