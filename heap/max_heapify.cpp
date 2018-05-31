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
    return max_heapify(A,max_index,n);
}

int main()
{
    int n=10;
    int A[10]={1,14,10,8,7,9,3,2,4,6};
    max_heapify(A,0,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
