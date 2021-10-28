for i in range(int(input())):
    k,N=map(int,input().split())
    num=[]

    for i in range((N-1)//10+1):
        num.extend(list(map(int,input().split())))

    sortedNum=sorted(num)
    n=0
    p=0

    for i in range(N-1):
        if num[i]!=sortedNum[p]:
            n+=1
        else:
            p+=1    

    if num[len(num)-1]==sortedNum[p]:
        print(k,n)
    else:
        print(k,n+1)
