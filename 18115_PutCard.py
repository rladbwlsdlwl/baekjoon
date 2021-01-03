import sys
from collections import deque

input=sys.stdin.readline
d=deque() # using deque
n,table=int(input()),list(reversed(list(map(int,input().split()))))

for val in range(n):
    if(table[val]==1):
        d.append(val+1)
    elif(table[val]==2):
        p=d.pop()
        d.extend([val+1,p])
    else:
        d.appendleft(val+1)

print(*list(d)[::-1])

