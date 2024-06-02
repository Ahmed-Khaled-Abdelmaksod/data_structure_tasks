/**
 * @author : Ahmed Khaled Abdelmaksod
 * @brief  : Contains definitions for BST class
 * @date   : 3 DEC 2023
 */

#include "BST.h"

BST::BST()
{
    rootnode = new node();
}

BST::BST(int data)
{

    rootnode = new node(data, NULL, NULL);
}

BST::BST(node *root)
{
    rootnode = root;
}

void BST::print_in_order(node *root)
{
    if (root != NULL)
    {
        print_in_order(root->getLeft());
        cout << root->getData() << " ";
        print_in_order(root->getRight());
    }
}
void BST::print_pre_order(node *root)
{
    if (root != NULL)
    {
        cout << root->getData() << " ";
        print_pre_order(root->getLeft());
        print_pre_order(root->getRight());
    }
}
void BST::print_post_order(node *root)
{
    if (root != NULL)
    {
        print_post_order(root->getLeft());
        print_post_order(root->getRight());
        cout << root->getData() << " ";
    }
}
int BST::getSize(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return getSize(root->getLeft()) + getSize(root->getRight()) + 1;
}
int BST::BST_height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = BST_height(root->getLeft());
    int rightHeight = BST_height(root->getRight());
    return 1 + max(leftHeight, rightHeight);
}

bool BST::insert(int data)
{
    node *p = rootnode;
    if (rootnode == NULL)
    {
        rootnode = new node(data, NULL, NULL);
        return true;
    }
    else
    {
        int temp = 0;
        while (p != NULL)
        {
            temp = p->getData();
            if (temp == data) // don't insert
            {
                return false;
            }
            else if (data < temp)
            {
                if (p->getLeft() != NULL)
                {
                    p = p->getLeft();
                }
                else
                {
                    node *temp_node = new node(data, NULL, NULL);
                    p->setLeft(temp_node);
                    return true;
                }
            }
            else
            {
                if (p->getRight() != NULL)
                {
                    p = p->getRight();
                }
                else
                {
                    node *temp_node = new node(data, NULL, NULL);
                    p->setRight(temp_node);
                    return true;
                }
            }
        }
    }
    return false;
}

node *BST::search(int data)
{
    node *p = rootnode;
    int temp = 0;
    while (p != NULL)
    {
        temp = p->getData();
        if (temp == data)
        {
            return p;
        }
        else if (data < temp)
        {
            p = p->getLeft();
        }
        else
        {
            p = p->getRight();
        }
    }
    return p;
}
node *BST::min_node()
{
    node *p = rootnode;
    int temp = 0;
    node *min_node = NULL;
    if (rootnode != NULL)
    {
        min_node = rootnode;
    }
    else
    {
        return NULL;
    }
    while (p != NULL)
    {
        temp = p->getData();
        if (temp < min_node->getData())
        {
            min_node = p;
        }
        else
        {
            p = p->getLeft();
        }
    }
    return min_node;
}
node *BST::max_node()
{
    node *p = rootnode;
    int temp = 0;
    node *max_node = NULL;
    if (rootnode != NULL)
    {
        max_node = rootnode;
    }
    else
    {
        return NULL;
    }
    while (p != NULL)
    {
        temp = p->getData();
        if (temp > max_node->getData())
        {
            max_node = p;
        }
        else
        {
            p = p->getRight();
        }
    }
    return max_node;
}

node *BST::remove(int data)
{
    node *p = NULL;
    node *parent = NULL;
    char which_child = ' ';
    int temp = 0;
    if (rootnode == NULL)
    {
        return NULL;
    }
    p = rootnode;

    // find the node :
    while (p != NULL)
    {
        temp = p->getData();
        if (data == temp)
        {
            break;
        }
        else if (data < temp)
        {
            parent = p;
            p = p->getLeft();
            which_child = 'L';
        }
        else
        {
            parent = p;
            p = p->getRight();
            which_child = 'R';
        }
    }

    // if node are the leaf
    if ((p->getLeft() == NULL) && (p->getRight() == NULL))
    {
        if (parent != NULL)
        {

            if (which_child == 'L')
            {
                parent->setLeft(NULL);
            }
            else if (which_child == 'R')
            {
                parent->setRight(NULL);
            }
        }
        else // the node is the root
        {
            rootnode = NULL;
        }
        return p;
    }
    else if (p->getLeft() == NULL)
    {
        if (parent != NULL)
        {
            if (which_child == 'L')
            {
                parent->setLeft(p->getRight());
            }
            else if (which_child == 'R')
            {
                parent->setRight(p->getRight());
            }
        }
        else
        {
            rootnode = p->getRight();
        }
        return p;
    }
    else if (p->getRight() == NULL)
    {
        if (parent != NULL)
        {
            if (which_child == 'L')
            {
                parent->setLeft(p->getLeft());
            }
            else if (which_child == 'R')
            {
                parent->setRight(p->getLeft());
            }
        }
        else
        {
            rootnode = p->getLeft();
        }
        return p;
    }

    else
    {
        node *return_node = new node(*p);
        node *left_child = p->getLeft();
        if (left_child->getRight() == NULL)
        {
            p->setData(left_child->getData());
            p->setLeft(left_child->getLeft());
            delete left_child;
            return return_node;
        }
        node *max_left = left_child->getRight();
        node *parent2 = left_child;
        while (max_left != NULL)
        {
            parent2 = max_left;
            max_left = max_left->getRight();
        }
        p->setData(max_left->getData());
        if (max_left->getLeft() == NULL)
        {
            parent2->setRight(NULL);
        }
        else
        {
            parent2->setRight(max_left->getLeft());
        }
        delete max_left;
        return return_node;
    }
    return NULL;
}

void BST::delete_tree()
{
    if (rootnode != NULL)
    {
        destroy(rootnode);
        rootnode = NULL;
    }
    else
    {
    }
}
void BST::destroy(node *root)
{
    if (root != NULL)
    {
        destroy(root->getLeft());
        destroy(root->getRight());

        delete root;
    }
}
