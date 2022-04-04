for _ in range(int(input())):
    dp=[[0 for i in range(29)] for i in range(29)]
    for i in range(29):
        n=0
        for j in range(i,29):
            if i==0:
                dp[i][j]=j+1
            else:
                n+=dp[i-1][j-1]
                dp[i][j]=n
    n,m=map(int,input().split())
    print(dp[n-1][m-1])
