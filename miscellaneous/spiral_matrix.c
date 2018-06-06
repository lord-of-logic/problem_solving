#include <stdio.h>

int main() {
	//code
	int T;
	scanf("%d",&T);
	while(T)
	{
	    int A[4][4],i,j;
	    int n=4;
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	            scanf("%d",&A[i][j]);
	    int k=0;
	    for(k=0;k<n/2;k++)
	    {
	        for(i=k,j=k;j<n-k;j++)
	            printf("%d ",A[i][j]);
	        for(i=k+1,j=n-k-1;i<n-k;i++)
	            printf("%d ",A[i][j]);
	        for(i=n-k-1,j=n-k-2;j>=k;j--)
	            printf("%d ",A[i][j]);
	        for(i=n-k-2,j=k;i>=k+1;i--)
	            printf("%d ",A[i][j]);
	    }
	    printf("\n");
	    T--;
	}
	return 0;
}
