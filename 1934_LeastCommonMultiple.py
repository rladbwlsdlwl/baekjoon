def GCD(a,b):
    return GCD(b, a%b) if b else a

for _ in range(int(input())):
    a,b=map(int,input().split())
    print(a*b//GCD(a,b))
