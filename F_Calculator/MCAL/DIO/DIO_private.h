/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_PORTA_REG     *((volatile  u8*) 0X3B)
#define DIO_DDRA_REG      *((volatile  u8*) 0X3A)
#define DIO_PINA_REG      *((volatile  u8*) 0X39)


#define DIO_PORTB_REG     *((volatile  u8*) 0X38)
#define DIO_DDRB_REG      *((volatile  u8*) 0X37)
#define DIO_PINB_REG      *((volatile  u8*) 0X36)

#define DIO_PORTC_REG     *((volatile  u8*) 0X35)
#define DIO_DDRC_REG      *((volatile  u8*) 0X34)
#define DIO_PINC_REG      *((volatile  u8*) 0X33)

#define DIO_PORTD_REG     *((volatile  u8*) 0X32)
#define DIO_DDRD_REG      *((volatile  u8*) 0X31)
#define DIO_PIND_REG      *((volatile  u8*) 0X30)



#endif /* DIO_PRIVATE_H_ */
