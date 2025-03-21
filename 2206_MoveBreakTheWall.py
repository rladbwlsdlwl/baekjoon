from collections import deque

N, M = map(int, input().split())

path = [input() for _ in range(N)]

dp = [[[0 for _ in range(2)] for _ in range(M)] for _ in range(N)]

# BFS
def bfs():
    q = deque()
    q.append([0, 0, 1]) # y, x, power


    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    dp[0][0][1] = 1
    while q:
        y, x, power = q.popleft()

        if y == N-1 and x == M-1:
            return dp[y][x][power]

        for i in range(4):
            movey, movex = dy[i]+y, dx[i]+x

            if movey >= 0 and movey < N and movex >=0 and movex < M:

                # 길이 뚫려있고 방문하지 않았던 노드는 기록
                if path[movey][movex] == '0' and dp[movey][movex][power] == 0:
                    dp[movey][movex][power] = dp[y][x][power] + 1
                    q.append([movey, movex, power])
                # 벽이 있지만 부술 수 있는 경우 기록
                elif path[movey][movex] == '1' and power == 1:
                    dp[movey][movex][0] = dp[y][x][1] + 1 
                    q.append([movey, movex, 0])

    return -1

print(bfs())
