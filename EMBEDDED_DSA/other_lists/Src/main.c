#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

struct cll_node
{
    int data;
    struct cll_node *next;
};

typedef struct cll_node cll_nodeType;

void c_linkedlist_insert_at_start(cll_nodeType **head, int data);
void c_linkedlist_insert_at_end(cll_nodeType **head, int data);


int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");


    while (1)
    {
    }
}

void c_linkedlist_insert_at_start(cll_nodeType **head, int data)
{
    cll_nodeType *current = *head;
    cll_nodeType *newNode = (cll_nodeType *)malloc(sizeof(cll_nodeType));

    if(!newNode)
    {
        printf("Memory error!\n");
        return;
    }

    newNode->data = data;
    newNode->next = newNode;

    if(current == NULL)
    {
        *head = newNode;
        return;
    }

    while(current->next != *head)
    {
        current = current->next;
    }

    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}

void c_linkedlist_insert_at_end(cll_nodeType **head, int data)
{
    cll_nodeType *current = *head;
    cll_nodeType *newNode = (cll_nodeType *)malloc(sizeof(cll_nodeType));

    if(!newNode)
    {
        printf("Memory error!\n");
        return;
    }

    newNode->data = data;
    newNode->next = newNode;

    if(current == NULL)
    {
        *head = newNode;
        return;
    }

    while(current->next != *head)
    {
        current = current->next;
    }

    newNode->next = *head;
    current->next = newNode;
}