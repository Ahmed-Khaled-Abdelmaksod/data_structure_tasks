/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 13/7/2023
 * @brief  : it contains the implementation of the stack functions
 **************************************************************
*/


#include "stack_ds.h"



/****************************************************
 * @brief  : used to initialize the stack 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
return_state_t stack_initialization(stack_t *stack)
{
    return_state_t retval = return_nok;
    if(NULL == stack)
    {
        retval = return_nok;
        #ifdef STACK_DEBUGGER
            printf("failed to initialize stack \n");
        #endif

    }
    else
    {
        retval = return_ok;
        (stack->stack_ptr) = -1;
        #ifdef STACK_DEBUGGER
            printf("Stack initialized successfully\n");
        #endif
    }
    return (retval);
}



/****************************************************
 * @brief  : used to check if the stack is empty or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
static stack_state_t stack_empty(stack_t *stack)
{
    stack_state_t ret = FULL;
    if((stack->stack_ptr == -1))
    {
        /*
        #ifdef STACK_DEBUGGER
            printf("failed to initialize stack \n");
        #endif
        */
       ret = EMPTY;

    }
    else 
    {
         ret = HAS_ELEMENTS;
    }
    
    return ret;

}


/****************************************************
 * @brief  : used to check if the stack is full or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
static stack_state_t stack_full(stack_t *stack)
{
    stack_state_t ret = FULL;
    if((stack->stack_ptr == (STACK_MAX_SIZE - 1)))
    {
        /*
        #ifdef STACK_DEBUGGER
            printf("failed to initialize stack \n");
        #endif
        */
       ret = FULL;

    }
    else 
    {
         ret = HAS_ELEMENTS;
    }
    
    return ret;
}


/****************************************************
 * @brief  : used to check if the stack has elements or no 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from stack_state_t type
 * **************************************************
*/
stack_state_t stack_has_elements(stack_t *stack)
{
    stack_state_t ret = FULL;
    if((stack->stack_ptr >= 0) || (stack->stack_ptr <= STACK_MAX_SIZE))
    {
        /*
        #ifdef STACK_DEBUGGER
            printf("failed to initialize stack \n");
        #endif
        */
       ret = HAS_ELEMENTS;

    }
    else 
    {
         ret = FULL;
    }
    
    return ret;
}


/****************************************************
 * @brief  : used to display the elements of the stack 
 * @param  : stack is a pointer point to stack object
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_display(stack_t *stack)
{
    return_state_t ret = return_nok;
    uint16_t counter =0;
    if((stack == NULL) || (stack_empty(stack)==EMPTY))
    {
        ret=return_nok;
        #ifdef STACK_DEBUGGER
            printf("Error in displaying stack!! \n");
        #endif
    }
    else
    {
        ret = return_ok;
        printf("Stack Elements -> ");
        for(counter=0;counter<=(stack->stack_ptr);counter++)
        {
            printf("%i\t",(stack->elements[counter]));
        }
        printf("\n");
    }
    return ret;
}


/****************************************************
 * @brief  : used to return the size of elements inside the stack 
 * @param  : stack is a pointer point to stack object
 * @param  : variable where we will store the size 
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_size(stack_t *stack,uint32_t *size)
{
    return_state_t ret = return_nok;
    if((NULL == stack) || (NULL == size) )
    {
        ret = return_nok;
        #ifdef STACK_DEBUGGER
            printf("Error in size function!! \n");
        #endif
    }
    else
    {
        ret = return_ok;
        *size = (stack->stack_ptr + 1);
    }
    return ret;
}



/* _____________________________ Mechanism functions _____________________________ */
/****************************************************
 * @brief  : used to push element to the stack 
 * @param  : stack is a pointer point to stack object
 * @param  : the value to be pushed
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_push(stack_t *stack,sint32_t value)
{
    return_state_t ret = return_nok;
    if((NULL == stack) || (stack_full(stack)==FULL))
    {
        ret = return_nok;
        #ifdef STACK_DEBUGGER
            printf("fail to push [%i] value!! \n",value);
        #endif
    }
    else
    {
        stack->stack_ptr++;
        stack->elements[stack->stack_ptr] = value;
        printf("value [%i] pushed successfully to stack\n",value);
        ret = return_ok;
    }
    return ret;
}


/****************************************************
 * @brief  : used to pop element to the stack  
 * @param  : stack is a pointer point to stack object
 * @param  : pointer to the var where we will store the popped value
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_pop(stack_t *stack,sint32_t *value)
{
    return_state_t ret = return_nok;
    if((NULL == stack) || (value == NULL) || (stack_empty(stack) == EMPTY))
    {
        ret = return_nok;
        #ifdef STACK_DEBUGGER
            printf("fail to pop value!! \n");
        #endif
    }
    else
    {
        ret = return_ok;
        *value = (stack->elements)[stack->stack_ptr];
        printf("value [%i] popped successfully from stack\n",*value);
        stack->stack_ptr--;
    }
    return ret;
}


/****************************************************
 * @brief  : used to get the top value 
 * @param  : stack is a pointer point to stack object
 * @param  : pointer to the var where we will store the popped value
 * @retval : return value from return_state_t type
 * **************************************************
*/
return_state_t stack_top(stack_t *stack,sint32_t *value)
{
    return_state_t ret = return_nok;
     if((NULL == stack) || (value == NULL) || (stack_empty(stack) == EMPTY))
    {
        ret = return_nok;
        #ifdef STACK_DEBUGGER
            printf("fail to get top value!! \n");
        #endif
    }
    else
    {
        ret = return_ok;
        *value = (stack->elements)[stack->stack_ptr];
    }
    return ret;
}
