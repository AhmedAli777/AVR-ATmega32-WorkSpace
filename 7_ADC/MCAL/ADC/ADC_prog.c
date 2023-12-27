/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "ADC_int.h"


void ADC_voidADCInit(){
	DIO_voidSetPortDir(DIO_PORTA,DIO_PORT_INPUT);
	//ENABLE ADC
	SET_BIT(ADCSRA,ADEN);



	ADCSRA &= 0XF8;      //CLEAR PRESCAL BITS    0B11111000
	ADCSRA |= PRESCALE;

	ADMUX  &= 0X3F;      //CLEAR REF. BITS       0B00111111
	ADMUX  |= (REFERENCE << REFS0);

	CLR_BIT(ADMUX,ADLAR);


}



u32  ADC_u16ReadChannel(u8 u8CH){

     u8CH &= 0X07; // make sure that channel not bigger than 7

	 ADMUX = (ADMUX & 0xF8) | u8CH ; // clear bits 0:2 first to avoid garbage value from old operation, whit respict other bit as they are (5,6,7) , then assign Channel Id on it.

	 ADCSRA |= (1<<ADSC);

	while (!(ADCSRA & (1<<ADIF)) ); //STUCK UNTIL FLAG OF FINSH CONVEGRATION =1
	 ADCSRA|=(1<<ADIF); // clear flag

	 return ADC;
 }

