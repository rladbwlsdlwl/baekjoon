N = int(input())

card = list(map(int, input().split()))

# 부분 합 1, 2
pSum_even = [0 for _ in range(N)]
pSum_odd = [0 for _ in range(N)]

pSum_even[0], pSum_odd[1] = card[0], card[1]
for i in range(2, N, 2):
    pSum_even[i] = pSum_even[i-2] + card[i]
    pSum_odd[i+1] = pSum_odd[i-1] + card[i+1]


def sol():
    if N==2:
        return max(card[0], card[1])
    
    
    # 카드 분배 시작
    # 밑장빼기 수행
    ans = 0

    # i가 0일때와 N-2일 때는 따로 구할 예정
    for i in range(2, N-1, 2):
        # 2개씩 나누어줄 때 i번째에서 밑장빼기를 할 경우 나올 수 있는 최대 합을 구함
        tmp = pSum_even[i-2] + max(card[i], card[N-1]) + pSum_odd[N-3] - pSum_odd[i-1]

        ans = max(ans, tmp)

    # i=0
    ans = max(ans, max(card[0], card[N-1]) + pSum_odd[N-3])
    # i=N-2
    ans = max(ans, max(card[N-2], card[N-1]) + pSum_even[N-4])


    # 밑장빼기를 안했을 경우의 경우의 수도 찾아줌
    ans = max(ans, pSum_even[N-2])

    return ans

ans = sol()

print(ans)

