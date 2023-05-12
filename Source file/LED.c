#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Service/TM4C123.h"
#include "../Headers/LED.h"
void led(int color) {
    GPIO_PORTF_DATA_R &= (~0x0E);
    GPIO_PORTF_DATA_R |= color;
}
