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

void printSpiral(node *root)
{
    if(!root)
        return;
    stack<node *> S1;
    stack<node *> S2;
    S1.push(root);
    int level=0;
    while(!(S1.empty() && S2.empty()))
    {
        while(!S1.empty())
        {
            node* now=S1.top();
            S1.pop();
            cout<<now->data<<" ";
            if(now->right)
                S2.push(now->right);
            if(now->left)
                S2.push(now->left);
        }
        while(!S2.empty())
        {
            node* now=S2.top();
            S2.pop();
            cout<<now->data<<" ";
            if(now->left)
                S1.push(now->left);
            if(now->right)
                S1.push(now->right);
        }
    }
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    printSpiral(root);
    return 0;
}
