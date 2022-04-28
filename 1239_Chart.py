import itertools 
n,num=int(input()),list(map(int,input().split()))

def getChart(num):
    cnt=0
    pfix=[0 for _ in range(n)]
    for i in range(n):
        if i==0:
            pfix[i]=num[i]
        else:
            pfix[i]=num[i]+pfix[i-1]

    for i in range(n-1):
        for j in range(i+1,n):
            if pfix[i]+50==pfix[j]:
                cnt+=1
                break

    return cnt

ans=0
for arr in list(itertools.permutations(num)):
    ans=max(ans,getChart(arr))

print(ans)
