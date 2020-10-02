go,back,goal=map(int,input().split())
move=go-back
distance=goal-go
if(distance<=0):
    print("1")
else:
    if(distance%move==0):
        print(distance//move+1)
    else:
        print(distance//move+2)

