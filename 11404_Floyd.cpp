#include<iostream>
#include<algorithm>
#define MAX 101
const int INF = 987654321;
using namespace std;

int dp[MAX][MAX];

int main() {
	int n, m;
	cin >> n >> m;
	
	// initialized 
	for (int i = 1; i <= n; i++) 
		fill_n(dp[i], MAX, INF);
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	// input
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		dp[s][e] = min(dp[s][e], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != INF)
				cout << dp[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}

	return 0;

}
