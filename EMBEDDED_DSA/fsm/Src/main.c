#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

#define TRAFFIC_LIGHTS_PORT         GPIOA
#define CAR_SENSOR_PORT             GPIOC

#define EAST_LED_RED                (1U << 9)
#define EAST_LED_YELLOW             (1U << 8)
#define EAST_LED_GREEN              (1U << 7)

#define NORTH_LED_RED               (1U << 6)
#define NORTH_LED_YELLOW            (1U << 5)
#define NORTH_LED_GREEN             (1U << 4)

#define EAST_LED_RED_MODE_BIT       (1U < 18)
#define EAST_LED_YELLOW_MODE_BIT    (1U < 16)
#define EAST_LED_GREEN_MODE_BIT     (1U < 14)

#define NORTH_LED_RED_MODE_BIT      (1U < 18)
#define NORTH_LED_YELLOW_MODE_BIT   (1U < 16)
#define NORTH_LED_GREEN_MODE_BIT    (1U < 14)

//go north, PA9-4 = 100001 makes it green on North and red on East
//wait north, PA9-4 = 100010 makes it yellow on North and red on East
//go east, PA9-4 = 001100 makes it red on north and green on east
//wait east PA9-4 = 010100 makes it red on North and yellow on East

struct State
{
    uint32_t output;
    uint32_t time;
    uint8_t next_state[4];
};

typedef const struct State stateType;

#define go_north                    0
#define wait_north                  1
#define go_east                     2
#define wait_east                   3

stateType STATE_MACHINE[4] = {
    // using 3 sec and 0.5 for demo
    {0x210, 3000, {go_north, wait_north, go_north, wait_north}},
    {0x220, 500,  {go_east, go_east, go_east, go_east}},
    {0x210, 3000, {go_east, go_east, wait_east, wait_east}},
    {0x210, 500,  {go_north, go_north, go_north, go_north}}
};

void TrafficSystemInit();

int main(void)
{
    system_init();
    printf("\n");

    TrafficSystemInit();

    while (1);
}

void TrafficSystemInit(void)
{
    RCC->AHB1ENR |= (0x01 | 0x04); // enable clock access to PORTA and PORT C
    TRAFFIC_LIGHTS_PORT->MODER |= NORTH_LED_GREEN_MODE_BIT  | NORTH_LED_RED_MODE_BIT |
                                  NORTH_LED_YELLOW_MODE_BIT | EAST_LED_RED_MODE_BIT  |
                                  EAST_LED_YELLOW_MODE_BIT  | EAST_LED_GREEN_MODE_BIT;
}