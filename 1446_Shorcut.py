N, D = map(int, input().split())

cmd = []
for _ in range(N):
    start, end, sc = map(int, input().split())

    cmd.append((start, end, sc))

# 이전 최단 거리와 함께 누적 계산하기 위해 앞 경로부터 탐색
# 후 순위 경로부터 탐색하면 누적 계산 불가
cmd.sort(key = lambda x: (x[0], x[1]))


INF = 1_0000
dp = [i for i in range(INF + 1)]

for start, end, sc in cmd:
    if end > D: continue

    dp[end] = min(dp[end], dp[start] + sc)
    
    j = 0
    for i in range(end, D+1):
        dp[i] = min(dp[i], dp[end]+j)
        j += 1

print(dp[D])
