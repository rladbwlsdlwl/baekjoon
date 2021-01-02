import sys
input=sys.stdin.readline

table=list(set(input().rstrip() for _ in range(int(input()))))
print(*sorted(table, key=lambda x: (len(x),x[0:])) ,sep='\n')

