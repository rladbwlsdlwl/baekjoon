N=int(input())
p=N//5

Make=True
while(p>=0):
    if((N-(p*5))%3==0):
        break
    else:
        if(p==0):
            Make=False
        p-=1
if(Make):
    print(p+(N-5*p)//3)
else:
    print(-1)
