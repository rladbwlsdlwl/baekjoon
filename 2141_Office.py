street=[list(map(int,input().split())) for _ in range(int(input()))]

n=0
avg=sum(street[i][1] for i in range(len(street)))/2

for p,q in sorted(street, key=lambda x:x[0]):
    n+=q
    if n>=avg:
        print(p)
        break
