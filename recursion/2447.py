def make_star(n):
    result=[]
    for i in range(3*len(n)):
        if(i//len(n)==1):
            result.append(n[i%len(n)]+" "*len(n)+n[i%len(n)])
        else:
            result.append(n[i%len(n)]*3)
    return result

n=int(input())
star=["***","* *","***"]
cnt=0
while(n!=3):
    n=n//3
    cnt+=1

for i in range(cnt):
    star=make_star(star)

for s in star:
    print(s)
