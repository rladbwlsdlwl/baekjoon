arr=[input().split() for _ in range(int(input()))]
for p,q in sorted(arr,key=lambda x:x[0]):
    print(p,q)

