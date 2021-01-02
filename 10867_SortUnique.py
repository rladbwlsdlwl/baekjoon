import sys
input=sys.stdin.readline

input()
print(*sorted(list(set(map(int,input().split())))))

