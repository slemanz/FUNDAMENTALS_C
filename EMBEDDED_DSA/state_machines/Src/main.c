#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

struct __FILE {int handle;};
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f)
{
    int c;

    c = uart2_read();
    if(c == '\r')
    {
        uart2_write(c);
        c = '\n';
    }
    uart2_write(c);
    return c;
}

int fputc(int c, FILE *f)
{
    return uart2_write(c);
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