class Treenode:
    def __init__(self, val='', left=None, right=None):
        self.val=val
        self.left=left
        self.right=right


def preorder(root):
    if(root):
        print(root.val,end="")
        preorder(root.left)
        preorder(root.right)

def inorder(root):
    if(root):
        inorder(root.left)
        print(root.val,end="")
        inorder(root.right)

def postorder(root):
    if(root):
        postorder(root.left)
        postorder(root.right)
        print(root.val,end="")

        
root=Treenode()
tmp=[root]

for _ in range(int(input())):
    a,b,c=input().split()
    
    if(len(tmp)>1):
        for p in tmp:
            if(p.val==a):
                curr=p; break
        tmp.remove(curr)
    else:
        curr=tmp.pop()
    
    curr.val=a
    
    if(b!='.'):
        temp=Treenode(b); curr.left=temp; tmp.append(temp)
    if(c!='.'):
        temp=Treenode(c); curr.right=temp; tmp.append(temp)

    
preorder(root); print()
inorder(root); print()
postorder(root); print()

