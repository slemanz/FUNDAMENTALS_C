#include "stm32f401xx.h"
#include <stdio.h>
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

int main(void)
{
    system_init();
    printf("\n");

    arrayType signal ={{10, 20, 30, 11, 12, 13, 14}, 50, 7};

    printf("The original array is: \n\r");
    for(int i = 0; i < signal.length; i++)
    {
        printf(" %ld ", signal.data[i]);
    }
    printf("\n\r\n\r");


    array_append(&signal, 5);
    array_insert(&signal, 2, 25);

    printf("After append and Insertion array is: \n\r");
    for(int i = 0; i < signal.length; i++)
    {
        printf(" %ld ", signal.data[i]);
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