/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_TMR1_TMR1_CONFIG_H_
#define MCAL_TMR1_TMR1_CONFIG_H_


/***************************************************************************/
/******** *Timer/Counter1 Control Register A  TCCR1A*   ********************/
/***************************************************************************/
#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4
#define FOC1A    3
#define FOC1B    2
#define WGM11    1
#define WGM10    0

/***************************************************************************/
/*********** *Timer/Counter1 Control Register B  TCCR1B*   *****************/
/***************************************************************************/
#define ICNC1     7
#define ICES1     6
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0
/***************************************************************************/
/*************************** Timer/Counter Interrupt Mask Register – TIMSK   ************************/
/*************************************************************************/

#define  OCIE2       7
#define  TOIE2       6
#define  TICIE1      5
#define  OCIE1A      4
#define  OCIE1B      3
#define  TOIE1       2
#define  OCIE0       1
#define  TOIE0       0

/*************************************************************************/
/************* Timer/Counter Interrupt Flag Register – TIFR   ************/
/*************************************************************************/


#define TOVF1   2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5

/***************************************************************************/
/*************************** TIMER 1 MODES  ************************/
/*************************************************************************/

#define TMR1_NORMAL			0
#define TMR1_PWM_PC_8BIT	1				// PC Stands for Phase Correct
#define TMR1_PWM_PC_9BIT	2
#define TMR1_PWM_PC_10BIT	3
#define TMR1_CTC_OCR1A_TOP	4
#define TMR1_FAST_PWM_8BIT	5
#define TMR1_FAST_PWM_9BIT	6
#define TMR1_FAST_PWM_10BIT	7
#define TMR1_PC_FC_ICR1		8				// FC Stands for Frequency Correct
#define TMR1_PC_FC_OCR1A	9
#define TMR1_PC_ICR1		10
#define TMR1_PC_OCR1A   	11
#define TMR1_CTC_ICR1_TOP	12
#define TMR1_FAST_PWM_ICR1	14
#define TMR1_FAST_PWM_OCR1A	15



/***************************************************************************/
#define TIMER1_MODE		TMR1_CTC_OCR1A_TOP
/*************************************************************************/

/***************************************************************************/
/*************************** TIMER 0 PRESCALER  ************************/
/*************************************************************************/

#define    TIMER1_NO_CLOCK_SOURCE    	 0
#define    TIMER1_NO_PRESCALER 	         1
#define    TIMER1_Prescaler_8	     	 2
#define    TIMER1_Prescaler_64	         3
#define    TIMER1_Prescaler_256	         4
#define    TIMER1_Prescaler_1024	     5
#define    TIMER1_FALLING_ADGE	         6
#define    TIMER1_RISING_ADGE	    	 7

/**************************************************************/
#define  	 TIMER1_Prescaler	TIMER1_Prescaler_1024
/**************************************************************/

/***************************************************************************/
/*************************** TIMER1 OC1A MODE  *****************************/
/***************************************************************************/

#define  	OC1A_disconnected	    0
#define  	Toggle_OC1A          	1
#define  	Clear_OC1A		        2  //NON Inverted PWM "FAST PWM"
#define  	Set_OC1A		        3  //Inverted PWM "FAST PWM"


/***************************************************************************/
#define TIMER1_OC1A_MODE		OC1A_disconnected
/***************************************************************************/

/***************************************************************************/
/*************************** TIMER1 OC1B MODE  *****************************/
/***************************************************************************/

#define  	OC1B_disconnected	    0
#define  	Toggle_OC1B          	1
#define  	Clear_OC1B		        2
#define  	Set_OC1B	            3


/***************************************************************************/
#define TIMER1_OC1B_MODE		OC1B_disconnected
/***************************************************************************/


#endif /* MCAL_TMR1_TMR1_CONFIG_H_ */
