
#include "BinaryTree.hpp"
#include "BinaryTreeTemplate.hpp"

int main( int argc , char* argv[] )
{
    BinaryTree my_tree(1);
    my_tree.AddChild(2);
    my_tree.AddChild(3);

    //my_tree.Print(1);
    //std::cout << std::endl;

    my_tree.GetChildren()[1].AddChild(4);
    my_tree.GetChildren()[1].AddChild(5);

    //my_tree.Print(1);
    //std::cout << std::endl;

    my_tree.GetChildren()[1].GetChildren()[0].AddChild(6);

    my_tree.Print(1);
    std::cout << std::endl;


    BinaryTreeTemplate my_tree_template(10);

    my_tree_template.AddChild(11);
    my_tree_template.AddChild(12);
    my_tree_template.AddChild(13);

    my_tree_template.GetChildren()[1].AddChild(14);
    my_tree_template.GetChildren()[1].AddChild(15);

    my_tree_template.GetChildren()[1].GetChildren()[0].AddChild(16);

    my_tree_template.Print(1);

    return 0;
}