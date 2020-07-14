T=int(input())
for i in range(T):
    score=list(map(int,input().split()))
    avg=sum(score[1:])/score[0]
    result=0
    for s in range(1,score[0]+1):
        if(avg<score[s]):
            result+=1
    print("%.3f%%" %(result/score[0]*100))
