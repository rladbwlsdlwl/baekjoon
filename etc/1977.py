table=[ for i in range(1,101)] #push number between 1 and 10000
result=[i for i in range(int(input()),int(input())+1) if(i in table)]
print(str(sum(result))+'\n'+str(result[0]) if(len(result)) else -1)

