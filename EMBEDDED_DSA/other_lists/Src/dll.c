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
void d_linkedlist_insert_at_position(dll_nodeType **head, int data, int position);
int d_linkedlist_length(dll_nodeType *head);
void d_linkedlist_print_list(dll_nodeType *head);
void d_linkedlist_delete_last_node(dll_nodeType **head);
void d_linkedlist_delete_front_node(dll_nodeType **head);
void d_linkedlist_delete_position_node(dll_nodeType **head, int position);


int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    dll_nodeType *head = NULL;

    d_linkedlist_insert_at_start(&head, 21);
    d_linkedlist_insert_at_start(&head, 14);
    d_linkedlist_insert_at_start(&head, 7);
    d_linkedlist_insert_at_end(&head, 19);
    d_linkedlist_insert_at_position(&head, 99, 1);
    printf("List len: %d\n", d_linkedlist_length(head));
    d_linkedlist_print_list(head);



    d_linkedlist_delete_front_node(&head);
    d_linkedlist_delete_last_node(&head);
    d_linkedlist_delete_position_node(&head, 2);

    printf("\nList len: %d\n", d_linkedlist_length(head));
    d_linkedlist_print_list(head);


    while (1)
    {
    }
}

int d_linkedlist_length(dll_nodeType *head)
{
    dll_nodeType *current = head;
    int count = 0;
    if(head == NULL)
    {
        return 0;
    }

    while(current != NULL)
    {
        current = current->next;
        count++;
    }

    return count;
}

void d_linkedlist_print_list(dll_nodeType *head)
{
    dll_nodeType *current = head;
    if(head == NULL)
    {
        printf("Null list\n");
        return;
    }

    while(current != NULL)
    {
        printf("%d --> ", current->data);
        current = current->next;
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
        *head = new_node;
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

void d_linkedlist_insert_at_position(dll_nodeType **head, int data, int position)
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

    if(position == 1)
    {
        new_node->next = *head;
        new_node->prev = NULL;
        if(*head)
        {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    int k = 1;
    while(k < (position - 1) && (current->next != NULL))
    {
        current = current->next;
        k++;
    }

    if(k < position-1)
    {
        printf("invalid position passed to function\n\r");
        return;
    }

    new_node->next = current->next;
    new_node->prev = current;
    
    if(current->next)
    {
        current->next->prev = new_node;
    }
    current->next = new_node;
    return;
}

void d_linkedlist_delete_last_node(dll_nodeType **head)
{
    dll_nodeType *temp = *head;
    dll_nodeType *current = *head;

    if(*head == NULL)
    {
        printf("The list is empty!!!\n\r");
    }

    while(current->next != NULL)
    {
        current = current->next;
    }

    temp = current->prev;
    temp->next = current->next;
    free(current);

    return;
}

void d_linkedlist_delete_front_node(dll_nodeType **head)
{
    dll_nodeType *temp = *head;

    if(*head == NULL)
    {
        printf("The list is empty!!!\n\r");
    }

    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    return;
}

void d_linkedlist_delete_position_node(dll_nodeType **head, int position)
{
    dll_nodeType *current;
    dll_nodeType *temp = *head;

    int k = 1;

    if(*head == NULL)
    {
        printf("The list is empty!!!\n\r");
        return;
    }

    if(position == 1)
    {
        *head = (*head)->next;

        if(*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    while(k < position && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }

    if(k < position - 1)
    {
        printf("Position does not exist!\n");
        return;
    }

    current = temp->prev;
    current->next = temp->next;

    if(temp->next)
    {
        temp->next->prev = current;
    }

    free(temp);
    return;
}