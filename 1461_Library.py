N, M = map(int, input().split())
book = sorted(list(map(int, input().split())))


def countBook():
    for i in range(N):
        if book[i] >= 0:
            return (i, N-i)

    return (N, 0)


p, q = 0, N-1 # book's position
left, right = countBook() # count left, right remain book

ans = 0
while left > 0 or right > 0:
    if left < 0 or right > 0 and abs(book[p]) <= book[q]:
        if ans == 0:
            ans += book[q]
        else:
            ans += book[q] * 2
        q -= M
        right -= M 
    else:
        if ans == 0:
            ans += abs(book[p])
        else:
            ans += abs(book[p]) * 2
        p += M
        left -= M 

print(ans)
