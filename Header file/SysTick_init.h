#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>
// to make 1 sec we used wait for underflow flag to be 1 ... ex : clk of tivaC used is 16 MHZ so we put clock = 16000000

void systick_init(uint32_t clock);

// to make it delay n sec sec we put f = n
void delay( uint32_t clock,int f);

#endif // !SYSTICK_H



