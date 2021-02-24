N=int(input())
time=sorted(list(map(int,input().split())))

result,wait=time[0],time[0]

for t in time[1:]:
    wait+=t
    result+=wait

print(result)
