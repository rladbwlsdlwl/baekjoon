n=int(input())
for i in range(n):
    print(' '*i,end="")
    print('*'*((n-i)*2-1))
for i in range(n-1):
    print(' '*(n-2-i),end="")
    print('*'*((i+2)*2-1))
