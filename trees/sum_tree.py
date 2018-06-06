#check if root.data==sum of left subtree data + sum of right subtree data
class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def isSumTree(root):
    if(root==None):
        return 0
    if(root.left==None and root.right==None):
        return root.data
    if(isSumTree(root.left) and isSumTree(root.right)):
        if(root.data==isSumTree(root.left)+isSumTree(root.right)):
            return 2*root.data
        return False
    return False

root=None
root=node(10)
root.left=node(3)
root.right=node(4)
root.left.left=node(1)
root.left.right=node(2)
if isSumTree(root):
    print("It is a sum tree.")
else:
    print("It is not a sum tree.")
