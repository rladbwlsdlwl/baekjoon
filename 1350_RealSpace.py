n=int(input())
file=list(map(int,input().split()))
cluster=int(input())

ans=0
for i in range(n):
    ans=ans+cluster*(file[i]//cluster)+(cluster if file[i]%cluster else 0)

print(ans)
