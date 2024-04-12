MAX_HEIGHT = 257

N, M, B = map(int, input().split())

table = [-1 for _ in range(MAX_HEIGHT)]

for _ in range(N):
    h = list(map(int, input().split()))
    for hv in h:
        if table[hv] == -1:
            table[hv] = 0

        table[hv] += 1


def findMinHeight():
    # put box
    for i in range(MAX_HEIGHT):
        if table[i] >= 0:
            return (table[i], i) # count box, box's height 


def findMaxHeight():
    # remove box
    for i in range(MAX_HEIGHT-1, -1, -1):
        if table[i] >= 0:
            return (table[i], i) # count box, box's height 




ans = 0
low, l = findMinHeight()
high, h = findMaxHeight()

while low != N*M:

    if high*2 < low or low > B: # remove box
        table[h] = -1
        table[h-1] = 0 if table[h-1] == -1 else table[h-1]
        table[h-1] += high
        B += high
        ans += 2*high
        
    else: # put box
        table[l] = -1
        table[l+1] = 0 if table[l+1] == -1 else table[l+1]
        table[l+1] += low
        B -= low
        ans += low

    # find min, max block's height
    low, l = findMinHeight()
    high, h = findMaxHeight()


print(ans, table.index(max(table)))
