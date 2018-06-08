#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void insert(node **root,int data)
{
    node *temp_root=*root;
    if(!temp_root)
    {
        temp_root=new node(data);
        *root=temp_root;
        return;
    }
    if(temp_root->data>data)
    {
        insert(&temp_root->left,data);
        return;
    }
    insert(&temp_root->right,data);
    return;
}

void leftview(node* root,int curr_level,int* max_level)
{
    if(!root)
        return;
    if(curr_level>*max_level)
    {
        cout<<root->data<<" ";
    }
    if(curr_level>*max_level)
        *max_level=curr_level;
    leftview(root->left,curr_level+1,max_level);
    leftview(root->right,curr_level+1,max_level);
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100,101,102};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    int* max_level=new int(0);
    leftview(root,1,max_level);
    return 0;
}
