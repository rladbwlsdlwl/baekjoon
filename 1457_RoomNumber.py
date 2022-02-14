N=input()
def getNumber(n):
    dp=[0 for _ in range(10)]
    for num in n:
        dp[int(num)]+=1
    
    dp[6]=(dp[6]+dp[9])//2+(dp[6]+dp[9])%2

    return max(dp[:9])

print(getNumber(N))
