import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, Q = map(int,input().split())
water=list(map(int,input().split()))

graph=[[] for _ in range(N+1)]


def dfs(n):
    visited[n]=True

    connected.append(n)
    cnt=1 if water[n-1] else -1

    for child in graph[n]:
        if not visited[child]:
            cnt+=dfs(child)


    return cnt


for _ in range(M):
    node1, node2 = map(int,input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

dp=[0 for _ in range(N+1)]
visited=[False for _ in range(N+1)]

for _ in range(Q):
    node=int(input())

    if not visited[node]:
        connected=[]
        dp[node]=1 if dfs(node)>0 else 0
        
        for i in range(1, len(connected)):
            dp[connected[i]]=dp[node]

    
    print(dp[node])
