/**
 * @author : Ahmed Khaled Abdelmaksod
 * @brief  : Contains definitions for node class
 * @date   : 2 DEC 2023
 */
#include "node.h"
#include "stdlib.h"
node::node()
{
    this->data = 0;
    this->setLeft(NULL);
    this->setRight(NULL);
}
node::node(int data, node *left, node *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

node *node::getLeft()
{
    return this->left;
}
node *node::getRight()
{
    return this->right;
}
int node::getData()
{
    return this->data;
}
void node::setData(int data)
{
    this->data = data;
}
void node::setLeft(node *left)
{
    this->left = left;
}
void node::setRight(node *right)
{
    this->right = right;
}