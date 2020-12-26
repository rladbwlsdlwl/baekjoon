n,k=map(int,input().split())

def fac(n,k):
    result=1
    for i in range(k):
        result*=(n-i)

    return result

if((N+K-1)//2>=N):
    n,k=N+K-1,N
else:
    n,k=N+K-1,(N+K-1)-N

print(fac(n,k)//fac(k,k)%1000000000)

