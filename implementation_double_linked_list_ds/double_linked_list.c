/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 22/7/2023
 * @brief  : it contains the implementation of double linked list data structure
 **************************************************************
*/

#include<stdlib.h>
#include<stdio.h>
#include"double_linked_list.h"

void double_linked_list_add_at_beginning(node_t **list,uint32_t data)
{
    node_t *node = NULL;
    node = (node_t*)(malloc(sizeof(node_t)));
    if(node != NULL)
    {
        node->data = data;
        if((*list) == NULL)
        {
            node->left_link = NULL;
            node->right_link = NULL;
            *list = node;
        }
        else
        {
            node->right_link = (*list);
            node->left_link = NULL;
            (*list)->left_link = node;
            *list = node;
        }
    }
    else
    {
        printf("Cannot allocate the node\n");
    }

}
void double_linked_list_add_at_end(node_t *list,uint32_t data)
{
    node_t *node = list;
    node_t *inserted_node = NULL;
    if(list == NULL)
    {
        double_linked_list_add_at_beginning(&list,data);
    }
    else
    {
        inserted_node = (node_t*)(malloc(sizeof(node_t)));
        if(inserted_node == NULL)
        {
            printf("Cannot allocate the node\n");
        }
        else
        {
            while(node->right_link != NULL)
            {
                node = node->right_link;
            }
            inserted_node->data = data;
            node->right_link = inserted_node;
            inserted_node->left_link = node;
            inserted_node->right_link = NULL;
        }
        
    }
}
void double_linked_list_add_after(node_t *list,uint32_t data,uint32_t position)
{
    uint32_t counter = 1;
    node_t *node = list;
    node_t *inserted_node = NULL;
    if(position > double_linked_list_get_length(list))
    {
        printf("wrong position \n");
    }
    else
    {
        if(list == NULL)
        {
            double_linked_list_add_at_beginning(&list,data);
        }
        else
        {
            inserted_node = (node_t *)(malloc(sizeof(node_t)));
            inserted_node->data = data;
            if(inserted_node == NULL)
            {
                printf("Cannot allocate the node\n");
            }
            else
            {
                while (counter < position)
                {
                    counter++;
                    node = node->right_link;
                }
                inserted_node->right_link = node->right_link;
                inserted_node->left_link = node;
                node->right_link->left_link = inserted_node;
                node->right_link = inserted_node;
                if(position == double_linked_list_get_length(list))
                {
                    node->right_link = NULL;
                }
            }
        }
    }
}
void double_linked_list_add_before(node_t *list,uint32_t data,uint32_t position)
{
    node_t *temp_node = list;
    node_t *inserted_node = NULL;
    uint32_t counter = 1;
    if(position > double_linked_list_get_length(list))
    {
        printf("wrong position\n");
    }
    else
    {
        if(list==NULL)
        {
            double_linked_list_add_at_beginning(&list,data);
        }
        else
        {
            inserted_node = (node_t *)(malloc(sizeof(node_t)));
            if(inserted_node == NULL)
            {
                printf("cannot allocate the node\n");
            }
            else
            {
                inserted_node->data = data;
                while (counter < position)
                {
                    counter++;
                    temp_node = temp_node->right_link;
                }
                inserted_node->right_link = temp_node;
                inserted_node->left_link = temp_node->left_link;
                temp_node->left_link->right_link = inserted_node;
                temp_node->left_link = inserted_node;
            }
        }
    }
}

void double_linked_list_delete_at(node_t **list,uint32_t position)
{
    uint32_t counter=1;
    uint32_t length = double_linked_list_get_length(*list);
    node_t *node = *list;
    if((position == 0) || (position > length))
    {
        printf("wrong position !!!\n");
    }
    else
    {

    
        if((length == 0) || (length == 1) || (position == 1))
        {
            double_linked_list_delete_at_beginning(list);
        }
        else
        {
            while (counter < position)
            {
                counter++;
                node = node->right_link;
            }
            node->right_link->left_link = node->left_link;
            node->left_link->right_link = node->right_link;
            node->left_link = NULL;
            node->right_link=NULL;
            free(node);
            
        }
    }
}
void double_linked_list_delete_at_beginning(node_t **list)
{
    node_t *node= *list;
    if(1 == double_linked_list_get_length(*list))
    {
        *list == NULL;
        free(node);
    }
    else if((*list) == NULL)
    {
        printf("Empty list !!!\n");
    }
    else
    {
        node->right_link->left_link = NULL;
        *list = node->right_link;
        node->right_link = NULL;
        free(node);
    }
}

uint32_t double_linked_list_get_length(node_t *list)
{
    uint32_t counter=1;
    node_t *node = list;
    if(list == NULL)
    {
        counter = 0;
    }
    else
    {
        while(node->right_link != NULL)
        {
            node = node->right_link;
            counter++;
        }
    }
    return counter;
}

void double_linked_list_display_forward(node_t *list)
{
    node_t *node = list;
    if(NULL == list)
    {
        printf("Empty list !!\n");
    }
    else
    {
        printf("DATA IN FORWARD : ");
        while(node != NULL)
        {
            printf("%i >> ",node->data);
            node = node->right_link;
        }
        printf("NULL\n");

    }
}
void double_linked_list_display_reverse(node_t *list)
{
    node_t *node = list;
    node_t *last_node = NULL;
    if(NULL == list)
    {
        printf("Empty list !!\n");
    }
    else
    {
        while(node->right_link != NULL)
        {
            
            node = node->right_link;
        }
        last_node = node;
        printf("DATA IN FORWARD : ");
        while(last_node != NULL)
        {
            printf("%i >> ",last_node->data);
            last_node = last_node->left_link;
        }
        printf("NULL\n");

    }
}

void double_linked_list_reverse_list(node_t **list)
{
    node_t *node = *list;
    node_t *temp = NULL;
    while (node->right_link != NULL)
    {
        node = node->right_link;
    }
    *list = node;
    while(node != NULL)
    {
        temp = node->right_link;
        node->right_link = node->left_link;
        node->left_link = temp;
        node = node->right_link;
    }   
}