#include<iostream>
#define MAX 100

using namespace std;

int weight[MAX + 1];
int cost[MAX + 1];

int dp[MAX + 1][MAX * MAX + 1];
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> weight[i + 1];

	for (int i = 0; i < N; i++)
		cin >> cost[i + 1];

	for (int i = 0; i <= N; i++)
		fill_n(dp[i], MAX * MAX + 1, 0);


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX * MAX; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= cost[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + weight[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < MAX * MAX + 1; i++) {
		if (dp[N][i] >= M) {
			ans = i;
			break;
		}
	}


	cout << ans << "\n";

	return 0;
}
