import sys
input=sys.stdin.readline

def fibo(n):
    arr=[0,1,1]
    for i in range(3,n+1):
        arr.append(arr[i-2]+arr[i-1])

    return arr[n]

print(fibo(int(input().rstrip())))

