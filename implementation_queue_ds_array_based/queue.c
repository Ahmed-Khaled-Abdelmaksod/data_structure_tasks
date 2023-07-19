/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 19/7/2023
 * @brief  : it contains the implementations of the functions of
 *           queue.h
 **************************************************************
*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "queue.h"


queue_t *queue_creation(uint32_t max_size,queue_state_t *state)
{
    queue_t *queue = NULL;
    if(state == NULL)
    {
        *state = QUEUE_NULL_POINTER;
    }
    else
    {
        queue = (queue_t *)malloc(sizeof(queue_t));
        if(queue == NULL)
        {
            *state = QUEUE_NULL_POINTER;
        }
        else
        {
            queue->queue_array = (void **)(calloc(max_size,sizeof(void *)));
            if((queue->queue_array) == (NULL))
            {
                *state = QUEUE_NULL_POINTER;
            }
            else
            {
                queue->queue_count = 0;
                queue->queue_front = -1;
                queue->queue_rear  = -1;
                queue->queue_max_size = max_size;
                *state = QUEUE_OK;
            }
        }
    }
    return queue;
}
queue_state_t queue_destroy(queue_t *queue)
{
    queue_state_t state = QUEUE_NOK;
    if(queue == NULL)
    {
        state = QUEUE_NULL_POINTER;
    }
    else
    {
        free(queue->queue_array);
        free(queue);
        state = QUEUE_OK;
    }
    return state;
}

queue_state_t enqueue(queue_t *queue,void *value)
{
    queue_state_t state = QUEUE_NOK;
    if((value == NULL) || (queue == NULL))
    {
        state = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_full(queue))
        {
            state = QUEUE_FULL;
        }
        else
        {
            (queue->queue_rear)++;
            if((queue->queue_rear) == (queue->queue_max_size))
            {
                queue->queue_rear = 0;
            }
            queue->queue_array[queue->queue_rear] = value;
            if((queue->queue_count) == 0)
            {
                queue->queue_front = 0;
                (queue->queue_count) = 1;
            }
            else
            {
                (queue->queue_count)++;
            }
            state = QUEUE_OK;
        }
    }
    return state;
}


void* dequeue(queue_t *queue,queue_state_t *state)
{
    void *ptr = NULL;
    if((queue == NULL) || (state ==NULL))
    {
        *state = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue))
        {
            *state = QUEUE_EMPTY;
        }
        else
        {
            ptr = (queue->queue_array[queue->queue_front]);
            (queue->queue_front)++;
            if((queue->queue_front) == (queue->queue_max_size))
            {
                queue->queue_front = 0;
            }
            if((queue->queue_count) == 0)
            {
                queue->queue_count = 1;
                queue->queue_front = 0;
                queue->queue_rear = 0;
            }
            else
            {
                (queue->queue_count)++;
            }
            *state = QUEUE_OK;
        }
    }
    return ptr;
}

void* queue_front(queue_t *queue,queue_state_t *state)
{
    void *value = NULL;
    if((queue == NULL) || (state ==NULL))
    {
        *state = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue))
        {
            *state = QUEUE_EMPTY;
        }
        else
        {
            value = queue->queue_array[queue->queue_front];
            *state = QUEUE_OK;
        }
    }
    return value;
}

void* queue_rear(queue_t *queue,queue_state_t *state)
{
    void *value = NULL;
    if((queue == NULL) || (state ==NULL))
    {
        *state = QUEUE_NULL_POINTER;
    }
    else
    {
        if(queue_is_empty(queue))
        {
            *state = QUEUE_EMPTY;
        }
        else
        {
            value = queue->queue_array[queue->queue_rear];
            *state = QUEUE_OK;
        }
    }
    return value;
}

static uint8_t queue_is_empty(queue_t *queue)
{
    uint8_t state = 0;
    if((queue->queue_count) == 0)
    {
        state = 1;
    }
    else
    {
        state = 0;
    }
    return state;
}
static uint8_t queue_is_full(queue_t *queue)
{
    uint8_t state = 0;
    if((queue->queue_count) == (queue->queue_max_size))
    {
        state = 1;
    }
    else
    {
        state = 0;
    }
    return state;
}