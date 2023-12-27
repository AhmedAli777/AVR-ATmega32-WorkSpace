/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


//USE DIO_PORTA , DIO_PORTB, DIO_PORTC, DIO_PORTD
#define LCD_PORT DIO_PORTC

#define LCD_RS   DIO_PORTB, DIO_PIN0
#define LCD_RW   DIO_PORTB, DIO_PIN1
#define LCD_E    DIO_PORTB, DIO_PIN2
#endif /* HAL_LCD_LCD_CONFIG_H_ */
