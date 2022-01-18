from collections import defaultdict

N=int(input())
A=list(map(int,input().split()))

table=defaultdict(list)

for i,n in enumerate(A):
    table[n].append(i)

P=[0 for _ in range(N)]
cnt=0
for n in sorted(set(A)):
    for idx in table[n]:
        P[idx]=cnt
        cnt+=1


print(*P)

