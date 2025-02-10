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

    /* Type 2 initialization */
    shapeType button2;
    button2.type = 2;
    button2.x_coord = -10;
    button2.y_coord = -30;

    printf("The button2 type is %d\r\n", button2.type);
    printf("The button2 x_coordinate is: %ld\r\n", button2.x_coord);
    printf("The button2 y_coordinate is: %ld\r\n", button2.y_coord);

    /* Type 3 initialization */
    shapeType panel;
    shapeType *pnl;
    pnl = &panel;

    pnl->type = 3;
    pnl->x_coord = 22;
    pnl->y_coord = 22;

    printf("The panel type is %d\r\n", panel.type);
    printf("The panel x_coordinate is: %ld\r\n", panel.x_coord);
    printf("The panel y_coordinate is: %ld\r\n\n", panel.y_coord);

    /* Dynamic allocate in heap */

    shapeType *sq;
    sq = (shapeType *)malloc(sizeof(shapeType));
    sq->type = 4;
    sq->x_coord = 4;
    sq->y_coord = 4;

    printf("The sq malloc type is %d\r\n", sq->type);
    printf("The sq malloc x_coordinate is: %ld\r\n", sq->x_coord);
    printf("The sq malloc y_coordinate is: %ld\r\n\n", sq->y_coord);


    while (1);
}