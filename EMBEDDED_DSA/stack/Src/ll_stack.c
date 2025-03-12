#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"


typedef struct Stack stackType;

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

typedef struct Node nodeType;

void ll_stack_push(int data);
int ll_stack_pop(void);
void ll_stack_print(void);

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    ll_stack_push(7);
    ll_stack_push(14);
    ll_stack_push(21);
    ll_stack_pop();
    ll_stack_push(28);
    ll_stack_print();

    while (1)
    {
    }
}

void ll_stack_push(int data)
{
    nodeType *newNode;
    newNode = (nodeType *)malloc(sizeof(nodeType));

    if(!newNode)
    {
        printf("Stack error\n\r");
    }else
    {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

int ll_stack_pop(void)
{
    nodeType *temp;
    int popped_data = -999;

    if(top == NULL)
    {
        printf("Stack is empty\n\r");
    }else
    {
        temp = top;
        top = top->next;
        popped_data = temp->data;

        free(temp);
    }

    return popped_data;
}

void ll_stack_print(void)
{
    nodeType *temp;
    temp = top;

    while(temp != NULL)
    {
        printf("The stack element is %d\n\r", temp->data);
        temp = temp->next;
    }
    printf("\r\n");
}