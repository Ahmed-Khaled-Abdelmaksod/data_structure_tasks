/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 13/7/2023
 * @brief  : it contains the test 
 **************************************************************
*/
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
int main(void)
{
    queue_t *queue_1 = NULL;
    queue_state_t state = QUEUE_NOK;
    uint32_t size = 0;
    uint32_t count = 0;
    void *value = NULL;
    uint32_t x0 = 0x11;
    uint32_t x1 = 0x22;
    uint32_t x2 = 0x33;
    uint32_t x3 = 0x44;
    uint32_t x4 = 0x55;
    printf("Enter size : ");
    scanf("%i",&size);

    queue_1 = queue_creation(size,&state);
    if((state) == (QUEUE_OK))
    {
        printf("Queue is created successfully \n");
    }

    state = enqueue(queue_1,&x0);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x0);
    }
    state = enqueue(queue_1,&x1);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x1);
    }
    state = enqueue(queue_1,&x2);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x2);
    }
    state = enqueue(queue_1,&x3);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x3);
    }
    state = enqueue(queue_1,&x4);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x4);
    }
    void *ptr = NULL;
    ptr = queue_front(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("front => 0x%X\n",*((uint32_t *)ptr));
    }
    ptr = queue_rear(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("rear => 0x%X\n",*((uint32_t *)ptr));
    }

    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }

    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }
    ptr = queue_front(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("front => 0x%X\n",*((uint32_t *)ptr));
    }
    ptr = queue_rear(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("rear => 0x%X\n",*((uint32_t *)ptr));
    }

    state = enqueue(queue_1,&x0);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%X enqueued successfully\n",x0);
    }
    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }

    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }
    queue_display(queue_1);
    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }
    ptr = dequeue(queue_1,&state);
    if(state == QUEUE_OK)
    {
        printf("Value 0x%x is dequeued sucessfully\n",*((uint32_t *)(ptr)));
    }
    

    state = queue_destroy(queue_1);
    if(state == QUEUE_OK)
    {
        printf("Queue is destroyed successfully\n");
    }
    return 0;
}