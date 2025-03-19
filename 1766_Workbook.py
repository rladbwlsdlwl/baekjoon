import heapq
# min heap (ascending sort)

N, M = map(int,input().split())

graph = [[] for _ in range(N+1)]
indegree = [0 for _ in range(N+1)]

for _ in range(M):
    node1, node2 = map(int, input().split())

    # 선행 문제에 해당하는 node1을 풀었을 경우 node2의 차수를 줄임
    graph[node1].append(node2)
    # node2 선행 문제 수 기록
    indegree[node2] += 1


q = []
for i in range(1, N+1):
    if indegree[i] == 0:
        heapq.heappush(q, i)


ans = []
while len(ans) < N:
    p = heapq.heappop(q)
    
    ans.append(p)

    # p를 풀경우 p가 선행문제였던 child node의 차수를 줄임
    for child in graph[p]:
        indegree[child] -= 1
        if indegree[child] == 0:
            heapq.heappush(q, child)
    
print(*ans)
