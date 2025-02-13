#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

/*
    Control: PA0
    Gas: PC0
    Brake: PC1
 */


#define CONTROL_PORT            GPIOA
#define BRAKE_AND_GAS_PORT      GPIOC

#define ENG_CONTROL             (1U < 0)
#define ENG_BRAKE               (1U < 1)
#define ENG_GAS                 (1U < 0)

#define ENG_BRAKE_MODE_BIT      (1U << 2)
#define ENG_GAS_MODE_BIT        (1U << 1)


int main(void)
{
    system_init();
    printf("\n");


    while (1)
    {
        
    }
}