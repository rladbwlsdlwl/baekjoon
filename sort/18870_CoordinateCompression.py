# O(NlogN)
n=int(input())
num=list(map(int,input().split()))

table={} # value to index
sortedNum=sorted(set(num))
for i in range(len(sortedNum)):
    table[sortedNum[i]]=i

print(' '.join(map(str,[table[n] for n in num])))

