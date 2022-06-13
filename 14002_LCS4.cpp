#include<iostream>
#define MAX 1000

using namespace std;

int seq[MAX];
int dp[MAX] = { 0, };


void dfs(int n, int size) {
	if (size>1) {
		int n_;
		for (int i = n; i >= 0; i--) {
			if (dp[i] == size - 1 && seq[n] > seq[i]) {
				n_ = i;
				break;
			}
		}

		dfs(n_, size - 1);
		cout << seq[n_] << " ";
	}
}

void getLongestSubsequence(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (seq[i] > seq[j])
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
	}


	int idx = 0;
	for (int i = 0; i < n; i++)
		idx = (dp[i] > dp[idx] ? i : idx);

	cout << dp[idx] << "\n";

	dfs(idx, dp[idx]);
	cout << seq[idx] << "\n";
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> seq[i];

	getLongestSubsequence(n);

	return 0;
}
