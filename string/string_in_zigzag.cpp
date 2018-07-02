#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string str="ravindrababuravula";
    int k=3;
    vector<string> S(k,"");
    int temp=0;
    int flag=0;
    for(int i=0;i<str.length();i++)
    {
        S[temp]+=str[i];
        if(flag==0)
        {
            temp++;
            if(temp==k-1)
                flag=1;
            continue;
        }
        if(flag==1)
        {
            temp--;
            if(temp==0)
                flag=0;
        }
    }
    for(int i=0;i<S.size();i++)
        cout<<S[i];
    cout<<"\n";
    for(int i=0;i<S.size();i++)
    {
        for(int z=0;z<i;z++)
            cout<<" ";
        for(int j=0;j<S[i].length();j++)
        {
            cout<<S[i][j];
            for(int z=0;z<k-i;z++)
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
//r   n
// a i d a
//  v   r
