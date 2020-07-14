result=1
for i in range(3):
    result*=int(input())
result=str(result)
for i in range(10):
    print(result.count(str(i)))

