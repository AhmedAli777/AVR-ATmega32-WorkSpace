/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef MCAL_WDT_WDT_PRIVATE_H_
#define MCAL_WDT_WDT_PRIVATE_H_

#define WDTCR			*((volatile u8*)0x41)

#define WDTCR_WDTOE		4
#define WDTCR_WDE		3
#define WDTCR_WDP2		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0



#endif /* MCAL_WDT_WDT_PRIVATE_H_ */
