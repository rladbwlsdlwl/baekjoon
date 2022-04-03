n,m,k=map(int,input().split())

def find_road(r1,c1,r2,c2):
    for i in range(r1,r2+1):
        for j in range(c1,c2+1):
            if i==0 or j==0:
                dp[i][j]=1
            else:
                dp[i][j]=dp[i-1][j]+dp[i][j-1]


dp=[[0 for _ in range(m)] for _ in range(n)]

if k==0:
    find_road(0,0,n-1,m-1)
else:
    if k%m==0:
        find_road(0,0,k//m-1,m-1)
        dp[n-1][m-1]=dp[k//m-1][m-1]
    else:
        find_road(0,0,k//m,k%m-1)
        find_road(k//m,k%m-1,n-1,m-1)

print(dp[n-1][m-1])
