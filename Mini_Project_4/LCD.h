/*
 * LCD.h
 *
 *  Created on: Oct 1, 2021
 *      Author: DELL
 */

#ifndef LCD_H_
#define LCD_H_
#include"std_types.h"
/* LCD Commands */
#define LCD_RS_PIN PIN0_ID
#define LCD_RW_PIN PIN1_ID
#define LCD_EN_PIN PIN2_ID
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80
void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_displayString(const uint8* str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);
void LCD_clearScreen(void);
#endif /* LCD_H_ */
