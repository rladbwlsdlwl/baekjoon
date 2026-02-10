import sys
input = sys.stdin.readline

N = int(input().strip())
word = list(input().strip())

ans = 0
for _ in range(N-1):

    cmp_word = list(input().strip())
    cnt = 0 
    # 추가 or 삭제 or 교체 가능
    for ch in word:
        # 같은 문자 제거
        if ch in cmp_word:
            cmp_word.remove(ch)
        else:
            cnt += 1
    
    # 같은 종류 (0, 0)
    # 비슷한 종류
    # 추가 (1, 0)
    # 삭제 (0, 1)
    # 교체 (1, 1)
    if(cnt <= 1 and len(cmp_word) <= 1):
        ans += 1

print(ans)
