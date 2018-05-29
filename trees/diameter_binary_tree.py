class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    def diameter(self,diam):
        def max(a,b):
            if(a>b):
                return a
            return b
        if(self.left==None and self.right==None):
            return 0
        if(self.left==None):
            right_height=1+self.right.diameter(diam)
            if(diam[0]<right_height):
                diam[0]=right_height
            return right_height
        if(self.right==None):
            left_height=1+self.left.diameter(diam)
            if(diam[0]<left_height):
                diam[0]=left_height
            return left_height
        left_height=1+self.left.diameter(diam)
        right_height=1+self.right.diameter(diam)
        if(diam[0]<left_height+right_height):
            diam[0]=left_height+right_height
        return max(left_height,right_height)

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
diam=[0]
root.diameter(diam)
print("Diameter of the tree is:",diam[0])
