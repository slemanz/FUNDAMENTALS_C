#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

void pa7_button_init(void)
{
    GPIO_Handle_t Button;
    Button.pGPIOx = GPIOA;
    Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
    Button.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

    GPIO_Init(&Button);
}

bool btn_state;


int main(void)
{
    system_init();
    pa7_button_init();
    printf("\n");



    while (1)
    {
        btn_state = (bool)GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_7);
    }
}