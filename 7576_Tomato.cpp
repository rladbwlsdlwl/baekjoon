#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> element;

int R, C;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool isValid(int i, int j) {
	return (i >= 0 && i < R&& j >= 0 && j < C);
}

int get_tomato(vector<vector<int>>& t) {
	queue<pair<element, int>>q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (t[i][j] == 1)
				q.push({ { i,j }, 0 });
		}
	}

	int ans = 0;
	int r, c;
	while (!q.empty()) {
		pair<element, int> p = q.front();
		q.pop();

		r = p.first.first;
		c = p.first.second;
		ans = p.second;

		for (int i = 0; i < 4; i++) {
			int x = c + dx[i];
			int y = r + dy[i];
			if (isValid(y, x) && t[y][x] == 0) {
				q.push({ {y,x},ans + 1 });
				t[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (t[i][j] == 0)
				return -1;
		}
	}

	return ans;
}
int main() {
	cin >> C >> R;
	vector<vector<int>>t(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> t[i][j];
	}

	cout << get_tomato(t);

	return 0;
}
