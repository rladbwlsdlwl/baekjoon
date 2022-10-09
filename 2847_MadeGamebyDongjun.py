level=[]
n=int(input())

for _ in range(n):
    level.append(int(input()))

ans=0
for i in range(n-2, -1, -1):
    if level[i]>=level[i+1]:
        ans+=level[i]-level[i+1]+1
        level[i]=level[i+1]-1

print(ans)

