x=int(input())
cnt=1
ans=1

while(ans<=x):
    ans+=cnt
    cnt+=1
cnt-=1
ans-=cnt

p=x-ans
print((str(1+p)+'/'+str(cnt-p)) if(cnt%2==0) else (str(cnt-p)+'/'+str(1+p)))
