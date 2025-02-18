#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

struct dll_node
{
    int data;
    struct dll_node *prev;
    struct dll_node *next;
};

typedef struct dll_node dll_nodeType;

void d_linkedlist_insert_at_start(dll_nodeType **head, int data);
void d_linkedlist_insert_at_end(dll_nodeType **head, int data);


int main(void)
{
    system_init();
    printf("\n");

    while (1)
    {
    }
}

void d_linkedlist_insert_at_start(dll_nodeType **head, int data)
{
    dll_nodeType *new_node = (dll_nodeType*)malloc(sizeof(dll_nodeType));

    if(!new_node)
    {
        printf("Memory Error\n\r");
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head == new_node;
        return;
    }

    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void d_linkedlist_insert_at_end(dll_nodeType **head, int data)
{
    dll_nodeType *current = *head;
    dll_nodeType *new_node = (dll_nodeType*)malloc(sizeof(dll_nodeType));

    if(!new_node)
    {
        printf("Memory Error!\n\r");
        return;
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    
    if(current == NULL)
    {
        *head = new_node;
        return;
    }

    while(current->next != NULL)
    {
        current = current->next;
    }

    new_node->prev = current;
    current->next = new_node;
}