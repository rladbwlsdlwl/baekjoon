for i in range(int(input())):
    n,x,y,z=map(int,input().split())
    table.append([x*y*z,x+y+z,n])
    
table=sorted(table, key=lambda x: x[2])
table=sorted(table,key=lambda x: x[1])
table=sorted(table,key=lambda x:x[0])

print(table[0][2],table[1][2],table[2][2])




