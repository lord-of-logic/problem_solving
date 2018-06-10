T=int(input())
for t in range(T):
    str=input()
    max_palin=""
    max_palin_len=0
    V=[[0 for i in range(len(str))] for j in range(len(str))]
    for fill in range(len(str)):
        for i,j in zip(range(len(str)),range(fill,len(str))):
            if(i==j):
                V[i][j]=1
                if(max_palin_len<j-i+1):
                    max_palin_len=j-i+1
                    max_palin=str[i:j+1]
                continue
            if(str[i]!=str[j]):
                V[i][j]=0
                continue
            if(j-i==1):
                V[i][j]=2
                if(max_palin_len<j-i+1):
                    max_palin_len=j-i+1
                    max_palin=str[i:j+1]
                continue
            if(V[i+1][j-1]==0):
                V[i][j]=0
                continue
            V[i][j]=2+V[i+1][j-1]
            if(max_palin_len<j-i+1):
                max_palin_len=j-i+1
                max_palin=str[i:j+1]
    print(max_palin)
#T(n)=O(n^2)
#S(n)=O(n^2)
