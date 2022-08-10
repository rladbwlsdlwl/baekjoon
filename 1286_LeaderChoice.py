from collections import defaultdict
n=int(input())

student=[]
for _ in range(n):
    student.append(list(map(int,input().split())))

visited=[[False for _ in range(n)] for _ in range(n)]
ans=[0 for _ in range(n)]

for j in range(5):
    tmp=defaultdict(list)
    for i in range(n):
        tmp[student[i][j]].append(i) 
      
    for key in tmp: # class 별 학생 리스트
        for me in tmp[key]: 
            for other in tmp[key]:
                if me!=other and not visited[me][other]:
                    visited[me][other]=True
                    ans[me]+=1

print(ans.index(max(ans))+1)
