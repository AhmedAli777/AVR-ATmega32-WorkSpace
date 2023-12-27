/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var &= ~(1 << (BitNo))
#define GET_BIT(Var,BitNo)    ((Var >>BitNo)     &1)
#define TOG_BIT(Var, BitNo)   Var ^=  (1 << (BitNo))



#endif
