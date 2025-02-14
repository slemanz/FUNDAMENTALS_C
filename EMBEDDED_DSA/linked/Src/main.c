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
uint8_t linkedlist_create(int32_t *arr, uint32_t arr_len);
uint32_t linkedlist_length(nodeType *l_list);
uint8_t linkedlist_insert(nodeType *l_list, uint32_t idx, int32_t elem);

nodeType *head;


int main(void)
{
    system_init();
    printf("\n");

    int32_t task_pri[] = {0, 2, 5, 4, 1, 4, 6};
    linkedlist_create(task_pri, 7);
    //linkedlist_insert(head, 1, 3);

    nodeType *pri_list = head;
    //uint32_t len = linkedlist_length(pri_list);
    uint32_t len = 3;

    printf("Linked list len is: %ld\n\r", len);
    printf("Linked list content is:\n\r");
    while(head != NULL)
    {
        printf("%d\n\r", pri_list->data);
        pri_list = pri_list->next;
    }


    while (1)
    {
        
    }
}

uint8_t linkedlist_create(int32_t *arr, uint32_t arr_len)
{
    nodeType *last, *temp;
    head = (nodeType*)malloc(sizeof(nodeType));

    if(!head) return 0; // null

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < arr_len; i++)
    {
        temp = (nodeType*)malloc(sizeof(nodeType));
        if(!temp) return 0;

        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return 1;
}

uint32_t linkedlist_length(nodeType *l_list)
{
    uint32_t len = 0;

    while(l_list)
    {
        len++;
        l_list = l_list->next;
    }

    return len;
}

uint8_t linkedlist_insert(nodeType *l_list, uint32_t idx, int32_t elem)
{
    nodeType *temp;

    if(idx > linkedlist_length(l_list))
    {
        return 0;
    }

    temp = (nodeType*)malloc(sizeof(nodeType));
    temp->data = elem;

    /* Insertion at the begining */
    if(idx == 0)
    {
        temp->next = l_list;
        l_list = temp;
    }

    else
    {
        for(int i =0; i < idx-1; i++)
        {
            l_list = l_list->next;
        }
        temp->next = l_list->next;
        l_list->next = temp;
    }
    return 1;
}