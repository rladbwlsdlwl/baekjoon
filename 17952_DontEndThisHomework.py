import sys 
input = sys.stdin.readline

ans = 0
stk = []
for _ in range(int(input())):
    homework = list(map(int, input().strip().split()))

    if homework[0] == 0:
        if len(stk) == 0:
            continue

        p_order, p_score, p_time = stk.pop()

        p_time -= 1

        if p_time > 0:
            stk.append((p_order, p_score, p_time))
        else:
            ans += p_score
    else:
        order, score, time = homework

        time -= 1

        if time > 0:
            stk.append((order, score, time))
        else:
            ans += score
print(ans)
