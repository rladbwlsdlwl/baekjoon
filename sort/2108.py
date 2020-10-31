import math
import sys
input=sys.stdin.readline

number=[0]*8001
n=int(input())
for _ in range(n):
    number[int(input())+4000]+=1

#average
avg=0
for i,j in enumerate(number):
    avg+=(i-4000)*j

print(round(avg/n))

#middle
mid=0
for i,j in enumerate(number):
    mid+=j
    if(mid>=n//2+1):
        mid=i-4000; break

print(mid)

#frequency
print(number[number.index(max(number))+1:].index(max(number))+len(number[:number.index(max(number))+1])-4000 if(number.count(max(number))>1) else number.index(max(number))-4000)

#range
check=True
mx,mn=0,0
for i,j in enumerate(number):
    if(j>0):
        if(check): mn=i; check=False
        mx=i
print(mx-mn)
        


