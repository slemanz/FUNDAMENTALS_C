#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <system.h>

struct ARRAY
{
    int32_t data[50];
    int32_t capacity;   /* Capacity of array capped at 50 */
    int32_t length;     /* Lenght of array user wants to initialize */
};

typedef struct ARRAY arrayType;
void array_append(arrayType *arr, int32_t elem);
void array_insert(arrayType *arr, uint32_t idx, int32_t elem);
int32_t array_delete(arrayType *arr, uint32_t idx);
void array_reverse(arrayType *arr);
int8_t array_isAscending(arrayType *arr);
int8_t array_isDescending(arrayType *arr);

int main(void)
{
    system_init();
    printf("\n");

    arrayType array1 ={{10, 20, 30, 40, 50}, 50, 5};

    if(array_isAscending(&array1))
    {
        printf("Is ascending\n\r");
    }

    array_reverse(&array1);

    if(array_isDescending(&array1))
    {
        printf("Is descending\n\r");
    }

    
    printf("\n\r\n\r");

    while (1);
}

void array_append(arrayType *arr, int32_t elem)
{
    if(arr->length < arr-> capacity)
    {
        arr->data[arr->length++] = elem;
    }
}

void array_insert(arrayType *arr, uint32_t idx, int32_t elem)
{
    if(idx <= arr->length)
    {
        for(int i = arr->length; i > idx; i--)
        {
            arr->data[i] = arr->data[i-1];
        }
        arr->data[idx] = elem;
        arr->length++;
    }
}

int32_t array_delete(arrayType *arr, uint32_t idx)
{
    int32_t elem;
    if(idx < arr->length)
    {
        elem = arr->data[idx];

        for(int i = idx; i < arr->length - 1; i++)
        {
            arr->data[i] = arr->data[i+1];
        }
        arr->length--;
        return elem;
    }
    return 0;
}

void array_reverse(arrayType *arr)
{
    int i, j;
    int32_t *temp;
    temp = (int32_t *)malloc(arr->length*sizeof(int32_t));

    for(i = arr->length - 1, j=0; i>=0; i--, j++)
    {
        temp[j] = arr->data[i];
    }

    for(i = 0; i < arr->length; i++)
    {
        arr->data[i] = temp[i];
    }
    free(temp);
}

int8_t array_isAscending(arrayType *arr)
{
    for(int i=0; i < arr->length-1; i++)
    {
        if(arr->data[i] > arr->data[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int8_t array_isDescending(arrayType *arr)
{
    for(int i=0; i < arr->length-1; i++)
    {
        if(arr->data[i] < arr->data[i+1])
        {
            return 0;
        }
    }
    return 1;
}