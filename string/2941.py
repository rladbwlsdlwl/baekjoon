alphabet=['c=','c-','dz=','d-','lj','nj','s=','z=']
word=0

s=input()
s_len=len(s)
for c in alphabet:
    if(c=='z='):
        if(s.count('dz=')):
            cnt=s.count('z=')-s.count('dz=') 
        else:
            cnt=s.count(c)
    else:
        cnt=s.count(c)
    
    word+=cnt
    s_len-=len(c)*cnt

print(word+s_len)
    
    
