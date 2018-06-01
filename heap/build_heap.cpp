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

bool max_heapify(int A[],int i,int n)
{
    if(i>=n/2)
        return true;
    if(n%2==0 && i==n/2-1)
    {
        if(A[i]<A[2*i+1])
            swap(A,i,2*i+1);
        return true;
    }
    if(A[i]>A[2*i+1] && A[i]>A[2*i+2])
        return true;
    int max_index=max(A,i);
    swap(A,i,max_index);
    return true && max_heapify(A,max_index,n);
}

bool build_heap(int A[],int i,int n)
{
    if(i<0)
        return true;
    max_heapify(A,i,n);
    return build_heap(A,i-1,n);
}

int main()
{
    int n=8;
    int A[10]={9,6,5,0,8,2,7,1,3};
    build_heap(A,n-1,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
