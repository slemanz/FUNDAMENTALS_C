#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

struct Queue{
    int front;
    int rear;
    int capacity;
    int size;
    int *array;
};

typedef struct Queue queueType;


queueType *queue_create(int capacity);
int queue_getSize(queueType *queue);
int queue_getFrontElem(queueType *queue);
int queue_getRearElem(queueType *queue);
int queue_isEmpty(queueType *queue);
int queue_isFull(queueType *queue);

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");


    while (1)
    {
    }
}

queueType *queue_create(int capacity)
{
    queueType *queue = malloc(sizeof(queueType));
    if(!queue)
    {
        printf("Memory error\n\r");
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    if(!queue->array)
    {
        printf("Memory error\n\r");
        free(queue);
        return NULL;
    }

    return queue;
}

int queue_getSize(queueType *queue)
{
    return queue->size;
}

int queue_getFrontElem(queueType *queue)
{
    return queue->array[queue->front];
}

int queue_getRearElem(queueType *queue)
{
    return queue->array[queue->rear];
}

int queue_isEmpty(queueType *queue)
{
    return (queue->size == 0);
}

int queue_isFull(queueType *queue)
{
    return (queue->size == queue->capacity);
}