#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>

template <class T> class BinaryTree
{
public:
    BinaryTree() {}
    BinaryTree(const T& value) {this->value = value;}

    virtual ~BinaryTree() {}

    void AddChild(const T& child) {this->children.push_back(BinaryTree (child));}
    void RemoveChild(const T& child)
    {
        for( int i = 0; i < this->children.size(); i++)
        {
            if( this->children[i] == child)
            {
                this.children.erase(this->children.begin+i);
                return;
            }
        }
    }

    void SetValue(int value) {this->value = value;}
    T& GetValue() {return this->value;}

    std::vector<BinaryTree>& GetChildren() {return this->children;}

    void Print();

private:
    T value;
    std::vector<BinaryTree> children;
};


#endif // __BINARYTREE_H__