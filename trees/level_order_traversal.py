import sys

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
    def levelOrder(self,root):
        #Write your code here
        queue=[]
        queue.append(root)
        while(len(queue)!=0):
            temp=queue[0]
            del queue[0]
            print (temp.data,"",end="")
            if(temp.left!=None):
                queue.append(temp.left)
            if(temp.right!=None):
                queue.append(temp.right)
            
T=[50,15,62,5,20,58,91,3,8,37,60,24,100,23]
myTree=Solution()
root=None
for i in range(len(T)):
    data=T[i]
    root=myTree.insert(root,data)
myTree.levelOrder(root)
