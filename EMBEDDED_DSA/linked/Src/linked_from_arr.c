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
nodeType* linkedlist_create(int32_t *arr, uint32_t arr_len);


int main(void)
{
    system_init();
    printf("\n");

    int32_t task_pri[] = {0, 2, 5, 4, 1, 4, 6};
    nodeType *pri_list = linkedlist_create(task_pri, 7);


    printf("Linked list content is:\n\r");
    while(pri_list != NULL)
    {
        printf("%d\n\r", pri_list->data);
        pri_list = pri_list->next;
    }


    while (1)
    {
        
    }
}

nodeType* linkedlist_create(int32_t *arr, uint32_t arr_len)
{
    nodeType *head, *last, *temp;
    head = (nodeType*)malloc(sizeof(nodeType));

    if(!head) return head; // null

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < arr_len; i++)
    {
        temp = (nodeType*)malloc(sizeof(nodeType));
        if(!temp) return temp;

        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return head;
}