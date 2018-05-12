#include<iostream>

using namespace std;

int main()
{
    int h[256]={0};
    string str1="gfngaa";
    string str2="nagfag";
    for(int i=0;i<str1.length();i++)
        h[str1[i]]+=1;
    for(int i=0;i<str2.length();i++)
        h[str2[i]]-=1;
    for(int i=0;i<256;i++)
    {
        if(h[i]!=0)
        {
            cout<<"Not anagram.";
            return 0;
        }
    }
    cout<<"Anagram.";
    return 0;
}
