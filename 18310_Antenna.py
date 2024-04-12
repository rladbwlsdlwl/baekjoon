N = int(input())

home = list(map(int, input().split()))

home.sort()

print(home[len(home) // 2 + (0 if len(home) % 2 == 1 else -1)])
