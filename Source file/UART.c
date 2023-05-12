#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Service/TM4C123.h"
#include "../Headers/GPIO.h"
#include "../Headers/UART.h"
#include "../Headers/LED.h"
#include "../Headers/GPS.h"
#include "../Headers/SysTick_init.h"
#include "../Headers/Distance.h"
#include "../Headers/LCD.h"

void UART0_Init(int baudRate){
 unsigned long uartIBRD, uartFBRD;
    double CLDIV = (16000000.0 / (16.0 * baudRate));

    uartIBRD = (int)(CLDIV);
    uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);
		SET(SYSCTL_RCGCUART_R,0);
		SET(SYSCTL_RCGCGPIO_R,0);	
		CLEAR(UART0_CTL_R,0);
		UART0_IBRD_R = uartIBRD;
    UART0_FBRD_R = uartFBRD;
    UART0_LCRH_R |= 0x70;
    UART0_CTL_R |= 0x301;
    GPIO_PORTA_DEN_R |= 0x03;
    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_AMSEL_R &= ~0x03;
    GPIO_PORTA_PCTL_R |= 0x00000011;


}

unsigned char ReadUart0(void){

	while ((UART0_FR_R & RXEMPTY) != 0) {}
    return ((char)(UART0_DR_R & 0xFF));
	
}
void WriteUart0(unsigned char c){
	while((UART0_FR_R & TXFULL) != 0){}
		UART0_DR_R = c;

}


void UART5_Init(unsigned long baudRate) {
    unsigned long uartIBRD, uartFBRD;
    double CLDIV = (16000000.0 / (16.0 * baudRate));

    uartIBRD = (int)(CLDIV);
    uartFBRD = (int)((CLDIV - uartIBRD) * 64 + 0.5);

    SET(SYSCTL_RCGCUART_R, 5);
    SET(SYSCTL_RCGCGPIO_R, 4);
    while ((SYSCTL_PRGPIO_R & (0x01 << 4)) == 0) {}
    CLEAR(UART5_CTL_R, 0);
    UART5_IBRD_R = uartIBRD;
    UART5_FBRD_R = uartFBRD;
    UART5_LCRH_R |= 0x70;
    UART5_CTL_R |= 0x301;
    GPIO_PORTE_DEN_R |= 0x30;
    GPIO_PORTE_AFSEL_R |= 0x30;
    GPIO_PORTE_AMSEL_R &= ~0x30;
    GPIO_PORTE_PCTL_R |= 0x00110000;

}

void UART5_WriteChar(unsigned char ch) {						//Write Char
    while ((UART5_FR_R & TXFULL) != 0) {}
    UART5_DR_R = ch;
}

unsigned char UART5_ReadChar(void) {								//Read Char
    while ((UART5_FR_R & RXEMPTY) != 0) {}
    return (UART5_DR_R & 0xFF);
}

void UART5_ReadString(char *str, char stopCh){		//Read String
	char c = UART5_ReadChar();
	while(c && c != stopCh){
		*str = c;
		str++;
		c = UART5_ReadChar();
	}
	*str = 0x00;
}
