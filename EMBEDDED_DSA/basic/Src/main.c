#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

int main(void)
 {
    system_init();
    systick_init(1); // 1hz

    while (1)
    {   
        
    }
}

void SysTick_Handler(void)
{
}