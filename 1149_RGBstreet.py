home=[list(map(int,input().split())) for _ in range(int(input()))]
table=[home[0]]

for i in range(1,len(home)):
    tmp=[]
    tmp.append(home[i][0]+min(table[i-1][1],table[i-1][2]))
    tmp.append(home[i][1]+min(table[i-1][0],table[i-1][2]))
    tmp.append(home[i][2]+min(table[i-1][0],table[i-1][1]))
    
    table.append(tmp)


print(min(table[len(home)-1]))   
