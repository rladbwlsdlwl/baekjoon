#include<iostream>
#define MAX 100001

using namespace std;

int cmd[2][MAX];
int dp[2][MAX];
int main() {
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++)
				cin >> cmd[i][j];
		}

		int mx1 = 0, mx2 = 0;

		dp[0][0] = 0;
		dp[1][0] = 0;
		for (int i = 1; i <= n; i++) {
			mx1 = max(mx1, dp[1][i-1]);
			mx2 = max(mx2, dp[0][i-1]);
			dp[0][i] = mx1 + cmd[0][i];
			dp[1][i] = mx2 + cmd[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}

	return 0;
}
