/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 22/7/2023
 * @brief  : it contains the test of double linked list data structure
 **************************************************************
*/
#include<stdio.h>
#include"double_linked_list.h"
node_t *list = NULL;
int main(void)
{
    double_linked_list_add_at_beginning(&list,22);
    printf("%i\n",double_linked_list_get_length(list));
    double_linked_list_display_forward(list);
    double_linked_list_add_at_end(list,33);
    double_linked_list_add_at_end(list,44);
    double_linked_list_add_at_end(list,55);
    double_linked_list_display_forward(list);
    double_linked_list_display_reverse(list);
    double_linked_list_add_after(list,66,2);
    double_linked_list_display_forward(list);
    double_linked_list_add_before(list,88,2);
    double_linked_list_display_forward(list);
    double_linked_list_delete_at_beginning(&list);
    double_linked_list_display_forward(list);
    double_linked_list_delete_at(&list,3);
    double_linked_list_display_forward(list);
    double_linked_list_delete_at(&list,0);
    double_linked_list_display_forward(list);
    printf("---------------------------------------\n");
    double_linked_list_reverse_list(&list);
    double_linked_list_display_forward(list);


    return 0;
}