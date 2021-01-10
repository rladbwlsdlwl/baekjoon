import math
import sys
input=sys.stdin.readline

N=int(input())
team=list(list(map(int,input().split())) for _ in range(N))

def dfs(n,cnt):
    global ability
    if(cnt==N//2):
        a,b=0,0

        for i in range(N):
            for j in range(N):
                if(result[i] and result[j]):
                    a+=team[i][j]
                elif(not result[i] and not result[j]):
                    b+=team[i][j]
                    
        ability=min(ability,abs(a-b))
    else:
        for i in range(n,N):
            result[i]=1
            dfs(i+1,cnt+1)
            result[i]=0

result=[1]+[0 for _ in range(N-1)] # figure out N//2 (대 칭)
ability=math.inf
dfs(1,1)
print(ability)


