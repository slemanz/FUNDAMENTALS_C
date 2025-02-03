#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

extern int __io_putchar(int ch)
{
    return uart2_write(ch);
}

extern int __io_getchar(void)
{
    return uart2_read();
}


int n;
char str[80];

int main(void)
 {
    system_init();

    while (1)
    {   
        printf("Please enter a number:\r\n");
        scanf("%d", &n);
        printf("the number: %d\r\n", n);
    }
}