def solution(N,m,M,T,R):
    ans,beat=0,m
    while N:
        if beat+T<=M:
            beat+=T
            N-=1
        else:
            if beat-R<=m:
                beat=m
            else:
                beat-=R
        ans+=1

    return ans


N,m,M,T,R=map(int,input().split())
print(-1 if m+T>M else solution(N,m,M,T,R))
