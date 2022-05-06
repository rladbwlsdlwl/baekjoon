#include<iostream>
#define MAX 100
using namespace std;

int n;
int eqt[MAX]; // equation
long long dp[MAX][21];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> eqt[i];

	for (int i = 0; i < n; i++)
		fill_n(dp[i], 21, 0);

	dp[0][eqt[0]] = 1;
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] && j + eqt[i] <= 20)
				dp[i][j + eqt[i]] += dp[i - 1][j];
			if (dp[i - 1][j] && j - eqt[i] >= 0)
				dp[i][j - eqt[i]] += dp[i - 1][j];
		}
	}

	cout << dp[n - 2][eqt[n - 1]] << "\n";
	return 0;
}
