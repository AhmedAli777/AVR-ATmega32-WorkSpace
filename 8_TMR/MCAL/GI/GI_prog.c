/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#include "GI_int.h"



void GI_voidEnable()
{
	SET_BIT(GI_SREG_REG, SREG_I);
}


void GI_voideDisable()
{
	CLR_BIT(GI_SREG_REG, SREG_I);
}
