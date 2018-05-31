#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    nm = input().split()
    n = int(nm[0])
    m = int(nm[1])
    A = list(map(int, input().rstrip().split()))
    cc=[]
    for i in range(n+1):
        ctemp=[]
        for j in range(m+1):
            if(i==0 and j==0):
                ctemp.append(1)
                continue
            if(j==0):
                ctemp.append(0)
                continue
            if(i<A[j-1]):
                ctemp.append(ctemp[j-1])
                continue
            ctemp.append(cc[i-A[j-1]][j]+ctemp[j-1])
        cc.append(ctemp)
    print("Number of ways to form change is:",cc[n][m],end="")
