#code

class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
        
def formBST(start,end,arr = []):
    mid=(start+end)//2
    root=None
    root=node(arr[mid])
    if(start<=mid-1):
        root.left=formBST(start,mid-1,arr)
    if(mid+1<=end):
        root.right=formBST(mid+1,end,arr)
    return root

def preorder(root):
    if root==None:
        return
    print(root.data,"",end="")
    preorder(root.left)
    preorder(root.right)

T=int(input())
for i in range(T):
    n=int(input())
    arr=[]
    arr=list(map(int, input().rstrip().split()))
    start=0
    end=len(arr)
    root=None
    root=formBST(start,end-1,arr)
    preorder(root)
    print("")
