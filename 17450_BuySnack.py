s1, s2 = map(int,input().split())
n1, n2 = map(int,input().split())
u1, u2 = map(int,input().split())

p, q, r = -500 if s1*10>=5000 else 0, -500 if n1*10>=5000 else 0, -500 if u1*10>=5000 else 0 
a, b, c = (s2*10)/(s1*10+p), (n2*10)/(n1*10+q), (u2*10)/(u1*10+r)

if a>b and a>c:
    print("S")
elif b>a and b>c:
    print("N")
else:
    print("U")
