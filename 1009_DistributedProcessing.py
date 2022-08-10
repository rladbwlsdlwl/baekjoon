import sys
input=sys.stdin.readline

def init():
    dp=[[10]] # 10 은 항상 0이나옴
    for i in range(1,10):
        tmp=[]
        n=i
        while n not in tmp:
            tmp.append(n)
            n=int(str(n*i)[-1])

        dp.append(tmp)
    
    return dp

dp=init()
for _ in range(int(input())):
    mul, cnt=map(int,input().split())
    mul%=10
    col=cnt%len(dp[mul])

    print(dp[mul][col-1] if col else dp[mul][-1])

