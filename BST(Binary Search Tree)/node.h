/**
 * @author : Ahmed Khaled Abdelmaksod
 * @brief  : Contains declerations for node class
 * @date   : 2 DEC 2023
 */

#ifndef _NODE_H_
#define _NODE_H_
class node
{
private:
    int data;
    node *right;
    node *left;

public:
    node();
    node(int data, node *left, node *right);

    node *getLeft();
    node *getRight();
    int getData();
    void setData(int data);
    void setLeft(node *left);
    void setRight(node *right);
};
#endif