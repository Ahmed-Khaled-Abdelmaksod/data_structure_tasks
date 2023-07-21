/**************************************************************
 * @author : Ahmed Khaled Abdelmaksod 
 * @date   : 21/7/2023
 * @brief  : it contains the test of linked list data structure
 **************************************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include<windows.h>
void menu(void);
int main(void)
{
    uint16_t choice = 0;
    node_t *list = NULL;
    while(1)
    {
        menu();
        scanf("%i",&choice);
        switch (choice)
        {
        case 1 :
            linked_list_insert_at_beginning(&list);
            break;
        
        case 2 :
            linked_list_insert_at_end(list);
            break;
        case 3 :
            linked_list_insert_at_middle(list);
            break;
        case 4 :
            linked_list_delete_at_beginning(&list);
            break;
        case 5 :
            linked_list_delete(&list);
            break;
        case 6 :
            printf("length : %i\n",linked_list_get_length(list));
            break;
        case 7 :
            linked_list_display(list);
            break;
            
        case 8 :
            exit(1);
            break;
        default:
            printf("wrong choice !!! \n");
            break;
        }
    }

    return 0;
}
void menu(void)
{
    Sleep(200);
    printf("\n------------------------------------------------\n");
    printf("1- linked_list_insert_at_beginning\n");
    printf("2- linked_list_insert_at_end\n");
    printf("3- linked_list_insert_at_middle\n");
    printf("4- linked_list_delete_at_beginning\n");
    printf("5- linked_list_delete\n");
    printf("6- linked_list_get_length\n");
    printf("7- linked_list_display\n");
    printf("8- Exit\n");
    printf("\n------------------------------------------------\n");
    
}