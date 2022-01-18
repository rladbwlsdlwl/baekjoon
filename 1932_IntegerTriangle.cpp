#include<iostream>
#include<algorithm>
#define MAX 501
using namespace std;

int dp[MAX][MAX] = { 0, };
int table[MAX][MAX];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> table[i][j];
	}

	dp[1][1] = table[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) 
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + table[i][j];
		
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) 
		mx = max(mx, dp[n][i]);
	

	cout << mx << "\n";
	return 0;
}
