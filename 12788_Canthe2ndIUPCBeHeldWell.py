import sys
input=sys.stdin.readline

N=int(input())
M,K=map(int,input().split())
team=sorted(list(map(int,input().split())))

cnt=0
pen=0
for i in range(N-1,-1,-1):
    if M*K>pen:
        pen+=team[i]
        cnt+=1
    else:
        break

print(cnt if M*K<=pen else "STRESS")

