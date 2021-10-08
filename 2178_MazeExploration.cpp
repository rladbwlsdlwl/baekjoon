#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int maze[100][100];
bool visited[100][100] = { false, };
queue <pair<int, int>> q;
queue <int> cnt;


void move(int r, int c,int val) {
	if (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == 1 && visited[r][c]==false) {
		q.push(make_pair(r, c));
		cnt.push(val + 1);
		visited[r][c] = true;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < m; j++) 
			maze[i][j] = row[j] - '0';
		
	} //fill maze

	int ans = 10001;
	move(0, 0, 0);
  	while (!q.empty()) { // BFS
		pair<int, int>tmp = q.front();
		int val = cnt.front();

		//cout << tmp.first << ", " << tmp.second << "\n";
		if (tmp.first == n-1 && tmp.second == m-1)
			ans = min(ans, val);
		
		q.pop();
		cnt.pop();

		move(tmp.first - 1, tmp.second,val);
		move(tmp.first, tmp.second + 1,val);
		move(tmp.first + 1, tmp.second,val);
		move(tmp.first, tmp.second - 1,val);
	}

	cout << ans;
	
	return 0;
}


