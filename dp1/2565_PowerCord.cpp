#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get_LCS(vector<pair<int, int>>&cmd) {
	sort(cmd.begin(), cmd.end());

	int dp[100];
	fill_n(dp, 100, 1);

	for (int i = 0; i < cmd.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (cmd[i].second >= cmd[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int mx = 0;
	for (int i = 0; i < cmd.size(); i++)
		mx = max(mx, dp[i]);

	return cmd.size() - mx;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>cmd(n);

	for (int i = 0; i < n; i++)
		cin >> cmd[i].first >> cmd[i].second;

	cout << get_LCS(cmd) << "\n";

	return 0;
}
