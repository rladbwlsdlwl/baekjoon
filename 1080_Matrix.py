import sys
input=sys.stdin.readline

def reverse_(i,j):
    for p in range(i,i+3):
        for q in range(j,j+3):
            start[p][q]=0 if start[p][q] else 1

N,M=map(int,input().split())
start=[list(map(int,input().strip())) for _ in range(N)]
goal=[list(map(int,input().strip())) for _ in range(N)]

cnt=0
for i in range(N-2):
    for j in range(M-2):
        if start[i][j]!=goal[i][j]:
            reverse_(i,j)
            cnt+=1

print(-1 if start!=goal else cnt)
