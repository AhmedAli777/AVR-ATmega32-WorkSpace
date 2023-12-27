/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_



#define LSB_FIRST  1 // 1 FOR LSB FIRST  , 0 FOR MSB
#define POLARITY   0 // 0 OR 1
#define PHASE      0 // 0 OR 1


#define div_2    0x4 //0100
#define div_4    0x0 //0000

#define div_8    0x5 //0101
#define div_16   0x1 //0001

#define div_32   0x6 //0110
#define div_64   0x2 //0010

#define div_128  0x3 //0011

#define FREQ    div_8



#define SS1 DIO_PORTA,DIO_PIN0
#define SS2 DIO_PORTA,DIO_PIN1

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
