N = int(input())

stopped = False
numList = []

def isDescStr(s):
    for i in range(len(s)-1):
        if s[i] <= s[i+1]: # ascending
            return False
        
    return True

#backtracking
def dfs(numStr, numLength):
    if not isDescStr(numStr):
        return 
    if numLength == 0:
        numList.append(numStr)
        return 

    for n in range(10):
        dfs(numStr+str(n), numLength-1)


for size in range(10): # 9876543210's length
    if stopped:
        break
    for n in range(0, 10): # 0 to 9
        if len(numList) > N : 
            stopped = True
            break
        
        dfs(str(n), size)
        
print(numList[N] if len(numList) > N else "-1")
