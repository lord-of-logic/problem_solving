#include<iostream>
#include<vector>

using namespace std;

int mini(int a,int b)
{
    return a<b?a:b;
}

int long_inc_sub(int A[],int n,vector<int>& B)
{
    for(int i=0;i<n;i++)
    {
        int max_len=1;
        for(int j=0;j<i;j++)
            if(A[i]>A[j])
                if(max_len<1+B[j])
                    max_len=1+B[j];
        B.push_back(max_len);
    }
    return 0;
}

int long_dec_sub(int A[],int n,vector<int>& B)
{
    for(int i=n-1;i>=0;i--)
    {
        int max_len=1;
        for(int j=n-1;j>i;j--)
            if(A[j]<A[i])
                if(max_len<1+B[j])
                    max_len=1+B[j];
        B[i]=max_len;
    }
    return 0;
}

int main()
{
    int A[]={10,15,16,9,4,3,11,1};
    int n=8;
    vector<int> inc_len,dec_len(n,0);
    long_inc_sub(A,n,inc_len);
    long_dec_sub(A,n,dec_len);
    int max_size=0;
    int top_index=0;
    for(int i=0;i<n;i++)
    {
        int min=mini(inc_len[i],dec_len[i]);
        if(max_size<2*(min-1)+1)
        {
            max_size=2*(min-1)+1;
            top_index=i;
        }
    }
    cout<<"The maximum number of elements in the hill are: "<<max_size<<"\n";
    cout<<"The top of the hill is: "<<A[top_index]<<"\n";

    //Left hill sequence
    int inc_index=inc_len[top_index]-1;
    int left_num=(max_size-1)/2;
    vector<int> hill(max_size,0);
    for(int i=top_index-1;i>=0 && left_num>=0;i--)
        if(inc_len[i]==inc_index)
        {
            hill[left_num-1]=A[i];
            left_num--;
            inc_index--;
        }

    //middle element
    hill[(max_size-1)/2]=A[top_index];//middle element is top of hill.

    //Right hill sequence
    int right_num=(max_size-1)/2;
    int dec_index=dec_len[top_index]-1;
    for(int i=top_index+1,j=0;i<n && j<=right_num;i++,j++)
        if(dec_len[i]==dec_index)
        {
            hill[(max_size-1)/2+1+j]=A[i];//The index is left hill elements + middle element + actual index
            dec_index--;
        }

    cout<<"The elements of the hill are: ";
    for(int i=0;i<hill.size();i++)
        cout<<hill[i]<<" ";
    return 0;
}
