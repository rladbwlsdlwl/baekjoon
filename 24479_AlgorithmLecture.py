import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N, M, R = map(int, input().split())

graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]

for _ in range(M):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)


for i in range(N+1):
    graph[i].sort()

order = 1
def dfs(R):
    global order
    visited[R] = True
    ans[R] = order

    order += 1

    for child in graph[R]:
        if not visited[child]:
            dfs(child)

ans = [0 for _ in range(N+1)]
dfs(R)

print(*ans[1:], sep="\n")
