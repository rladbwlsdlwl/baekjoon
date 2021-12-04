import sys
input=sys.stdin.readline

class Solution:
    def __init__(self):
        self.n=0
        self.inorder=[]
        self.postorder=[]
        self.index=[0 for _ in range(100001)]

    def input(self):
        self.n=int(input())
        self.inorder=list(map(int,input().split()))
        self.postorder=list(map(int,input().split()))

    def answer(self):
        for i,num in enumerate(self.inorder):
            self.index[num]=i
        
        self.dfs()

    def dfs(self): 
        stack=[(0,self.n-1,0,self.n-1)] # (inleft, inright, postleft, postright)
        while len(stack): 
            p=stack.pop() 
            inleft, inright, postleft, postright=p[0],p[1],p[2],p[3]
            if inleft>inright or postleft>postright:
                continue

            root=self.postorder[postright]
            leftsize=self.index[root]-inleft
            print(root,end=" ")

            stack.append((self.index[root]+1,inright,postleft+leftsize,postright-1)) # right node push 
            stack.append((inleft,self.index[root]-1,postleft,postleft+leftsize-1)) # left node push          
            # inleft,inright는 index이용 / postleft, postright는 leftsize이용 
s=Solution()
s.input()
s.answer()
