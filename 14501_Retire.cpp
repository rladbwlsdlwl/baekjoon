#include<iostream>
#include<vector>
#include<algorithm> // use max
#define MAX 16

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>day(MAX, 0);
	vector<int>money(MAX, 0);
	for (int i = 1; i <= n; i++) {
		cin >> day[i];
		cin >> money[i];
	}

	int dp[MAX];
	fill_n(dp, MAX, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int p = i - j + 1;
			if (day[p] <= j)
				dp[i] = max(dp[i], money[p] + dp[p - 1]);
		}
	}

	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, dp[i]);

	cout << mx << "\n";
	return 0;
}
