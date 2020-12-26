import sys
input=sys.stdin.readline

def get_island(w,h):
    island=[]
    result=0
    for i in range(h):
        island.append(list(map(int,input().split())))

    i=0
    arr=[]
    while(True):
        if(i>=h):
            break
        if(island[i].count(1)>0):
            arr.append([i,island[i].index(1)])
            result+=1
            
            while(len(arr)):
                p=arr.pop()
                island[p[0]][p[1]]=0
                    
                if(p[0]-1>=0):
                    if(p[1]-1>=0 and island[p[0]-1][p[1]-1]==1):
                        island[p[0]-1][p[1]-1]=0
                        arr.append([p[0]-1,p[1]-1])
                    if(island[p[0]-1][p[1]]==1):
                        island[p[0]-1][p[1]]=0
                        arr.append([p[0]-1,p[1]])
                    if(p[1]+1<w and island[p[0]-1][p[1]+1]==1):
                        island[p[0]-1][p[1]+1]=0
                        arr.append([p[0]-1,p[1]+1])
                if(p[1]-1>=0 and island[p[0]][p[1]-1]==1):
                    island[p[0]][p[1]-1]=0
                    arr.append([p[0],p[1]-1])
                if(p[1]+1<w and island[p[0]][p[1]+1]==1):
                    island[p[0]][p[1]+1]=0
                    arr.append([p[0],p[1]+1])
                if(p[0]+1<h):
                    if(p[1]-1>=0 and island[p[0]+1][p[1]-1]==1):
                        island[p[0]+1][p[1]-1]=0
                        arr.append([p[0]+1,p[1]-1])
                    if(island[p[0]+1][p[1]]==1):
                        island[p[0]+1][p[1]]=0
                        arr.append([p[0]+1,p[1]])
                    if(p[1]+1<w and island[p[0]+1][p[1]+1]==1):
                        island[p[0]+1][p[1]+1]=0
                        arr.append([p[0]+1,p[1]+1])
                
        else:
            i+=1
                
    return result


while(True):
    w,h=map(int,input().split())
    if(w==h==0):
        break
    else:
        print(get_island(w,h))

