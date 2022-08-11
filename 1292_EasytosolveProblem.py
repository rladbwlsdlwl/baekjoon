pSum=[0]
n=1
while(len(pSum)<=1000):
    top=pSum[-1]
    for i in range(1,n+1):
        pSum.append(n*i+top)
    n+=1

a,b=map(int,input().split())
print(pSum[b]-pSum[a-1])

