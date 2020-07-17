array=[]
for i in range(1,10001):
    if(i<10):
        p=i+i
        array.append(p)
    elif(i<100):
        p=i+i//10+i%10
        array.append(p)
    elif(i<1000):
        p=i+i//100+i%100//10+i%100%10
        array.append(p)
    elif(i<10000):
        p=i+i//1000+i%1000//100+i%1000%100//10+i%1000%100%10
        array.append(p)
for i in range(1,10001):
    if(i not in array):
        print(i)

