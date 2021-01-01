import sys
input=sys.stdin.readline

queue=[]

for _ in range(int(input())):
    query=list(input().split())
    
    if(query[0]=="push"):
        queue.append(query[1])
    elif(query[0]=="pop"):
        print(queue.pop(0) if(len(queue)) else -1)
    elif(query[0]=="size"):
        print(len(queue))
    elif(query[0]=="empty"):
        print(0 if(len(queue)) else 1)
    elif(query[0]=="front"):
        print(queue[0] if(len(queue)) else -1)
    else:
        print(queue[-1] if(len(queue)) else -1)
        

