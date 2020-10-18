import sys
input=sys.stdin.readline

table=[0]*10001
for i in range(int(input())):
    N=int(input())
    table[N]+=1

for value,count in enumerate(table):
    if(count!=0):
        for i in range(count):
            print(value)


