import math
from itertools import combinations

N,M=map(int,input().split())
chicken,home=[],[]

for i in range(N):
    city=list(map(int,input().split()))
    for j in range(N):
        if(city[j]==1):
            home.append([i,j])
        elif(city[j]==2):
            chicken.append([i,j])

distance=math.inf
for ch in combinations(chicken,M):
    dis=0
    for i,j in home:
        ans=math.inf
        for p,q in ch:
            ans=min(ans,abs(i-p)+abs(j-q))
        dis+=ans
    distance=min(distance,dis)

print(distance)

