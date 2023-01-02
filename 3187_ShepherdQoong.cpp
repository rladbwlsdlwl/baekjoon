#include<iostream>
#include<queue> // BFS
#define MAX 250

using namespace std;


int M, N;
char map[MAX][MAX];
bool visited[MAX][MAX] = { false, };

int V, K; // 늑대, 양


int dx[] = { 0, 1, 0 ,-1 };
int dy[] = { -1, 0, 1, 0 };

pair<int, int> findPos() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((map[i][j] == 'v' && !visited[i][j]) || (map[i][j] == 'k' && !visited[i][j]))
				return { i, j };
		}
	}

	return { -1, -1 };
}

void bfs(int y, int x) {
	int v = 0, k = 0;

	queue<pair<int, int>>q;
	q.push({ y, x });

	visited[y][x] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		if (map[p.first][p.second] == 'v')
			v++;
		if (map[p.first][p.second] == 'k')
			k++;


		for (int i = 0; i < 4; i++) {
			int moveX = p.second + dx[i];
			int moveY = p.first + dy[i];

			if (moveX >= 0 && moveX < N && moveY >= 0 && moveY < M && !visited[moveY][moveX] && map[moveY][moveX] != '#') {
				visited[moveY][moveX] = true;

				q.push({ moveY,moveX });
			}
		}
	}


	if (k > v) // 양이 더 많을 경우
		K += k;
	else
		V += v;
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}


	V = 0, K = 0;

	while (true) {
		pair<int, int>pos = findPos();

		if (pos.first == -1)
			break;

		bfs(pos.first, pos.second);
	}

	cout << K << " " << V << "\n";

	return 0;
}
