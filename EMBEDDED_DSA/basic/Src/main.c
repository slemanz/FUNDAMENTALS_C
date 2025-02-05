#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

uint32_t x, *pt, data[5];

int main(void)
 {
    system_init();
    systick_init(1); // 1hz

    data[0] = 0xBABEFACE;
    data[1] = 0xBABADADA;
    data[2] = 0xDEADBEAF;
    data[3] = 0xBEEFCAFE;

    // same
    x = data[0];
    x = *data;


    // same
    pt = data;
    pt = &data[0];


    // same
    x = data[3];
    x = *(data+3);

    // same
    pt = data;
    data[2] = 0x1234;
    pt[2]   = 0x1234;
    *(pt+2) = 0x1234;

    while (1)
    {   
        
    }
}

void SysTick_Handler(void)
{
}