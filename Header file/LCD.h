#ifndef LED_H
#define LED_H

#define RS 0x20 /* PORTB BIT5 mask */
#define RW 0x40 /* PORTB BIT6 mask */
#define EN 0x80 /* PORTB BIT7 mask */
#define HIGH 1
#define LOW 0

#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80 
#define SecondRow         0xC0 
#define Wakeup						0x30

void LCD_init(void);
void lcd_write4bits(unsigned char data, unsigned char control);
void LCD_CMD(unsigned char command);
void LCD_data(unsigned char data);
void LCD_String(char* string);
void LCD_message_Dis(double dis);
void LCD_message(char* data);


void delay_milli(int i);

void delay_micro(int i);


#endif // !LED_H
