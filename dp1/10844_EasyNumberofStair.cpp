#include<iostream>
#define MOD 1000000000
using namespace std;
/*
void dfs(int k,int knum) {
	if (k == 1) {
		ans++;
		return;
	}
	if (knum - 1 >= 0)
		dfs(k - 1, knum - 1);
	if (knum + 1 <= 9)
		dfs(k - 1, knum + 1);
}
*/

int dp[101][10] = { 0, };
int main() {
	int N;
	cin >> N;

	fill_n(dp[1], 10, 1);
	dp[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i]) % MOD;

	cout << ans << "\n";
	return 0;
}

