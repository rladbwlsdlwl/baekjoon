import heapq
# min heap to max heap

N = int(input())
snow = list(map(int, input().split()))

home = []
for i in range(N):
    heapq.heappush(home, -1*snow[i])

ans = 0
while home:
    ans += 1
    if len(home) > 1:
        node1, node2 = heapq.heappop(home), heapq.heappop(home)
        if node1 < -1:
            heapq.heappush(home, node1+1)
        if node2 < -1:
            heapq.heappush(home, node2+1)
    else:
        node1 = heapq.heappop(home)
        if node1 < -1:
            heapq.heappush(home, node1+1)

print(-1 if ans > 1440 else ans)
