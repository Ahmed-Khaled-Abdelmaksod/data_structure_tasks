/**
 * @author : Ahmed Khaled Abdelmaksod
 * @brief  : Contains Test for BST class
 * @date   : 2 DEC 2023
 */

#include <iostream>
#include "BST.h"
#include "node.h"
using namespace std;

int main(void)
{
    node *root = new node(25, NULL, NULL);
    BST tree(root);
    tree.insert(5);
    tree.insert(27);
    tree.insert(29);
    tree.insert(7);
    tree.insert(4);
    tree.insert(26);
    cout << "In-order phase : ";
    tree.print_in_order(root);
    cout << endl;
    cout << "pre-order phase : ";
    tree.print_pre_order(root);
    cout << endl;
    cout << "post-order phase : ";
    tree.print_post_order(root);
    cout << endl
         << "TREE Height : " << tree.BST_height(root) << endl;
    cout << "Size : " << tree.getSize(root) << endl;
    node *found_node = tree.search(27);
    if (found_node != NULL)
    {
        cout << "found : " << found_node->getData() << endl;
    }
    else
    {
        cout << "Not found\n";
    }

    node *not_found_node = tree.search(55);
    if (not_found_node != NULL)
    {
        cout << "found : " << found_node->getData() << endl;
    }
    else
    {
        cout << "55 Not found\n";
    }

    node *min_node = tree.min_node();
    cout << "MIN : " << min_node->getData() << endl;

    node *max_node = tree.max_node();
    cout << "MAX : " << max_node->getData() << endl;

    // test remove
    cout << "In-order phase : ";
    tree.print_in_order(root);
    cout << endl;

    node *deleted = NULL;
    deleted = tree.remove(29);
    if (deleted != NULL)
    {
        cout << deleted->getData() << " is deleted !!\n";
    }
    cout << "In-order phase : ";
    tree.print_in_order(root);
    cout << endl;
    delete deleted;

    deleted = tree.remove(5);
    if (deleted != NULL)
    {
        cout << deleted->getData() << " is deleted !!\n";
    }
    cout << "In-order phase : ";
    tree.print_in_order(root);
    cout << endl;
    delete deleted;
    tree.delete_tree();
    cout << "root garbage value : " << root->getData() << "\tso : ";
    cout << "tree destroyed sucessfully !!\n";

    return 0;
}