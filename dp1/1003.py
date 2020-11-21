import sys
input=sys.stdin.readline


def fibo(n):
    arr=[[1,0],[0,1]]
    for i in range(2,n+1):
        arr.append([arr[i-1][0]+arr[i-2][0],arr[i-1][1]+arr[i-2][1]])

    return arr[n]

for _ in range(int(input().strip())):
    print(*fibo(int(input().strip())))
   

