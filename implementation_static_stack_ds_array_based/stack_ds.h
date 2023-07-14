/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 13/7/2023
 * @brief  : it contains the prototypes of the stack data structure functions
 **************************************************************
*/
#ifndef _STACK_DS_H_
#define _STACK_DS_H_

#define STACK_MAX_SIZE 5
#define STACK_DEBUGGER

/*__________________________ include section __________________________*/
#include"platform_types.h"
#include<stdio.h>
#include<stdlib.h>

// we will define stack structure which consist of array and pointer to the index of the top element
typedef struct 
{
    sint32_t elements[STACK_MAX_SIZE];
    sint32_t stack_ptr;
}stack_t;

typedef enum
{
    EMPTY,
    FULL,
    HAS_ELEMENTS
}stack_state_t;

/* _____________________________ helper functions _____________________________ */


/****************************************************
 * @brief  : used to initialize the stack 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
return_state_t stack_initialization(stack_t *stack);


/****************************************************
 * @brief  : used to check if the stack is empty or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
static stack_state_t stack_empty(stack_t *stack);


/****************************************************
 * @brief  : used to check if the stack is full or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
static stack_state_t stack_full(stack_t *stack);


/****************************************************
 * @brief  : used to check if the stack has elements or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
stack_state_t stack_has_elements(stack_t *stack);


/****************************************************
 * @brief  : used to display the elements of the stack 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_display(stack_t *stack);


/****************************************************
 * @brief  : used to return the size of elements inside the stack 
 * @param  : stack is a pointer point to stack object
 * @param  : variable where we will store the size 
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_size(stack_t *stack,uint32_t *size);



/* _____________________________ Mechanism functions _____________________________ */
/****************************************************
 * @brief  : used to push element to the stack 
 * @param  : stack is a pointer point to stack object
 * @param  : the value to be pushed
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_push(stack_t *stack,sint32_t value);


/****************************************************
 * @brief  : used to pop element to the stack  
 * @param  : stack is a pointer point to stack object
 * @param  : pointer to the var where we will store the popped value
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_pop(stack_t *stack,sint32_t *value);


/****************************************************
 * @brief  : used to get the top value 
 * @param  : stack is a pointer point to stack object
 * @param  : pointer to the var where we will store the popped value
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_top(stack_t *stack,sint32_t *value);

#endif