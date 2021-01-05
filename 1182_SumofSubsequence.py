n,s=map(int,input().split())
table=list(map(int,input().split()))
cnt=0

def get_subsequence(arr,val):
    global cnt
    for i in range(len(arr)):
        if(arr[i]==val):
            cnt+=1
        get_subsequence(arr[i+1:],val-arr[i])

get_subsequence(table,s)
print(cnt)

