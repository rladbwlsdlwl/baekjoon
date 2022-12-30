N = int(input())
dice = list(map(int, input().split()))


def isValid(n):
	for i in range(6):
		if visited[i] and i==notAdjacent[n]:
			return False

	return True

def dfs(cnt, n, CNT):
	visited[n] = True

	if cnt == 1:
		mn[CNT] = min(mn[CNT], sum(dice[i] for i in range(6) if visited[i]))

		visited[n] = False
		return 

	for i in range(n+1, 6):
		if isValid(i):
			dfs(cnt-1, i, CNT)


	visited[n] = False



# 0과 5는 마주보는 면 (A와 F)
notAdjacent = [5, 4, 3, 2, 1, 0]


mn = [150]*3
visited = [False for _ in range(6)]


# 마주보지 않는 면 중에서 가능한 최소 면 합 찾기
for i in range(6):
	dfs(3, i, 2)
	dfs(2, i, 1)
	dfs(1, i, 0)




if N==1:
	mn = 250
	for i in range(6):
		mn = min(mn, sum(dice[j] for j in range(6) if j!=notAdjacent[i]))

	print(mn)
else:
	print(4*mn[2] + ((N-2)*4+(N-1)*4)*mn[1] + ((N-2)*(N-2)+(N-1)*(N-2)*4)*mn[0])
