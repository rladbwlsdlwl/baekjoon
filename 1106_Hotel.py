Customer, N = map(int, input().split())
dp = [0 for _ in range(100_001)] # 사용한 금액 별로 수용 가능한 최대 인원

for _ in range(N):
    coin, people = map(int, input().split())

    for i in range(coin, 100001):
        dp[i] = max(dp[i], dp[i-coin] + people)

ans = 0
for i in range(100_001):
    if dp[i] >= Customer:
        ans = i
        break

print(ans)
