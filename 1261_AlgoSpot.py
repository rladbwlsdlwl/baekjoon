# shortest path
# dijksrra
import heapq

N, M = map(int, input().split())
maze = [list(map(int, input())) for _ in range(M)]


dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
def dijkstra(r, c):
	# min heap
	hq = []
	dp = [[10000 for _ in range(c)] for _ in range(r)]
	visited = [[False for _ in range(c)] for _ in range(r)]


	dp[0][0] = maze[0][0]
	heapq.heappush(hq, (maze[0][0], 0 , 0)) # (cost, row, col)
	while heapq:
		p = heapq.heappop(hq)

		if p[1] == r-1 and p[2] == c-1:
			break
		elif visited[p[1]][p[2]] or dp[p[1]][p[2]] < p[0]:
			continue

		visited[p[1]][p[2]] = True
		for i in range(4):
			movey, movex = dy[i] + p[1], dx[i] + p[2]

			if 0 <= movey < r and 0 <= movex < c and not visited[movey][movex]:
				path = p[0] + maze[movey][movex]
				if dp[movey][movex] >= path: # 최단경로를 발견했을때 push
					dp[movey][movex] = path
					heapq.heappush(hq, (dp[movey][movex], movey, movex))

	return dp[r-1][c-1]


print(dijkstra(M, N))