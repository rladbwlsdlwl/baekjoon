conference=[]
N=int(input())
for _ in range(N):
    conference.append(list(map(int,input().split())))

conference.sort(key=lambda x: (x[1],x[0]))

cnt=1
hour=conference[0][1] #end hour

for i in range(1,N):
    if(hour<=conference[i][0]):
        hour=conference[i][1]
        cnt+=1

print(cnt)



