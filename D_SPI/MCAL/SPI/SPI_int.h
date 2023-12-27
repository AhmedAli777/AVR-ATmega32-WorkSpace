/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "SPI_config.h"
#include "SPI_private.h"

void SPI_voidMasterInit(void);
void SPI_voiddSlaveInit(void);
u8 SPI_u8Transfer(u8 u8Data);
void SPI_voidInterruptEnable(void);
void SPI_voidSetCallBack( void (*Lpfunc)(void) );




#endif /* MCAL_SPI_SPI_INT_H_ */
