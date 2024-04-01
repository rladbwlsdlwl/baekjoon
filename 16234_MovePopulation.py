from collections import deque
import sys
input = sys.stdin.readline

N, L, R = map(int, input().split())
people = [list(map(int, input().split())) for _ in range(N)]



dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]

def bfs(r, c):
	tmp = deque()
	union = []

	tmp.append((r, c))
	union.append((r, c))


	while tmp:
		nodeY, nodeX = tmp.popleft()

		for p in range(4):
			movey, movex = nodeY + dy[p], nodeX + dx[p]

			if movey < 0 or movey >= N or movex < 0 or movex >= N:
				continue
			if visited[movey][movex]:
				continue

			if L <= abs(people[nodeY][nodeX] - people[movey][movex]) <= R:
				tmp.append((movey, movex))
				union.append((movey, movex))
				visited[movey][movex] = True


	# 국가별 합산
	if len(union) == 1:
		return 0

	res = sum(people[i][j] for i, j in union) // len(union)
	for i, j in union:
		people[i][j] = res

	return 1

cnt = 0
while True:
	stopped = 0
	visited = [[False for _ in range(N)] for _ in range(N)]

	# 노드 순회
	for i in range(N):
		for j in range(N):
			if not visited[i][j]:
				visited[i][j] = True
				stopped += bfs(i, j)



	if stopped == 0:
		break

	cnt += 1

print(cnt)



