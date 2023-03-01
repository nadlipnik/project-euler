#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>
#include <iostream>

class BinaryTree
{
public:
    BinaryTree() {}
    BinaryTree(int value) {this->value = value;}

    virtual ~BinaryTree() {}

    void AddChild(int child) {this->children.push_back(BinaryTree (child));}
    void RemoveChild(int child)
    {
        for( int i = 0; i < this->children.size(); i++)
        {
            if( this->children[i].value == child)
            {
                this->children.erase(this->children.begin()+i);
                return;
            }
        }
    }

    void SetValue(int value) {this->value = value;}
    int GetValue() {return this->value;}

    std::vector<BinaryTree>& GetChildren() {return this->children;}

    void Print(int depth)
    {
        for ( int i = 0 ; i < depth ; ++i )
        {
            if ( i != depth-1 ) std::cout << "    ";
            else std::cout << "|-- ";
        }
        std::cout << this->value << std::endl;
        for ( uint i = 0 ; i < this->children.size() ; ++i )
        {
            this->children.at(i).Print( depth+1 );
        }
    }

private:
    int value;
    std::vector<BinaryTree> children;
};


#endif // __BINARYTREE_H__