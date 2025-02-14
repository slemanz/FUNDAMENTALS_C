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
int32_t linkedlist_delete(nodeType *l_list, uint32_t idx);
int32_t linkedlist_min(nodeType *l_list);
int32_t linkedlist_max(nodeType *l_list);
int32_t linkedlist_reverse(nodeType *l_list);

nodeType *head;


int main(void)
{
    system_init();
    printf("\n");

    int32_t task_pri[] = {0, 2, 5, -4, 1, 4, 6};
    if(linkedlist_create(task_pri, 7))
    {
        printf("Created list!\n");
    }
    linkedlist_insert(head, 3, 77);
    linkedlist_insert(head, 1, 3);
    linkedlist_delete(head, 0);

    uint32_t len = linkedlist_length(head);
    linkedlist_reverse(head);

    printf("Linked list len is: %ld\n\r", len);
    printf("Linked list max is: %ld\n\r", linkedlist_max(head));
    printf("Linked list min is: %ld\n\r", linkedlist_min(head));
    printf("Linked list content is:\n\r");
    while(head != NULL)
    {
        printf("%d\n\r", head->data);
        head = head->next;
    }

    free(head);
    printf("End of the program.\n");


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

int32_t linkedlist_delete(nodeType *l_list, uint32_t idx)
{
    nodeType *temp;
    int32_t del;

    if(idx >= linkedlist_length(l_list)) return 0;

    if(idx == 0)
    {
        temp = head;
        del = head->data;
        head = head->next;
        free(temp);
        return del;
    }else
    {
        for(int i = 0; i < idx; i++)
        {
            temp = l_list;
            l_list = l_list->next;
        }
        temp->next = l_list->next;
        del = l_list->data;
        free(l_list);

        return del;
    }

}

int32_t linkedlist_min(nodeType *l_list)
{
    int32_t min = 0;

    if(l_list != NULL)
    {
        min = l_list->data;
        l_list = l_list->next;
    }

    while(l_list != NULL)
    {
        if(l_list->data < min) min = l_list->data;
        l_list = l_list->next;
    }
    return min;
}

int32_t linkedlist_max(nodeType *l_list)
{
    int32_t max = 0;

    if(l_list != NULL)
    {
        max = l_list->data;
        l_list = l_list->next;
    }

    while(l_list != NULL)
    {
        if(l_list->data > max) max = l_list->data;
        l_list = l_list->next;
    }
    return max;
}

int32_t linkedlist_reverse(nodeType *l_list)
{
    nodeType *temp;
    int32_t *arr;
    temp = l_list;

    int i = 0;
    arr = (int32_t *)malloc(sizeof(int32_t)*linkedlist_length(l_list));
    if(arr == NULL)
    {
        return 0;
    }

    while(temp != NULL)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }

    temp = l_list;
    i--;

    while(temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
        i--;
    }

}