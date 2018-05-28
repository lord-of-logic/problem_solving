class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    def getHeight(self,root):
        if(root==None):
            return -1
        leftHeight=self.getHeight(root.left)
        rightHeight=self.getHeight(root.right)
        if leftHeight<rightHeight:
            return 1+rightHeight
        else:
            return 1+leftHeight

T=[50,15,62,5,20,58,91,3,8,37,60,24,100,23]
myTree=Solution()
root=None
for i in range(len(T)):
    data=T[i]
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print(height)       
