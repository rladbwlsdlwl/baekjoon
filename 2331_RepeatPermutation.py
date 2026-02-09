A, P = map(int, input().split())

cnt = 0
table = {}
while A not in table:
    table[A] = cnt

    tmp = 0
    while A > 0:
        tmp += (A % 10) ** P
        A //= 10

    A = tmp
    cnt += 1


print(table[A])
