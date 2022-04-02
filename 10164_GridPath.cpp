#include<iostream>
#include<vector>

using namespace std;

int bfs(int r1, int c1, int r2, int c2) {
	int cnt = 0;
	vector<pair<int, int>>maze;
	maze.push_back({ r1,c1 });

	while (maze.size()) {
		pair<int,int>p = maze.back();
		int move_r = p.first;
		int move_c = p.second;
		maze.pop_back();

		if (move_r == r2 && move_c == c2) {
			cnt++;
			continue;
		}

		if (move_r + 1 <= r2)
			maze.push_back({ move_r + 1,move_c });
		if (move_c + 1 <= c2)
			maze.push_back({ move_r,move_c + 1 });
	}

	return cnt;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	cout << (k == 0 ? bfs(0, 0, n - 1, m - 1) : (k % m == 0 ? bfs(0, 0, k / m - 1, m - 1) : bfs(0, 0, k / m, k % m - 1) * bfs(k / m, k % m - 1, n - 1, m - 1)));

	return 0;
}
