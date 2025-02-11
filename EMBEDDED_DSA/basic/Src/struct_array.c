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

int main(void)
{
    system_init();
    printf("\n");

    shapeType shapes[5] = {
                                {0, -3, -5},
                                {3, 5, 6},
                                {1, -8, 10},
                                {2, 90, -8},
                                {1, 0, 0}
    };

    for(int i = 0; i < 5; i++)
    {
        printf("Shape %d (%d): (%ld, %ld)\n\r", i+1, shapes[i].type, shapes[i].x_coord, shapes[i].y_coord);
    }


    while (1);
}