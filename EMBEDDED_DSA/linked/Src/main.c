#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <system.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node nodeType;


int main(void)
{
    system_init();
    printf("\n");

    int32_t val = 9;
    int32_t val2 = 29;

    nodeType *head, *last, *temp;

    head = (nodeType*)malloc(sizeof(nodeType));

    if(!head)
    {
        printf("Head low memory\n");
        while(1);
    }

    /* Store data */
    head->data = val;
    head->next = NULL;
    last = head;

    /* Add a new node at begining of the list */
    temp = (nodeType*)malloc(sizeof(nodeType));
    if(!temp)
    {
        printf("temp low memory\n");
        while(1);
    }

    temp->data = val2;
    temp->next = head;
    head = temp;


    printf("Linked list content is:\n\r");
    while(temp != NULL)
    {
        printf("%d\n\r", temp->data);
        temp = temp->next;
    }


    while (1)
    {
        
    }
}