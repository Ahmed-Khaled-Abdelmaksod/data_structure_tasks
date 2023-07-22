/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 22/7/2023
 * @brief  : it contains the prototypes of double linked list data structure
 **************************************************************
*/

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include"platform_types.h"

typedef struct node
{
    uint32_t data;
    struct node *right_link;
    struct node *left_link;
}node_t;

void double_linked_list_add_at_beginning(node_t **list,uint32_t data);
void double_linked_list_add_at_end(node_t *list,uint32_t data);
void double_linked_list_add_after(node_t *list,uint32_t data,uint32_t position);
void double_linked_list_add_before(node_t *list,uint32_t data,uint32_t position);

void double_linked_list_delete_at(node_t **list,uint32_t position);
void double_linked_list_delete_at_beginning(node_t **list);

uint32_t double_linked_list_get_length(node_t *list);

void double_linked_list_display_forward(node_t *list);
void double_linked_list_display_reverse(node_t *list);

void double_linked_list_reverse_list(node_t **list);

#endif