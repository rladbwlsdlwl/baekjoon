N, M, K = map(int, input().split())
person = [False for _ in range(N)]

# init
for _ in range(M):
    person[int(input())] = True

for _ in range(K):
    person_next = [False for _ in range(N)]
    for i in range(N):
        if person[i]:
            person_next[i-1] = not person_next[i-1] 
            person_next[(i+1) % N] = not person_next[(i+1) % N]
    person = person_next
print(sum(1 if person[i] else 0 for i in range(N)))
