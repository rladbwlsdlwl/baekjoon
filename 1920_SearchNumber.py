# time complexity O(nlogn)
# sort(nlogn) && binary search (logn)

def binary_search(val,begin,end):
    while(begin<=end):
        mid=(begin+end)//2
        if(A[mid]==val):
            return 1
        elif(A[mid]<val):
            begin=mid+1
        else:
            end=mid-1

    return 0

input()
A=sorted(list(map(int,input().split())))
input()
B=list(map(int,input().split()))

for b in B:
    print(binary_search(b,0,len(A)-1))
    

