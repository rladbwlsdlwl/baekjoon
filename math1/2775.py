import sys
input=sys.stdin.readline

for _ in range(int(input().rstrip())):
    apart=[]
    row=int(input().rstrip())
    col=int(input().rstrip())

    for i in range(row+1):
        temp=[]
        for j in range(col+1):
            if(i==0):
                temp.append(j)
            else:
                temp.append(sum(apart[i-1][0:j+1]))

        apart.append(temp)

    print(apart[-1][-1])

