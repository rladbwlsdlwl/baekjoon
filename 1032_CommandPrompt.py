n=int(input())
file=[input() for _ in range(n)]
validChar=[True for _ in range(len(file[0]))]

for i in range(1,n):
    for j in range(len(file[0])):
        if validChar[j] and file[0][j]!=file[i][j]:
            validChar[j]=False
    

for i in range(len(file[0])):
    if validChar[i]:
        print(file[0][i], end="")
    else:
        print("?", end="")
