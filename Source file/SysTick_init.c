#include <stdint.h>
#include "../Service/TM4C123.h"
#include "../Headers/SysTick_init.h"


void systick_init(uint32_t clock){                       // clock is the clock of tiva used
    NVIC_ST_CTRL_R = 0;                             //disable Timer
    NVIC_ST_RELOAD_R = (clock -1);                //to make 1 secound as our Tiva has clk = clock
    NVIC_ST_CURRENT_R = 0;                          //to clear counter value and underflow flag of counter
    NVIC_ST_CTRL_R = 5;                              //to put at source clk 1 to get PROCESOR CLK  and put 1 on enable 
    while ((NVIC_ST_CTRL_R & 0X10000) == 0){}          //1 sec to let underflow flag be 1 

}
void delay( uint32_t clock,int f)                                     // if we want to delay it more than 1 sec
{
    int i;
    for ( i = 0; i < f; i++)
    {
        systick_init(clock);
			
    }
}
