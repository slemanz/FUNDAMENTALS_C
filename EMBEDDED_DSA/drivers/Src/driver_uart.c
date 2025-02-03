#include "driver_uart.h"

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}


void uart2_init(void)
{
    uart2_init_pins();
    UART2_PCLK_EN();

    // no flow control (default reset)
    uint32_t temp = ((1 << 3) | (1 << 2)); // tx and rx enable
    UART2->CR1 = temp; 
    UART2->BRR = compute_uart_div(16000000, 115200); // baurate

    UART2->CR1 |= (1 << 13);// enable uart periph
}


void uart2_init_pins(void)
{
    GPIO_Handle_t UartPin;

    UartPin.pGPIOx = GPIOA;
    UartPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    UartPin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    UartPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    UartPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    UartPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    UartPin.GPIO_PinConfig.GPIO_PinAltFunMode = PA2_ALTFN_UART2_TX;

    GPIO_Init(&UartPin);

    UartPin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
    UartPin.GPIO_PinConfig.GPIO_PinAltFunMode = PA3_ALTFN_UART2_RX;
    GPIO_Init(&UartPin);
}


int uart2_write(int ch)
{
	while(!(UART2->SR & UART_FLAG_TXE));
    UART2->DR = ch;

    return ch;
}

int uart2_read(void)
{
	while(!(UART2->SR & UART_FLAG_RXNE));
    return UART2->DR;

}