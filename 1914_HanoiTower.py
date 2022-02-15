import sys
input=sys.stdin.readline
# sys.setrecursionlimit(10**7)

def hanoi(n, from_ ,tmp_, to_):
    if n==1:
        print(from_,to_)
        return
    
    hanoi(n-1,from_,to_,tmp_)
    print(from_,to_)
    hanoi(n-1,tmp_,from_,to_)

N=int(input())
mov=0
for _ in range(N):
    mov=mov*2+1
print(mov)

if N<=20:
    hanoi(N,1,2,3)    
    
