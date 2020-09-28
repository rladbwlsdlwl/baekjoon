insertion_sort(arr):
    for i in range(1,len(arr)):
        key=arr[i];j=0
        for j in range(i-1,-1,-1):
            if(key<arr[j]):
                arr[j+1]=arr[j]

            else:
                j+=1
                break

        arr[j]=key
        
arr=[int(input()) for _ in range(int(input()))]
insertion_sort(arr)
print(*arr,sep="\n")



