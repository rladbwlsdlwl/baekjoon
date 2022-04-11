#include<iostream>

using namespace std;

int cmd[100][100];
long long dp[100][100] = { 0, };
/* backtracking - time exceed
void dfs(int i,int j) {
	if (i == n-1 && j == n-1) {
		ans++;
		return;
	}
	else if (i >=n || j >=n)
		return;

	dfs(i + cmd[i][j],j);
	dfs(i, j + cmd[i][j]);
}
*/

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> cmd[i][j];
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		int move_x, move_y;
		for (int j = 0; j < n; j++) {
			move_x = j + cmd[i][j];
			move_y = i + cmd[i][j];
			
			if (i == n - 1 && j == n - 1)
				break;
			if (move_x < n)
				dp[i][move_x] = dp[i][move_x] + dp[i][j];
			if (move_y < n)
				dp[move_y][j] = dp[move_y][j] + dp[i][j];
		}
	}
	
	cout << dp[n-1][n-1] << "\n";

	return 0;
}
