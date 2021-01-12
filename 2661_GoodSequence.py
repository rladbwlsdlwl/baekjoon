def dfs(cnt):
    for i in range(1,cnt//2+1):
        if(number[-i:]==number[-2*i:-i]):
            return -1

    if(cnt==N):
        print("".join(list(str(i) for i in number)))
        return 0
    
    for i in range(1,4):
        number.append(i)
        if(dfs(cnt+1)==0):
            return 0
        number.pop()

N=int(input())
number=[]
dfs(0)


