for i in range(int(input())):
    n,m=map(int,input().split())
    paper=list(map(int,input().split())) #queue

    cnt=0
    check=[True if(i==m) else False for i in range(n)]
    while(n>0):
        idx=paper.index(max(paper))
        
        paper=paper[idx:]+paper[:idx]
        check=check[idx:]+check[:idx]
        paper.pop(0); p=check.pop(0)
        cnt,n=cnt+1,n-1
        
        if(p): break

    print(cnt)
