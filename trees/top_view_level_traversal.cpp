#include<iostream>
#include<vector>
#include<queue>
#include<map>

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
    node* root;
    int hd;
    qentry(node*root,int hd)
    {
        this->root=root;
        this->hd=hd;
    }
};

void topView(struct node *root)
{
    queue<qentry *> Q;
    map<int,int> M;
    if(!root)
        return;
    qentry* new_root=new qentry(root,0);
    Q.push(new_root);
    while(!Q.empty())
    {
        qentry* now=Q.front();
        Q.pop();
        if(M.find(now->hd)==M.end())
        {
            M[now->hd]=now->root->data;
            cout<<now->root->data<<" ";
        }
        if(now->root->left)
        {
            qentry* new_left=new qentry(now->root->left,(now->hd)-1);
            Q.push(new_left);
        }
        if(now->root->right)
        {
            qentry* new_right=new qentry(now->root->right,(now->hd)+1);
            Q.push(new_right);
        }
    }
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    topView(root);
    return 0;
}
