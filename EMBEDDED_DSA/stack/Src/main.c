#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

struct Stack{
    int top;
    int capacity;
    int *array;
};

typedef struct Stack stackType;

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");


    while (1)
    {
    }
}

stackType* stack_create(int capacity)
{
    stackType *stack = (stackType*)malloc(sizeof(stackType));

    if(!stack)
    {
        printf("Not able to create stack!\n");
        return;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity*sizeof(int));

    if(!stack->array)
    {
        printf("Not able to create array of this size.\n\r");
        free(stack);
        return NULL;
    }

    return stack;
}

void stack_double_size(stackType *stack)
{
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity*sizeof(int));
}

int stack_isFull(stackType *stack)
{
    return (stack->top == stack->capacity-1);
}

int stack_isEmpty(stackType *stack)
{
    return (stack->top == -1);
}

void stack_push(stackType *stack)
{

}