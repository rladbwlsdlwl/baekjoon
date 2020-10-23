import sys
input=sys.stdin.readline

arr=[]
for i in range(int(input())):
    arr.append(list(map(int,input().split())))


for p,q in sorted(arr,key=lambda x:(x[0],x[1])):
    print(p,q)

