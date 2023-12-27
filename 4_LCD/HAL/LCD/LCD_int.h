/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "../../LIB/TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_config.h"




#define LCD_CLR              0X01
#define LCD_HOME             0X02
#define LCD_ENTRY_MODE       0X06
#define LCD_DISOFF           0X08
#define LCD_DISPON_CURSON    0X0C
#define LCD_FUNCSET          0X30
#define LCD_FUNCSET_8BIT     0X38
#define LCD_SETCURS_DDRAM    0X80
#define LCD_DISPON_CURSBLINK 0X0F
#define LCD_CGRAM_ADDRESS    0x40


void LCD_voidInit();
void LCD_ClrLCD();
void LCD_voidSendCMD(u8 u8CMD);
void LCD_voidWriteChar(u8 u8CHAR);
void LCD_voidGoTo(u8 X, u8 Y);
void LCD_voidWriteString(u8 *u8ptrString);
void LCD_voidWriteNum(s32 s32NUM);
void LCD_VoidSaveCustomChar(u8 u8CGRAMIndex, u8 u8CustomArr[]);
void LCD_VoidWriteCustomChar(u8 u8CGRAMIndex);


#endif /* HAL_LCD_LCD_INT_H_ */
