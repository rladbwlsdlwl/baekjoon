# Shortest Path
# dijkstra
import heapq # min heap
import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
graph = [[] for _ in range(N)]
reversedGraph = [[] for _ in range(N)]

INF = 10000000
def dijkstra(graph, start):
    hq = []
    heapq.heappush(hq, (0, start)) # distance, node

    distance = [INF for _ in range(N)]
    distance[start] = 0
    while hq:
        cost, node = heapq.heappop(hq)
         
        if distance[node] < cost:
            continue

        for conn_node, conn_cost in graph[node]:
            if distance[conn_node] > distance[node] + conn_cost:
                distance[conn_node] = cost + conn_cost
                heapq.heappush(hq, (distance[conn_node], conn_node))

    for i in range(N):
        dp[i] += distance[i]

for _ in range(M):
    node1, node2, cost = map(int, input().split())
    graph[node1 - 1].append((node2 - 1, cost)) # K -> 모든 노드의 최단경로
    reversedGraph[node2 - 1].append((node1 -1, cost)) # 모든노드 -> K의 최단경로를 위해 역순으로 그래프 생성

dp = [0 for _ in range(N)]
dijkstra(reversedGraph, K-1) # K에서 출발하는 역순그래프
dijkstra(graph, K-1) 

print(max(dp))
