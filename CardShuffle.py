N = int(input())

P = list(map(int, input().split()))
S = list(map(int, input().split()))


def listToTuple(list):
	return tuple(n for n in list)

# 카드를 섞은 뒤, 차례로 나누어 줌
goal = listToTuple([0, 1, 2]*(N//3))


visited = set()
visited.add(listToTuple(P))

size = 0
while size < len(visited) and goal not in visited:
	move = [0]*N

	for i in range(N):
		move[S[i]] = P[i]

	P = move
	visited.add(listToTuple(P))

	size += 1


if goal in visited:
	print(size)
else:
	print("-1")
