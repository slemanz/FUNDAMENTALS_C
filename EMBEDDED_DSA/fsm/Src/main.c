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

int main(void)
{
    system_init();
    printf("\n");

    while (1);
}