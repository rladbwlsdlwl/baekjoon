import sys
input=sys.stdin.readline

arr=[]
for i in range(int(input())):
    arr.append(list(map(int,input().split())))

for p,q in sorted(arr,key=lambda x: (x[1],x[0])):
    print(p,q)

