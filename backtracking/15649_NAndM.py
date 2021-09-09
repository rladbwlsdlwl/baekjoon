import sys
input=sys.stdin.readline

class Solution:
    def __init__(self,n=0,m=0):
        self.n=n
        self.m=m
        self.temp=[] # 답 출력
        self.numList=[] # 자연수 리스트
        self.check=[]

    def get_init(self): # 사용자 입력 값으로 초기화
        self.n,self.m=map(int,input().split())
        self.numList=[i+1 for i in range(self.n)]
        self.check=[False for _ in range(self.n)]

    def answer(self):
        self.dfs(self.m)

    def dfs(self,m):
        if m==0:
            print(*self.temp, end=" ")
            print()
        else:
            for i in range(self.n):
                if self.check[i]:
                    continue
                self.check[i]=True
                self.temp.append(self.numList[i])
                self.dfs(m-1)
                self.check[i]=False
                self.temp.pop()


s=Solution()
s.get_init()
s.answer()


