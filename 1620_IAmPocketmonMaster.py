import sys
input=sys.stdin.readline

m,k=map(int,input().split())
idx=[0]
name={}

for i in range(m):
    s=input().strip()
    idx.append(s)
    name[s]=i+1

for _ in range(k):
    s=input().strip()
    if s[0]>='1' and s[0]<='9':
        print(idx[int(s)])
    else:
        print(name[s])


