import sys
input=sys.stdin.readline

N=int(input())

table=[1,2]

for i in range(2,N):
    table.append(table[i-1]+table[i-2]%15746)

print(table[N-1]%15746)
