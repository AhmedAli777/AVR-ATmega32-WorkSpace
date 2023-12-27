/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
#include "ADC_private.h"


////////////////////////////////////////////////////
#define EXT     0X00
#define VCC     0X01
#define INT     0X03

#define REFERENCE        VCC
//////////////////////////////////////////////




#define DIV_2        0X00
#define DIV_4        0X02
#define DIV_8        0X03
#define DIV_16       0X04
#define DIV_32       0X05
#define DIV_64       0X06
#define DIV_128      0X07
#define PRESCALE         DIV_8


///////////////////////////////////////////
#define Adj_Right 0
#define Adj_Left  1


#define RESULT_ADJUST    Adj_Right
/////////////////////////////////////////////
#define Enable    1
#define Disable   0
#define Interrupt        Disable
/////////////////////////////////////////////





#endif /* MCAL_ADC_ADC_CONFIG_H_ */
