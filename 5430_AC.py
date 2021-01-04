import sys
input=sys.stdin.readline

for _ in range(int(input())):
    p,n=input().rstrip(),int(input().rstrip())
    arr=list(input().rstrip()[1:-1].split(',')) # push [], arr='' and len(arr)=1 
    
    isReversed=False; stopped=False
    front,rear=0,n
    for c in p:
        if(c=='R'):
            isReversed=not isReversed
        else:
            if(n==0):
                stopped=True
                break
            if(isReversed):
                rear-=1
            else:
                front+=1
            n-=1

    if(stopped):
        print("error")
    else:
        arr=arr[front:rear]
        print('['+','.join(arr[::-1])+']' if(isReversed) else '['+','.join(arr)+']')

