/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "UART_int.h"


#define UBBRVAL_NORMALSPEED   (F_CPU)/(BAUDRATE*16UL)-1
#define UBBRVAL_DOUBLESPEED   (F_CPU)/(BAUDRATE*8UL)-1

void UART_voidInit(void)
{

//ENABLE SENDING AND REVEIVING
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
//ENABLE OR DISABLE DOUBLE SPEED

#if DOUBLESPEED ==1
	SET_BIT(UCSRA,U2X);
#endif


//STOPBIT
#if STOPBITS ==2
	USCRC |= (1<<URSEL) | (1<<USBS)
#endif

//BARITYMODE
#if BARITYMODE  ==2 || BARITYMODE  ==3
	USCRC |= (1<<URSEL) | (1<<UPM0)
#endif


#if DOUBLESPEED ==0
	#if UBBRVAL_NORMALSPEED < 255
		UBRRL = UBBRVAL_NORMALSPEED ;
	#elif UBBRVAL >255
		UBRRL = (u8)UBBRVAL_NORMALSPEED;
		UBRRH &= ~(1<<URSEL) | (UBBRVAL_NORMALSPEED>>8) ;
	#endif
#elif DOUBLESPEED ==1
	#if UBBRVAL_DOUBLESPEED < 255
		UBRRL = UBBRVAL_DOUBLESPEED ;
	#elif UBBRVAL >255
		UBRRL = (u8)UBBRVAL_DOUBLESPEED;
		UBRRH &= ~(1<<URSEL) | (UBBRVAL_DOUBLESPEED>>8) ;
	#endif
#endif
}


void UART_voidSendChar( u8 u8Data )
{
    // Wait for empty transmit buffer
    while(!( UCSRA & (1<<UDRE) ));

    // Put data into buffer, sends the data
    UDR = u8Data;
}

/****************************************/
void UART_voidSendString(u8 *String)
 {
    while(*String != '\0')
        {
    	UART_voidSendChar(*String++);
        }
 }
/****************************************/
u8 UART_u8Receive( void )
    {
        //Wait for data to be received
        while ( !(UCSRA & (1<<RXC)) );
        // Get and return received data from buffer
        return UDR;
    }
