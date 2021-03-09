N=int(input())
distance,city=list(map(int,input().split())),list(map(int,input().split()))

ans=0 
p=0
min_val=int(1e9)

while(p<N-1):
    if(min_val>city[p]):
        min_val=city[p]
    
    ans+=min_val*distance[p]
    p+=1

print(ans)
