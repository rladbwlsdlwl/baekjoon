import heapq # min heap 
import sys
input=sys.stdin.readline
INF=sys.maxsize

def dijkstra(s):
    global dp
    dp[s]=0
    heap=[]
    heapq.heappush(heap,(0,s))

    while heap:
        w,node=heapq.heappop(heap)
        
        if dp[node]<w: # if Enter 1->2 3, 1->2 5 Do not compare 
            continue 
        for end,wei in graph[node]:
            move=w+wei
            if dp[end]>move:
                dp[end]=move
                heapq.heappush(heap,(move,end))


# input

V,E=map(int,input().split())
start=int(input())
graph=[[] for _ in range(V+1)]

for _ in range(E):
    s,e,w=map(int,input().split())
    graph[s].append((e,w))


# execution
dp=[INF for _ in range(V+1)]
dijkstra(start)

# print
for val in dp[1:]:
    print("INF" if val==INF else val)

