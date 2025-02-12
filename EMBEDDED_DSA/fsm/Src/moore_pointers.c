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

#define NORTH_SENSOR                (1U < 1)
#define EAST_SENSOR                 (1U < 0)

//go north, PA9-4 = 100001 makes it green on North and red on East
//wait north, PA9-4 = 100010 makes it yellow on North and red on East
//go east, PA9-4 = 001100 makes it red on north and green on east
//wait east PA9-4 = 010100 makes it red on North and yellow on East

struct State
{
    uint32_t output;
    uint32_t time;
    const struct State *next_state[4];
};

typedef const struct State stateType;

#define go_north                    &STATE_MACHINE[0]
#define wait_north                  &STATE_MACHINE[1]
#define go_east                     &STATE_MACHINE[2]
#define wait_east                   &STATE_MACHINE[3]

stateType STATE_MACHINE[4] = {
    // using 3 sec and 0.5 for demo
    {0x210, 3000, {go_north, wait_north, go_north, wait_north}},
    {0x220, 500,  {go_east, go_east, go_east, go_east}},
    {0x210, 3000, {go_east, go_east, wait_east, wait_east}},
    {0x210, 500,  {go_north, go_north, go_north, go_north}}
};

void TrafficSystemInit(void);
void delayMs(int n);

stateType *statePt;
uint8_t system_input;


int main(void)
{
    system_init();
    printf("\n");

    TrafficSystemInit();
    statePt = go_north;

    while (1)
    {
        TRAFFIC_LIGHTS_PORT->ODR = statePt->output;
        delayMs(statePt->time);
        system_input = CAR_SENSOR_PORT->IDR & (NORTH_SENSOR | EAST_SENSOR);
        statePt = statePt->next_state[system_input];
    }
}

void TrafficSystemInit(void)
{
    RCC->AHB1ENR |= (0x01 | 0x04); // enable clock access to PORTA and PORT C
    TRAFFIC_LIGHTS_PORT->MODER |= NORTH_LED_GREEN_MODE_BIT  | NORTH_LED_RED_MODE_BIT |
                                  NORTH_LED_YELLOW_MODE_BIT | EAST_LED_RED_MODE_BIT  |
                                  EAST_LED_YELLOW_MODE_BIT  | EAST_LED_GREEN_MODE_BIT;
}

void delayMs(int n)
{
    SYSTICK->LOAD = 16000; /* Reload with number of clocks per milliseconds */
    SYSTICK->VAL  = 0;     /* Clear current value register */
    SYSTICK->CTRL = 0x05; /* Enable the timer */

    for(int i = 0; i < n; i++)
    {
        while((SYSTICK->CTRL & 0x10000) == 0){} // wait until count flag is set
    }
    SYSTICK->CTRL = 0;

}