import sys
input=sys.stdin.readline
table={}

input()
temp1=list(map(int,input().split()))
input()
temp2=list(map(int,input().split()))

for i in range(len(temp1)):
    if(temp1[i] in table):
        table[temp1[i]]+=1
    else:
        table[temp1[i]]=1

print(' '.join(str(table[c]) if(c in table) else '0' for c in temp2))

