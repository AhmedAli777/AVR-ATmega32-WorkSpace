/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_ADC_INT_H_
#define MCAL_ADC_INT_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/TYPES.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../DIO/DIO_int.h"



#define ADLAR     5
#define REFS0     6
#define REFS1     7

#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADSC      6
#define ADIF      4
#define ADEN      7

#define CH_0 0X00
#define CH_1 0X01
#define CH_2 0X02
#define CH_3 0X03
#define CH_4 0X04
#define CH_5 0X05
#define CH_6 0X06
#define CH_7 0X07

void ADC_voidADCInit();
u32  ADC_u16ReadChannel(u8 u8CH);


#endif /* MCAL_ADC_INT_H_ */
