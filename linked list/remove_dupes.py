class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next
    def removeDuplicates(self,head):
        #Write your code here
        if(head==None):
            return head
        temp_head=head
        head2=head
        temp_head=temp_head.next
        while(temp_head):
            if(head2.data==temp_head.data):
                temp_head=temp_head.next
                continue
            else:
                head2.next=temp_head
                head2=head2.next
                temp_head=temp_head.next
        head2.next=None
        return head
        
mylist= Solution()
T=[1,1,2,2,3,3,2,2,4,4]
head=None
for i in range(len(T)):
    data=T[i]
    head=mylist.insert(head,data)    
head=mylist.removeDuplicates(head)
mylist.display(head); 
