/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_ICU_ICU_CONFIG_H_
#define MCAL_ICU_ICU_CONFIG_H_

#define F_CPU               1000000UL
#define TMR1_PRE            1024
#define TMR1_TickTime       TMR1_PRE/F_CPU
#define NOISECANCELLER      1  // 0 DEISABLE 1 ENABLE

#endif /* MCAL_ICU_ICU_CONFIG_H_ */
