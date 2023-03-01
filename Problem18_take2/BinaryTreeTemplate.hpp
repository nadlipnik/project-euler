#ifndef __BINARYTREE_TEMPLATE_H__
#define __BINARYTREE_TEMPLATE_H__

#include <vector>
#include <iostream>

template <class T> class BinaryTreeTemplate
{
public:
    BinaryTreeTemplate() {}
    BinaryTreeTemplate(const T& value) {this->value = value;}

    virtual ~BinaryTreeTemplate() {}

    void AddChild(const T& child) {this->children.push_back(BinaryTreeTemplate (child));}
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

    std::vector<BinaryTreeTemplate>& GetChildren() {return this->children;}

    void Print();

private:
    T value;
    std::vector<BinaryTreeTemplate> children;
};

#endif // __BINARYTREE_TEMPLATE_H__