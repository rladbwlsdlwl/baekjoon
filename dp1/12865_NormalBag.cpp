#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>>cmd(N + 1, vector<int>(2, 0)); 
	for (int i = 1; i <= N; i++)
		cin >> cmd[i][0] >> cmd[i][1];


	vector<vector<int>>dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) {
		int weight = cmd[i][0];
		int val = cmd[i][1];
		for (int j = 0; j <= K; j++) {
			if (weight > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(val + dp[i - 1][j - weight], dp[i - 1][j]);
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}
