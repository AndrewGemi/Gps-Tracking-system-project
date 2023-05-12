#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Service/TM4C123.h"
#include "../Headers/SysTick_init.h"
#include "../Headers/LCD.h"


// Rs --> PB0  ,  Rw --> PB1 , E --> PB2
// data --> PB4-7

void LCD_init(void) {
	SET(SYSCTL_RCGCGPIO_R, 1);						 // activate clock for port B
	while ((SYSCTL_PRGPIO_R & (0x01 << 1)) == 0) {}  // allow time for clock to start

	GPIO_PORTB_DIR_R |= 0XFF;  //PB4-->7 OUTPUT
	GPIO_PORTB_DEN_R |= 0xFF;  //PB4-->7 DIGITAL

	GPIO_PORTB_AFSEL_R &= ~0xff;    //disable alternative functions for portB
	GPIO_PORTB_AMSEL_R &= ~0Xff;    //disable analogue function
	GPIO_PORTB_PCTL_R &= ~0XFF;     //regular digital pins

	LCD_CMD(Wakeup);
	delay_milli(100);
	LCD_CMD(Function_set_4bit);
		delay_milli(100);
	LCD_CMD(moveCursorRight);
		delay_milli(100);
	LCD_CMD(clear_display);
		delay_milli(100);
	LCD_CMD(cursorBlink);
		delay_milli(100);
	

}
void delay_milli(int i)
{
	systick_init(i*16000);
}

void delay_micro(int i)
{
	systick_init(i*16);
}

void LCD_message_Dis(double dis) {
	 char buffer[50];
	LCD_CMD(clear_display);
	delay_milli(15);
	LCD_CMD(FirstRow);
	delay_milli(15);
	LCD_CMD(cursorOn);
	delay_milli(15);
	LCD_String("Total Distance");
	delay_milli(15);
	LCD_CMD(SecondRow);
	delay_milli(15);
	LCD_CMD(cursorOn);
	delay_milli(15);
	snprintf(buffer,50, "%.2f", dis);
	//sprintf(buffer, "%.2f", dis);
	LCD_String(buffer);
	LCD_String(" m");

}
void LCD_message(char* data) {
	LCD_CMD(clear_display);
	delay_milli(100);
	LCD_CMD(cursorOn);
	delay_milli(100);
	LCD_CMD(FirstRow);
	delay_milli(100);
	LCD_String(data);
	delay_milli(100);
}
void lcd_write4bits(unsigned char data, unsigned char control)
{
	data &= 0xf0;
	control &= 0x0f;
	GPIO_PORTB_DATA_R = data | control;
	GPIO_PORTB_DATA_R = data | control | 4;
	delay_micro(120);
	GPIO_PORTB_DATA_R = data;
}
void LCD_CMD(unsigned char command)
{
	lcd_write4bits(command & 0xf0, 0);
	lcd_write4bits(command << 4, 0);
	if (command < 4)

		delay_milli(2);
	else
		delay_micro(40);
}
void LCD_data(unsigned char data) // print 1 char
{
	lcd_write4bits(data & 0xf0, 1);
	lcd_write4bits(data << 4, 1);
	delay_micro(40);
}
void LCD_String(char* string)
{
	int i;
	for (i = 0; string[i] != 0; i++)  /* Send each char of string till the NULL */
	{
		if (i == 16)
		{
			LCD_CMD(SecondRow);
		}
		LCD_data(string[i]);  /* Call LCD data write */

	}

}
