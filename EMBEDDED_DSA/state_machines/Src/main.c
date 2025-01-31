#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

uint64_t ticks = 0;

int main(void)
 {
    system_init();

    uint64_t start_time = system_get_ticks();

    while (1)
    {   
        if((system_get_ticks() - start_time) >= 3000)
        {
            printf("DSA Test\n\r");
            GPIO_ToggleOutputPin(LED_PORT, LED_PIN);
            start_time = system_get_ticks();
        }
    }
}