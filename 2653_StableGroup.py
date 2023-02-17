N = int(input())
group = [list(map(int, input().split())) for _ in range(N)]


visited = [False for _ in range(N)]
connection = []


def isValid(conn):
    for n in conn:
        tmp = []
        for i in range(N):
            if group[n][i] == 0:
                tmp.append(i)



        if tmp!=conn:
            return False
        
        visited[n] = True

    return True


stopped = False
for i in range(N):
    if not visited[i]:
        conn = [j for j in range(N) if group[i][j] == 0]

        if not isValid(conn) or len(conn) < 2:
            stopped = True
            break

        connection.append(conn)


if stopped:
    print("0")
else:
    print(len(connection))
    for conn in connection:
        for n in conn:
            print(n+1, end=" ")
        print()
