/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 13/7/2023
 * @brief  : it contains the test of the implemented functions
 **************************************************************
*/

/**
 * we have to use stack_initialization before using any stack
*/

#include"stack_ds.h"
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    return_state_t ret = return_nok;
    stack_t stack1;
    sint32_t value = 0 ;
    uint32_t size = 0 ;
    
    // start test stack 1 
    ret = stack_initialization(&stack1);
    ret = stack_push(&stack1,11);
    ret = stack_push(&stack1,22);
    ret = stack_push(&stack1,33);
    ret = stack_push(&stack1,44);
    ret = stack_push(&stack1,55);
    ret = stack_push(&stack1,66);
    ret = stack_push(&stack1,77);
    ret = stack_display(&stack1);
    ret = stack_top(&stack1,&value);
    printf("Stack top value -> %i \n",value);
    ret = stack_pop(&stack1,&value);
    ret = stack_top(&stack1,&value);
    printf("Stack top value -> %i \n",value);
    ret = stack_size(&stack1,&size);
    printf("Size of the stack -> %i \n",size);
    ret = stack_pop(&stack1,&value);
    ret = stack_pop(&stack1,&value);
    ret = stack_pop(&stack1,&value);
    ret = stack_pop(&stack1,&value);
    ret = stack_size(&stack1,&size);
    printf("Size of the stack -> %i \n",size);
    

    return 0;
}