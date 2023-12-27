/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "ICU_int.h"
#include <avr/interrupt.h>


#define NULL 		( (void*) 0 )

static void (*GPFunc_IC)(void)=NULL;
void ICU_voidSeICtCallBack(void(*LocPFunc)(void))
{
	GPFunc_IC=LocPFunc;
}


ISR(TIMER1_CAPT_vect)
{
	if(GPFunc_IC!=NULL)
	{
		GPFunc_IC();
	}

}


void ICU_voidInit()
{

	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6, DIO_PIN_INPUT);
	TMR1_voidInit();
	TMR1_voidSetTimerCounter(0);

	TCCR1B &=  ~(1<<ICNC1);
	TCCR1B |=  (NOISECANCELLER <<ICNC1);
}

void ICU_voidSetICFalling()
{

	TCCR1B &= ~(1<<ICES1);

}
void ICU_voidSetICRising()
{
	TCCR1B |= (1<<ICES1);

}


u16 ICU_u16GetICUFreq(){

	u16 FirstRising,SecondRising, Period,freq;

	TMR1_voidSetTimerCounter(0);

		TIFR=(1<<ICF1);

		ICU_voidSetICRising(); // ICR rising edg.
		while((TIFR&(1<<ICF1))==0);
		TIFR=(1<<ICF1);
		FirstRising=ICR1;


		while((TIFR&(1<<ICF1))==0);
		TIFR=(1<<ICF1);
		SecondRising=ICR1;

		TMR1_voidSetTimerCounter(0);

		if( SecondRising>FirstRising)
		{
			Period= SecondRising-FirstRising;
			freq= F_CPU  / (Period * TMR1_PRE);
		}
		else
		{
			freq=0;
		}
		return freq;
}

u16 ICU_u16GetICUDuty(){

	u16 FirstRising,FirstFalling,SecondRising,DutyCycle, Period,OnTime;

		TMR1_voidSetTimerCounter(0);
		TIFR=(1<<ICF1);
		ICU_voidSetICRising(); // ICR rising edg.
		while((TIFR&(1<<ICF1))==0);
		TIFR=(1<<ICF1);
		FirstRising=ICR1;


		ICU_voidSetICFalling();  // ICR falling edg.
		while((TIFR&(1<<ICF1))==0);
		TIFR=(1<<ICF1);
		FirstFalling=ICR1;

		ICU_voidSetICRising(); // ICR rising edg.
		while((TIFR&(1<<ICF1))==0);
		TIFR=(1<<ICF1);
		SecondRising=ICR1;

		TMR1_voidSetTimerCounter(0);
			if(FirstFalling>FirstRising && SecondRising>FirstFalling)
			{
				Period= SecondRising-FirstRising;
				OnTime = FirstFalling-FirstRising;
				DutyCycle= (OnTime*100)/Period;
			}
			else
			{
				DutyCycle=0;
			}
return DutyCycle;
}

void ICU_voidEnableICInterrupt(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void ICU_voidDisableICInterrupt(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
