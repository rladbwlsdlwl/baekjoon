import sys
input=sys.stdin.readline

sequence=list(int(input()) for _ in range(int(input())))

temp=[]; result=[]; stopped=False 
n=1

for c in sequence:
    while(n<=c):
        result.append('+')
        temp.append(n)
        n+=1
    if(c!=temp.pop()):
        stopped=True
        break
    else:
        result.append('-')

if(stopped):
    print("NO")
else:
    print('\n'.join(result))

