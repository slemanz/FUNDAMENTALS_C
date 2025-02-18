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
int c_linkedlist_length(cll_nodeType *head);
void c_linkedlist_print_list(cll_nodeType *head);


int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    cll_nodeType *head = NULL;

    c_linkedlist_insert_at_start(&head, 7);
    c_linkedlist_insert_at_start(&head, 20);
    c_linkedlist_insert_at_start(&head, 28);
    c_linkedlist_insert_at_end(&head, 32);

    printf("The length of the list: %d\n", c_linkedlist_length(head));
    c_linkedlist_print_list(head);



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

int c_linkedlist_length(cll_nodeType *head)
{
    cll_nodeType *current = head;
    int count = 0;
    if(head == NULL)
    {
        return 0;
    }
    do{
        current = current->next;
        count++;
    }while(current != head);

    return count;
}

void c_linkedlist_print_list(cll_nodeType *head)
{
    cll_nodeType *current = head;
    if(head == NULL)
    {
        return;
    }

    do{
        printf("%d --> ", current->data);
        current = current->next;
    }while(current != head);
    printf("\n");
}