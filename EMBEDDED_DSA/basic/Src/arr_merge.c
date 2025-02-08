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
void array_sort_ascend(arrayType *arr);
void array_sort_descend(arrayType *arr);

int32_t array_max(arrayType *arr);
int32_t array_min(arrayType *arr);
int32_t array_sum(arrayType *arr);
double array_mean(arrayType *arr);
arrayType* array_merge(arrayType *arr1, arrayType *arr2);

int main(void)
{
    system_init();
    printf("\n");

    arrayType signal  = {{10, 20, 30, 11, 12, 13, 14}, 50, 7};
    arrayType signal2 = {{11, 21, 31, 15, 16, 16, 18}, 50, 7};

    arrayType *full_signal;
    full_signal = array_merge(&signal, &signal2);

    printf("Merge of arrays: \n\r");
    for(int i = 0; i < full_signal->length; i++)
    {
        printf(" %ld ", full_signal->data[i]);
    }
    printf("\n\r\n\r");

    printf("max: %ld\n\r", array_max(full_signal));
    printf("min: %ld\n\r", array_min(full_signal));
    printf("sum: %ld\n\r", array_sum(full_signal));
    printf("mean: %.3lf\n\r", array_mean(full_signal));

    array_sort_ascend(full_signal);
    printf("Merge of arrays sort ascend: \n\r");
    for(int i = 0; i < full_signal->length; i++)
    {
        printf(" %ld ", full_signal->data[i]);
    }
    

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

void array_sort_ascend(arrayType *arr)
{
    int32_t i, j, n_temp;
    for(i = 1; i < arr->length; i++)
    {
        n_temp = arr->data[i];
        j = i;
        while(j > 0 && n_temp < arr->data[j - 1])
        {
            arr->data[j] = arr->data[j-1];
            --j;
        }
        arr->data[j] = n_temp;
    }
}

void array_sort_descend(arrayType *arr)
{
    int32_t i, j, n_temp;
    for(i = 1; i < arr->length; i++)
    {
        n_temp = arr->data[i];
        j = i;
        while(j > 0 && n_temp > arr->data[j - 1])
        {
            arr->data[j] = arr->data[j-1];
            --j;
        }
        arr->data[j] = n_temp;
    }
}


int32_t array_max(arrayType *arr)
{
    int32_t max = arr->data[0];
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->data[i] > max)
        {
            max = arr->data[i];
        }
    }
    return max;
}

int32_t array_min(arrayType *arr)
{
    int32_t min = arr->data[0];
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->data[i] < min)
        {
            min = arr->data[i];
        }
    }
    return min;
}

int32_t array_sum(arrayType *arr)
{
    int32_t sum = 0;
    for(int i = 0; i < arr->length; i++)
    {
        sum += arr->data[i];
    }
    return sum;
}

double array_mean(arrayType *arr)
{
    int32_t sum = 0;
    sum = array_sum(arr);

    double mean = 0.0f;
    mean = ((double)sum)/(arr->length);



    return mean;
}

arrayType* array_merge(arrayType *arr1, arrayType *arr2)
{
    int32_t i, j, k;
    i = 0;
    j = 0;
    k = 0;

    arrayType *dest_arr = (arrayType *)malloc(sizeof(arrayType));
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->data[i] < arr2->data[j])
        {
            dest_arr->data[k++] = arr1->data[i++];
        }else
        {
            dest_arr->data[k++] = arr2->data[j++];
        }
    }

    for(; i < arr1->length; i++)
    {
        dest_arr->data[k++] = arr1->data[i];
    }
    for(; j<arr2->length; j++)
    {
        dest_arr->data[k++] = arr2->data[j];
    }
    dest_arr->length = arr1->length + arr2->length;

    return dest_arr;
}