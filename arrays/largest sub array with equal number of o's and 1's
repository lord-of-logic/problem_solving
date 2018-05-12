#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    map<int,int> M;
    string str="111110001110";
    vector<int> cum;
    int c=0,max=0;
    int first=0,last=0;
    if(str[0]==0)
        cum.push_back(-1);
    else
        cum.push_back(1);
    for(int i=1;i<str.length();i++)
    {
        int n=cum.size();
        if(str[i]=='1')
            cum.push_back(cum[n-1]+1);
        else
            cum.push_back(cum[n-1]-1);
    }
    for(int i=0;i<cum.size();i++)
    {
        if(!M.count(cum[i]))
            M[cum[i]]=i;
        else
        {
            int temp=i-M[cum[i]];
            if(temp>max)
            {
                first=M[cum[i]]+1;
                last=i;
                max=temp;
            }
        }
    }
    cout<<"Starting index: "<<first<<"\n";
    cout<<"Ending index: "<<last<<"\n";
    cout<<"Size of sub array: "<<max<<"\n";
    return 0;
}
