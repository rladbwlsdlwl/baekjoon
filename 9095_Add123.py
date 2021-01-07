def get_add(n):
    arr=[1,2,3]
    global cnt
    if(n==0):
        cnt+=1
    for i in arr:
        if(n-i<0):
            break
        else:
            get_add(n-i)
            
for _ in range(int(input())):
    cnt=0
    get_add(int(input()))
    print(cnt)

