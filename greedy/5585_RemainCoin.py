n=int(input())
Coin=[500,100,50,10,5,1]
ans=0

for c in Coin:
    ans+=n//c
    n%=c

print(ans)
