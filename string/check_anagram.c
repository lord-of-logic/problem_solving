#include<stdio.h>

int main()
{
    int h[256]={0};
    char str1[]="g ngaa";
    int str1_len=6;
    char str2[]="nag ag";
    int str2_len=6;
    int i=0;
    for(i=0;i<str1_len;i++)
        h[str1[i]-'\0']+=1;
    for(i=0;i<str2_len;i++)
        h[str2[i]-'\0']-=1;
    for(i=0;i<256;i++)
    {
        if(h[i]!=0)
        {
            printf("Not anagram.");
            return 0;
        }
    }
    printf("Anagram.");
    return 0;
}
