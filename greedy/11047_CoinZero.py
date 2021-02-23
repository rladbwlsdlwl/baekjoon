import sys
input=sys.stdin.readline

N,K=map(int,input().split())
table=[int(input()) for _ in range(N)]
coincnt=0

while(K):
    C=table.pop()
    coincnt+=K//C
    K=K%C

print(coincnt)
