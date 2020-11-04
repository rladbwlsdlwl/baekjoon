import sys
input=sys.stdin.readline

for _ in range(int(input().rstrip())):
    h,w,n=map(int,input().split())
    
    print(str((n-1)%h+1)+str((n-1)//h+1).rjust(2,'0'))
    

