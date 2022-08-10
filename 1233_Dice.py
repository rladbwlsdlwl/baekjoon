dp=[0 for _ in range(81)]

a,b,c=map(int,input().split())
for i in range(1,a+1):
    for j in range(1,b+1):
        for k in range(1,c+1):
            dp[i+j+k]+=1

print(dp.index(max(dp)))
