#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <system.h>

struct shape{
    uint8_t type;
    int32_t x_coord;
    int32_t y_coord;
};

typedef struct shape shapeType;

/*
    1   = rectangle
    2   = square
    3   = circle
    4   = triangle
 */

int main(void)
{
    system_init();
    printf("\n");

    /* Type 1 initialization */
    shapeType button = {1, 5, -2};

    printf("The button type is %d\r\n", button.type);
    printf("The button x_coordinate is: %ld\r\n", button.x_coord);
    printf("The button y_coordinate is: %ld\r\n", button.y_coord);

    while (1);
}