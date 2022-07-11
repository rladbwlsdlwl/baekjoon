from collections import deque

N,K=map(int,input().split())

cup=deque(); cnt=1
while N:
    if N%2:
        cup.append(cnt)
    N=N//2
    cnt*=2


ans=0
while len(cup)>K:
    ans+=cup[0]
    cup[0]*=2

    while len(cup)>1 and cup[0]==cup[1]:
        cup.popleft()
        cup[0]*=2

print(ans)
