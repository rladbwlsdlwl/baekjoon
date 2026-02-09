from collections import deque

N, M, R = map(int, input().split())


graph = [[] for _ in range(N+1)]

for _ in range(M):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

# BFS
# 너비 순으로, 노드 번호가 작은 순으로 방문
q = deque([R]) # node
visited = [True if i == R else False for i in range(N+1)]

ans = [0 for _ in range(N+1)]
cnt = 1
while q:
    node = q.popleft()


    ans[node] = cnt
    cnt += 1

    # 노드 정렬
    graph[node].sort()



    for child in graph[node]:
        if not visited[child]:
            visited[child] = True
            q.append(child)

print(*ans[1: ], sep='\n')
