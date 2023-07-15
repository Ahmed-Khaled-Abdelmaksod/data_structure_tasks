
/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 14/7/2023
 * @brief  : it contains the implementation of stack functions
 **************************************************************
*/
#include"dynamic_stack_ds.h"
#include<stdlib.h>
#include<stdio.h>

static uint8_t stack_full(stack_t *stack)
{
    return ((stack->stack_count) == (stack->stack_max_size));
}


static uint8_t stack_empty(stack_t *stack)
{
    return ((stack->stack_top) == -1);
}


stack_status_t stack_count(stack_t *stack,uint32_t *count)
{
    stack_status_t retval = STACK_NOK;
    if((stack == NULL) || (count == NULL))
    {
        retval = STACK_NOK;
    }
    else
    {
        retval = STACK_OK;
        *count = (stack->stack_count);
    }
    return retval;
}
 stack_t* stack_creation(stack_status_t *retval,uint32_t stack_size)
{
    stack_t* stack=NULL;
    if(retval == NULL)
    {
        *retval = STACK_NOK;
    }
    else
    {
        stack = (stack_t *)malloc(sizeof(stack_t));
        if(!stack)
        {
            *retval = STACK_NOK;
        }
        else
        {
            stack->stack_top = -1;
            stack->stack_count = 0;
            stack->stack_max_size = stack_size;
            (stack->stack_ptr) = (void**)malloc(sizeof(void *) * stack_size);
            if(!(stack->stack_top))
            {
                *retval = STACK_NOK;
            }
            else
            {
                *retval = STACK_OK;
            }
        }
    }
    return stack;
}
stack_status_t stack_destroy(stack_t* stack)
{
    stack_status_t retval = STACK_NOK;
    if((stack == NULL))
    {
        retval = STACK_NOK;
    }
    else
    {
        free((stack->stack_ptr));
        free((stack));
        
        retval = STACK_OK;
    }
    return retval;
}

// mechanism functions
stack_status_t stack_push(stack_t* stack,void *value)
{
    stack_status_t retval = STACK_NOK;
    if(stack == NULL)
    {
        retval = STACK_NOK;
    }
    else
    {
        if(!stack_full(stack))
        {
            
            (stack->stack_count)++;
            (stack->stack_top)++;
            (stack->stack_ptr[stack->stack_top]) = value;
            retval = STACK_OK;
        }
        else
        {
            retval = STACK_NOK;
        }
    }
    return retval;
}
void* stack_pop(stack_t* stack,stack_status_t *retval)
{
    
    void *ptr = NULL;
    if((stack == NULL) || (retval == NULL))
    {
        *retval = STACK_NOK;
    }
    else
    {
        if(!stack_empty(stack))
        {

            ptr = (void *)(stack->stack_ptr[stack->stack_top]);
            (stack->stack_top)--;
            (stack->stack_count)--;
            *retval = STACK_OK;
        }
        else
        {
            *retval = STACK_NOK;
        }
    }
    return ptr;
}
void *stack_top(stack_t* stack,stack_status_t *retval)
{
    *retval = STACK_NOK;
    void *ptr = NULL;
    if((stack == NULL) || (retval == NULL))
    {
        *retval = STACK_NOK;
    }
    else
    {
        if(!stack_empty(stack))
        {

            (ptr) = (void *)(stack->stack_ptr[stack->stack_top]);
            *retval = STACK_OK;
        }
        else
        {
            *retval = STACK_NOK;
        }
    }
    return ptr;
}
