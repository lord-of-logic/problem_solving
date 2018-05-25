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

void inorder(node *head)
{
    if(!head)
        return;
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
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
    cout<<"In-order traversal of given binary tree is: ";
    inorder(root);
    return 0;
}
