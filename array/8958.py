T=int(input())
for i in range(T):
    s=input()
    score,cnt=0,0
    for p in s:
        if(p=='O'):
            cnt+=1
        else:
            cnt=0
        score+=cnt
    print(score)
