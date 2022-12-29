n, m, s = map(int,input().split())

sub = []
for _ in range(n):
    a, b = map(int, input().split())
    sub.append((a, b))

sub.sort()

stopped=False
start = 0

for i in range(n):
    if start+m <= sub[i][0]:
        stopped=True
        break
    start = sub[i][0]+sub[i][1]

if start+m <= s:
    stopped = True
print(start if stopped else "-1")
