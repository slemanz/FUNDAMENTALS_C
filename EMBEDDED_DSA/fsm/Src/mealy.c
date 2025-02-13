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

struct State
{
    uint32_t output[2];
    uint32_t time;
    const struct State *next_state[2];
};

typedef const struct State stateType;

#define stop    &STATE_MACHINE[0]
#define go      &STATE_MACHINE[1]

stateType STATE_MACHINE[2] = {
    {{2,0} , 100, {stop, go}},
    {{0,1} , 100, {stop, go}}
};

void delayMs(int n);
void EngineSystemInit(void);

stateType *statePt;
uint32_t system_input;

int main(void)
{
    system_init();
    printf("\n");

    EngineSystemInit();
    statePt = stop;


    while (1)
    {
        system_input = CONTROL_PORT->IDR & ENG_CONTROL;
        BRAKE_AND_GAS_PORT->ODR = statePt->output[system_input];
        delayMs(statePt->time);
        statePt = statePt->next_state[system_input];
    }
}

void delayMs(int n)
{
    SYSTICK->LOAD = 16000; /* Reload with number of clocks per milliseconds */
    SYSTICK->VAL  = 0;     /* Clear current value register */
    SYSTICK->CTRL = 0x05; /* Enable the timer */

    for(int i = 0; i < n; i++)
    {
        while((SYSTICK->CTRL & 0x10000) == 0){} // wait until count flag is set
    }
    SYSTICK->CTRL = 0;

}

void EngineSystemInit(void)
{
    RCC->AHB1ENR |= 0x1 | 0x4;

    BRAKE_AND_GAS_PORT->ODR |= ENG_BRAKE_MODE_BIT | ENG_GAS_MODE_BIT;

}