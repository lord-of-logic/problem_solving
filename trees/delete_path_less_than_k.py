class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def removePath(root,k):
    if(root==None):
        return True
    if(k<=0):
        return True
    if(root.left==None and root.right==None):
        return False
    leftPath=True
    leftPath=removePath(root.left,k-1)
    
    rightPath=True
    rightPath=removePath(root.right,k-1)
    if(leftPath==False and rightPath==False):
        return False
    if(leftPath==False):
        root.left=None
    if(rightPath==False):
        root.right=None
    return leftPath and rightPath

def inorder(root):
    if root==None:
        return 0
    inorder(root.left)
    print(root.data," ",end="")
    inorder(root.right)
    
def preorder(root):
    if root==None:
        return 0
    print(root.data," ",end="")
    preorder(root.left)
    preorder(root.right)
    
root=None
root=node(2)
root.left=node(6)
root.right=node(3)
root.left.left=node(9)
root.left.right=node(1)
root.left.left.left=node(5)
root.left.left.right=node(7)
root.left.right.right=node(8)
root.left.left.left.left=node(4)
root.left.right.right.right=node(10)
root.left.right.right.right.right=node(20)
k=5
removePath(root,k)
print("Inorder of processed tree: ",end="")
inorder(root)
print()
print("Preorder of processed tree: ",end="")
preorder(root)
