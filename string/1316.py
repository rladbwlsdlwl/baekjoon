cnt=0
for i in range(int(input())):
    stopped=False
    s=input()
    idx=0

    while(idx<len(s)):
        p=s.count(s[idx])

        if(p==1):
            idx+=1
        else:
            c=s[idx]
            idx,p=idx+1,p-1
            while(p>0):
                if(c!=s[idx]):
                    stopped=True
                    break
                else:
                    idx+=1
                    p-=1
            if(stopped):
                break
    
    if(not stopped):
        cnt+=1
print(cnt)    
