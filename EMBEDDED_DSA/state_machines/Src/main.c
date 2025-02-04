#include "stm32f401xx.h"
#include <stdio.h>
#include <system.h>

enum states{
    STATE_A = 0,
    STATE_B,
    STATE_C
};

typedef enum states State_Type;

void state_a_function(void);
void state_b_function(void);
void state_c_function(void);

static void (*state_table[])(void) = {
                                        state_a_function,
                                        state_b_function,
                                        state_c_function
};

static State_Type current_state;
static int Clock;

int main(void)
 {
    system_init();

    while (1)
    {   
    }
}

void state_machine_init(void)
{
    
}

void state_a_function(void)
{

}

void state_b_function(void)
{

}

void state_c_function(void)
{

}