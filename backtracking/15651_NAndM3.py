import sys
input=sys.stdin.readline

class Solution:
    def __init__(self,n=0,m=0):
        self.n=n
        self.m=m
        self.numArray=[i+1 for i in range(n)]
        self.temp=[] # put answer

    def get_answer(self):
        self.dfs(self.m)

    def dfs(self,m):
        if m==0:
            print(*self.temp, end=" ")
            print()
        else:
            for i in range(self.n):
                self.temp.append(self.numArray[i])
                self.dfs(m-1)
                self.temp.pop()


N,M=map(int, input().split())

s=Solution(N,M)
s.get_answer()

