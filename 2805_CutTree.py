n,m=map(int,input().split())
tree=sorted(list(map(int,input().split())))

left,right=0,tree[n-1]
ans=0
while left<=right:
    mid=(left+right)//2
    cut=0
    for n in tree:
        if n>mid:
            cut+=n-mid
    
    if cut>=m:
        ans=max(ans,mid) # 나무의 길이가 최대일 때
        left=mid+1
    else:
        right=mid-1

print(ans)

