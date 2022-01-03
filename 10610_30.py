from collections import defaultdict
N=input()
# 1. count 0 (End of number is zero)
# 2. sum of each number is 3's multiple

if '0' in N and sum(list(int(n) for n in N))%3==0:
    number=defaultdict(int)
    ans=""
    for n in N:
        number[int(n)]+=1
    for i in range(9,-1,-1):
        ans+=number[i]*str(i)
        
    print(ans)
else:
    print(-1)
