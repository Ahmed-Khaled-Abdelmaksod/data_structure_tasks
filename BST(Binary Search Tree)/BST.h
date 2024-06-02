/**
 * @author : Ahmed Khaled Abdelmaksod
 * @brief  : Contains declerations for BST class
 * @date   : 2 DEC 2023
 */

#ifndef _BST_H_
#define _BST_H_

#include "node.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
class BST
{
private:
    node *rootnode;
    void destroy(node *root);

public:
    // Constractor to add new tree without any node (size = 0);
    BST();
    // Constractor to add new tree with root node (size = 1);
    BST(int data);
    // constractor to add node directly to the tree
    BST(node *root);
    // traverse BST methods
    void print_in_order(node *root);
    void print_pre_order(node *root);
    void print_post_order(node *root);

    int getSize(node *root);
    // height of the tree
    int BST_height(node *root);

    // insert new node
    bool insert(int data);
    // algorithms to remove and search for a node
    node *remove(int data);
    node *search(int data);
    // get min & max nodes
    node *min_node();
    node *max_node();
    // destroy nodes and trees
    void delete_tree();
};
#endif