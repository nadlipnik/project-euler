
#include "BinaryTree.hpp"
#include "BinaryTreeTemplate.hpp"

int main( int argc , char* argv[] )
{
    BinaryTree<int> my_tree(1);
    my_tree.AddChild(2);
    my_tree.AddChild(3);

    return 0;
}