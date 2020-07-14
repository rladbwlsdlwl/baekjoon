mport sys
input=sys.stdin.readline
list=[]
avg=0
for i in range(5):
    list.append(int(input()))
    if(list[-1]<40):
        list[-1]=40
    avg+=list[-1]
    
print(avg//5)
