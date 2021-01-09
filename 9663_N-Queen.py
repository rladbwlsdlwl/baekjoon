adjacent(n):
    for i in range(n):
        if(chess[n]==chess[i] or n-i==abs(chess[n]-chess[i])):
            return False
    return True

def dfs(n):
    global result
    if(n==N):
        result+=1
    else:
        for i in range(N):
            chess[n]=i
            if(adjacent(n)):
                dfs(n+1)
result=0
N=int(input())
chess=[0 for i in range(N)]
dfs(0)
print(result)

