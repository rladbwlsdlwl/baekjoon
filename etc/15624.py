import sys
input=sys.stdin.readline

n=int(input())
p,q=0,1
for i in range(2,n+1):
    p,q=q,(p+q)%1000000007
print(q%1000000007 if(n>0) else p)

