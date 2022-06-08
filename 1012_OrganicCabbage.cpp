#include<iostream>

using namespace std;

int M, N, K;
int ans = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool land[50][50] = { false, };

void dfs(int r, int c) {
	land[r][c] = false;

	for (int i = 0; i < 4; i++) {
		int x = c + dx[i], y = r + dy[i];
		if (0 <= y && y < M && 0 <= x && x < N && land[y][x])
			dfs(r + dy[i], c + dx[i]);
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> N >> M >> K;

		int r, c;
		while (K--) {
			cin >> c >> r;
			land[r][c] = true;
		}

		ans = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (land[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
