#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <system.h>

struct coord1{
    int8_t x;
    int8_t y;
};

union coord2{
    int8_t x;
    int8_t y;
};

typedef struct coord1 coord1Type;
typedef union coord2 coord2Type;


int main(void)
{
    system_init();
    printf("\n");

    coord1Type location1 = {-3, 4};
    coord2Type location2 = {2};

    printf("location1 (%d, %d)\r\n", location1.x, location1.y);
    printf("location2 (%d, %d)\r\n", location2.x, location2.y);


    while (1);
}