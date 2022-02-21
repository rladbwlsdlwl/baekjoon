#include<iostream>
#include<vector>
#define MAX 100000
const int INF_ = -1000;

using namespace std;

int dp[MAX];

int get_sum(vector<int>& num) {
	dp[0] = num[0];

	for (int i = 1; i < num.size(); i++) 
		dp[i] = (num[i] < num[i] + dp[i - 1] ? num[i] + dp[i - 1] : num[i]);
	
	int mx = INF_;
	for (int i = 0; i < num.size(); i++)
		mx = (mx < dp[i] ? dp[i] : mx);

	return mx;
}

int main() {
	int n;
	cin >> n;

	vector<int>cmd(n);
	for (int i = 0; i < n; i++)
		cin >> cmd[i];

	cout << get_sum(cmd) << "\n";

	return 0;
}
