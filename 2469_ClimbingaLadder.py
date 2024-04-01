K = int(input())
N = int(input())


goal = input()
maze = [list(input()) for _ in range(N)]


tp, btm = ["" for _ in range(K)], ["" for _ in range(K)]

# top
for i in range(K):
	pos = i
	for j in range(N):
		if maze[j][0] == "?":
			break
		if pos > 0 and maze[j][pos-1] == "-":
			pos -= 1
		elif pos < K-1 and maze[j][pos] == "-":
			pos += 1

	tp[pos] = chr(ord('A') + i)

# print(tp)
# bottom
for i in range(K):
	pos = i
	for j in range(N-1, -1, -1):
		if maze[j][0] == "?":
			break
		if pos > 0 and maze[j][pos-1] == "-":
			pos -= 1
		elif pos < K-1 and maze[j][pos] == "-":
			pos += 1

	btm[pos] = goal[i]

# print(btm)

ans = ""
i, stopped = 0, False

while i < K-1:
	if tp[i] == btm[i]:
		ans += "*"
		i += 1
	else:
		if tp[i+1] == btm[i]:
			ans += "-*"
			i += 2
		else:
			stopped = True
			break


print(ans[:K-1] if not stopped else "x"*(K-1))
