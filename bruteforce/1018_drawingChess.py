import sys
input=sys.stdin.readline

class Solution:
    def __init__(self,chess=[]):
        self.chess=chess
        self.drawing=[]

    def fill_chess(self):
        m,n=map(int,input().split())

        for _ in range(m):
            self.chess.append(list(input()))
    
    def min_drawing_cnt(self):
        for r in range(len(self.chess)-8+1):
            for c in range(len(self.chess[0])-8+1):
                self.drawing.append(min(self.count_color('W',r,c), self.count_color('B',r,c)))

        return min(self.drawing)

    def count_color(self,color,row,col):
        cnt=0
        check=True if color=="W" else False

        for i in range(row,row+8):
            for j in range(col,col+8):
                if (check and color=="W" and self.chess[i][j]!="W") or (not check and color=="B" and self.chess[i][j]!="B"):
                    cnt+=1
                
                color="B" if color=="W" else "W"
                check=not check
            
            check=not check #바둑판 다음 기준으로 행 색이 바뀜
            color="B" if color=="W" else "W" #바둑판 다음 기준으로 행 색이 바뀜

        return cnt


s=Solution()
s.fill_chess()
print(s.min_drawing_cnt())

