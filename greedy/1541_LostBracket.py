operation=input().split('-')

ans=0

for i,op in enumerate(operation):
    temp=op.split('+')
    if(i==0):
        for val in temp:
            ans+=int(val)
    else:
        tmp=0
        for val in temp:
            tmp+=int(val)
        
        ans+=-1*tmp

print(ans)


