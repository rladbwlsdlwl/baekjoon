N, K = map(int, input().split())
coin = [int(input()) for _ in range(N)]

INF = 100000
dp = [INF for _ in range(K+1)]

dp[0] = 0
for i in range(1, K+1):
    for j in range(N):
        if i-coin[j] >= 0:
            dp[i] = min(dp[i], dp[i - coin[j]] + 1)

print(-1 if dp[K] == INF else dp[K])
