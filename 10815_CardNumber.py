# time complexity O(n)
# counting sort (n)

table=[0 for _ in range(20000001+1)] # -10,000,000 ~ +10,000,000

input()
A=list(map(int,input().split()))
input()
B=list(map(int,input().split()))

for a in A:
    table[a+10000000]+=1

for b in B:
    if(table[b+10000000]>0):
        print(1,end=" ")
    else:
        print(0,end=" ")

