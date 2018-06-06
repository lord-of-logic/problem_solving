#include<stdio.h>

void swap(char *str, int i,int j)
{
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}

int main()
{
    char str[]="ranjith";
    int str_len=7;
    int i=0,j=str_len-1;
    while(i<j)
    {
        swap(str,i,j);
        i++;
        j--;
    }
    printf(str);
    return 0;
}
