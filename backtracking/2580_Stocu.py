import sys
input=sys.stdin.readline

class Solution:
    def __init__(self,stocu):
        self.stocu=stocu
        self.stop=False

    def find_blank(self):
        for i in range(9):
            for j in range(9):
                if self.stocu[i][j]==0:
                    return (i,j)

        return (-1,-1)

    def find_number(self,x,y):
        arr1=[i for i in self.stocu[x]]
        arr2=[self.stocu[i][y] for i in range(9)]
        arr3=[]
        for i in range(3*(x//3),3*(x//3)+3):
            arr3.extend(self.stocu[i][3*(y//3):3*(y//3)+3])

        arr=set(arr1+arr2+arr3)
        result=[i for i in range(1,10) if i not in arr]
        
        return result

    def dfs(self):
        x,y=self.find_blank()
        if x==y==-1:
            self.stop=True

            for i in range(9):
                for j in range(9):
                    print(self.stocu[i][j],end=" ")
                print()
            
            return
        else:
            for i in self.find_number(x,y):
                if self.stop:
                    break
                self.stocu[x][y]=i
                self.dfs()
            
            self.stocu[x][y]=0

stocu=[list(map(int,input().split())) for _ in range(9)]
s=Solution(stocu)
s.dfs()
