N = input()
idx, n = 0, 0

while idx < len(N):    
    n += 1
    for num in str(n):
        if idx < len(N) and num == N[idx]:
            idx += 1

print(n)
