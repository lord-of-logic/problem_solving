#include<iostream>
#include<vector>

using namespace std;

class node
{
public:
    char data;
    node *left;
    node*right;
    node(char a)
    {
        this->data=a;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void postorder(node* root)
{
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root=new node('a');
    root->left=new node('b');
    root->right=new node('c');
    root->left->left=new node('d');
    root->left->right=new node('e');
    root->right->left=new node('f');
    root->right->right=new node('g');
    cout<<"Post-order traversal of given binary tree is: ";
    postorder(root);
    return 0;
}
