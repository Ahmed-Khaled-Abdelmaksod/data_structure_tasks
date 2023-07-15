/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 14/7/2023
 * @brief  : it contains the prototypes of stack functions
 **************************************************************
*/

#ifndef _DYNAMIC_STACK_DS_H
#define _DYNAMIC_STACK_DS_H

#include"platform_types.h"

typedef enum 
{
    STACK_NOK=0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_PTR
}stack_status_t;

typedef struct 
{
    void     **stack_ptr;
    uint32_t stack_count;
    sint32_t stack_top;
    uint32_t stack_max_size;
}stack_t;

// helper functions
static uint8_t stack_empty(stack_t *stack);
static uint8_t stack_full(stack_t *stack);
stack_status_t stack_count(stack_t *stack,uint32_t *count);
stack_t* stack_creation(stack_status_t *retval,uint32_t stack_size);
stack_status_t stack_destroy(stack_t* stack);
// mechanism functions
stack_status_t stack_push(stack_t* stack,void *value);
void *stack_pop(stack_t* stack,stack_status_t *retval);
void *stack_top(stack_t* stack,stack_status_t *retval);


#endif