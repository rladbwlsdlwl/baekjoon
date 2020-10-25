import sys
input=sys.stdin.readline

alphabet=list(set(input().rstrip() for _ in range(int(input()))))
print(*sorted(alphabet, key=lambda x: (len(x),x[0:])), sep="\n")

