def count_n(number):
    tmp=[]
    for i in range(10):
        tmpList=[]
        for j in range(10):
            cnt=0
            if i==j:
                tmpList.append(cnt)
                continue
            for k in number[i]:
                if k not in number[j]:
                    cnt+=1
            for k in number[j]:
                if k not in number[i]:
                    cnt+=1
            tmpList.append(cnt)
        tmp.append(tmpList)

    return tmp            
            
number=[[0,1,2,4,5,6], [2,5], [0,2,3,4,6], [0,2,3,5,6], [1,3,2,5], #0,1,2,3,4
    [0,1,3,5,6], [0,1,4,6,5,3], [0,2,5], [0,1,2,3,4,5,6],[0,1,2,3,5,6]] #5,6,7,8,9

temp=count_n(number)
N,K,P,X=map(int,input().split()) #최대 N, K길이의 수, P만큼 변경가능, X의 숫자

ans=0
x=[0 for _ in range(K-len(str(X)))]
x.extend([int(n) for n in str(X)])
#print(x)

for n in range(1,N+1):
    if n==X:
        continue
    cnt=0
    nList=[0 for _ in range(K-len(str(n)))]
    nList.extend([int(v) for v in str(n)])
    #print(nList)
    for i in range(K):
        cnt+=temp[x[i]][nList[i]]
        #print(x[i],nList[i],temp[x[i]][nList[i]])
    if 1<=cnt<=P:
        ans+=1

print(ans)
