

struct node
{
    int value;
    node* left;
    node* right;
}

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    
    void destroy_tree(void);
    void insert(int value);
private:
    void destroy_tree(node* leaf);
    void insert(int value, node* leaf);
    node* root;
};