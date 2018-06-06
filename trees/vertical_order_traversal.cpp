#include<iostream>
#include<vector>

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

class sll_node
{
    public:
    int data;
    sll_node* next;
    sll_node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class dll_node
{
    public:
    int hd;
    dll_node* left;
    dll_node* right;
    sll_node* next;
    dll_node(int hd)
    {
        this->hd=hd;
        this->left=nullptr;
        this->right=nullptr;
        this->next=nullptr;
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

void verticalorder(node *root,dll_node *head,int hd)
{
    if(!head->next)
        head->next=new sll_node(root->data);
    else
    {
        if(head->next->data>root->data)
        {
            sll_node *new_node=new sll_node(root->data);
            new_node->next=head->next;
            head->next=new_node;
        }
        else
        {
            sll_node* sll_temp=head->next;
            while(sll_temp->next && sll_temp->next->data<root->data)
                sll_temp=sll_temp->next;
            sll_node *new_node=new sll_node(root->data);
            new_node->next=sll_temp->next;
            sll_temp->next=new_node;
        }
    }
    if(root->left)
    {
        if(!head->left)
        {
            dll_node* dll_temp=new dll_node(hd-1);
            head->left=dll_temp;
            dll_temp->right=head;
        }
        verticalorder(root->left,head->left,hd-1);
    }
    if(root->right)
    {
        if(!head->right)
        {
            dll_node* dll_temp=new dll_node(hd+1);
            head->right=dll_temp;
            dll_temp->left=head;
        }
        verticalorder(root->right,head->right,hd+1);
    }
    return;
}

void printvertical(dll_node* head)
{
    while(head->left)
        head=head->left;
    while(head)
    {
        sll_node* sll_temp=head->next;
        while(sll_temp)
        {
            cout<<sll_temp->data<<" ";
            sll_temp=sll_temp->next;
        }
        cout<<"$";
        head=head->right;
    }
}

int main()
{
    node *root=nullptr;
    vector<int> A={50,15,62,5,20,58,91,3,8,37,60,24,100};
    for(int i=0;i<A.size();i++)
        insert(&root,A[i]);
    dll_node* head = new dll_node(0);
    verticalorder(root,head,0);
    printvertical(head);
    return 0;
}
