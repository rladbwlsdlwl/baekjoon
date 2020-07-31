N=int(input())
if(N==1):
    print(1)
else:
    p=2
    move=2
    while(N>p):
        p=p+6*(move-1)
        move+=1
     
    if(N==p):
        print(move)
    else:
        print(move-1)
