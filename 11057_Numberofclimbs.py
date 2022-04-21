num=[1 for _ in range(10)]
for _ in range(int(input())-1):
    tmp=[0 for _ in range(10)]
    for i in range(10):
        tmp[i]=sum(num[i:])%10007
    num=tmp

print(sum(num)%10007)


