/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 21/7/2023
 * @brief  : it contains the prototypes of single linked list data structure
 * 
 *  NOTE : THE DATA MUST BE FROM UINT32_T TYPE !!
 **************************************************************
*/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include"platform_types.h"


typedef enum 
{
    LINKED_LIST_NOK=0,
    LINKED_LIST_OK,
}state_t;

typedef struct node 
{
    uint32_t data;
    struct node *link_ptr;
}node_t;

state_t linked_list_insert_at_beginning(node_t **list); // get data inside it from user
state_t linked_list_insert_at_end(node_t *list);
state_t linked_list_insert_at_middle(node_t *list); // take position && data from user
state_t linked_list_delete_at_beginning(node_t **list);
state_t linked_list_delete(node_t **list);
uint32_t linked_list_get_length(node_t *list);
state_t linked_list_display(node_t *list);
#endif
