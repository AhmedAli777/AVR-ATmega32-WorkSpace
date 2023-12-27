/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef HAL_SERVO_SERVO_CONFIG_H_
#define HAL_SERVO_SERVO_CONFIG_H_


#define F_CPU                1000000UL
#define SERVOFREQ            50
#define TIMER_PRESCALLER     1   //MAKE SURE TO CONFIG TIMER TO THIS PRESCALLER
#define TOP                  (F_CPU/(SERVOFREQ * TIMER_PRESCALLER) -1)

#define MAXANGLE             180
#define MINANGLE             0
#define TIME_0DEG            (f64)0.001  //SEC
#define TIME_180DEG          (f64)0.002  //SEC

#define SERVO1_PIN           DIO_PORTD,DIO_PIN4
#define SERVO2_PIN           DIO_PORTD,DIO_PIN5

#endif /* HAL_SERVO_SERVO_CONFIG_H_ */
