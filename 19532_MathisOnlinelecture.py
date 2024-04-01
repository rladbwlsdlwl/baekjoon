a, b, c, d, e, f = map(int, input().split())

x, y = 0, 0
for X in range(-999, 1000):
    for Y in range(-999, 1000):
        if a*X + b*Y == c and d*X + e*Y == f:
            x, y = X, Y
            break

print(x, y)
