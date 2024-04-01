N = int(input())
order = list(map(int, input().split())) if int(input()) else [-1]
validNum = [i for i in range(0, 10) if i not in order]

def isValidNum(n, nList):
    for c in str(n):
        if int(c) not in nList:
            return False
        
    return True

ans, tmp = 9999999, 0
for i in range(N, 9999999): # ascd
    if isValidNum(i, validNum):
        ans = tmp + len(str(i))
        break
    tmp += 1

tmp = 0
for i in range(N, -1, -1): # decs
    if isValidNum(i, validNum):
        ans = min(tmp + len(str(i)), ans)
        break
    tmp += 1

print(min(ans, abs(N - 100)))
