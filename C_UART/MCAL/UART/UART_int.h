/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_config.h"
#include "UART_private.h"

void UART_voidInit(void);

void UART_voidSendChar( u8 u8Data );

void UART_voidSendString(u8 *String);

u8 UART_u8Receive( void );
#endif /* MCAL_UART_UART_INT_H_ */
