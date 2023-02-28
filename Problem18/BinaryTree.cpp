#include "BinaryTree.h"

BinaryTree::BinaryTree():
{
    // pass
}

BinaryTree::~BinaryTree()
{
    destroy_tree();
}

void BinaryTree::destroy_tree(void)
{
    destroy_tree(root);
}

void BinaryTree::destroy_tree(node* leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int value, node* leaf)
{
    if (value < leaf->value)
    {
        if (leaf->left != NULL)
        {
            insert(value, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left = NULL; // set the child to NULL
            leaf->right = NULL; // set the child to NULL
        }
    }
    else if (value >= leaf->value)
    {
        if (leaf->right != NULL)
        {
            insert(value, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->left = NULL; // set the child to NULL
            leaf->right = NULL; // set the child to NULL
        }
    }
}