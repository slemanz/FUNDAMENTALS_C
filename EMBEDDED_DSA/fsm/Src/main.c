#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

struct ARRAY
{
    int32_t data[50];
    int32_t capacity;   /* Capacity of array capped at 50 */
    int32_t length;     /* Lenght of array user wants to initialize */
};

typedef struct ARRAY arrayType;

int main(void)
{
    system_init();
    printf("\n");

    arrayType signal ={{10, 20, 30, 11, 12, 13, 14}, 50, 7};

    printf("The original array is: \n\r");
    for(int i = 0; i < signal.length; i++)
    {
        printf(" %ld ", signal.data[i]);
    }
    printf("\n\r\n\r");


    while (1);
}