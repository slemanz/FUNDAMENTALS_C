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
void queue_enqueue(queueType *queue, int data);
int queue_dequeue(queueType *queue);
void queue_delete(queueType *queue);

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    queueType *temperature_values;
    temperature_values = queue_create(5);

    queue_enqueue(temperature_values, 25);
    queue_enqueue(temperature_values, 27);
    queue_enqueue(temperature_values, 28);
    queue_enqueue(temperature_values, 24);

    printf("Queue size: %d\n\r", queue_getSize(temperature_values));
    printf("Front elem: %d\n\r", queue_getFrontElem(temperature_values));

    printf("Dequeue elem: %d\n\r", queue_dequeue(temperature_values));
    printf("Dequeue elem: %d\n\r", queue_dequeue(temperature_values));
    printf("Dequeue elem: %d\n\r", queue_dequeue(temperature_values));

    printf("\n\r");
    printf("Queue size: %d\n\r", queue_getSize(temperature_values));
    printf("Front elem: %d\n\r", queue_getFrontElem(temperature_values));


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

void queue_enqueue(queueType *queue, int data)
{
    if(queue_isFull(queue))
    {
        // handle the error
        printf("Queue overflow\n\r");
    }else
    {
        queue->rear = (queue->rear+1) % queue->capacity;
        queue->array[queue->rear] = data;
        if(queue->front == -1)
        {
            queue->front = queue->rear;
        }

        queue->size += 1;
    }
}

int queue_dequeue(queueType *queue)
{
    int data = -999;
    if(queue_isEmpty(queue))
    {
        printf("Queue is empty\r\n");
        return data;
    }

    data = queue->array[queue->front];
    if(queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
        queue->size = 0;
    }else
    {
        queue->front = (queue->front+1) % queue->capacity;
        queue->size -= 1;
    }

    return data;
}

void queue_delete(queueType *queue)
{
    if(queue)
    {
        if(queue->array)
        {
            free(queue->array);
        }

        free(queue);
    }
}