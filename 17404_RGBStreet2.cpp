#include<iostream>
#define MAX 1000

using namespace std;

const int INF = 999999;

int N;
int home[MAX][3];
int dp[3][MAX][3];

int dfs(int i, int j, int color) {
	if (dp[color][i][j] != INF)
		return dp[color][i][j];
	if (i == 0) {
		if (j == color)
			return INF;

		return home[i][j];
	}


	if (j == 0)
		dp[color][i][j] = min(dfs(i - 1, 1, color), dfs(i - 1, 2, color)) + home[i][j];
	else if (j == 1)
		dp[color][i][j] = min(dfs(i - 1, 0, color), dfs(i - 1, 2, color)) + home[i][j];
	else
		dp[color][i][j] = min(dfs(i - 1, 0, color), dfs(i - 1, 1, color)) + home[i][j];

	return dp[color][i][j];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> home[i][0] >> home[i][1] >> home[i][2];

		fill_n(dp[0][i], 3, INF);
		fill_n(dp[1][i], 3, INF);
		fill_n(dp[2][i], 3, INF);
	}

	for (int i = 0; i < 3; i++)
		dp[i][N - 1][i] = dfs(N - 1, i, i);

	cout << (min(dp[0][N - 1][0], min(dp[1][N - 1][1], dp[2][N - 1][2]))) << "\n";
	
	return 0;
}
