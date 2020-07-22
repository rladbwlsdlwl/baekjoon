class hanoi:
    def __init__(self):
        self.move=[]
        self.cnt=0
    def hanoi_tower(self,n,start,temp,end):
        if(n==1):
            self.cnt+=1
            self.move.append([start,end])
        else:
            self.hanoi_tower(n-1,start,end,temp)
            self.cnt+=1
            self.move.append([start,end])
            self.hanoi_tower(n-1,temp,start,end)

h=hanoi()
h.hanoi_tower(int(input()),1,2,3)
print(h.cnt)
for i in range(h.cnt):
    print(h.move[i][0],h.move[i][1])
