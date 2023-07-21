/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 21/7/2023
 * @brief  : it contains the implementation of single linked list data structure
 **************************************************************
*/

#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>
state_t linked_list_insert_at_beginning(node_t **list)
{
    state_t state = LINKED_LIST_NOK;
    node_t *node = NULL;
    
    if((list == NULL))
    {
        state = LINKED_LIST_NOK;
    }
    else
    {
        node = (node_t*)malloc(sizeof(node_t));
        if(node != NULL)
        {
            printf("Enter value of the node : ");
            scanf("%i",&(node->data));
            if(*list == NULL)
            {
                *list = node;
                node->link_ptr = NULL;
            }
            else
            {
                node->link_ptr = *list;
                *list = node;
            }
            state = LINKED_LIST_OK;
        }
        else
        {
            state = LINKED_LIST_NOK;
        }
       
    }
    return state;
}
state_t linked_list_insert_at_end(node_t *list)
{
    state_t state = LINKED_LIST_NOK;
    node_t *last_node = list;
    node_t *inserted_node = NULL;
    if(list == NULL)
    {
        printf("Use linked_list_insert_at_beginning\n");
        state = LINKED_LIST_NOK;
    }
    else
    {
        inserted_node = (node_t *)(malloc(sizeof(node_t)));
        printf("Enter value of the node : ");
        scanf("%i",&(inserted_node->data));
        while ((last_node->link_ptr) != NULL)
        {
            last_node = (last_node->link_ptr);
        }
        last_node->link_ptr = inserted_node;
        inserted_node->link_ptr = NULL;
        state = LINKED_LIST_OK;
    }
    return state;
}
state_t linked_list_insert_at_middle(node_t *list)
{
    state_t state = LINKED_LIST_NOK;
    uint32_t position = 0;
    node_t *inserted_node = NULL;
    node_t *temp_node = list;
    uint32_t counter=1;
    printf("Enter position of the inserted node (start from position 1)\n");
    scanf("%i",&position);
    if(position > linked_list_get_length(list))
    {
        printf("wrong position , try again!!\n");
        state = LINKED_LIST_NOK;
    }
    else
    {
        inserted_node = (node_t*)(malloc(sizeof(node_t)));
        printf("Enter Data : ");
        scanf("%i",&(inserted_node->data));
        if(inserted_node != NULL)
        {
            while(counter < (position - 1))
            {
                counter++;
                temp_node = temp_node->link_ptr;
            }
            inserted_node->link_ptr = temp_node->link_ptr;
            temp_node->link_ptr = inserted_node;
            state = LINKED_LIST_OK; 
        }
        else
        {
            state = LINKED_LIST_NOK;
        }
    }
    return state;
} 
state_t linked_list_delete_at_beginning(node_t **list)
{
    state_t state = LINKED_LIST_NOK;
    node_t *node = *list;
    uint32_t length = linked_list_get_length(node);
    if(length == 1)
    {
        free(node);
        node = NULL;
        state = LINKED_LIST_OK;
    }
    else
    {
        *list = (*list)->link_ptr;
        free(node);
        state = LINKED_LIST_OK;
    }
    return state;

}
state_t linked_list_delete(node_t **list)
{
    state_t state = LINKED_LIST_NOK;
    node_t *node = *list;
    node_t *temp_node = node;
    uint32_t length = linked_list_get_length(node);
    uint32_t position = 0;
    uint32_t counter = 1;
    printf("Enter the position of the deleted element (start from position 1): ");

    scanf("%i",&position);
    if(position == 1)
    {
        printf("use linked_list_delete_at_beginning function\n"); 
    }
    if(position > linked_list_get_length(*list))
    {
        printf("try again !! , wrong position\n");
    }
    else 
    {
        while (counter <= (position-1))
        {
            temp_node = temp_node->link_ptr;
            if(counter == (position-2))
            {
                node = temp_node;
            }
            counter++;

        }
        node->link_ptr = temp_node->link_ptr;
        free(temp_node);
        temp_node = NULL;
    }
    return state;
}
uint32_t linked_list_get_length(node_t *list)
{
    uint32_t counter = 1;
    node_t *node = list;
    if(list == NULL)
    {
        counter = 0;
    }
    else
    {
        
        while((node->link_ptr) != NULL)
        {
            counter++;
            node = (node->link_ptr);
        }
    }
    return counter;
}
state_t linked_list_display(node_t *list)
{
    state_t state = LINKED_LIST_NOK;
    node_t *node = list;
    if(list == NULL )
    {
        printf("EMPTY LIST !!!");
        state = LINKED_LIST_NOK;
    }
    else
    {
        printf("data : ");
        while ((node) != NULL)
        {
            printf("%i >> ",node->data);
            node = node->link_ptr;
        }
        printf("NULL\n");
    }
    return state;
}