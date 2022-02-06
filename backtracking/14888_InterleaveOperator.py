import math

def eval(val, i, opcnt):
    global n
    oper=n-opcnt
    if i==0:
        val+=num[oper]
    elif i==1:
        val-=num[oper]
    elif i==2:
        val*=num[oper]
    else:
        val/=num[oper]
    return int(val)

def dfs(n, val):
    global mx,mn
    if n==0:
        mx=max(mx,val)
        mn=min(mn,val)
    else:
        for i in range(len(oper)):
            if oper[i]==0:
                continue
            oper[i]-=1
            dfs(n-1, eval(val,i,n))
            oper[i]+=1
            
n=int(input())
num=list(map(int,input().split()))
oper=list(map(int,input().split()))

mx=-1*math.inf
mn=math.inf
dfs(n-1, num[0]) # number of operator, calculate

print(mx)
print(mn)
