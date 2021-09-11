import sys
input=sys.stdin.readline

class Solution:
    def __init__(self):
        self.n=0
        self.m=0
        self.numArray=[]
        self.show=[]

    def putValue(self):            
        N,M=map(int,input().split())
        self.n,self.m=N,M
        self.numArray=[i+1 for i in range(N)]
        
    def getValue(self):
        self.dfs(0,self.m)

    def dfs(self,n,m):
        if m==0:
            print(*self.show, end=" ")
            print()
        else:
            for i in range(n,self.n):
                self.show.append(self.numArray[i])
                self.dfs(i+1,m-1)
                self.show.pop()


s=Solution()
s.putValue()
s.getValue()
