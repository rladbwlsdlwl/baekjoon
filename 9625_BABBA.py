ans = [1, 0]

for _ in range(int(input())):
    ans = [ans[1], ans[0] + ans[1]]

print(*ans)
