from collections import deque
c,r,h=map(int,input().split())
tomato=[[list(map(int,input().split())) for _ in range(r)] for _ in range(h)]

def isValid(i,j,k):
    return True if 0<=i<h and 0<=j<r and 0<=k<c else False

dq=deque()
for i in range(h):
    for j in range(r):
        for k in range(c):
            if tomato[i][j][k]==1:
                dq.append((i,j,k))

dx=[0,1,0,-1,0,0]
dy=[-1,0,1,0,0,0]
dz=[0,0,0,0,-1,1]

while dq:
    q=dq.popleft()

    for i in range(6):
        z=q[0]+dz[i]
        y=q[1]+dy[i]
        x=q[2]+dx[i]
        
        if isValid(z,y,x) and tomato[z][y][x]==0:
            tomato[z][y][x]=tomato[q[0]][q[1]][q[2]]+1
            dq.append((z,y,x))


ans=0
stopped=False
for i in range(h):
    for j in range(r):
        for k in range(c):
            if tomato[i][j][k]==0:
                stopped=True
                break
            ans=max(ans,tomato[i][j][k])
        if stopped:
            break
    if stopped:
        break

print(-1 if stopped else ans-1)
