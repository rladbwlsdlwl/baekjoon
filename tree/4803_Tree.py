import sys
input=sys.stdin.readline

def dfs_v(n):
    visited_v[n]=True
    vertex=1
    for i in range(len(graph[n])):
        next=graph[n][i]
        if not visited_v[next]:
            vertex+=dfs_v(next)

    return vertex

def dfs_e(n):
    visited_e[n]=True
    edge=len(graph[n])
    for i in range(len(graph[n])):
        next=graph[n][i]
        if not visited_e[next]:
            edge+=dfs_e(next)

    return edge
c=1
while(True):
    n,m=map(int,input().split())

    if n==m==0:
        break

    graph=[[] for _ in range(501)]
    visited_v=[False for _ in range(501)]
    visited_e=[False for _ in range(501)]

    for i in range(m):
        n1,n2=map(int,input().split())
        graph[n1].append(n2)
        graph[n2].append(n1)

    ans=0
    for n in range(1,n+1):
        if visited_v[n]:
            continue
        if(dfs_v(n)-1==dfs_e(n)//2):
            ans+=1

    print("Case "+str(c),end="")
    if ans>1:
        print(": A forest of "+str(ans)+" trees.")
    elif ans==1:
        print(": There is one tree.")
    else:
        print(": No trees.")
    
    c+=1
    
