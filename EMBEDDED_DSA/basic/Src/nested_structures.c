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

struct screen{
    shapeType shapes[2];
    uint32_t height;
    uint32_t width;
};

typedef struct screen screenType;

int main(void)
{
    system_init();
    printf("\n");

    screenType homescreen;

    homescreen.shapes[0].type = 1;
    homescreen.shapes[0].x_coord = -10;
    homescreen.shapes[0].y_coord = 15;

    homescreen.shapes[1].type = 2;
    homescreen.shapes[1].x_coord = -30;
    homescreen.shapes[1].y_coord = 25;

    homescreen.width = 500;
    homescreen.height = 300;

    printf("The height of the screen is: %ld \r\n", homescreen.height);

    while (1);
}