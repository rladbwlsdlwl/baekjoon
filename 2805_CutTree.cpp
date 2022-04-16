#include<iostream>
#include<algorithm>
#define MAX 1000000

int tree[MAX];
long long dp[MAX];
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree, tree + n);

	int cut = 0;
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = dp[i + 1] + (tree[i + 1] - tree[i]) * (n - i - 1);
		if (dp[i] > m) {
			cut = i + 1;
			break;
		}
		else if (dp[i] == m) {
			cut = i;
			break;
		}
	}

	int ans = tree[cut];
	long long remain = dp[cut];
	while (remain < m) {
		remain += 1 * (n - cut);
		ans--;
	}
	
	cout << ans << "\n";

	return 0;
}
