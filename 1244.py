N = int(input())
flag = list(map(int, input().split()))


for _ in range(int(input())):
    gender, number = map(int, input().split())

    if gender == 1:
        # 배수에 해당하는 값을 반전
        for i in range(number, N+1, number):
            flag[i-1] ^= 1

    else:

        flag[number - 1] ^= 1
        # 대칭점 찾은 후 반전
        for i in range(1, N):
            left, right = number - i - 1, number + i - 1
            if left < 0 or right >= N or flag[left] != flag[right]:
                break
            else:
                flag[left] ^= 1
                flag[right] ^= 1

for i in range(N):
    if (i+1)%20:
        print(flag[i], end = " ")
    else:
        print(flag[i])
