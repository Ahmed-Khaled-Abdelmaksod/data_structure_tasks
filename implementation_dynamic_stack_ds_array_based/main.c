/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 14/7/2023
 * @brief  : it contains the test of dynamic stack data structure
 **************************************************************
*/


#include<stdio.h>
#include<stdlib.h>
#include"dynamic_stack_ds.h"
int main(void)
{
    stack_t *stack1 =NULL;
    uint32_t size = 0;
    return_state_t ret = STACK_NOK;
    return_state_t *ret_ptr = &ret;
    void *ptr = NULL;
    uint8_t c = 'a';
    uint16_t s = 0x11;
    uint32_t i = 0x22;
    uint32_t count=0;
    printf("Enter Size of the stack \n");
    scanf("%i",&size);
    stack1 = stack_creation(ret_ptr,size);
    if(ret == STACK_OK)
    {
        printf("Stack is created successfully \n");
    }
    ptr = &c;
    ret = stack_push(stack1,ptr);
    if(ret == STACK_OK)
    {
        printf("value pushed successfully\n");
    }
    ptr=&s;
    ret = stack_push(stack1,ptr);
    if(ret == STACK_OK)
    {
        printf("value pushed successfully\n");
    }
    ptr=&i;
    ret = stack_push(stack1,ptr);
    if(ret == STACK_OK)
    {
        printf("value pushed successfully\n");
    }

    ptr = stack_top(stack1,&ret);
    if(ret == STACK_OK)
    {
        printf("value in top : 0x%X\n",*((uint32_t *)ptr));
    }
    ret = stack_count(stack1,&count);
    if(ret == STACK_OK)
    {
        printf("Count : %i\n",count);
    }


    ptr = stack_pop(stack1,&ret);
    if(ret == STACK_OK)
    {
        printf("value [0x%X] is popped successfully \n",*((uint32_t *)(ptr)));
       
        ptr = stack_top(stack1,&ret);
        if(ret == STACK_OK)
        {
            printf("value in top : 0x%X\n",*((uint16_t *)ptr));
        }
        ret = stack_count(stack1,&count);
        if(ret == STACK_OK)
        {
            printf("Count : %i\n",count);
        }
        
    }

    ptr = stack_pop(stack1,&ret);
    if(ret == STACK_OK)
    {
        printf("value [0x%X] is popped successfully \n",*((uint16_t *)(ptr)));
       
        ptr = stack_top(stack1,&ret);
        if(ret == STACK_OK)
        {
            printf("value in top : %c\n",*((uint8_t *)ptr));
        }
        ret = stack_count(stack1,&count);
        if(ret == STACK_OK)
        {
            printf("Count : %i\n",count);
        }
        
    }

    
    ptr = stack_pop(stack1,&ret);
    if(ret == STACK_OK)
    {
        printf("value [0x%X] is popped successfully \n",*((uint16_t *)(ptr)));
        ret = stack_count(stack1,&count);
        if(ret == STACK_OK)
        {
            printf("Count : %i\n",count);
        }
        
    }


    ret = stack_destroy(stack1);
    if(ret == STACK_OK)
    {
        printf("Stack is destroyed successfully \n");
    }
    else
    {
        printf("cannot destroy stack :(\n");

    }
    return 0;
}