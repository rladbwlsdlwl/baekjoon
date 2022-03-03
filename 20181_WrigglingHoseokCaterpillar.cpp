#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long dp[100001];
long long sum = 0;
int main() {
	int N, K;
	cin >> N >> K;

	vector<int>cmd(N+1);
	for (int i = 1; i <= N; i++)
		cin >> cmd[i];

	dp[0] = 0;
	for (int l = 0, r = 1; r <= N; r++) {
		sum += cmd[r];
		dp[r] = dp[r - 1];
		while (sum >= K) {
			dp[r] = max(dp[r], sum - K + dp[l]);
			sum -= cmd[++l];
		}
	}

	cout << dp[N] << "\n";

	return 0;
}
