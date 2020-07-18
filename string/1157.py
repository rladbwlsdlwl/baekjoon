s=sorted(input().upper())
chr='?'
mx=0
idx=0
while(idx<len(s)):
    p=s.count(s[idx])
    if(mx==p):
        chr='?'
    if(mx<p):
        mx=p
        chr=s[idx]

    idx+=p

print(chr)
    


