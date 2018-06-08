#include<iostream>
#include<vector>
#include<queue>

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

class qentry
{
    public:
    int level;
    node* root;
    qentry(node* root,int level)
    {
        this->level=level;
        this->root=root;
    }
};

void rightView(node *root)
{
   vector<int> V;
   if(!root)
        return;
    queue<qentry*> Q;
    qentry* new_node=new qentry(root,1);
    Q.push(new_node);
    while(!Q.empty())
    {
        qentry* now=Q.front();
        Q.pop();
        if(now->level>V.size())
            V.push_back(now->root->data);
        else
            V[now->level-1]=now->root->data;
        if(now->root->left)
        {
            qentry* new_left=new qentry(now->root->left,now->level+1);
            Q.push(new_left);
        }
        if(now->root->right)
        {
            qentry* new_right=new qentry(now->root->right,now->level+1);
            Q.push(new_right);
        }
    }
    for(int i=0;i<V.size();i++)
        cout<<V[i]<<" ";
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100,101,102};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    rightView(root);
    return 0;
}
