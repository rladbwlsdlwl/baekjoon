#include<iostream>
#define MAX 1000

using namespace std;
int main() {
	int n;
	cin >> n;

	int cmd[MAX];
	for (int i = 0; i < n; i++)
		cin >> cmd[i];

	int dp[MAX];
	fill_n(dp, n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (cmd[i] > cmd[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++)
		mx = max(mx, dp[i]);

	cout << mx << "\n";
	return 0;
}
