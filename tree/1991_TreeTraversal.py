class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

    def push(self,head,parent,val1,val2):
        if head:
            if head.val==parent:
                if val1!='.':
                    head.left=TreeNode(val1)
                if val2!='.':
                    head.right=TreeNode(val2)
            else:
                head.left=self.push(head.left,parent,val1,val2)
                head.right=self.push(head.right,parent,val1,val2)
        
        return head

    def preorder(self,head):
        if head:
            print(head.val,end="")
            self.preorder(head.left)
            self.preorder(head.right)

    def inorder(self,head):
        if head:
            self.inorder(head.left)
            print(head.val,end="")
            self.inorder(head.right)

    def postorder(self,head):
        if head:
            self.postorder(head.left)
            self.postorder(head.right)
            print(head.val,end="")
                
        
head=TreeNode('A')
for _ in range(int(input())):
    p,c1,c2=input().split()
    head=head.push(head,p,c1,c2)

head.preorder(head); print()
head.inorder(head); print()
head.postorder(head); print()
