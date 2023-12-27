/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#include "MCAL/DIO/DIO_int.h"
#include "MCAL/UART/UART_int.h"

/*
NODE 1
int main()
{

	 UART_voidInit();

	u8 i;

	while(1)
	{
		for (i=1 ; i<10; i++)
		{
		UART_voidSendChar( i );
		_delay_ms(100);
		}
	}
	return 0;
}
*/


//NODE 2
#include "HAL/SS/SS_int.h"
int main()
{
	DIO_voidSetPortDir(DIO_PORTA, DIO_PORT_OUTPUT);
	UART_voidInit();
	SS_voidInit(DIO_PORTA);
	u8 receive;

	while(1)
	{
		receive= UART_u8Receive();
		SS_voidDisplayNumer(DIO_PORTA, receive);
	}
	return 0;
}

