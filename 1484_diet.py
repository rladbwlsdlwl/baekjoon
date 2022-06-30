G=int(input())

now,before=2,1 # 현재몸무게 now, 이전 몸무게 before
validWeight=False

while before<now:
    g=pow(now,2)-pow(before,2)

    if now-1==before and g>G:
        break
    elif g==G:
        validWeight=True
        print(now)
        before,now=before+1,now+1
    elif g<G:
        now+=1
    else:
        before+=1

if not validWeight:
    print(-1)

