/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 18/7/2023
 * @brief  : it contains the prototypes if queue data structure
 **************************************************************
*/
#ifndef _QUEUE_H

#define _QUEUE_H
#include"platform_types.h"

typedef struct 
{
    void **queue_array;
    uint32_t queue_count;
    uint32_t queue_max_size;
    sint32_t queue_front;
    sint32_t queue_rear;
}queue_t;

typedef enum 
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_NULL_POINTER
}queue_state_t;


queue_t *queue_creation(uint32_t max_size,queue_state_t *state);
queue_state_t queue_destroy(queue_t *queue);

queue_state_t enqueue(queue_t *queue,void *value);
void* dequeue(queue_t *queue,queue_state_t *state);
void* queue_front(queue_t *queue,queue_state_t *state);
void* queue_rear(queue_t *queue,queue_state_t *state);

static uint8_t queue_is_empty(queue_t *queue);
static uint8_t queue_is_full(queue_t *queue);



#endif