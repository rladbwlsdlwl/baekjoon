import sys
input=sys.stdin.readline

N=int(input())

graph=[[] for _ in range(N+1)]
parent=[-1 for _ in range(N+1)]
visited=[False for _ in range(N+1)]

for _ in range(N-1):
    n1,n2=map(int,input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

stack=[1]

while stack:
    p=stack.pop()
    visited[p]=True

    for child in graph[p]:
        if visited[child]==False:
            parent[child]=p
            stack.append(child)


for i in range(2,N+1):
    print(parent[i])



