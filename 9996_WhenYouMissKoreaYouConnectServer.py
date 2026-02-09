import sys
input = sys.stdin.readline


N = int(input())

pattern = input().split("*")

for _ in range(N):
    s = input()

    # front check
    front = pattern[0]
    # back check
    back = pattern[1]

    if len(s) >= len(front) + len(back) and s[:len(front)] == front and s[-len(back):] == back:
        print("DA")
    else:
        print("NE")
