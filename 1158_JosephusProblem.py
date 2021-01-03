n,k=map(int,input().split())
table=[i+1 for i in range(n)]

p=-1
result=[]
while(n>0):
    p=(p+k)%n
    result.append(str(table.pop(p)))
    n,p=n-1,p-1

print('<'+', '.join(result)+'>')

