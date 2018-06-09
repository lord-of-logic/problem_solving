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

int levelOfNode(node* root,node *a,int level)
{
    if(!root)
        return 0;
    if(root->data==a->data)
        return level;
    return levelOfNode(root->left,a,level+1)+levelOfNode(root->right,a,level+1);
}

bool sameParent(node* root,node *a,node* b)
{
    if(!root || (!root->left && !root->right))
        return false;
    if(!root->left || !root->right)
            return false;
    if((root->left->data==a->data && root->right->data==b->data) || (root->left->data==b->data && root->right->data==a->data))
        return true;
    return sameParent(root->left,a,b) || sameParent(root->right,a,b);
}

bool ifCousin(node *root,node *a,node *b)
{
    if(!root)
        return false;
    if(!a || !b)
        return false;
    int a_level=levelOfNode(root,a,0);
    int b_level=levelOfNode(root,b,0);
    if(a_level!=b_level)
        return false;
    return !(sameParent(root,a,b));
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100,101,102};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    ifCousin(root,root->left->left,root->right->left)?cout<<"They are cousins.":cout<<"They are not cousins.";
    return 0;
}
