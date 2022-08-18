def dfs(n,k):
    if dp[n][k]>0:
        return dp[n][k]
    if n//2<k:
        return 0
    dp[n][k]=(dfs(n-1,k)+dfs(n-2,k-1))%1000000003

    return dp[n][k]

n,k=int(input()),int(input())

dp=[[0]*(k+1) for _ in range(n+1)]

for i in range(n+1):
    dp[i][1]=i


print(dfs(n,k))
