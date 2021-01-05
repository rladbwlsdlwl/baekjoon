from itertools import combinations
while(True):
    s=input().split()
    if(s.pop(0)=='0'):
        break
    else:
        for i in combinations(s,6):
            print(" ".join(i))
        print()

