n=int(input())
if(n==1):
    print('*')
else:
    if(n%2==0):
        for i in range(n):
            print('* '*(n//2))
            print(' *'*(n//2))
        else:
            for i in range(n):
                print('* '*(n//2)+'* ')
                print(' *'*(n//2))
