import math

n=int(input())
arr=sorted(list(map(int,input().split())))
mn=math.inf
for i in range(n):
    if(mn>arr[i]+arr[len(arr)-1-i]):
        mn=arr[i]+arr[len(arr)-1-i]

print(mn)

