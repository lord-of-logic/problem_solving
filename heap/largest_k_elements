#include<iostream>

using namespace std;

int swap(int A[],int i,int j)
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
    return 0;
}

int max(int A[],int i)
{
    return A[2*i+1]>A[2*i+2]?2*i+1:2*i+2;
}

bool max_heapify(int A[],int i,int *heap_size)
{
    if(i>=*heap_size/2)
        return true;
    if(*heap_size%2==0 && i==*heap_size/2-1)
    {
        if(A[i]<A[2*i+1])
            swap(A,i,2*i+1);
        return true;
    }
    if(A[i]>A[2*i+1] && A[i]>A[2*i+2])
        return true;
    int max_index=max(A,i);
    swap(A,i,max_index);
    return true && max_heapify(A,max_index,heap_size);
}

bool build_max_heap(int A[],int i,int *heap_size)
{
    if(i<0)
        return true;
    max_heapify(A,i,heap_size);
    return build_max_heap(A,i-1,heap_size);
}

int delete_max(int A[],int n,int *heap_size)
{
    int max=A[0];
    A[0]=A[*heap_size-1];
    max_heapify(A,0,heap_size);
    *heap_size-=1;
    return max;
}

int main()
{
    int n=9;
    int k=4;
    int A[9]={9,6,5,0,8,2,7,1,3};
    int *heap_size=new int;
    *heap_size=n;
    build_max_heap(A,n-1,heap_size);
    cout<<"The heap is: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\nThe largest "<<k<<" elements are: ";
    for(int i=0;i<k;i++)
        cout<<delete_max(A,n,heap_size)<<" ";
    return 0;
}
